#include "tcp_server.h"
#include "eventloop.h"
int main() {
  EventLoop loop;
  TcpServer tcpserver(&loop);
  tcpserver.start();
  loop.loop();
  return 0;
}