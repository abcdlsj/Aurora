#include "main.h"

void doit(int fd);
void read_request(rio_t *rp);
int parse_uri(char *uri, char *filename, char *cgiargs);
void serve_static(int fd, char *filename, int filesize);
void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char * filename, char *cgiargs);
void clienterror(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg);

/* $begin errorfuns */
/* $begin unixerror */
void unix_error(char *msg) { /* Unix-style error */
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(0);
}
/* $end unixerror */
void gai_error(int code, char *msg) /* Getaddrinfo-style error */ {
  fprintf(stderr, "%s: %s\n", msg, gai_strerror(code));
  exit(0);
}
/* $end errorfuns */

//

int Dup2(int fd1, int fd2) {
  int rc;

  if ((rc = dup2(fd1, fd2)) < 0)
    unix_error("Dup2 error");
  return rc;
}

/* $begin forkwrapper */
pid_t Fork(void) {
  pid_t pid;

  if ((pid = fork()) < 0)
    unix_error("Fork error");
  return pid;
}
/* $end forkwrapper */

void Execve(const char *filename, char *const argv[], char *const envp[])
{
  if (execve(filename, argv, envp) < 0)
    unix_error("Execve error");
}

/* $begin wait */
pid_t Wait(int *status)
{
  pid_t pid;

  if ((pid  = wait(status)) < 0)
    unix_error("Wait error");
  return pid;
}
/* $end wait */
//
void *Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset) {
  void *ptr;

  if ((ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1))
    unix_error("mmap error");
  return(ptr);
}

void Munmap(void *start, size_t length)
{
  if (munmap(start, length) < 0)
    unix_error("munmap error");
}

int Open(const char *pathname, int flags, mode_t mode)
{
  int rc;

  if ((rc = open(pathname, flags, mode))  < 0)
    unix_error("Open error");
  return rc;
}

void Close(int fd)
{
  int rc;

  if ((rc = close(fd)) < 0)
    unix_error("Close error");
}


/****************************************
 * The Rio package - Robust I/O functions
 ****************************************/

/*
 * rio_readn - Robustly read n bytes (unbuffered)
 */
/* $begin rio_readn */
ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while (nleft > 0) {
    if ((nread = read(fd, bufp, nleft)) < 0) {
      if (errno == EINTR) /* Interrupted by sig handler return */
	nread = 0;      /* and call read() again */
      else
	return -1;      /* errno set by read() */
    }
    else if (nread == 0)
      break;              /* EOF */
    nleft -= nread;
    bufp += nread;
  }
  return (n - nleft);         /* Return >= 0 */
}
/* $end rio_readn */

/*
 * rio_writen - Robustly write n bytes (unbuffered)
 */
/* $begin rio_writen */
ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
  size_t nleft = n;
  ssize_t nwritten;
  char *bufp = usrbuf;

  while (nleft > 0) {
    if ((nwritten = write(fd, bufp, nleft)) <= 0) {
      if (errno == EINTR)  /* Interrupted by sig handler return */
	nwritten = 0;    /* and call write() again */
      else
	return -1;       /* errno set by write() */
    }
    nleft -= nwritten;
    bufp += nwritten;
  }
  return n;
}
/* $end rio_writen */

/*
 * rio_read - This is a wrapper for the Unix read() function that
 *    transfers min(n, rio_cnt) bytes from an internal buffer to a user
 *    buffer, where n is the number of bytes requested by the user and
 *    rio_cnt is the number of unread bytes in the internal buffer. On
 *    entry, rio_read() refills the internal buffer via a call to
 *    read() if the internal buffer is empty.
 */
/* $begin rio_read */
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
  int cnt;

  while (rp->rio_cnt <= 0) {  /* Refill if buf is empty */
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf,
		       sizeof(rp->rio_buf));
    if (rp->rio_cnt < 0) {
      if (errno != EINTR) /* Interrupted by sig handler return */
	return -1;
    }
    else if (rp->rio_cnt == 0)  /* EOF */
      return 0;
    else
      rp->rio_bufptr = rp->rio_buf; /* Reset buffer ptr */
  }

  /* Copy min(n, rp->rio_cnt) bytes from internal buf to user buf */
  cnt = n;
  if (rp->rio_cnt < n)
    cnt = rp->rio_cnt;
  memcpy(usrbuf, rp->rio_bufptr, cnt);
  rp->rio_bufptr += cnt;
  rp->rio_cnt -= cnt;
  return cnt;
}
/* $end rio_read */

/*
 * rio_readinitb - Associate a descriptor with a read buffer and reset buffer
 */
/* $begin rio_readinitb */
void rio_readinitb(rio_t *rp, int fd)
{
  rp->rio_fd = fd;
  rp->rio_cnt = 0;
  rp->rio_bufptr = rp->rio_buf;
}
/* $end rio_readinitb */

