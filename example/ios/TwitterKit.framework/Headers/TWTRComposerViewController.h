//
//  TWTRComposerViewController.h
//  TwitterKit
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TWTRCardConfiguration;
@class TWTRComposerTheme;
@class TWTRTweet;
@protocol TWTRComposerViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface TWTRComposerViewController : UIViewController

@property (nonatomic, weak, nullable) id<TWTRComposerViewControllerDelegate> delegate;

/**
 * A theme to use for the composer. If nil will default to the light theme.
 */
@property (nonatomic, null_resettable) TWTRComposerTheme *theme;

/**
 * Use initWithUserID: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Returns a fully initialized version of the composer.
 *
 * @param userID The ID of the user that is tweeting
 */
- (instancetype)initWithUserID:(NSString *)userID;

/**
 * Returns a fully initialized version of the composer which will tweet with a card.
 *
 * @param userID     The ID of the user that is tweeting the card
 * @param cardConfig The card configuration that will be associated with this Tweet
 */
- (instancetype)initWithUserID:(NSString *)userID cardConfiguration:(nullable TWTRCardConfiguration *)cardConfig;

@end

@protocol TWTRComposerViewControllerDelegate <NSObject>

@optional
/**
 * Called when the user taps the cancel button. This method will be called after the view controller is dismissed.
 */
- (void)composerDidCancel:(TWTRComposerViewController *)controller;

/**
 * Called when the user successfully sends a Tweet. The resulting Tweet object is returned.
 * This method is called after the view controller is dimsissed.
 */
- (void)composerDidSucceed:(TWTRComposerViewController *)controller withTweet:(TWTRTweet *)tweet;

/**
 * This method is called if the composer is not able to send the Tweet. 
 * The view controller will not be dismissed automatically if this method is called.
 */
- (void)composerDidFail:(TWTRComposerViewController *)controller withError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
