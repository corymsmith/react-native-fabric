//
//  TWTRTweetUrlEntity.h
//
//  Copyright (c) 2016 Twitter. All rights reserved.
//

#import <TwitterKit/TWTRJSONConvertible.h>
#import "TWTRTweetEntity.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A Tweet entity which represents a URL
 */
@interface TWTRTweetUrlEntity : TWTRTweetEntity <NSCoding, TWTRJSONConvertible>

/**
 * The URL to display. This property may be truncated and may 
 * not be a valid URL.
 */
@property (nonatomic, copy, readonly) NSString *displayUrl;

/**
 * The expanded URL. This property will be a valid URL.
 */
@property (nonatomic, copy, readonly) NSString *expandedUrl;

/**
 * The t.co link which will redirect to the original URL.
 */
@property (nonatomic, copy, readonly) NSString *url;

@end

NS_ASSUME_NONNULL_END

