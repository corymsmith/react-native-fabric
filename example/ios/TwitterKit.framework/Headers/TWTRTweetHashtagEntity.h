//
//  TWTRTweetHashtagEntity.h
//
//  Copyright (c) 2016 Twitter. All rights reserved.
//

#import <TwitterKit/TWTRJSONConvertible.h>
#import "TWTRTweetEntity.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A Tweet entity which represents a Hashtag like '#twitterkit'
 */
@interface TWTRTweetHashtagEntity : TWTRTweetEntity <NSCoding, TWTRJSONConvertible>

/**
 * The text represented by this entity.
 * @note This entity does not include the '#'.
 */
@property (nonatomic, copy, readonly) NSString *text;

@end

NS_ASSUME_NONNULL_END
