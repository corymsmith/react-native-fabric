//
//  TWTRTweetViewDelegate.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TWTRSession;
@class TWTRTweet;
@class TWTRTweetDetailViewController;
@class TWTRTweetView;
@class TWTRUser;
@protocol TWTRSessionStore;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TWTRAuthenticationCompletionHandler)(id<TWTRSessionStore> sessionStore, NSString *userID);

/**
 Delegate for `TWTRTweetView` to receive updates on the user interacting with this particular Tweet view.
 
    // Create the tweet view
    TWTRTweetView *tweetView = [[TWTRTweetView alloc] initWithTweet:tweet];
    // Set the delegate
    tweetView.delegate = self;
 */
@protocol TWTRTweetViewDelegate <NSObject>

@optional

/**
 *  The tweet view image was tapped.
 *
 *  @param tweetView The Tweet view that was tapped.
 *  @param image     The exact UIImage data shown by the Tweet view.
 *  @param imageURL  The full URL of the image being shown.
 */
- (void)tweetView:(TWTRTweetView *)tweetView didTapImage:(UIImage *)image withURL:(NSURL *)imageURL;

/**
 * The Tweet view video was tapped.
 * If this method is not implemented a video player will be presented.
 *
 *  @param tweetView The Tweet view that was tapped.
 *  @param videoURL  The full URL of the video being shown.
 */
- (void)tweetView:(TWTRTweetView *)tweetView didTapVideoWithURL:(NSURL *)videoURL;

/**
 *  A URL in the text of a tweet was tapped. Implement to show your own webview rather than opening Safari.
 *
 *  @param tweetView The Tweet view that was tapped.
 *  @param url       The URL that was tapped.
 */
- (void)tweetView:(TWTRTweetView *)tweetView didTapURL:(NSURL *)url;

/**
 *  Called when the user's profile image is tapped.
 *  If this method is not implemented and the device is running on iOS 9+ we will deep link into the Twitter application.
 *
 *  @param tweetView The Tweet view that was tapped.
 *  @param user The Twitter user.
 */
- (void)tweetView:(TWTRTweetView *)tweetView didTapProfileImageForUser:(TWTRUser *)user;

/**
 *  Called when the Tweet is tapped and will present a detail view controller.
 *  If this method is not implemented the detail view controller will be presented modally with the inherited themes
 *  of the tweetView. 
 *
 *  If this method is implemented the return value will be used to determine how to proceed. If YES is returned the controller
 *  will be presented as if this method was not implemented. If NO is returned the controller will not be presented and it
 *  it is the developer's responsibility to show it. This allows the developer to push the detail view controller onto their 
 *  own navigation stack, or present in a way that is appropriate for their particular use-case.
 *
 *  @param tweetView  The Tweet view showing this Tweet object.
 *  @param controller The Tweet detail view controller that should be displayed.
 */
- (BOOL)tweetView:(TWTRTweetView *)tweetView shouldDisplayDetailViewController:(TWTRTweetDetailViewController *)controller;

@end

NS_ASSUME_NONNULL_END
