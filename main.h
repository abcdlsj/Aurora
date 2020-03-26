/*
 *   Copyright (c) 2020 @abcdlsj
 *   All rights reserved.
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define	MAXLINE	 8192  /* Max text line length */
#define LISTENQ  1024  /* Second argument to listen() */

extern char **environ; /* Defined by libc */

/*rio*/
#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;
    int rio_cnt;
    char *rio_bufptr;
    char rio_buf[RIO_BUFSIZE];
} rio_t;

void unix_error(char *msg);
void gai_error(int code, char *msg);

int open_clientfd(char *hostname, char *port);
int open_listenfd(char *port);

ssize_t rio_readn(int fd, void *usrbuf, size_t t);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
static ssize_t rio_read(rio_t *rrp, char *usrbuf, size_t n);
void rio_readinitb(rio_t *rp, int fd);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);

void read_requesthdrs(rio_t *rp);
void clienterror(int fd, char *cause, char *errnum,
		 char *shortmsg, char *longmsg);

#endif // __MAIN_H__
