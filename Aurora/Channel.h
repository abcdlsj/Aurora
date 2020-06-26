//
// Created by abcdlsj on 2020/6/9.
//

#ifndef AURORA_AURORA_CHANNEL_H_
#define AURORA_AURORA_CHANNEL_H_
#include <functional>
#include <memory>
#include <sys/epoll.h>

#include "noncopyable.h"

namespace Aurora {

class Eventloop;

class Channel : noncopyable {
 public:
  typedef std::function<void()> ReadCallback;
  typedef std::function<void()> WriteCallback;
  typedef std::function<void()> CloseCallback;
  typedef std::function<void()> ErrorCallback;

  Channel(Eventloop *loop, int fd);
  ~Channel();

  void setReadCallback(const ReadCallback &cb) {
  }
};

}

#endif //AURORA_AURORA_CHANNEL_H_
