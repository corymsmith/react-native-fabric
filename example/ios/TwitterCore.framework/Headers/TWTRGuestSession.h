//
//  TWTRGuestSession.h
//  TwitterKit
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TwitterCore/TWTRAuthSession.h>

@class TWTRGuestSession;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block called when guest login succeeds or fails.
 *
 *  @param guestSession A `TWTRGuestSession` containing the OAuth tokens or nil.
 *  @param error Error that will be non nil if the authentication request failed.
 */
typedef void (^TWTRGuestLogInCompletion)(TWTRGuestSession * _Nullable guestSession, NSError * _Nullable error);

/**
 *  `TWTRGuestSession` represents a guest session authenticated with the Twitter API. See `TWTRSession` for user sessions.
 */
@interface TWTRGuestSession : NSObject <TWTRBaseSession>

/**
 *  The bearer access token for guest auth.
 */
@property (nonatomic, copy, readonly) NSString *accessToken;

/**
 *  The guest access token.
 */
@property (nonatomic, copy, readonly) NSString *guestToken;

/**
 *  This property can be used to make a best guess about whether the token will
 *  still be valid or not.
 *
 *  Guest tokens expire after a short time interval but
 *  the actual interval is not specified. This property will return YES if a sufficient
 *  amount of time has passed indicating that the token is probably no longer valid.
 *  In most situations you should make a request with the token and see if the API
 *  accepts the token or not.
 */
@property (nonatomic, readonly) BOOL probablyNeedsRefreshing;

/**
 *  Returns an `TWTRGuestSession` object initialized by copying the values from the dictionary or nil if the dictionary is missing.
 *
 *  @param sessionDictionary (required) The dictionary received after successfull authentication from Twitter guest-only authentication.
 */
- (instancetype)initWithSessionDictionary:(NSDictionary *)sessionDictionary;

/**
 *  Returns a `TWTRGuestSession` object
 *
 *  @param accessToken the access token
 *  @param guestToken the guest access token
 */
- (instancetype)initWithAccessToken:(NSString *)accessToken guestToken:(nullable NSString *)guestToken;

/**
 *  Unavailable. Use `-initWithSessionDictionary:` instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
