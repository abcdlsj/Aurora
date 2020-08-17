#include "tcp_server.h"
#include "acceptor.h"
#include "channel.h"
#include "tcp_connect.h"

#include <errno.h>
#include <iostream>
#include <vector>

TcpServer::TcpServer() : _epollfd(-1), _pAcceptor(nullptr) {}
TcpServer::~TcpServer() {}
void TcpServer::start() {
  _epollfd = epoll_create(1);
  if (_epollfd <= 0)
    cout << "epoll_create error, errno:" << _epollfd << endl;
  _pAcceptor = new Acceptor(_epollfd); // Memory Leak !!!
  _pAcceptor->setCallBack(this);
  _pAcceptor->start();

  for (;;) {
    vector<Channel *> channels;
    int fds = epoll_wait(_epollfd, _events, MAX_EVENTS, -1);
    if (fds == -1) {
      cout << "epoll_wait error, errno:" << errno << endl;
      break;
    }
    for (int i = 0; i < fds; i++) {
      Channel *pChannel = static_cast<Channel *>(_events[i].data.ptr);
      pChannel->setRevents(_events[i].events);
      channels.push_back(pChannel);
    }

    vector<Channel *>::iterator it;
    for (it = channels.begin(); it != channels.end(); ++it) {
      (*it)->handleEvent();
    }
  }
}