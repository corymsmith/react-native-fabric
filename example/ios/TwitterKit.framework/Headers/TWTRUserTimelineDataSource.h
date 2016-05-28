//
//  TWTRUserTimelineDataSource.h
//  TwitterKit
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TwitterKit/TWTRTimelineDataSource.h>

@class TWTRAPIClient;

NS_ASSUME_NONNULL_BEGIN

/**
 *  This Timeline Data Source provides a list of Tweets roughly consistent with the list on a Users profile page. The difference is that this data source will filter out Tweets that are direct replies to other users by default.
 *
 *  These Tweets are ordered chronologically with the most recent first.
 */
@interface TWTRUserTimelineDataSource : NSObject <TWTRTimelineDataSource>

/**
 *  The screen name of the User whose Tweets are being shown. Either the `screenName` or the `userID` are required.
 */
@property (nonatomic, copy, readonly) NSString *screenName;

/**
 *  The userID of the User whose Tweets are being shown. Either the `screenName` or the `userID` are required.
 */
@property (nonatomic, copy, readonly) NSString *userID;

/**
 *  The number of Tweets to request in each query to the Twitter Timeline API when fetching the next batch of Tweets. Will request 30 Tweets by default. Setting this value to 0 will use the server default.
 */
@property (nonatomic, readonly) NSUInteger maxTweetsPerRequest;

/**
 *  Whether to request replies in the set of Tweets from the server.
 *
 *  Defaults to NO.
 */
@property (nonatomic, readonly) BOOL includeReplies;

/**
 *  Whether to request retweets in the set of Tweets from the server.
 *
 *  Defaults to YES.
 */
@property (nonatomic, readonly) BOOL includeRetweets;

/**
 *  Convenience initializer. Uses default values for `maxTweetsPerRequest`, `includeReplies` and `includeRetweets`.
 *
 *  @param screenName The screen name of a Twitter User
 *  @param client     The API client to use for making network requests.
 *
 *  @return A fully initialized user timeline datasource or nil.
 */
- (instancetype)initWithScreenName:(NSString *)screenName APIClient:(TWTRAPIClient *)client;

/**
 *  The designated initialzer accepted values for properties.
 *
 *  @param userID              The user ID of the Twitter User
 *  @param screenName          The screen name of the Twitter User
 *  @param APIClient           The API client to use for making network requests.
 *  @param maxTweetsPerRequest The number of Tweets per batch to request. A value of 0 will use the server default.
 *  @param includeReplies      Whether replies should be requested
 *  @param includeRetweets     Whether retweets should be requested
 *
 *  @return A fully initialized user timeline datasource or nil.
 */
- (instancetype)initWithScreenName:(nullable NSString *)screenName userID:(nullable NSString *)userID APIClient:(TWTRAPIClient *)client maxTweetsPerRequest:(NSUInteger)maxTweetsPerRequest includeReplies:(BOOL)includeReplies includeRetweets:(BOOL)includeRetweets NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
