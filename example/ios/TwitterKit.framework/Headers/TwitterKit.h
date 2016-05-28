//
//  TwitterKit.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#if __has_feature(modules)
@import AVFoundation;
@import Accounts;
@import CoreMedia;
@import Foundation;
@import Social;
@import TwitterCore;
@import UIKit;
#else
#import <AVFoundation/AVFoundation.h>
#import <Accounts/Accounts.h>
#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>
#import <Social/Social.h>
#import <TwitterCore/TwitterCore.h>
#import <UIKit/UIKit.h>
#endif


#if __IPHONE_OS_VERSION_MIN_REQUIRED < 80000
#error "TwitterKit doesn't support iOS 7.x and lower. Please, change your minimum deployment target to iOS 8.0"
#endif

#import <TwitterKit/Twitter.h>
#import <TwitterKit/TWTRAPIClient.h>
#import <TwitterKit/TWTRCardConfiguration.h>
#import <TwitterKit/TWTRCollectionTimelineDataSource.h>
#import <TwitterKit/TWTRComposer.h>
#import <TwitterKit/TWTRComposerTheme.h>
#import <TwitterKit/TWTRComposerViewController.h>
#import <TwitterKit/TWTRJSONConvertible.h>
#import <TwitterKit/TWTRListTimelineDataSource.h>
#import <TwitterKit/TWTRLogInButton.h>
#import <TwitterKit/TWTRMoPubAdConfiguration.h>
#import <TwitterKit/TWTRMoPubNativeAdContainerView.h>
#import <TwitterKit/TWTRNotificationConstants.h>
#import <TwitterKit/TWTROAuthSigning.h>
#import <TwitterKit/TWTRSearchTimelineDataSource.h>
#import <TwitterKit/TWTRTimelineDataSource.h>
#import <TwitterKit/TWTRTimelineType.h>
#import <TwitterKit/TWTRTimelineViewController.h>
#import <TwitterKit/TWTRTweet.h>
#import <TwitterKit/TWTRTweetDetailViewController.h>
#import <TwitterKit/TWTRTweetTableViewCell.h>
#import <TwitterKit/TWTRTweetView.h>
#import <TwitterKit/TWTRTweetViewDelegate.h>
#import <TwitterKit/TWTRUser.h>
#import <TwitterKit/TWTRUserTimelineDataSource.h>

