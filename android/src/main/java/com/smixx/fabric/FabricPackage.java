package com.smixx.fabric;

import android.app.Activity;
import android.content.Intent;
import android.util.Log;

import com.facebook.react.ReactPackage;
import com.facebook.react.bridge.JavaScriptModule;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.uimanager.ViewManager;

import java.util.ArrayList;
import java.util.List;

public class FabricPackage implements ReactPackage {

    private Activity mActivity = null;
    public FabricPackage(Activity activity) {
        mActivity = activity;
    }
    private SMXTwitter mTwitterModuleInstance;

    @Override
    public List<NativeModule> createNativeModules(
            ReactApplicationContext reactContext) {
        List<NativeModule> modules = new ArrayList<>();
        modules.add(new SMXCrashlytics(reactContext, mActivity));
        modules.add(new SMXAnswers(reactContext, mActivity));

        try {
            Class cls = Class.forName("com.twitter.sdk.android.core.TwitterCore");
            mTwitterModuleInstance = new SMXTwitter(reactContext, mActivity);
            modules.add(mTwitterModuleInstance);
            Log.d("FabricPackage", "Added SMXTwitter");
        } catch (ClassNotFoundException e) {
            Log.d("FabricPackage", "TwitterKit is not available.");
        }

        return modules;
    }

    @Override
    public List<Class<? extends JavaScriptModule>> createJSModules() {
        return new ArrayList<>();
    }

    @Override
    public List<ViewManager> createViewManagers(ReactApplicationContext reactContext) {
        return new ArrayList<>();
    }

    public void handleActivityResult(final int requestCode, final int resultCode, final Intent data) {
        if (mTwitterModuleInstance == null) {
            return;
        }

        mTwitterModuleInstance.onActivityResult(requestCode, resultCode, data);
    }
}