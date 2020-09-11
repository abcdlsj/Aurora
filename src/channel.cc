#include "channel.h"
#include "eventloop.h"
#include "i_channel_callback.h"

#include <iostream>
#include <sys/epoll.h>

Channel::Channel(EventLoop *ploop, int sockfd)
    : _events(0), _sockfd(sockfd), _revents(0), _pCallBack(nullptr),
      _pLoop(ploop) {}

void Channel::setCallBack(IChannelCallBack *pCallBack) { _pCallBack = pCallBack; }

void Channel::setRevents(int revents) { _revents = revents; }

void Channel::handleEvent() {
  if (_revents & EPOLLIN) {
    _pCallBack->OnIn(_sockfd);
  }
}

void Channel::update() { _pLoop->update(this); }
int Channel::getSockfd() { return _sockfd; }

int Channel::getEvents() { return _events; }
void Channel::enableReading() {
  _events |= EPOLLIN;
  update();
}
