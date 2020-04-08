/*
 *   Copyright (c) 2020 @abcdlsj
 *   All rights reserved.
 */

/* main.c --- Aurora Main.c
 *
 * Author: abcdlsj <lisongjianshuai@gmail.com>
 * Copyright © 2020, abcdlsj, all rights reserved.
 * Created: 20 三月 2020
 *
 */
//Code:

#include "main.h"

/* $begin unixerror */
void unix_error(char *msg) /* Unix-style error */
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(0);
}
/* $end unixerror */

//
void sigchid_handler(int sig) {
  //循环处理僵死子进程，WNOHANG 表明在有尚未终止的子进程在运行时不要阻塞
  while(waitpid(-1, 0, WNOHANG) > 0) ;
  return;
}
//

/* $begin sigaction */
handler_t *Signal(int signum, handler_t *handler)
{
  struct sigaction action, old_action;

  action.sa_handler = handler;
  sigemptyset(&action.sa_mask); /* Block sigs of type being handled */
  action.sa_flags = SA_RESTART; /* Restart syscalls if possible */

  if (sigaction(signum, &action, &old_action) < 0)
    unix_error("Signal error");
  return (old_action.sa_handler);
}
/* $end sigaction */

// 更好的处理 SIGPIPE 信号和 EPIPE 错误
void Rio_writen(int fd, void *usrbuf, size_t n)
{
    if (Rio_writen(fd, usrbuf, n) != n) {
      if (errno == EPIPE)
	fprintf(stderr, "EPIPE error");

      fprintf(stderr, "%s ", strerror(errno));
      unix_error("Client side has ended connection");
    }
}

/* main */
int main(int argc, char **argv) {
  int listenfd, connfd;
  char hostname[MAXLINE], port[MAXLINE];
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;

  /* 检查参数 */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }

  listenfd = open_listenfd(argv[1]);

  //SIGCHLD 回收僵死子进程的资源
  Signal(SIGCHLD, sigchid_handler);

  while(1) {
    clientlen = sizeof(clientaddr);
    connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
    getnameinfo((struct sockaddr *)&clientaddr, clientlen, hostname, MAXLINE, port, MAXLINE, 0);

    /* //多进程 */
    if (fork() == 0) {
      close(listenfd);
      doit(connfd);
      close(connfd);
      exit(0);
    }

    close(connfd);
    printf("Accepted connection from (%s, %s)\n", hostname, port);

  }
}

void doit(int fd) {
  int is_static;
  struct stat sbuf;
  char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
  char filename[MAXLINE], cgiargs[MAXLINE];
  rio_t rio;

  rio_readinitb(&rio, fd); //初始化 RIO 缓冲区
  if(!rio_readlineb(&rio, buf, MAXLINE)) return;
  printf("%s", buf);

  /*读请求行*/
  sscanf(buf, "%s %s %s", method, uri, version);

  //不是这三个请求返回 501
  if(strcasecmp(method, "GET") && strcasecmp(method, "HEAD") && strcasecmp(method, "POST")) {
    clienterror(fd, method, "501", "Not Implemented", "Aurora does not implement this method");
    return;
  }

  read_requesthdrs(&rio, cgiargs, method);

  is_static = parse_uri(uri, filename, cgiargs, method);
  if(stat(filename, &sbuf) < 0) {
    clienterror(fd, filename, "404", "Not found", "Aurora couldn't find this file");
    return;
  }
  if(is_static ) {
    if(!(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode)) {
      clienterror(fd, filename, "403", "Forbidden", "Aurora couldn't read the file");
      return;
    }
    /*HEAD GET*/
    serve_static(fd, filename, sbuf.st_size, method);
  }
  else {
    if(!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
      clienterror(fd, filename, "403", "Forbidden", "Aurora couldn't run the CGI programe");
      return;
    }
    /*GET HEAD POST*/
    serve_dynamic(fd, filename, cgiargs, method);
  }
}

