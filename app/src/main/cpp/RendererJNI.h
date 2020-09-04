//
// Created by chenjunlong on 2020/9/4.
//
#include <jni.h>
#ifndef ANDROIDGLESTEST_RENDERERJNI_H
#define ANDROIDGLESTEST_RENDERERJNI_H


#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     android_gles_test_RendererJNI
 * Method:    glesInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_android_gles_test_RendererJNI_glesInit
(JNIEnv *, jobject);

/*
 * Class:     android_gles_test_RendererJNI
 * Method:    glesRender
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_android_gles_test_RendererJNI_glesRender
(JNIEnv *, jobject);

/*
 * Class:     android_gles_test_RendererJNI
 * Method:    glesResize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_android_gles_test_RendererJNI_glesResize
(JNIEnv *, jobject, jint, jint);


JNIEXPORT void JNICALL Java_android_gles_test_RendererJNI_readShaderFile
(JNIEnv *env, jobject self, jobject assetManager);

#ifdef __cplusplus
}
#endif

#endif //ANDROIDGLESTEST_RENDERERJNI_H
