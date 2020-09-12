#include "declear.h"
#include "task.h"

class Thread
{
    public:
        Thread(Task& task);
        void start();
        pid_t gettid();
    private:
        Task _task;
};
