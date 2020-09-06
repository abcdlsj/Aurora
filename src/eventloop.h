#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H
#include "declear.h"
class EventLoop {
public:
  EventLoop();
  ~EventLoop();
  void loop();
  void update(Channel *channel);

private:
  bool _quit;
  Epoll *_poller;
};
#endif //_EVENTLOOP_H