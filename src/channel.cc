#include "channel.h"
#include "eventloop.h"
#include "i_channel_callback.h"

#include <iostream>
#include <sys/epoll.h>

Channel::Channel(int epollfd, int sockfd)
    : _epollfd(epollfd), _sockfd(sockfd), _events(0), _revents(0),
      _callBack(nullptr) {}

void Channel::setCallBack(IChannelCallBack *callBack) { _callBack = callBack; }

void Channel::setRevents(int revents) { _revents = revents; }

void Channel::handleEvent() {
  if (_revents & EPOLLIN) {
    _callBack->OnIn(_sockfd);
  }
}

void Channel::update() { _loop->update(this); }
int Channel::getSockfd() { return _sockfd; }

int Channel::getEvents() { return _events; }
void Channel::enableReading() {
  _events |= EPOLLIN;
  update();
}
