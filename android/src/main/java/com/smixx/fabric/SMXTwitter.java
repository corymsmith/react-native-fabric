package com.smixx.fabric;

import android.app.Activity;
import android.content.Intent;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.WritableNativeMap;
import com.twitter.sdk.android.core.Result;
import com.twitter.sdk.android.core.TwitterCore;
import com.twitter.sdk.android.core.TwitterException;
import com.twitter.sdk.android.core.TwitterSession;
import com.twitter.sdk.android.tweetcomposer.TweetComposer;
import com.twitter.sdk.android.core.identity.TwitterLoginButton;

public class SMXTwitter extends ReactContextBaseJavaModule {
    public Activity activity;
    public TwitterLoginButton loginButton;

    public SMXTwitter(ReactApplicationContext reactContext, Activity activity) {
        super(reactContext);
        this.activity = activity;
    }

    @Override
    public String getName() {
        return "SMXTwitter";
    }

    @ReactMethod
    public void login(final Callback callback) {

        loginButton = new TwitterLoginButton(this.activity);
        loginButton.setCallback(new com.twitter.sdk.android.core.Callback<TwitterSession>() {
            @Override
            public void success(Result<TwitterSession> sessionResult) {
                WritableMap result = new WritableNativeMap();
                result.putString("authToken", sessionResult.data.getAuthToken().token);
                result.putString("authTokenSecret",sessionResult.data.getAuthToken().secret);
                result.putString("userID", sessionResult.data.getUserId()+"");
                result.putString("userName", sessionResult.data.getUserName());
                callback.invoke(null, result);
            }

            @Override
            public void failure(TwitterException exception) {
                exception.printStackTrace();
                callback.invoke(exception.getMessage());
            }
        });

        loginButton.performClick();
    }

    @ReactMethod
    public void composeTweet(ReadableMap options, Callback callback) {
        String text = "";

        if (hasValidKey("text", options)) {
            text = options.getString("text");
        }

        try {
            TweetComposer.Builder builder = new TweetComposer.Builder(this.activity)
                .text(text);

            builder.show();
            callback.invoke("OK");
        } catch (Exception e) {
            callback.invoke("error");
        }
    }

    @ReactMethod
    public void logOut() {
        TwitterCore.getInstance().logOut();
    }

    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (loginButton != null) {
            loginButton.onActivityResult(requestCode, resultCode, data);
        }
    }

    private boolean hasValidKey(String key, ReadableMap options) {
        return options.hasKey(key) && !options.isNull(key);
    }
}
