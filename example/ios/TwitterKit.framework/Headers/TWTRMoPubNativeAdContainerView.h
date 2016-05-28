//
//  TWTRMoPubNativeAdContainerView.h
//  TwitterKit
//
//  Copyright © 2016 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  A default combination of colors for the native ads.
 */
typedef NS_ENUM(NSUInteger, TWTRNativeAdTheme) {
    /**
     *  Official light theme.
     */
    TWTRNativeAdThemeLight,
    /**
     *  Official dark theme.
     */
    TWTRNativeAdThemeDark
};

/**
 *  The ad view rendered using MoPub. This class is not intended for public use other than to configure
 *  color options. Colors can be configured by setting the theme and further customized by tweaking
 *  the individual color options.
 *
 *  ## UIAppearance
 *
 *  You may use UIAppearance proxy objects to style certain aspects of the
 *  the ad view to match your application's design.
 
 *  // Setting a theme
 *  [TWTRMoPubNativeAdContainerView appearance].theme = TWTRNativeAdThemeDark;
 *
 *  // Overriding colors of certain properties
 *  [TWTRMoPubNativeAdContainerView appearance].primaryTextColor = [UIColor yellowColor];
 *
 *  @note You can't change the theme through an appearance proxy after the
 *  view has already been added to the view hierarchy.
 */
@interface TWTRMoPubNativeAdContainerView : UIView <UIAppearanceContainer>

/**
 *  Setting the theme of ad views. This is the base template that can
 *  be overridden by setting your custom colors for the available view
 *  properties. Default is `TWTRNativeAdThemeLight`.
 */
@property (nonatomic) TWTRNativeAdTheme theme UI_APPEARANCE_SELECTOR;

/**
 *  Background color of this ad container view. Defaults to #F5F8FA.
 */
@property (nonatomic) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;

/**
 *  Background color of the ad within the container. Defaults to #FFFFFF.
 */
@property (nonatomic) UIColor *adBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 *  Primary text color used within the ad cell including the underlying ad. Defaults to #292F33.
 */
@property (nonatomic) UIColor *primaryTextColor UI_APPEARANCE_SELECTOR;

/**
 *  Background color of buttons. Defaults to #174791.
 */
@property (nonatomic) UIColor *buttonBackgroundColor UI_APPEARANCE_SELECTOR;


@end

NS_ASSUME_NONNULL_END
