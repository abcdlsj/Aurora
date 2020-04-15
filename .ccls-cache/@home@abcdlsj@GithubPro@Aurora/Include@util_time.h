#ifndef AURORA_INCLUDE_UTIL_TIME_H
#define AURORA_INCLUDE_UTIL_TIME_H
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include <queue>
#include <stack>
#include "http_base.h"
using namespace std;

const char* ok_200_title = "OK";

#endif // AURORA_INCLUDE_UTIL_TIME_H
