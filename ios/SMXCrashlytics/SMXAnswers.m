#import "SMXAnswers.h"
#import <React/RCTBridgeModule.h>
#import <React/RCTEventDispatcher.h>
#import <React/RCTBridge.h>
#import <Crashlytics/Crashlytics.h>

@implementation SMXAnswers
@synthesize bridge = _bridge;

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}


RCT_EXPORT_METHOD(logSignUp:(NSString *)signUpMethod
                  success:(BOOL)succeeded
                  customAttributes:(NSDictionary *)customAttributes)
{
  [Answers logSignUpWithMethod:signUpMethod success:[NSNumber numberWithBool:succeeded] customAttributes:customAttributes];
}

RCT_EXPORT_METHOD(logLogin:(NSString *)loginMethod
                  success:(BOOL)succeeded
                  customAttributes:(NSDictionary *)customAttributes)
{
  [Answers logLoginWithMethod:loginMethod success:[NSNumber numberWithBool:succeeded] customAttributes:customAttributes];
}

RCT_EXPORT_METHOD(logShare:(nullable NSString *)shareMethodOrNil
                  contentName:(nullable NSString *)contentNameOrNil
                  contentType:(nullable NSString *)contentTypeOrNil
                  contentId:(nullable NSString *)contentIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil) {
  [Answers logShareWithMethod:shareMethodOrNil contentName:contentNameOrNil contentType:contentTypeOrNil contentId:contentIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logInvite:(nullable NSString *)inviteMethodOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logInviteWithMethod:inviteMethodOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logPurchase:(nullable NSString *)itemPriceOrNil
                  currency:(nullable NSString *)currencyOrNil
                  success:(BOOL)purchaseSucceeded
                  itemName:(nullable NSString *)itemNameOrNil
                  itemType:(nullable NSString *)itemTypeOrNil
                  itemId:(nullable NSString *)itemIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logPurchaseWithPrice:[self getDecimalFromString:itemPriceOrNil] currency:currencyOrNil success:[NSNumber numberWithBool:purchaseSucceeded] itemName:itemNameOrNil itemType:itemTypeOrNil itemId:itemIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logLevelStart:(nullable NSString *)levelNameOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logLevelStart:levelNameOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logLevelEnd:(nullable NSString *)levelNameOrNil
                  score:(nullable NSString *)scoreOrNil
                  success:(BOOL)levelCompletedSuccesfully
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logLevelEnd:levelNameOrNil score:[self getDecimalFromString:scoreOrNil] success:[NSNumber numberWithBool:levelCompletedSuccesfully] customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logAddToCart:(nullable NSString *)itemPriceOrNil
                  currency:(nullable NSString *)currencyOrNil
                  itemName:(nullable NSString *)itemNameOrNil
                  itemType:(nullable NSString *)itemTypeOrNil
                  itemId:(nullable NSString *)itemIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  
  [Answers logAddToCartWithPrice:[self getDecimalFromString:itemPriceOrNil] currency:currencyOrNil itemName:itemNameOrNil itemType:itemTypeOrNil itemId:itemIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logStartCheckout:(nullable NSString *)totalPriceOrNil
                  currency:(nullable NSString *)currencyOrNil
                  itemCount:(nullable NSString *)itemCountOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logStartCheckoutWithPrice:[self getDecimalFromString:totalPriceOrNil] currency:currencyOrNil itemCount:[self getIntegerFromString:itemCountOrNil] customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logRating:(nullable NSString *)ratingOrNil
                  contentName:(nullable NSString *)contentNameOrNil
                  contentType:(nullable NSString *)contentTypeOrNil
                  contentId:(nullable NSString *)contentIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logRating:[self getDecimalFromString:ratingOrNil] contentName:contentNameOrNil contentType:contentTypeOrNil contentId:contentIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logContentView:(nullable NSString *)contentNameOrNil
                  contentType:(nullable NSString *)contentTypeOrNil
                  contentId:(nullable NSString *)contentIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logContentViewWithName:contentNameOrNil contentType:contentTypeOrNil contentId:contentIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logSearch:(nullable NSString *)queryOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logSearchWithQuery:queryOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logCustom:(NSString *)eventName
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logCustomEventWithName:eventName customAttributes:customAttributesOrNil];
}

- (NSDecimalNumber *)getDecimalFromString:(NSString *)stringValue {
  if(stringValue != nil) {
    return [NSDecimalNumber decimalNumberWithString:stringValue];
  }
  return nil;
}

- (NSNumber *)getIntegerFromString:(NSString *)stringValue {
  if(stringValue != nil) {
    return [NSNumber numberWithInteger:[stringValue integerValue]];
  }
  return nil;
}

@end
