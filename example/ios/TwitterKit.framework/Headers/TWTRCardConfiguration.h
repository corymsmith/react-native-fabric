//
//  TWTRCardConfiguration.h
//  TwitterKit
//
//  Copyright © 2015 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Enum of the possible Twitter Card types.
 */
typedef NS_ENUM(NSUInteger, TWTRCardType){
    /**
     *  A Twitter App Card that includes a promotional image.
     */
    TWTRCardTypePromoImageApp,

    /**
     *  An unknown or unsupported Twitter Card type.
     */
    TWTRCardTypeUnknown
};

/**
 * `TWTRCardConfiguration` is the representation of configurations for constructing a Twitter Card.
 *
 *  @see https://dev.twitter.com/cards/overview
 */
@interface TWTRCardConfiguration : NSObject

/**
 *  Type of Twitter Card configuration.
 */
@property (nonatomic, readonly) TWTRCardType cardType;

/**
 *  Title of the Card.
 */
@property (nonatomic, readonly, copy, nullable) NSString *cardTitle;

/**
 *  Description of the Card.
 */
@property (nonatomic, readonly, copy, nullable) NSString *cardDescription;

/**
 *  Unique image representing the content. Size of the image cannot exceed 1MB.
 *  The minimum dimensions can vary depending on the Card type. See https://dev.twitter.com/cards/types
 *  for more detailed requirements.
 */
@property (nonatomic, readonly, nullable) UIImage *image;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Creates a new instance of configuration for a Twitter App Promo Card.
 *
 *  @param promoImage           (Required) Unique image of the user generated content to be promoted.
 *  @param iPhoneAppID          (Optional) String representation of your app ID in the App Store (.i.e. "307234931"). Either the `iPhoneAppID` or `iPadAppID` has to be provided.
 *  @param iPadAppID            (Optional) String representation of your app ID in the App Store (.i.e. "307234931"). Either the `iPhoneAppID` or `iPadAppID` has to be provided.
 *  @param googlePlayAppID      (Optional) String representation of your app ID in Google Play (.i.e. "com.android.app")
 *
 *  @return A new instance of `TWTRCardConfiguration` for a Twitter App Card.
 */
+ (TWTRCardConfiguration *)appCardConfigurationWithPromoImage:(UIImage *)promoImage iPhoneAppID:(nullable NSString *)iPhoneAppID iPadAppID:(nullable NSString *)iPadAppID googlePlayAppID:(nullable NSString *)googlePlayAppID;

@end

NS_ASSUME_NONNULL_END
