//
// Created by chenjunlong on 2020/9/6.
//

#include "EglHelper.h"
EglHelper::EglHelper() {
    mEglDisplay = EGL_NO_DISPLAY;
    mEglSurface = EGL_NO_SURFACE;
    mEglContext = EGL_NO_CONTEXT;
}

EglHelper::~EglHelper(){

}

int EglHelper::initEgl(EGLNativeWindowType window) {

    mEglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (mEglDisplay == EGL_NO_DISPLAY) {
        return -1;
    }

    EGLint *version = new EGLint[2];
    if (!eglInitialize(mEglDisplay, &version[0], &version[1])) {

        return -1;
    }

    const EGLint attrib_config_list[] = {
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 8,
            EGL_STENCIL_SIZE, 8,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_NONE
    };

    EGLint num_config;

    if (!eglChooseConfig(mEglDisplay, attrib_config_list, NULL, 1, &num_config)) {

        return -1;
    }

    EGLConfig eglConfig;
    if (!eglChooseConfig(mEglDisplay, attrib_config_list, &eglConfig, num_config, &num_config)) {

        return -1;
    }

    const EGLint attrib_ctx_list[] = {
            EGL_CONTEXT_CLIENT_VERSION, 2,
            EGL_NONE
    };
    mEglContext = eglCreateContext(mEglDisplay, eglConfig, NULL, attrib_ctx_list);
    if (mEglContext == EGL_NO_CONTEXT) {

        return -1;
    }

    mEglSurface = eglCreateWindowSurface(mEglDisplay, eglConfig, window, NULL);
    if (mEglSurface == EGL_NO_SURFACE) {

        return -1;
    }

    if (!eglMakeCurrent(mEglDisplay, mEglSurface, mEglSurface, mEglContext)) {

        return -1;
    }

    return 0;
}

int EglHelper::swapBuffers() {
    if (mEglDisplay != EGL_NO_DISPLAY && mEglSurface != EGL_NO_SURFACE &&
        eglSwapBuffers(mEglDisplay, mEglSurface)) {
        return 0;
    }
    return -1;
}

void EglHelper::destroyEgl() {
    if (mEglDisplay != EGL_NO_DISPLAY) {

        eglMakeCurrent(mEglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

        if (mEglSurface != EGL_NO_SURFACE) {
            eglDestroySurface(mEglDisplay, mEglSurface);
            mEglSurface = EGL_NO_SURFACE;
        }

        if (mEglContext != EGL_NO_CONTEXT) {
            eglDestroyContext(mEglDisplay, mEglContext);
            mEglContext = EGL_NO_CONTEXT;
        }

        if (mEglDisplay != EGL_NO_DISPLAY) {
            eglTerminate(mEglDisplay);
            mEglDisplay = EGL_NO_DISPLAY;
        }
    }
}
