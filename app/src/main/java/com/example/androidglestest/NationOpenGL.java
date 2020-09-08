package com.example.androidglestest;

import android.content.Context;
import android.content.res.AssetManager;
import android.view.Surface;


public class NationOpenGL {

    public NationOpenGL() {
    }
    static {
        System.loadLibrary("native-lib");
    }

    public native void nativeSurfaceCreate(Surface surface, AssetManager assetMgr);

    public native void nativeSurfaceChanged(int width, int height);

    public native void nativeSurfaceDestroyed();

}
