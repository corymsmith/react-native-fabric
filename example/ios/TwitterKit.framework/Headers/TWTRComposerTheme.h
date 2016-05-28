//
//  TWTRComposerTheme.h
//  TwitterKit
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TWTRComposerThemeType) {
    TWTRComposerThemeTypeLight,
    TWTRComposerThemeTypeDark,
};

@interface TWTRComposerTheme : NSObject

/**
 * Returns an instance of the theme object with the given type.
 */
- (instancetype)initWithThemeType:(TWTRComposerThemeType)type NS_DESIGNATED_INITIALIZER;

@end
