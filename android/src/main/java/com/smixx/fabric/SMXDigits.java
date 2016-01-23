package com.smixx.fabric;

import android.app.Activity;
import android.util.Log;

import com.crashlytics.android.Crashlytics;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

public class SMXDigits extends ReactContextBaseJavaModule {
    public Activity activity;

    public SMXDigits(ReactApplicationContext reactContext, Activity activity) {
        super(reactContext);
        this.activity = activity;
    }

    @Override
    public String getName() {
        return "SMXDigits";
    }

    @ReactMethod
    public void authenticate(ReadableMap options, Callback callback) {

    }
}