/*
 * rio_readnb - Robustly read n bytes (buffered)
 */
/* $begin rio_readnb */
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while (nleft > 0) {
    if ((nread = rio_read(rp, bufp, nleft)) < 0)
      return -1;          /* errno set by read() */
    else if (nread == 0)
      break;              /* EOF */
    nleft -= nread;
    bufp += nread;
  }
  return (n - nleft);         /* return >= 0 */
}
/* $end rio_readnb */

/*
 * rio_readlineb - Robustly read a text line (buffered)
 */
/* $begin rio_readlineb */
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
  int n, rc;
  char c, *bufp = usrbuf;

  for (n = 1; n < maxlen; n++) {
    if ((rc = rio_read(rp, &c, 1)) == 1) {
      *bufp++ = c;
      if (c == '\n') {
	n++;
	break;
      }
    } else if (rc == 0) {
      if (n == 1)
	return 0; /* EOF, no data read */
      else
	break;    /* EOF, some data was read */
    } else
      return -1;	  /* Error */
  }
  *bufp = 0;
  return n-1;
}
/* $end rio_readlineb */

/**********************************
 * Wrappers for robust I/O routines
 **********************************/
ssize_t Rio_readn(int fd, void *ptr, size_t nbytes)
{
  ssize_t n;

  if ((n = rio_readn(fd, ptr, nbytes)) < 0)
    unix_error("Rio_readn error");
  return n;
}

void Rio_writen(int fd, void *usrbuf, size_t n)
{
  if (rio_writen(fd, usrbuf, n) != n)
    unix_error("Rio_writen error");
}

void Rio_readinitb(rio_t *rp, int fd)
{
  rio_readinitb(rp, fd);
}

ssize_t Rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
  ssize_t rc;

  if ((rc = rio_readnb(rp, usrbuf, n)) < 0)
    unix_error("Rio_readnb error");
  return rc;
}

ssize_t Rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
  ssize_t rc;

  if ((rc = rio_readlineb(rp, usrbuf, maxlen)) < 0)
    unix_error("Rio_readlineb error");
  return rc;
}


//封装，达到协议无关性
int open_clientfd(char *hostname, char *port) {
  int clientfd, rc;
  struct addrinfo hints, *listp, *p;

  /* Get a list of potential server addresses */
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;  /* 每个地址限制一个 addrinfo 结构 */
  hints.ai_flags = AI_NUMERICSERV;  /* 强制 service 为端口号 */
  hints.ai_flags |= AI_ADDRCONFIG;  /* connections 推荐 */
  if ((rc = getaddrinfo(hostname, port, &hints, &listp)) != 0) {
    fprintf(stderr, "getaddrinfo failed (%s:%s): %s\n", hostname, port, gai_strerror(rc));
    return -2;
  }

  /* 遍历 */
  for (p = listp; p; p = p->ai_next) {
    /* 新建 socket 描述符 */
    if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
      continue; /* 建立失败，遍历列表下一个 */

    /* 连接 */
    if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
      break; /* 成功，退出循环 */
    if (close(clientfd) < 0) { /* 连接失败 */
      fprintf(stderr, "open_clientfd: close failed: %s\n", strerror(errno));
      return -1;
    }
  }

  /* Clean up */
  freeaddrinfo(listp);
  if (!p) /* 遍历完列表都没成功，失败 */
    return -1;
  else    /* 成功 */
    return clientfd;
}

int open_listenfd(char *port)
{
  struct addrinfo hints, *listp, *p;
  int listenfd, rc, optval=1;

  /* Get a list of potential server addresses */
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;             /* Accept connections */
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; /* 接收所有 IP 的请求 */
  hints.ai_flags |= AI_NUMERICSERV;            /* 使用端口号 */
  if ((rc = getaddrinfo(NULL, port, &hints, &listp)) != 0) {
    fprintf(stderr, "getaddrinfo failed (port %s): %s\n", port, gai_strerror(rc));
    return -2;
  }

  /* Walk the list for one that we can bind to */
  for (p = listp; p; p = p->ai_next) {
    /* Create a socket descriptor */
    if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
      continue;  /* Socket failed, try the next */

    /* Eliminates "Address already in use" error from bind */
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, /* 允许重用本地地址和端口 */
	       (const void *)&optval /* 使服务器能够被终止，重启，和立即开始接收连续请求 */, sizeof(int));

    /* Bind the descriptor to the address */
    if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
      break; /* Success */
    if (close(listenfd) < 0) { /* 失败，关闭描述符，继续循环 */
      fprintf(stderr, "open_listenfd close failed: %s\n", strerror(errno));
      return -1;
    }
  }

  /* Clean up */
  freeaddrinfo(listp);
  if (!p) /* No address worked */
    return -1;

  /* Make it a listening socket ready to accept connection requests */
  if (listen(listenfd, LISTENQ) < 0) {
    close(listenfd);
    return -1;
  }
  /* 返回监听描述符 */
  return listenfd;
}

