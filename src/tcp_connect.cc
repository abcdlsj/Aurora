#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <string.h> //for bzero
#include <sys/socket.h>
#include <unistd.h>

#include "channel.h"
#include "define.h"
#include "tcp_connect.h"
using namespace std;

TcpConnection::TcpConnection(int sockfd, EventLoop* loop)
    : _loop(loop), _sockfd(sockfd) {
  _PChannel = new Channel(_loop, _sockfd);
  _PChannel->setCallBack(this);
  _PChannel->enableReading();
}

TcpConnection::~TcpConnection() {}

void TcpConnection::OnIn(int sockfd) {
  int readlength;
  char line[MAX_LINE];
  if (sockfd < 0) {
    cout << "EPOLLIN sockfd < 0 error" << endl;
    return;
  }

  bzero(line, MAX_LINE);
  if ((readlength = read(sockfd, line, MAX_LINE)) < 0) {
    if (errno == ECONNRESET) {
      cout << "ECONNREST closed socket fd: " << sockfd << endl;
      close(sockfd);
    }
  } else if (readlength == 0) {
    cout << "read 0 closed socket fd: " << sockfd << endl;
    close(sockfd);
  } else {
    if (write(sockfd, line, readlength) != readlength) {
      cout << "error: not finished ont time" << endl;
    }
  }
}