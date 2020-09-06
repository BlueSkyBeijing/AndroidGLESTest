//
// Created by chenjunlong on 2020/9/6.
//

#ifndef ANDROIDGLESTEST_EGLTHREAD_H
#define ANDROIDGLESTEST_EGLTHREAD_H


#include <EGL/eglplatform.h>
#include "pthread.h"
#include "android/native_window.h"
#include "EglHelper.h"
#include <unistd.h>
#include "GLES2/gl2.h"


#define RENDER_MODULE_AUTO 1
#define RENDER_MODULE_MANUAL 2

class EglThread {
public:
    pthread_t mEglThread = -1;
    ANativeWindow *mANativeWindow = NULL;

    int mRenderType = RENDER_MODULE_MANUAL;

    bool isCreate = false;
    bool isChange = false;
    bool isExit = false;
    bool isStart = false;

    int surfaceWidth = 0;
    int surfaceHeight = 0;


    typedef void(*OnCreate)();
    OnCreate onCreate;

    typedef void(*OnChange)(int width, int height);
    OnChange onChange;

    typedef void(*OnDraw)();
    OnDraw onDraw;


    pthread_mutex_t pthread_mutex;
    pthread_cond_t pthread_cond;

public:
    EglThread();

    ~EglThread();

    void onSurfaceCreate(EGLNativeWindowType window);

    void onSurfaceChange(int width, int height);

    void setRenderModule(int renderModule);

    void notifyRender();

    void callBackOnCreate(OnCreate onCreate);

    void callBackOnChange(OnChange onChange);

    void callBackOnDraw(OnDraw onDraw);


};



#endif //ANDROIDGLESTEST_EGLTHREAD_H
