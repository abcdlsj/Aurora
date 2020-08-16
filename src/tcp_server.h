#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <string.h> //for bzero
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

#define MAX_LINE 100
#define MAX_EVENTS 500
#define MAX_LISTENFD 5

class TcpServer {
public:
  TcpServer();
  ~TcpServer();
  void start();

private:
  int createAndListen();
};