int Open_clientfd(char *hostname, char *port) {
  int rc;

  if ((rc = open_clientfd(hostname, port)) < 0)
    unix_error("Open_clientfd error");
  return rc;
}

int Open_listenfd(char *port) {
  int rc;

  if((rc = open_listenfd(port)) < 0)
    unix_error("Open_listenfd error");
  return rc;
}

int Accept(int s, struct sockaddr *addr, socklen_t *addrlen) {
  int rc;

  if((rc = accept(s, addr, addrlen)) < 0)
    unix_error("Accept error");
  return rc;
}

void Getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host, size_t hostlen, char *serv, size_t servlen, int flags) {
  int rc;
  if((rc = getnameinfo(sa, salen, host, hostlen, serv, servlen, flags)) != 0)
    gai_error(rc, "Getnameinfo error");
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

  listenfd = Open_listenfd(argv[1]);
  while(1) {
    clientlen = sizeof(clientaddr);
    connfd = Accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
    Getnameinfo((struct sockaddr *)&clientaddr, clientlen, hostname, MAXLINE, port, MAXLINE, 0);
    printf("Accepted connection from (%s, %s)\n", hostname, port);
    doit(connfd);
    close(connfd);
  }
}

/******************************************************************************/
void doit(int fd) {
  int is_static;
  struct stat sbuf;
  char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
  char filename[MAXLINE], cgiargs[MAXLINE];
  rio_t rio;

  Rio_readinitb(&rio, fd); //初始化 RIO 缓冲区
  if(!Rio_readlineb(&rio, buf, MAXLINE)) return;
  printf("%s", buf);
  sscanf(buf, "%s %s %s", method, uri, version);
  if(strcasecmp(method, "GET")) {
    clienterror(fd, method, "501", "Not Implemented", "Aurora does not implement this method");
    return;
  }
  if(is_static) {
    if(!(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode)) {
      clienterror(fd, filename, "403", "Forbidden", "Aurora couldn't read the file");
      return;
    }
    serve_static(fd, filename, sbuf.st_size);
  }
  else {
    if(!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
      clienterror(fd, filename, "403", "Forbidden", "Aurora couldn't run the CGI programe");
      return;
    }
    serve_dynamic(fd, filename, cgiargs);
  }
}

int parse_uri(char *uri, char *filename, char *cgiargs) {
  char *ptr;
  if(!strstr(uri, "cgi-bin")) {
    strcpy(cgiargs, "cgi-bin");
    strcpy(filename, ".");
    strcat(filename, uri);
    if(uri[strlen(uri) - 1] == '/')
      strcat(filename, "home.html");
    return 1;
  }
  else {
    ptr = index(uri, '?');
    if(ptr) {
      strcpy(cgiargs, ptr+1);
      *ptr = '\0';
    }
    else
      strcpy(cgiargs, "");
    strcpy(filename, ".");
    strcat(filename, uri);
    return 0;
  }
}

void serve_static(int fd, char *filename, int filesize) {
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

  srcfd = Open(filename, O_RDONLY, 0);
  srcp = Mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0); //line:netp:servestatic:mmap
  Close(srcfd);                       //line:netp:servestatic:close
  Rio_writen(fd, srcp, filesize);     //line:netp:servestatic:write
  Munmap(srcp, filesize);
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
  else
    strcpy(filetype, "text/plain");
}

/*
 * serve_dynamic - run a CGI program on behalf of the client
 */
/* $begin serve_dynamic */
void serve_dynamic(int fd, char *filename, char *cgiargs)
{
  char buf[MAXLINE], *emptylist[] = { NULL };

  /* Return first part of HTTP response */
  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Server: Aurora Web Server\r\n");
  Rio_writen(fd, buf, strlen(buf));

  if (Fork() == 0) { /* Child */ //line:netp:servedynamic:fork
    /* Real server would set all CGI vars here */
    setenv("QUERY_STRING", cgiargs, 1); //line:netp:servedynamic:setenv
    Dup2(fd, STDOUT_FILENO);         /* Redirect stdout to client */ //line:netp:servedynamic:dup2
    Execve(filename, emptylist, environ); /* Run CGI program */ //line:netp:servedynamic:execve
  }
  Wait(NULL); /* Parent waits for and reaps child */ //line:netp:servedynamic:wait
}
/* $end serve_dynamic */

/* $begin read_requesthdrs */
void read_requesthdrs(rio_t *rp)
{
  char buf[MAXLINE];

  Rio_readlineb(rp, buf, MAXLINE);
  printf("%s", buf);
  while(strcmp(buf, "\r\n")) {
    Rio_readlineb(rp, buf, MAXLINE);
    printf("%s", buf);
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
