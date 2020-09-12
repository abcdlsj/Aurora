#pragma once
#include "declear.h"
#include <string>
using namespace std;

class i_aurora_user
{
    public:
        virtual void onConnection(TcpConnection* pCon) = 0;
        virtual void onMessage(TcpConnection* pCon, Buffer* pBuf) = 0;
        virtual void onWriteComplate(TcpConnection* pCon) = 0;
};
