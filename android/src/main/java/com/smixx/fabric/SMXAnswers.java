package com.smixx.fabric;

import android.app.Activity;
import android.util.Log;

import com.crashlytics.android.answers.AddToCartEvent;
import com.crashlytics.android.answers.Answers;
import com.crashlytics.android.answers.AnswersEvent;
import com.crashlytics.android.answers.ContentViewEvent;
import com.crashlytics.android.answers.CustomEvent;
import com.crashlytics.android.answers.InviteEvent;
import com.crashlytics.android.answers.LevelEndEvent;
import com.crashlytics.android.answers.LevelStartEvent;
import com.crashlytics.android.answers.LoginEvent;
import com.crashlytics.android.answers.PurchaseEvent;
import com.crashlytics.android.answers.RatingEvent;
import com.crashlytics.android.answers.SearchEvent;
import com.crashlytics.android.answers.ShareEvent;
import com.crashlytics.android.answers.SignUpEvent;
import com.crashlytics.android.answers.StartCheckoutEvent;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.ReadableMapKeySetIterator;
import com.facebook.react.bridge.ReadableType;

import java.math.BigDecimal;
import java.util.Currency;

public class SMXAnswers extends ReactContextBaseJavaModule {
    public Activity activity;

    public SMXAnswers(ReactApplicationContext reactContext) {
        super(reactContext);
        this.activity = getCurrentActivity();
    }

    @Override
    public String getName() {
        return "SMXAnswers";
    }

    @ReactMethod
    public void logAddToCart(String itemPrice, String currency, String itemName, String itemType, String itemId, ReadableMap customAttributes) {

        AddToCartEvent event = new AddToCartEvent();
        if (currency != null)
            event.putCurrency(Currency.getInstance(currency));
        if (itemPrice != null)
            event.putItemPrice(new BigDecimal(itemPrice));
        if (itemName != null)
            event.putItemName(itemName);
        if (itemType != null)
            event.putItemType(itemType);
        if (itemId != null)
            event.putItemId(itemId);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logAddToCart(event);
    }

    @ReactMethod
    public void logContentView(String contentName, String contentType, String contentId, ReadableMap customAttributes) {
        ContentViewEvent event = new ContentViewEvent();
        if (contentId != null)
            event.putContentId(contentId);
        if (contentType != null)
            event.putContentType(contentType);
        if (contentName != null)
            event.putContentName(contentName);

        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logContentView(event);
    }

    @ReactMethod
    public void logCustom(String eventName, ReadableMap customAttributes) {
        CustomEvent event = new CustomEvent(eventName);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logCustom(event);
    }

    @ReactMethod
    public void logInvite(String method, ReadableMap customAttributes) {
        InviteEvent event = new InviteEvent();
        event.putMethod(method);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logInvite(event);
    }

    @ReactMethod
    public void logLevelStart(String levelName, ReadableMap customAttributes) {
        LevelStartEvent event = new LevelStartEvent();
        event.putLevelName(levelName);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logLevelStart(event);
    }

    @ReactMethod
    public void logLevelEnd(String levelName, String score, boolean success, ReadableMap customAttributes) {
        LevelEndEvent event = new LevelEndEvent();
        if (levelName != null)
            event.putLevelName(levelName);

        event.putSuccess(success);

        if (score != null)
            event.putScore(Double.valueOf(score));

        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logLevelEnd(event);
    }

    @ReactMethod
    public void logLogin(String method, boolean success, ReadableMap customAttributes) {
        LoginEvent event = new LoginEvent();
        event.putMethod(method);
        event.putSuccess(success);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logLogin(event);
    }

    @ReactMethod
    public void logPurchase(String itemPrice, String currency, boolean success, String itemName, String itemType, String itemId, ReadableMap customAttributes) {
        PurchaseEvent event = new PurchaseEvent();

        if (currency != null)
            event.putCurrency(Currency.getInstance(currency));
        if (itemPrice != null)
            event.putItemPrice(new BigDecimal(itemPrice));
        if (itemName != null)
            event.putItemName(itemName);
        if (itemType != null)
            event.putItemType(itemType);
        if (itemId != null)
            event.putItemId(itemId);

        event.putSuccess(success);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logPurchase(event);
    }

    @ReactMethod
    public void logRating(String rating, String contentId, String contentType, String contentName, ReadableMap customAttributes) {
        RatingEvent event = new RatingEvent();
        event.putRating(Integer.valueOf(rating));

        if (contentId != null)
            event.putContentId(contentId);
        if (contentType != null)
            event.putContentType(contentType);
        if (contentName != null)
            event.putContentName(contentName);

        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logRating(event);
    }

    @ReactMethod
    public void logSearch(String query, ReadableMap customAttributes) {
        SearchEvent event = new SearchEvent();
        event.putQuery(query);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logSearch(event);
    }

    @ReactMethod
    public void logShare(String method, String contentName, String contentType, String contentId, ReadableMap customAttributes) {
        ShareEvent event = new ShareEvent();
        event.putMethod(method);
        if (contentId != null)
            event.putContentId(contentId);
        if (contentType != null)
            event.putContentType(contentType);
        if (contentName != null)
            event.putContentName(contentName);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logShare(event);
    }

    @ReactMethod
    public void logSignUp(String method, boolean success, ReadableMap customAttributes) {
        SignUpEvent event = new SignUpEvent();
        event.putMethod(method);
        event.putSuccess(success);
        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logSignUp(event);
    }

    @ReactMethod
    public void logStartCheckout(String totalPrice, String count, String currency, ReadableMap customAttributes) {
        StartCheckoutEvent event = new StartCheckoutEvent();
        if (currency != null)
            event.putCurrency(Currency.getInstance(currency));
        if (count != null)
            event.putItemCount(Integer.valueOf(count));
        if (totalPrice != null)
            event.putTotalPrice(new BigDecimal(totalPrice));

        addCustomAttributes(event, customAttributes);
        Answers.getInstance().logStartCheckout(event);
    }

    private void addCustomAttributes(AnswersEvent event, ReadableMap attributes) {
        if (attributes != null) {
            ReadableMapKeySetIterator itr = attributes.keySetIterator();
            while (itr.hasNextKey()) {
                String key = itr.nextKey();

                ReadableType type = attributes.getType(key);
                switch (type) {
                    case Boolean:
                        event.putCustomAttribute(key, String.valueOf(attributes.getBoolean(key)));
                        break;
                    case Number:
                        event.putCustomAttribute(key, attributes.getDouble(key));
                        break;
                    case String:
                        event.putCustomAttribute(key, attributes.getString(key));
                        break;
                    case Null:
                        break;
                    default:
                        Log.e("ReactNativeFabric", "Can't add objects or arrays");
                }
            }
        }
    }


}
