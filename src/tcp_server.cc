#include "tcp_server.h"
#include "acceptor.h"
#include "channel.h"
#include "tcp_connect.h"

#include <errno.h>
#include <iostream>
#include <vector>

TcpServer::TcpServer(EventLoop *loop) : _loop(loop), _pAcceptor(nullptr) {}
TcpServer::~TcpServer() {}
void TcpServer::start() {
  _pAcceptor = new Acceptor(_loop); // Memory Leak !!!
  _pAcceptor->setCallBack(this);
  _pAcceptor->start();
}

void TcpServer::newConnection(int sockfd) {
  TcpConnection *tcp = new TcpConnection(sockfd, _loop);
  _connections[sockfd] = tcp;
}