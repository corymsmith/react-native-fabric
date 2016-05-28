//
//  TWTRTweetDetailViewController.h
//  TwitterKit
//
//  Copyright © 2016 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TWTRTweet;
@class TWTRUser;
@class TWTRTweetCashtagEntity;
@class TWTRTweetHashtagEntity;
@class TWTRTweetUserMentionEntity;
@protocol TWTRTweetDetailViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * A view controller which shows the detailed Tweet content.
 */
@interface TWTRTweetDetailViewController : UIViewController

/**
 * The Tweet being displayed.
 */
@property (nonatomic, readonly) TWTRTweet *tweet;

/**
 * The delegate for this view controller.
 */
@property (nonatomic, weak) id<TWTRTweetDetailViewControllerDelegate> delegate;

/**
 * The scroll view which is the root view of the view controller.
 * This view is exposed to allow for the adjustment of the scroll view's
 * contentInset or to interact with the scroll view's gesture recognizers.
 */
@property (nonatomic, readonly) UIScrollView *scrollView;

/**
 * The background color of the view.
 */
@property (nonatomic, null_resettable) UIColor *backgroundColor;

/**
 * The primary text color. This value will be applied to the 
 * username and tweet text.
 */
@property (nonatomic, null_resettable) UIColor *primaryTextColor;

/**
 * The secondary text color.
 */
@property (nonatomic, null_resettable) UIColor *secondaryTextColor;

/**
 * A color to apply to links.
 */
@property (nonatomic, null_resettable) UIColor *linkTextColor;

/**
 * A value indicating the amount that the action bar should be offset
 * from the bottom of the bar. A positive amount will move the view up
 * while a negative amount will move it down.
 */
@property (nonatomic) CGFloat actionBarInset;

/**
 * Initializes the receiver with the given tweet.
 */
- (instancetype)initWithTweet:(TWTRTweet *)tweet;

@end

@protocol TWTRTweetDetailViewControllerDelegate <NSObject>

@optional

/**
 *  called when a URL in the text of a tweet was tapped. Implement to show your own webview rather than opening Safari.
 *
 *  @param controller The TWTRTweetDetailViewController.
 *  @param url        The URL that was tapped.
 */
- (void)tweetDetailViewController:(TWTRTweetDetailViewController *)controller didTapURL:(NSURL *)URL;

/**
 *  Called when the user's profile image is tapped.
 *  If this method is not implemented and the device is running on iOS 9+ we will deep link into the Twitter application.
 *
 *  @param controller The TWTRTweetDetailViewController.
 *  @param user       The Twitter user.
 */
- (void)tweetDetailViewController:(TWTRTweetDetailViewController *)controller didTapProfileImageForUser:(TWTRUser *)user;

/**
 *  Called when a hashtag in the text of a tweet was tapped.
 *
 *  @param controller The TWTRTweetDetailViewController.
 *  @param hashtag    The hashtag that was tapped.
 */
- (void)tweetDetailViewController:(TWTRTweetDetailViewController *)controller didTapHashtag:(TWTRTweetHashtagEntity *)hashtag;

/**
 *  Called when a cashtag in the text of a tweet was tapped.
 *
 *  @param controller The TWTRTweetDetailViewController.
 *  @param cashtag    The cashtag that was tapped.
 */
- (void)tweetDetailViewController:(TWTRTweetDetailViewController *)controller didTapCashtag:(TWTRTweetCashtagEntity *)cashtag;

/**
 *  Called when a user mention in the text of a tweet was tapped.
 *
 *  @param controller  The TWTRTweetDetailViewController.
 *  @param userMention The user mention that was tapped.
 */
- (void)tweetDetailViewController:(TWTRTweetDetailViewController *)controller didTapUserMention:(TWTRTweetUserMentionEntity *)userMention;


@end

NS_ASSUME_NONNULL_END
