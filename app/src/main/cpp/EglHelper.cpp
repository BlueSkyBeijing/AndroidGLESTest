//
// Created by chenjunlong on 2020/9/6.
//

#include "EglHelper.h"
#include <string>
#include "JNILog.h"

int printEGLConfigurations(EGLDisplay dpy) {
    EGLint numConfig = 0;
    EGLint returnVal = eglGetConfigs(dpy, NULL, 0, &numConfig);

    if (!returnVal) {
        return false;
    }
    LOGD("Number of EGL configuration: %d\n", numConfig);
    EGLConfig* configs = (EGLConfig*) malloc(sizeof(EGLConfig) * numConfig);
    if (! configs) {
        LOGD("Could not allocate configs.\n");
        return false;
    }
    returnVal = eglGetConfigs(dpy, configs, numConfig, &numConfig);

    if (!returnVal) {
        free(configs);
        return false;
    }
    for(int i = 0; i < numConfig; i++) {
        LOGD("Configuration %d\n", i);

    }
    free(configs);
    return true;
}

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
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE,  EGL_OPENGL_ES2_BIT,
            EGL_RED_SIZE,       10,
            EGL_GREEN_SIZE,     10,
            EGL_BLUE_SIZE,      10,
            EGL_ALPHA_SIZE,     2,
            EGL_NONE
    };

    printEGLConfigurations(mEglDisplay);

    EGLint num_config;

    if (!eglChooseConfig(mEglDisplay, attrib_config_list, NULL, 1, &num_config)) {
        LOGE("eglChooseConfig error");
        return -1;
    }

    EGLConfig eglConfig;
    if (!eglChooseConfig(mEglDisplay, attrib_config_list, &eglConfig, num_config, &num_config)) {
        LOGE("eglChooseConfig error");
        return -1;
    }

    const EGLint attrib_ctx_list[] = {
            EGL_CONTEXT_CLIENT_VERSION, 2,
            EGL_NONE
    };
    mEglContext = eglCreateContext(mEglDisplay, eglConfig, NULL, attrib_ctx_list);
    if (mEglContext == EGL_NO_CONTEXT) {
        LOGE("eglCreateContext  error");
        return -1;
    }

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    std::string Extensions = eglQueryString(display, EGL_EXTENSIONS);
    LOGD("egl extensions  %s", Extensions.c_str());
    EGLint attribs[] = { EGL_GL_COLORSPACE, EGL_GL_COLORSPACE_BT2020_PQ_EXT,EGL_NONE };

    mEglSurface = eglCreateWindowSurface(mEglDisplay, eglConfig, window, attribs);
    if (mEglSurface == EGL_NO_SURFACE) {
        LOGE("eglCreateWindowSurface  error");
        return -1;
    }

    if (!eglMakeCurrent(mEglDisplay, mEglSurface, mEglSurface, mEglContext)) {
        LOGE("eglMakeCurrent  error");
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
