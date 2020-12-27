cmake_minimum_required(VERSION 3.18)
project(Aurora)

set(CMAKE_CXX_STANDARD 14)

add_executable(Aurora src/common.h src/acceptor.h src/config.h src/log.h src/tcp_server.h src/inetaddress.h src/channel_map.h src/acceptor.cc src/buffer.h src/buffer.cc src/channel.cc src/channel.h src/channel_map.cc src/event_loop.cc src/event_loop.h src/event_loop_thread.cc src/event_loop_thread.h src/http_request.cc src/http_request.h src/http_response.cc src/http_response.h src/http_server.cc src/http_server.h src/log.cc src/tcp_server.cc src/tcp_connection.cc src/tcp_connection.h src/thread_pool.cc src/thread_pool.h src/utils.cc src/utils.h src/read.cc src/event_dispatcher.h src/epolll_dispatcher.cc src/poll_dispatcher.cc src/tcp_client.cc)

TARGET_LINK_LIBRARIES(Aurora pthread)
