//
//  Twitter.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <TwitterCore/TWTRSession.h>
#import <TwitterKit/TWTRAPIClient.h>
#import <UIKit/UIKit.h>

@class TWTRSessionStore;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, TWTRLoginMethod) {
    
    /**
     * Attempts to log the user in with the system accounts.
     * This log in method will only grant limited application permissions to
     * the returned oauth token. If you would like to have more
     * application permissions granted you must use the TWTRLoginMethodWebBased
     * and configure your application correctly.
     */
    TWTRLoginMethodSystemAccounts = 1 << 0,
    
    /**
     * Presents a web view that allows the user to log in.
     * This method will allow the developer to request more application
     * permissions. To learn more about configuring your application to 
     * have higher levels of permissions. 
     * Visit https://dev.twitter.com/oauth/overview/application-permission-model for
     * more information about Twitter's application permission model.
     */
    TWTRLoginMethodWebBased       = 1 << 1,
    
    /**
     * Picks the first available log in method. The order in which 
     * methods are checked is TWTRLoginMethodSystemAccounts -> TWTRLoginMethodWebBased.
     */
    TWTRLoginMethodAll            = TWTRLoginMethodSystemAccounts | TWTRLoginMethodWebBased
};


/**
 *  The central class of the Twitter Kit.
 *  @note This class can only be used from the main thread.
 */
@interface Twitter : NSObject

/**
 *  Returns the Twitter singleton.
 *
 *  @return The Twitter singleton.
 */
+ (Twitter *)sharedInstance;

/**
 *  Start Twitter with your consumer key and secret. These will override any credentials
 *  present in your applications Info.plist.
 *
 *  You do not need to call this method unless you wish to provide credentials other than those
 *  in your Info.plist.
 *
 *  @param consumerKey    Your Twitter application's consumer key.
 *  @param consumerSecret Your Twitter application's consumer secret.
 */
- (void)startWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret;

/**
 *  Start Twitter with a consumer key, secret, and keychain access group. See -[Twitter startWithConsumerKey:consumerSecret:]
 *
 *  @param consumerKey    Your Twitter application's consumer key.
 *  @param consumerSecret Your Twitter application's consumer secret.
 *  @param accessGroup    An optional keychain access group to apply to session objects stored in the keychain.
 *
 *  @note In the majority of situations applications will not need to specify an access group to use with Twitter sessions.
 *  This value is only needed if you plan to share credentials with another application that you control or if you are
 *  using TwitterKit with an app extension.
 */
- (void)startWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret accessGroup:(nullable NSString *)accessGroup;

/**
 *  The current version of this kit.
 */
@property (nonatomic, copy, readonly) NSString *version;

/**
 *  Authentication configuration details. Encapsulates the `consumerKey` and `consumerSecret` credentials required to authenticate a Twitter application.
 */
@property (nonatomic, readonly) TWTRAuthConfig *authConfig;

/**
 *  Session store exposing methods to fetch and manage active sessions. Applications that need to manage
 *  multiple users should use the session store to authenticate and log out users.
 */
@property (nonatomic, readonly) TWTRSessionStore *sessionStore;

/**
 *  Triggers user authentication with Twitter.
 *
 *  This method will present UI to allow the user to log in if there are no saved Twitter login credentials.
 *  This method is equivalent to calling loginWithMethods:completion: with TWTRLoginMethodAll.
 *
 *  @param completion The completion block will be called after authentication is successful or if there is an error.
 *  @warning This method requires that you have set up your `consumerKey` and `consumerSecret`.
 */
- (void)logInWithCompletion:(TWTRLogInCompletion)completion;

/**
 *  Triggers user authentication with Twitter.
 *
 *  This method will attempt to log the user in based on the specified log in methods. If multiple methods
 *  are specified the system account method will be attempted first.
 *
 *  @param completion The completion block will be called after authentication is successful or if there is an error.
 *  @warning This method requires that you have set up your `consumerKey` and `consumerSecret`.
 */
- (void)logInWithMethods:(TWTRLoginMethod)methods completion:(TWTRLogInCompletion)completion;

/**
 *  Triggers user authentication with Twitter. Allows the developer to specify the presenting view controller.
 *
 *  This method will present UI to allow the user to log in if there are no saved Twitter login credentials.
 *
 *  @param viewController The view controller that will be used to present the authentication view.
 *  @param completion The completion block will be called after authentication is successful or if there is an error.
 *  @warning This method requires that you have set up your `consumerKey` and `consumerSecret`.
 */
- (void)logInWithViewController:(nullable UIViewController *)viewController completion:(TWTRLogInCompletion)completion;

/**
 *  Triggers user authentication with Twitter. Allows the developer to specify the presenting view controller.
 *
 *  This method will attempt to log the user in based on the specified log in methods. If multiple methods
 *  are specified the system account method will be attempted first.
 *
 *  @param viewController The view controller that will be used to present the authentication view.
 *  @param completion The completion block will be called after authentication is successful or if there is an error.
 *  @warning This method requires that you have set up your `consumerKey` and `consumerSecret`.
 */
- (void)logInWithViewController:(nullable UIViewController *)viewController methods:(TWTRLoginMethod)methods completion:(TWTRLogInCompletion)completion;

@end

NS_ASSUME_NONNULL_END
