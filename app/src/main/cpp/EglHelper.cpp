//
// Created by chenjunlong on 2020/9/6.
//

#include "EglHelper.h"
#include <string>
#include "JNILog.h"

void logConfigInfo(EGLDisplay dpy, EGLConfig  config)
{
    EGLint resultvalue = 0 ;
    eglGetConfigAttrib(dpy, config, EGL_RED_SIZE, &resultvalue);  LOGD("EGLConfigInfo : EGL_RED_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy, config, EGL_GREEN_SIZE, &resultvalue);   LOGD("EGLConfigInfo :EGL_GREEN_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy, config, EGL_BLUE_SIZE, &resultvalue);   LOGD("EGLConfigInfo :EGL_BLUE_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy, config, EGL_ALPHA_SIZE, &resultvalue);  LOGD("EGLConfigInfo :EGL_ALPHA_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy, config, EGL_DEPTH_SIZE, &resultvalue);   LOGD("EGLConfigInfo :EGL_DEPTH_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy, config, EGL_STENCIL_SIZE, &resultvalue);   LOGD("EGLConfigInfo :EGL_STENCIL_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy, config, EGL_SAMPLE_BUFFERS, &resultvalue);   LOGD("EGLConfigInfo :EGL_SAMPLE_BUFFERS :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_BIND_TO_TEXTURE_RGB, &resultvalue);   LOGD("EGLConfigInfo :EGL_BIND_TO_TEXTURE_RGB :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_SAMPLES, &resultvalue);   LOGD("EGLConfigInfo :EGL_SAMPLES :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_COLOR_BUFFER_TYPE, &resultvalue);   LOGD("EGLConfigInfo :EGL_COLOR_BUFFER_TYPE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_CONFIG_CAVEAT, &resultvalue);   LOGD("EGLConfigInfo :EGL_CONFIG_CAVEAT :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_CONFIG_ID, &resultvalue);  LOGD("EGLConfigInfo :EGL_CONFIG_ID :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_CONFORMANT, &resultvalue);   LOGD("EGLConfigInfo :EGL_CONFORMANT :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_LEVEL, &resultvalue);   LOGD("EGLConfigInfo :EGL_LEVEL :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_LUMINANCE_SIZE, &resultvalue);   LOGD("EGLConfigInfo :EGL_LUMINANCE_SIZE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_MAX_PBUFFER_WIDTH, &resultvalue);   LOGD("EGLConfigInfo :EGL_MAX_PBUFFER_WIDTH :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_MAX_PBUFFER_HEIGHT, &resultvalue);   LOGD("EGLConfigInfo :EGL_MAX_PBUFFER_HEIGHT :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_MAX_PBUFFER_PIXELS, &resultvalue);   LOGD("EGLConfigInfo :EGL_MAX_PBUFFER_PIXELS :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_MAX_SWAP_INTERVAL, &resultvalue);   LOGD("EGLConfigInfo :EGL_MAX_SWAP_INTERVAL :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_MIN_SWAP_INTERVAL, &resultvalue);   LOGD("EGLConfigInfo :EGL_MIN_SWAP_INTERVAL :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_NATIVE_RENDERABLE, &resultvalue);   LOGD("EGLConfigInfo :EGL_NATIVE_RENDERABLE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_NATIVE_VISUAL_TYPE, &resultvalue);   LOGD("EGLConfigInfo :EGL_NATIVE_VISUAL_TYPE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_NATIVE_VISUAL_ID, &resultvalue);   LOGD("EGLConfigInfo :EGL_NATIVE_VISUAL_ID :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_RENDERABLE_TYPE, &resultvalue);   LOGD("EGLConfigInfo :EGL_RENDERABLE_TYPE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_SURFACE_TYPE, &resultvalue);   LOGD("EGLConfigInfo :EGL_SURFACE_TYPE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_TRANSPARENT_TYPE, &resultvalue);   LOGD("EGLConfigInfo :EGL_TRANSPARENT_TYPE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_TRANSPARENT_RED_VALUE, &resultvalue);   LOGD("EGLConfigInfo :EGL_TRANSPARENT_RED_VALUE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_TRANSPARENT_GREEN_VALUE, &resultvalue);   LOGD("EGLConfigInfo :EGL_TRANSPARENT_GREEN_VALUE :	%u" , resultvalue );
    eglGetConfigAttrib(dpy,config, EGL_TRANSPARENT_BLUE_VALUE, &resultvalue);   LOGD("EGLConfigInfo :EGL_TRANSPARENT_BLUE_VALUE :	%u" , resultvalue );
}

std::string eglErrorString(EGLint error)
{
    switch(error)
    {
        case EGL_SUCCESS: return "No error";
        case EGL_NOT_INITIALIZED: return "EGL not initialized or failed to initialize";
        case EGL_BAD_ACCESS: return "Resource inaccessible";
        case EGL_BAD_ALLOC: return "Cannot allocate resources";
        case EGL_BAD_ATTRIBUTE: return "Unrecognized attribute or attribute value";
        case EGL_BAD_CONTEXT: return "Invalid EGL context";
        case EGL_BAD_CONFIG: return "Invalid EGL frame buffer configuration";
        case EGL_BAD_CURRENT_SURFACE: return "Current surface is no longer valid";
        case EGL_BAD_DISPLAY: return "Invalid EGL display";
        case EGL_BAD_SURFACE: return "Invalid surface";
        case EGL_BAD_MATCH: return "Inconsistent arguments";
        case EGL_BAD_PARAMETER: return "Invalid argument";
        case EGL_BAD_NATIVE_PIXMAP: return "Invalid native pixmap";
        case EGL_BAD_NATIVE_WINDOW: return "Invalid native window";
        case EGL_CONTEXT_LOST: return "Context lost";
    }
    return "Unknown error ";
}
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
    EGLConfig* configscur = configs;
    for(int i = 0; i < numConfig; i++) {
        LOGD("Configuration %d\n", i);
        logConfigInfo(dpy, *configscur);
        configscur++;
    }
    free(configs);
    return true;
}

