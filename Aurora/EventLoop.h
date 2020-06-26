//
// Created by abcdlsj on 2020/6/4.
//

#ifndef AURORA_AURORA_EVENTLOOP_H_
#define AURORA_AURORA_EVENTLOOP_H_
#include <atomic>
#include <mutex>
#include <vector>
#include <sys/types.h>

#include "Timer.h"
#include "Epoller.h"
#include "TimerQueue.h"

namespace Aurora {
class EventLoop: noncopyable {
 public:
  EventLoop();
  ~EventLoop();

  void loop();
  void quit();

  void runInloop(const Task& task);
  void runInloop(Task& task);
  void queueInloop(const Task& task);
  void queueInloop(Task& task);

};
}

#endif //AURORA_AURORA_EVENTLOOP_H_
