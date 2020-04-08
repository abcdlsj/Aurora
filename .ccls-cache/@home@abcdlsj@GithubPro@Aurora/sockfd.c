#include "sockfd.h"

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
