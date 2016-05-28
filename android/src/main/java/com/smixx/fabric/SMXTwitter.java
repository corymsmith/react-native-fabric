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
import com.google.gson.Gson;
import com.twitter.sdk.android.Twitter;
import com.twitter.sdk.android.core.Result;
import com.twitter.sdk.android.core.TwitterCore;
import com.twitter.sdk.android.core.TwitterException;
import com.twitter.sdk.android.core.TwitterSession;
import com.twitter.sdk.android.tweetcomposer.TweetComposer;
import com.twitter.sdk.android.core.identity.TwitterLoginButton;
import com.twitter.sdk.android.core.TwitterApiClient;
import com.twitter.sdk.android.core.models.User;
import retrofit.RetrofitError;
import retrofit.http.GET;
import retrofit.http.Query;

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
        public void fetchProfile(final Callback callback) {

            try {
                ReactNativeFabricApiClient client = new ReactNativeFabricApiClient(Twitter.getSessionManager().getActiveSession());
                client.getCustomService().show(Twitter.getSessionManager().getActiveSession().getUserId(), new com.twitter.sdk.android.core.Callback<User>() {
                    @Override
                    public void success(Result<User> result) {
                        Gson gson = new Gson();
                        WritableMap map = gson.fromJson(gson.toJson(result), WritableMap.class);
                        callback.invoke(null, map);
                    }

                    @Override
                    public void failure(TwitterException exception) {
                        exception.printStackTrace();
                        Twitter.getSessionManager().clearActiveSession();
                        callback.invoke(exception.getMessage());
                    }
                });
            } catch (Exception ex) {
                callback.invoke(ex.getMessage());
            }
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



    class ReactNativeFabricApiClient extends TwitterApiClient {
            public ReactNativeFabricApiClient(TwitterSession session) {
                super(session);
            }

            /**
             * Provide CustomService with defined endpoints
             */
            public CustomService getCustomService() {
                return getService(CustomService.class);
            }
        }

        // example users/show service endpoint
        interface CustomService {
            @GET("/1.1/users/show.json")
            void show(@Query("user_id") long id, com.twitter.sdk.android.core.Callback<User> cb);
        }
}
