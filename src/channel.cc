#include "channel.h"
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

int Channel::getSockfd() { return _sockfd; }

void Channel::enableReading() { _events |= EPOLLIN; }

void Channel::update() {
  struct epoll_event ev;
  ev.data.ptr = this;
  ev.events = _events;
  epoll_ctl(_epollfd, EPOLL_CTL_ADD, _sockfd, &ev);
}