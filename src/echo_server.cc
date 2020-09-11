#include "echo_server.h"
#include "tcp_connect.h"
#include <iostream>

EchoServer::EchoServer(EventLoop* pLoop) : _pLoop(pLoop,
_pServer(pLoop){

}
