cmake_minimum_required(VERSION 3.17)
project(Aurora)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aurora main.cpp Aurora/ThreadPool.h Aurora/noncopyable.h Aurora/Callbacks.h)