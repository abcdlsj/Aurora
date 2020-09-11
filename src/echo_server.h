#ifndef _ECHOSERVER_H
#define _ECHOSERVER_H
#include "i_aurora_user.h"
#include "tcp_server.h"

class EchoServer : public IAuraroUser {
public:
  EchoServer(EventLoop *ploop);
  ~EchoServer();
  void start();
  void virtual onConnection(TcpConnection *pCon);
  void virtual onMessage(TcpConnection *pCon, const string &data);

private:
  EventLoop *_pLoop;
  TcpServer _pServer;
};

#endif // _ECHOSERVER_H