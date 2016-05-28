//
//  TWTRLogInButton.h
//  TwitterKit
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <TwitterCore/TWTRSession.h>
#import <TwitterKit/Twitter.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  A Button which launches the sign in to Twitter flow when tapped.
 */
@interface TWTRLogInButton : UIButton

/**
 *  The completion block to be called with a `TWTRSession` if successful,
 *  and a `NSError` if logging in failed or was canceled.
 */
@property (nonatomic, copy) TWTRLogInCompletion logInCompletion;

/**
 *  The login methods to attempt when the button is pressed.
 *  Defaults to TWTRLoginMethodAll. See -[Twitter logInWithMethods:completion:] for more info.
 */
@property (nonatomic) TWTRLoginMethod loginMethods;

/**
 *  Returns a new log in button which launches Twitter log in when tapped and
 *  calls `completion` when logging in succeeds or fails.
 *
 *  Internally, this button simply calls `-[Twitter logInWithCompletion:]`.
 *
 *  @param completion The completion to be called with a `TWTRSession` if successful,
 *         and a `NSError` if logging in failed or was canceled.
 *  @return An initialized `TWTRLogInButton`.
 */
+ (instancetype)buttonWithLogInCompletion:(TWTRLogInCompletion)completion;

@end

NS_ASSUME_NONNULL_END
