//
// Created by abcdlsj on 2020/6/4.
//

#ifndef AURORA_AURORA_EPOLLER_H_
#define AURORA_AURORA_EPOLLER_H_
#include <vector>

#include "noncopyable.h"

namespace Aurora {
class EventLoop;
class Channel;

class EPoller : noncopyable {
 public:
  typedef std::vector<Channel *> ChannelList;

  explicit EPoller(EventLoop *loop);
  ~EPoller();

  void poll(ChannelList &activeChannels);
  void updateChannel(Channel *channel);

 private:
  void updateChannel(int op, Channel *channel);
  EventLoop *loop_;
  std::vector<struct epoll_event> events_;
  int epollfd_;
}
#endif //AURORA_AURORA_EPOLLER_H_
