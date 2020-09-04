package com.example.androidglestest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.widget.TextView;

import android.app.ActivityManager;
import android.content.pm.ConfigurationInfo;
import android.util.Log;

import static android.opengl.GLSurfaceView.RENDERMODE_WHEN_DIRTY;

public class MainActivity extends AppCompatActivity {
    private final int CONTEXT_CLIENT_VERSION = 3;
    private GLSurfaceView mGLSurfaceView;
    RendererJNI mRenderer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mGLSurfaceView = new GLSurfaceView(this);
        mRenderer=new RendererJNI(this);
        if (detectOpenGLES30()) {
            mGLSurfaceView.setEGLContextClientVersion(CONTEXT_CLIENT_VERSION);
            mGLSurfaceView.setRenderer(mRenderer);
            mGLSurfaceView.setRenderMode(RENDERMODE_WHEN_DIRTY);
        } else {
            Log.e("opengles30", "OpenGL ES 3.0 not supported on device.  Exiting...");
            finish();
        }

        setContentView(mGLSurfaceView);
    }

    @Override
    protected void onResume() {
        super.onResume();
        mGLSurfaceView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLSurfaceView.onPause();
    }

    private boolean detectOpenGLES30() {
        ActivityManager am = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo info = am.getDeviceConfigurationInfo();

        return (info.reqGlEsVersion >= 0x30000);
    }
}