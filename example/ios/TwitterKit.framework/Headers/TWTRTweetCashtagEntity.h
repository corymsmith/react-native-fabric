//
//  TWTRTweetCashtagEntity.h
//  TwitterKit
//
//  Copyright © 2016 Twitter. All rights reserved.
//

#import <TwitterKit/TWTRJSONConvertible.h>
#import "TWTRTweetEntity.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A Tweet entity which represents a Cashtag like '$twtr'
 */
@interface TWTRTweetCashtagEntity : TWTRTweetEntity <NSCoding, TWTRJSONConvertible>

/**
 * The text represented by this entity. 
 * @note This entity does not include the '$'.
 */
@property (nonatomic, copy, readonly) NSString *text;

@end

NS_ASSUME_NONNULL_END
