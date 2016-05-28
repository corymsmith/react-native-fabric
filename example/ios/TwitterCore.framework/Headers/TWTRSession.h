//
//  TWTRSession.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <TwitterCore/TWTRAuthConfig.h>
#import <TwitterCore/TWTRAuthSession.h>
#import <TwitterCore/TWTRGuestSession.h>

@class TWTRSession;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block called when user login succeeds or fails.
 *
 *  @param session Contains the OAuth tokens and minimal information associated with the logged in user or nil.
 *  @param error   Error that will be non nil if the authentication request failed.
 */
typedef void (^TWTRLogInCompletion)(TWTRSession * _Nullable session,  NSError * _Nullable error);

/**
 *  TWTRSession represents a user's session authenticated with the Twitter API.
 */
@interface TWTRSession : NSObject <TWTRAuthSession>

/**
 *  The authorization token.
 */
@property (nonatomic, copy, readonly) NSString *authToken;
/**
 *  The authorization token secret.
 */
@property (nonatomic, copy, readonly) NSString *authTokenSecret;
/**
 *  The username associated with the access token.
 */
@property (nonatomic, copy, readonly) NSString *userName;
/**
 *  The user ID associated with the access token.
 */
@property (nonatomic, copy, readonly) NSString *userID;

/**
 *  Returns an `TWTRSession` object initialized by copying the values from the dictionary or nil if the dictionary is missing.
 *
 *  @param sessionDictionary (required) The dictionary received after successfull authentication from Twitter OAuth.
 */
- (instancetype)initWithSessionDictionary:(NSDictionary *)sessionDictionary;

/**
 *  Returns an `TWTRSession` object initialized by copying the given tokens and user info.
 *
 *  @param authToken       (required) The authorization token for the session
 *  @param authTokenSecret (required) The authorization token secret for the session
 *  @param userName        (required) The username for the user associated with the session.
 *  @param userID          (required) The unique ID for the user associated with the session.
 *
 *  @return A `TWTRSession` object initialized with the provided parameters.
 */
- (instancetype)initWithAuthToken:(NSString *)authToken authTokenSecret:(NSString *)authTokenSecret userName:(NSString *)userName userID:(NSString *)userID NS_DESIGNATED_INITIALIZER;

/**
 *  Unavailable. Use -initWithSessionDictionary: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
