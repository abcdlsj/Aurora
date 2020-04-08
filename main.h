/*
 *   Copyright (c) 2020 @abcdlsj
 *   All rights reserved.
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/mman.h>
#include "rio.h"
#include "sockfd.h"

#endif // __MAIN_H__

extern char **environ; /* Defined by libc */
typedef void handler_t(int);

void unix_error(char *msg);
void sigchid_handler(int sig);

handler_t *Signal(int signum, handler_t *handler);

void doit(int fd);
void read_requesthdrs(rio_t *rp, char *cgiargs,char *method);
int parse_uri(char *uri, char *filename, char *cgiargs, char *method);
void serve_static(int fd, char *filename, int filesize, char* method);
void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char * filename, char *cgiargs, char* method);
void clienterror(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg);