void testGetGPUClock()
{
    float curGPUClock = 0.0f;
    if (FILE* CurFreqFile = fopen("/sys/class/kgsl/kgsl-3d0/devfreq/cur_freq", "r"))
    {
        int curFreq = 0;
        char curFreqBuffer[64];
        if (fgets(curFreqBuffer, 64, CurFreqFile) != nullptr)
        {
           curFreq = atol(curFreqBuffer);
        }
        fclose(CurFreqFile);

        if (FILE* GPUBusyPercentageFile = fopen("/sys/class/kgsl/kgsl-3d0/gpu_busy_percentage", "r"))
        {
            int gpuBusyPercentage = 0;
            char gpuBusyPercentageBuffer[64];
            if (fgets(gpuBusyPercentageBuffer, 64, GPUBusyPercentageFile) != nullptr)
            {
                sscanf(gpuBusyPercentageBuffer, "%d %%", &gpuBusyPercentage);
            }
            fclose(GPUBusyPercentageFile);

            curGPUClock = curFreq * gpuBusyPercentage * 0.01f;
        }
    }
}

EglHelper::EglHelper() {
    mEglDisplay = EGL_NO_DISPLAY;
    mEglSurface = EGL_NO_SURFACE;
    mEglContext = EGL_NO_CONTEXT;
}

EglHelper::~EglHelper(){

}

int EglHelper::initEgl(EGLNativeWindowType window) {

    testGetGPUClock();

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
            EGL_CONTEXT_CLIENT_VERSION, 3,
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
    //EGLint attribs[] = { EGL_GL_COLORSPACE_KHR, EGL_GL_COLORSPACE_BT2020_PQ_EXT,EGL_NONE };
    EGLint attribs[] = { EGL_GL_COLORSPACE_KHR, EGL_GL_COLORSPACE_DISPLAY_P3_EXT,EGL_NONE };

    int ResultValue = 0 ;
    int r, g, b, a;
    eglGetConfigAttrib(display, eglConfig, EGL_RED_SIZE, &ResultValue); r = ResultValue;
    eglGetConfigAttrib(display, eglConfig, EGL_GREEN_SIZE, &ResultValue); g = ResultValue;
    eglGetConfigAttrib(display, eglConfig, EGL_BLUE_SIZE, &ResultValue); b = ResultValue;
    eglGetConfigAttrib(display, eglConfig, EGL_ALPHA_SIZE, &ResultValue); a = ResultValue;

    LOGD("eglConfig R %d, G %d, B %d, A %d\n", r, g, b, a);

    logConfigInfo(display, eglConfig);

    mEglSurface = eglCreateWindowSurface(mEglDisplay, eglConfig, window, attribs);
    if (mEglSurface == EGL_NO_SURFACE) {
        EGLint errorcode = eglGetError();
        std::string errorstring = eglErrorString(errorcode);
        LOGE("eglCreateWindowSurface  error %s", errorstring.c_str());
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
