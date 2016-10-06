package com.smixx.fabric;

import android.app.Activity;
import android.util.Log;

import com.crashlytics.android.Crashlytics;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.ReadableMap;

public class SMXCrashlytics extends ReactContextBaseJavaModule {
    public Activity activity;

    public SMXCrashlytics(ReactApplicationContext reactContext) {
        super(reactContext);
        this.activity = getCurrentActivity();
    }

    @Override
    public String getName() {
        return "SMXCrashlytics";
    }

    @ReactMethod
    public void crash() {
        Crashlytics.getInstance().crash();
    }

    @ReactMethod
    public void logException(String value) {
        Crashlytics.logException(new RuntimeException(value));
    }

    @ReactMethod
    public void log(String message) {
        Crashlytics.log(message);
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
    public void setBool(String key, Boolean value) {
        Crashlytics.setBool(key, value);
    }

    @ReactMethod
    public void setString(String key, String value) {
        Crashlytics.setString(key, value);
    }

    @ReactMethod
    public void setNumber(String key, String numberString) {
        try {
            Number number = parse(numberString);
            if (number.getClass().equals(Double.class)) {
                Crashlytics.setDouble(key, number.doubleValue());
            } else if (number.getClass().equals(Float.class)) {
                Crashlytics.setFloat(key, number.floatValue());
            } else if (number.getClass().equals(Integer.class)) {
                Crashlytics.setInt(key, number.intValue());
            } else if (number.getClass().equals(Long.class)) {
                Crashlytics.setLong(key, number.longValue());
            }
        } catch (Exception ex) {
            Log.e("RNFabric:", ex.getMessage());
            ex.printStackTrace();
        }
    }

    @ReactMethod
    public void recordCustomExceptionName(String name, String reason, ReadableArray frameArray) {
        StackTraceElement[] stackTrace = new StackTraceElement[frameArray.size()];
        for (int i = 0; i < frameArray.size(); i++) {
            ReadableMap map = frameArray.getMap(i);
            String functionName = map.hasKey("functionName") ? map.getString("functionName") : "Unknown Function";
            StackTraceElement stack = new StackTraceElement(
                "",
                functionName,
                map.getString("fileName"),
                map.hasKey("lineNumber") ? map.getInt("lineNumber") : -1
            );
            stackTrace[i] = stack;
        }
        Exception e = new Exception(name + "\n" + reason);
        e.setStackTrace(stackTrace);
        Crashlytics.logException(e);
    }

    private static Number parse(String str) {
        Number number = null;

        if (str.contains(".")) {
            try {
                number = Double.parseDouble(str);
            } catch (NumberFormatException e) {
                number = Float.parseFloat(str);
            }
        } else {
            try {
                number = Integer.parseInt(str);
            } catch (NumberFormatException e2) {
                try {
                    number = Long.parseLong(str);
                } catch (NumberFormatException e3) {
                    throw e3;
                }
            }
        }
        return number;
    }
}
