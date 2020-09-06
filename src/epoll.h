#ifndef _EPOLL_H
#define _EPOLL_H
#include <sys/epoll.h>
#include <vector>

#include "declear.h"
#include "define.h"

using namespace std;

class Epoll {
public:
  Epoll();
  ~Epoll();
  void poll(vector<Channel *> *pChannels);
  void update(Channel *channel);

private:
  int _epollfd;
  struct epoll_event _events[MAX_EVENTS];
};

#endif // _EPOLL_H