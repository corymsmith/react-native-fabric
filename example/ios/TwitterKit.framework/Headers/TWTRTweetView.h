//
//  TWTRTweetView.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TwitterKit/TWTRTweetViewDelegate.h>

@class TWTRTweet;

NS_ASSUME_NONNULL_BEGIN

/**
 *  The style for Tweet views.
 */
typedef NS_ENUM(NSUInteger, TWTRTweetViewStyle) {
    
    /**
     *  A full-size Tweet view. Displays images if present.
     */
    TWTRTweetViewStyleRegular,
    
    /**
     *  A small Tweet view, primarily designed to be used in table views.
     */
    TWTRTweetViewStyleCompact
};

/**
 *  A default combination of colors for Tweet views.
 */
typedef NS_ENUM(NSUInteger, TWTRTweetViewTheme) {
    
    /**
     *  Official light theme.
     */
    TWTRTweetViewThemeLight,
    
    /**
     *  Official dark theme.
     */
    TWTRTweetViewThemeDark,
};

/**
 `TWTRTweetView` displays a single Tweet to the user. It handles background taps and other actions displayed to the user.
 
    TWTRAPIClient *APIClient = [[TWTRAPIClient alloc] init];
    [[APIClient loadTweetWithID:@"20" completion:^(TWTRTweet *tweet, NSError *error) {
        if (tweet) {
            TWTRTweetView *tweetView = [[TWTRTweetView alloc] initWithTweet:tweet];
            [self.view addSubview:tweetView];
        } else {
            NSLog(@"Error loading Tweet: %@", [error localizedDescription]);
        }
    }];

 ## Interaction
 
 The `TWTRTweetViewDelegate` is notified:

   - When the background is tapped.
   - When a link is selected.
   - When the share button is tapped.
   - When the share action completes.
   - When the favorite action completes.
 
 ## Usage in UITableView
 
 To allow for usage in a `UITableView`, the `configureWithTweet:` method allows configuration of an existing `TWTRTweetView` without having to create a new instance.
 
 ## Sizing
 
 When using Auto Layout, feel free to set a width or margin on the Tweet view. The height will be calculated automatically. For old-fashioned frame based layout you may use the standard `sizeThatFits:` method to calculate the appropriate height for a given width:
 
    // Find the height for a given width (20pts on either side)
    CGFloat desiredHeight = [tweetView sizeThatFits:CGSizeMake(self.view.frame.size.width - 40, CGFLOAT_MAX)].height;
 
 ## UIAppearance
 
 You may use UIAppearance proxy objects to style certain aspects of Tweet views before those views are added to the view hierarchy.
 
     // Using UIAppearance Proxy
     [TWTRTweetView appearance].theme = TWTRTweetViewThemeDark;
 
     // Setting colors directly
     [TWTRTweetView appearance].primaryTextColor = [UIColor yellowColor];
     [TWTRTweetView appearance].backgroundColor = [UIColor blueColor];
 
     // Setting action button visibility
     [TWTRTweetView appearance].showActionButtons = NO;
 
 _Note:_ You can't change the theme through an appearance proxy after the view has already been added to the view hierarchy. Direct `theme` property access will work though.
 */
@interface TWTRTweetView : UIView <UIAppearanceContainer>

/**
 *  Background color of the Tweet view and all text labels (fullname, username, Tweet text, timestamp).
 */
@property (nonatomic) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;

/**
 *  Color of Tweet text and full name.
 */
@property (nonatomic) UIColor *primaryTextColor UI_APPEARANCE_SELECTOR;

/**
 *  Color of links in Tweet text.
 */
@property (nonatomic) UIColor *linkTextColor UI_APPEARANCE_SELECTOR;

/**
 *  Set whether the border should be shown.
 *  Defaults to YES.
 */
@property (nonatomic) BOOL showBorder UI_APPEARANCE_SELECTOR;

/**
 *  Set whether the action buttons (Favorite, Share) should be shown. When toggled,
 *  both the visibility of the action buttons and the internal constraints are
 *  updated immediately. The layout will be updated the next layout pass that occurs.
 *
 *  Defaults to NO.
 */
@property (nonatomic) BOOL showActionButtons;

/**
 *  Setting the theme of the Tweet view will change the color properties accordingly.
 *
 *  Set to `TWTRTweetViewThemeLight` by default.
 */
@property (nonatomic) TWTRTweetViewTheme theme;

/**
 *  The style of the Tweet. i.e. `TWTRTweetViewStyleRegular` or `TWTRTweetViewStyleCompact`.
 */
@property (nonatomic, readonly) TWTRTweetViewStyle style;

/**
 *  Optional delegate to receive notifications when certain actions happen
 */
@property (nonatomic, weak) IBOutlet id<TWTRTweetViewDelegate> delegate;

/**
 *  Optional property to set a UIViewController from which to present various new UI
 *  e.g. when presenting a Share sheet, presenting a login view controller for actions, etc
 */
@property (nonatomic, weak) UIViewController *presenterViewController;

/**
 *  Convenience initializer to configure a compact style Tweet view.
 *
 *  @param tweet The Tweet to display.
 *
 *  @return The fully-configured Tweet view.
 */
- (instancetype)initWithTweet:(nullable TWTRTweet *)tweet;

/**
 *  Designated initializer. Initializes view with both Tweet and style.
 *
 *  @param tweet The Tweet to display.
 *  @param style The style of the Tweet view (regular or compact).
 *
 *  @return The fully configured Tweet view.
 */
- (instancetype)initWithTweet:(nullable TWTRTweet *)tweet style:(TWTRTweetViewStyle)style;

/**
 * Initialization with a frame parameter is not supported.
 */
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/**
  Find the size that fits into a desired space. This is a system method on UIView but implemented on `TWTRTweetView`
  
    // Calculate the desired height at 280 points wide
    CGSize desiredSize = [tweetView sizeThatFits:CGSizeMake(280, CGFLOAT_MAX)];


   @param size The space available. Should generally leave one orientation unconstrained, and the minimum width supported is 200pts.
 
   @return The size that will fit into the space available.
 */
- (CGSize)sizeThatFits:(CGSize)size;

/**
 *  Update all images and label text to fully represent the given Tweet.
 *
 *  @param tweet The Tweet to display.
 */
- (void)configureWithTweet:(nullable TWTRTweet *)tweet;

@end

NS_ASSUME_NONNULL_END
