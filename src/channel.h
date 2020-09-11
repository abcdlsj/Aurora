#ifndef _CHANNEL_H
#define _CHANNEL_H

#include "declear.h"

class Channel {
public:
  Channel(EventLoop* loop, int sockfd);
  ~Channel();
  void setCallBack(IChannelCallBack *callback);
  void handleEvent();
  void setRevents(int revent);
  void enableReading();
  int getSockfd();
  int getEvents();

private:
  void update();
  int _sockfd;
  int _events;  // 关注事件
  int _revents; // 已发生事件
  IChannelCallBack *_pCallBack;
  EventLoop *_pLoop;
};

#endif // _CHANNEL_H