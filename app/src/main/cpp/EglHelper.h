//
// Created by chenjunlong on 2020/9/6.
//

#ifndef ANDROIDGLESTEST_EGLHELPER_H
#define ANDROIDGLESTEST_EGLHELPER_H


#include "EGL/egl.h"
#include "EGL/eglext.h"

class EglHelper {


public:
    EGLDisplay mEglDisplay;
    EGLContext mEglContext;
    EGLSurface mEglSurface;


public:
    EglHelper();

    ~EglHelper();

    int initEgl(EGLNativeWindowType surface);
    int swapBuffers();
    void destroyEgl();
};


#endif //ANDROIDGLESTEST_EGLHELPER_H
