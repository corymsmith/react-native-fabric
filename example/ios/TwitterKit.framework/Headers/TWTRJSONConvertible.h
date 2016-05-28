//
//  TWTRJSONConvertible.h
//  TwitterKit
//
//  Copyright © 2016 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TWTRJSONConvertible <NSObject>

/**
 * Initialize the receiver with its JSON object representation.
 *
 * @param dictionary the JSON object representing this object.
 * @return the fully formed object or nil if the JSON is not valid.
 */
- (nullable instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
