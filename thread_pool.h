#pragma once

#include "declear.h"
#include "blocking_queue.h"
#include "task.h"
#include "i_run.h"

#include <vector>

using namespace std;

class ThreadPool : public IRun0 {
public:
    ThreadPool();

    void start(int numThreads);

    void addTask(Task &task);

    virtual void run0();

private:
    void runInThread();

    BlockingQueue<Task> _tasks;
    vector<Thread *> _threads;
};
