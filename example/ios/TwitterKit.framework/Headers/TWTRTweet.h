//
//  TWTRTweet.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TwitterKit/TWTRJSONConvertible.h>

@class TWTRTweet;
@class TWTRUser;

NS_ASSUME_NONNULL_BEGIN

/**
 *  `TWTRTweet` is an immutable representation of a Tweet.
 */
@interface TWTRTweet : NSObject <NSCoding, TWTRJSONConvertible>

# pragma mark - Properties

/**
 *  The ID of the Twitter Tweet.
 *  @warning This represents the id_str field, which could differ from the value of the id field.
 */
@property (nonatomic, copy, readonly) NSString *tweetID;

/**
 *  The date when this Tweet was created.
 */
@property (nonatomic, copy, readonly) NSDate *createdAt;

/**
 *  The text of the Tweet.
 */
@property (nonatomic, copy, readonly) NSString *text;

/**
 *  The Author of the Tweet.
 */
@property (nonatomic, readonly) TWTRUser *author;

/**
 *  ID of the authenticated Twitter user this Tweet was loaded for. Some Tweet properties e.g. `isLiked`
 *  can vary depending on the authenticated user. Nil means the Tweet was loaded from the perspective
 *  of a logged-out user or the authenticated user could not be determined.
 */
@property (nonatomic, readonly, nullable) NSString *perspectivalUserID;

/**
 *  The number of times this Tweet was liked.
 */
@property (nonatomic, readonly) long long likeCount;

/**
 *  The number of times this Tweet was retweeted.
 */
@property (nonatomic, readonly) long long retweetCount;

/**
 *  The language of the Tweet.
 */
@property (nonatomic, copy, readonly) NSString *languageCode;

/**
 *  The Tweet this Tweet was a reply to.
 */
@property (nonatomic, copy, readonly, nullable) NSString *inReplyToTweetID;

/**
 *  The User ID this Tweet was a reply to.
 */
@property (nonatomic, copy, readonly, nullable) NSString *inReplyToUserID;

/**
 *  The screen name of the user this Tweet was a reply to.
 *  @note This doesn't contain the `@` sign before the screen name.
 */
@property (nonatomic, copy, readonly, nullable) NSString *inReplyToScreenName;

/**
 *  The permalink URL for this Tweet.
 *
 *  Suitable for loading in a `UIWebView`, `WKWebView` or passing to Safari:
 *
 *  `[[UIApplication sharedApplication] openURL:tweet.permalink];`
 */
@property (nonatomic, copy, readonly) NSURL *permalink;

/**
 *  Whether this Tweet was liked by the authenticated user.
 *
 *  @warning The value of this property depends on the authenticated user.
 */
@property (nonatomic, readonly) BOOL isLiked;

/**
 *  Whether this Tweet was retweeted by the authenticated user.
 *
 *  @warning The value of this property depends on the authenticated user.
 */
@property (nonatomic, readonly) BOOL isRetweeted;

/**
 *  The Tweet ID of the authenticated user's retweet of this Tweet. This will be `nil` if there is no
 *  authenticated user or the user has not retweeted this Tweet.
 *
 *  @warning The value of this property depends on the authenticated user.
 */
@property (nonatomic, copy, readonly, nullable) NSString *retweetID;

/**
 *  The original, fully-hydrated Tweet that was retweeted. This corresponds to the `retweeted_status` API field.
 *  This is `nil` unless `self.isRetweet == YES`.
 */
@property (nonatomic, readonly, nullable) TWTRTweet *retweetedTweet;

/**
 *  Indicates whether this Tweet is a retweet of another Tweet.
 */
@property (nonatomic, readonly) BOOL isRetweet;

/**
 *  Creates an array of TWTRTweet instances from the array of Twitter API JSON response.
 *
 *  @param array A parsed array of Tweet API JSON responses.
 *  @return An array of TWTRTweet instances.
 */
+ (NSArray *)tweetsWithJSONArray:(nullable NSArray *)array;

/**
 *  Creates a new Tweet instance with a new value for the `isLiked` boolean
 *  value which is the opposite of the current value.
 */
- (TWTRTweet *)tweetWithLikeToggled;

/** 
 *  Tweet objects should be hyrdrated from a valid JSON object. See TWTRJSONConvertible for more information.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

