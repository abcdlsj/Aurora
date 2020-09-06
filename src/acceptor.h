#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H

#include "declear.h"
#include "define.h"
#include "i_channel_callback.h"

class Acceptor : public IChannelCallBack {
public:
  Acceptor(EventLoop* loop);
  ~Acceptor();
  void virtual OnIn(int socket);
  void setCallBack(IAcceptorCallBack *pCallBack);
  void start();

private:
  int createAndListen();
  int _epollfd;
  int _listenfd;
  Channel* _pAcceptChannel;
  IAcceptorCallBack *_pCallBack;
  EventLoop* _loop;
};

#endif // _ACCEPTOR_H