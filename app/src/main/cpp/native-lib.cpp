#include <jni.h>
#include <string>

#include "android/native_window.h"
#include "android/native_window_jni.h"
#include "EglThread.cpp"
#include "GLES2/gl2.h"
#include "RendererJNI.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_androidglestest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

EglThread *eglThread = NULL;


void callBackOnCreate() {

}

void callBackOnChange(int width, int height) {
    glViewport(0, 0, width, height);
}

void callBackOnDraw() {
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidglestest_NationOpenGL_nativeSurfaceCreate(JNIEnv *env, jobject instance,
                                                                  jobject surface) {

    eglThread = new EglThread();
    eglThread->callBackOnCreate(callBackOnCreate);
    eglThread->callBackOnChange(callBackOnChange);
    eglThread->callBackOnDraw(callBackOnDraw);
    eglThread->setRenderModule(RENDER_MODULE_MANUAL);


    ANativeWindow *nativeWindow = ANativeWindow_fromSurface(env, surface);
    eglThread->onSurfaceCreate(nativeWindow);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidglestest_NationOpenGL_nativeSurfaceChanged(JNIEnv *env,
                                                                   jobject instance, jint width,
                                                                   jint height) {
    if (eglThread) {
        eglThread->onSurfaceChange(width, height);
    }
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidglestest_NationOpenGL_nativeSurfaceDestroyed(JNIEnv *env,
                                                                     jobject instance) {
    if (eglThread) {
        eglThread->isExit = true;

//        void* retval;
//        pthread_join(eglThread, &retval);
        delete (eglThread);
        eglThread = NULL;
    }

}