int parse_uri(char *uri, char *filename, char *cgiargs, char *method) {
  char *ptr;
  if(!strstr(uri, "cgi-bin")) {
    strcpy(cgiargs, "");
    strcpy(filename, ".");
    strcat(filename, uri);
    if(uri[strlen(uri) - 1] == '/')
      strcat(filename, "index.html");
    return 1;
  }

  else {
    if(strcasecmp(method, "GET") == 0) {
      ptr = index(uri, '?');
      if(ptr) {
	strcpy(cgiargs, ptr+1);
	*ptr = '\0';
      }
      else
	strcpy(cgiargs, "");
    }
    strcpy(filename, ".");
    strcat(filename, uri);
    return 0;
  }
}

void serve_static(int fd, char *filename, int filesize, char* method) {
  int srcfd;
  char *srcp, filetype[MAXLINE], buf[MAXLINE];

  get_filetype(filename, filetype);
  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Server: Aurora Web Server\r\n");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Content-length: %d\r\n", filesize);
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Content-type: %s\r\n\r\n", filetype);
  Rio_writen(fd, buf, strlen(buf));

  if(strcasecmp(method, "HEAD") == 0)
    return;

  srcfd = open(filename, O_RDONLY, 0);
  srcp = mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
  close(srcfd);
  Rio_writen(fd, srcp, filesize);
  munmap(srcp, filesize);
}

void get_filetype(char *filename, char *filetype) {
  if (strstr(filename, ".html"))
    strcpy(filetype, "text/html");
  else if (strstr(filename, ".gif"))
    strcpy(filetype, "image/gif");
  else if (strstr(filename, ".png"))
    strcpy(filetype, "image/png");
  else if (strstr(filename, ".jpg"))
    strcpy(filetype, "image/jpeg");
  else if (strstr(filename, ".mepg"))
    strcpy(filetype, "video/mpeg");
  else if (strstr(filename, ".webm"))
    strcpy(filetype, "video/webm");
  else
    strcpy(filetype, "text/plain");
}

/*
 * serve_dynamic - run a CGI program on behalf of the client
 */
/* $begin serve_dynamic */
void serve_dynamic(int fd, char *filename, char *cgiargs, char* method)
{
  char buf[MAXLINE], *emptylist[] = { NULL };

  /* Return first part of HTTP response */
  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Server: Aurora Web Server\r\n");
  Rio_writen(fd, buf, strlen(buf));

  if(strcasecmp(method, "HEAD") == 0) return;

  if (fork() == 0) { /* Child */
    /* Real server would set all CGI vars here */
    setenv("QUERY_STRING", cgiargs, 1);
    dup2(fd, STDOUT_FILENO);         /* Redirect stdout to client */
    execve(filename, emptylist, environ); /* Run CGI program */
  }
}
/* $end serve_dynamic */

/* $begin read_requesthdrs */
void read_requesthdrs(rio_t *rp, char *cgiargs, char *method)
{
  char buf[MAXLINE];

  rio_readlineb(rp, buf, MAXLINE);
  printf("%s", buf);
  while(strcmp(buf, "\r\n")) {
    rio_readlineb(rp, buf, MAXLINE);
    printf("%s", buf);
  }

  if(strcasecmp(method, "POST") == 0) {
    rio_readnb(rp, buf, rp->rio_cnt);
    strcpy(buf, cgiargs);
  }
  return;
}
/* $end read_requesthdrs */

/* $begin clienterror */
void clienterror(int fd, char *cause, char *errnum,
		 char *shortmsg, char *longmsg) {
  char buf[MAXLINE];

  /* Print the HTTP response headers */
  sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Content-type: text/html\r\n\r\n");
  Rio_writen(fd, buf, strlen(buf));

  /* Print the HTTP response body */
  sprintf(buf, "<html><title>Aurora Error</title>");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "<body bgcolor=""ffffff"">\r\n");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "%s: %s\r\n", errnum, shortmsg);
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "<p>%s: %s\r\n", longmsg, cause);
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "<hr><em>The Aurora Web server</em>\r\n");
  Rio_writen(fd, buf, strlen(buf));
}
/* $end clienterror */
