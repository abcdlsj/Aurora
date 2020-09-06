#include "eventloop.h"
#include "channel.h"
#include "epoll.h"

EventLoop::EventLoop() : _quit(false), _poller(new Epoll()) {}

EventLoop::~EventLoop() {}

void EventLoop::loop() {
  while (!_quit) {
    vector<Channel *> channels;
    _poller->poll(&channels);

    vector<Channel *>::iterator it;
    for (it = channels.begin(); it != channels.end(); ++it) {
      (*it)->handleEvent();
    }
  }
}

void EventLoop::update(Channel *channel) { _poller->update(channel); }