#pragma once

class IChannelCallback
{
    public:
        virtual void handleRead() = 0;
        virtual void handleWrite() = 0;
};
