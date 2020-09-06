#ifndef _TCPCONNECT_H
#define _TCPCONNECT_H

#include "declear.h"
#include "i_channel_callback.h"

class TcpConnection : public IChannelCallBack {
public:
  TcpConnection(int sockfd, EventLoop* loop);
  ~TcpConnection();
  void virtual OnIn(int sockfd);

private:
  EventLoop* _loop;
  int _sockfd;
  Channel *_PChannel;
};

#endif // _TCPCONNECT_H
