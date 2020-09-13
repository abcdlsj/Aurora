//
// Created by abcdlsj on 2020/9/13.
//

#ifndef AURORA_LOG_H
#define AURORA_LOG_H

#include "stdarg.h"

#define LOG_DEBUG_TYPE 0
#define LOG_MSG_TYPE   1
#define LOG_WARN_TYPE  2
#define LOG_ERR_TYPE   3

void aurora_log(int severity, const char *msg);

void aurora_logx(int severity, const char *errstr, const char *fmt, va_list ap);

void aurora_msgx(const char *fmt, ...);

void aurora_debugx(const char *fmt, ...);


#define LOG_MSG(msg) aurora_log(LOG_MSG_TYPE, msg)
#define LOG_ERR(msg) aurora_log(LOG_ERR_TYPE, msg)

#endif //AURORA_LOG_H
