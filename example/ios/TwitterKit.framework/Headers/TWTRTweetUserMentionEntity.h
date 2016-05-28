//
//  TWTRTweetUserMentionEntity.h
//
//  Copyright (c) 2016 Twitter. All rights reserved.
//

#import <TwitterKit/TWTRJSONConvertible.h>
#import "TWTRTweetEntity.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A Tweet entity which represents a user mention.
 */
@interface TWTRTweetUserMentionEntity : TWTRTweetEntity <NSCoding, TWTRJSONConvertible>

/**
 * The userID of the user whom ha   s been mentioned.
 */
@property (nonatomic, copy, readonly) NSString *userID;

/**
 * The name of the user whom has been mentioned.
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 * The screen name of the user whom has been mentioned.
 */
@property (nonatomic, copy, readonly) NSString *screenName;

@end

NS_ASSUME_NONNULL_END
