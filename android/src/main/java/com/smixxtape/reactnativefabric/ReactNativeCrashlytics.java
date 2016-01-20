package com.smixxtape.reactnativefabric;

import android.app.Activity;

import com.crashlytics.android.Crashlytics;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.WritableNativeMap;
import com.twitter.sdk.android.core.Result;
import com.twitter.sdk.android.core.TwitterCore;
import com.twitter.sdk.android.core.TwitterException;
import com.twitter.sdk.android.core.TwitterSession;

public class SMXCrashlytics extends ReactContextBaseJavaModule {
    public Activity activity;

    public SMXCrashlytics(ReactApplicationContext reactContext, Activity activity) {
        super(reactContext);
        this.activity = activity;
    }

    @Override
    public String getName() {
        return "SMXCrashlytics";
    }

    @ReactMethod
    public void setUserEmail(String email) {
        Crashlytics.setUserEmail(email);
    }

    @ReactMethod
    public void setUserIdentifier(String userIdentifier) {
        Crashlytics.setUserIdentifier(userIdentifier);
    }

    @ReactMethod
    public void setUserName(String userName) {
        Crashlytics.setUserName(userName);
    }

    @ReactMethod
    public void setBool(String key, boolean value) {
        Crashlytics.setBool(key, value);
    }

    @ReactMethod
    public void setDouble(String key, double value) {
        Crashlytics.setDouble(key, value);
    }

    @ReactMethod
    public void setFloat(String key, float value) {
        Crashlytics.setFloat(key, value);
    }

    @ReactMethod
    public void setLong(String key, long value) {
        Crashlytics.setLong(key, value);
    }

    @ReactMethod
    public void setString(String key, String value) {
        Crashlytics.setString(key, value);
    }

    @ReactMethod
    public void setInt(String key, int value) {
        Crashlytics.setInt(key, value);
    }
}