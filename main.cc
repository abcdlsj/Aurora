#include "tcp_server.h"
#include "event_loop.h"
#include "echo_server.h"

int main(int args, char** argv)
{
    EventLoop loop;
    EchoServer echoserver(&loop);
    echoserver.start();
    loop.loop();
    return 0;
}
