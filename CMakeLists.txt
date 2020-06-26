cmake_minimum_required(VERSION 3.17)
project(Aurora)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aurora main.cpp Aurora/ThreadPool.h Aurora/noncopyable.h Aurora/Callbacks.h Aurora/ThreadPool.cc Aurora/Epoller.h Aurora/EPoller.cc Aurora/Logger.h Aurora/EventLoop.h Aurora/Timer.h Aurora/TimerQueue.h Aurora/Timestamp.h Aurora/Channel.h)