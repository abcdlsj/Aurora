#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include <map>
#include <sys/epoll.h>

#include "declear.h"
#include "define.h"
#include "i_acceptor_callback.h"

using namespace std;

class TcpServer : public IAcceptorCallBack {
public:
  TcpServer();
  ~TcpServer();
  void start();

  virtual void newConnection(int sockfd);

private:
  void update(Channel *pChannel, int op);
  int _epollfd;
  struct epoll_event _events[MAX_EVENTS];
  map<int, TcpConnection *> _channels;
  Acceptor *_pAcceptor;
};

#endif // _TCPSERVER_H