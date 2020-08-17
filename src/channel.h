#ifndef _CHANNEL_H
#define _CHANNEL_H

#include "declear.h"

class Channel {
public:
  Channel(int epollfd, int sockfd);
  ~Channel();
  void setCallBack(IChannelCallBack *callback);
  void handleEvent();
  void setRevents(int revent);
  int getSockfd();
  void enableReading();

private:
  void update();
  int _epollfd;
  int _sockfd;
  int _events;  // 关注事件
  int _revents; // 已发生事件
  IChannelCallBack *_callBack;
};

#endif // _CHANNEL_H