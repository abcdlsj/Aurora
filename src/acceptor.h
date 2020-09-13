//
// Created by abcdlsj on 2020/9/13.
//

#ifndef AURORA_ACCEPTOR_H
#define AURORA_ACCEPTOR_H

#include "common.h"

struct acceptor {
    int listen_port;
    int listen_fd;
};

struct acceptor *acceptor_init(int port);

#endif//AURORA_ACCEPTOR_H
