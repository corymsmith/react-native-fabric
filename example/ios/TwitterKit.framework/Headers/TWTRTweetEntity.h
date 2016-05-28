//
//  TWTRTweetEntity.h
//
//  Copyright (c) 2016 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TwitterKit/TWTRJSONConvertible.h>

NS_ASSUME_NONNULL_BEGIN

@interface TWTRTweetEntity : NSObject <NSCoding, NSCopying, TWTRJSONConvertible>

/**
 * The start index of the entity in code points.
 */
@property (nonatomic, readonly) NSInteger startIndex;

/**
 * The end index of the entity in code points.
 */
@property (nonatomic, readonly) NSInteger endIndex;

/**
 * Initializes the receiver with the given start index and end index.
 */
- (instancetype)initWithStartIndex:(NSInteger)startIndex endIndex:(NSInteger)endIndex;

/**
 * Subclasses should override this method to provide an accessibility value
 * which can be used inside of Tweets.
 */
- (NSString *)accessibilityValue;

@end

NS_ASSUME_NONNULL_END
