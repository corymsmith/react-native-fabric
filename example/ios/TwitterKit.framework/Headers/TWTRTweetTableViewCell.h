//
//  TWTRTweetTableViewCell.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TWTRTweetView.h"

@class TWTRTweet;

NS_ASSUME_NONNULL_BEGIN

/**
 *  A table view cell subclass which displays a Tweet.
 */
@interface TWTRTweetTableViewCell : UITableViewCell

/**
 *  The Tweet view inside this cell. Holds all relevant text and images.
 */
@property (nonatomic, readonly) TWTRTweetView *tweetView;

/**
 *  Configures the existing Tweet view with a Tweet. Updates labels, images, and thumbnails.
 *
 *  @param tweet The `TWTRTweet` model object for the Tweet to display.
 */
- (void)configureWithTweet:(TWTRTweet *)tweet;

/**
 *  Returns how tall the Tweet view should be.
 *
 *  Uses the system to calculate the Auto Layout height. This is the same as
 *  calling sizeThatFits: on a cached TWTRTweetView instance to let the system
 *  calculate how tall the resulting view will be including the image, Retweet
 *  view, and optional action buttons.
 *
 *  Note: The Auto Layout engine will throw an exception if this is called
 *  on a background thread.
 *
 *  @param tweet           the Tweet
 *  @param style           the style of the Tweet view
 *  @param width           the width of the Tweet
 *  @param showingActions  whether the Tweet view will be displaying actions
 *
 *  @return the calculated height of the Tweet view
 */
+ (CGFloat)heightForTweet:(TWTRTweet *)tweet style:(TWTRTweetViewStyle)style width:(CGFloat)width showingActions:(BOOL)showActions;

@end

NS_ASSUME_NONNULL_END
