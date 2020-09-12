#include "declear.h"
#include "i_channel_callback.h"
#include "buffer.h"
#include "i_run.h"

#include <string>
using namespace std;

class TcpConnection : public IChannelCallback
                      , public IRun0
                      , public IRun2
{
    public:
        TcpConnection(int sockfd, EventLoop* pLoop);
        ~TcpConnection();
        void send(const string& message);
        void sendInLoop(const string& message);
        void connectEstablished();
        void setUser(i_aurora_user* pUser);

        void setCallback(IAcceptorCallback* pCallback);
        virtual void handleRead();
        virtual void handleWrite();
        virtual void run0();
        virtual void run2(const string& message, void* param);
    private:
        int _sockfd;
        Channel* _pSocketChannel;
        EventLoop* _pLoop;
        i_aurora_user* _pUser;
        Buffer _inBuf;
        Buffer _outBuf;
};
