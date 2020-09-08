//
// Created by chenjunlong on 2020/9/8.
//

#include "android/log.h"

#ifndef ANDROIDGLESTEST_JNILOG_H
#define ANDROIDGLESTEST_JNILOG_H


#define LOGD(FORMAT, ...)  __android_log_print (ANDROID_LOG_DEBUG,"jniLog",FORMAT,##__VA_ARGS__)
#define LOGE(FORMAT, ...) __android_log_print (ANDROID_LOG_ERROR,"jniLog",FORMAT,##__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "jniLog", __VA_ARGS__)
#endif //ANDROIDGLESTEST_JNILOG_H
