#import "SMXAnswers.h"
#import "RCTBridgeModule.h"
#import "RCTEventDispatcher.h"
#import "RCTBridge.h"
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

RCT_EXPORT_METHOD(logPurchase:(nullable NSDecimalNumber *)itemPriceOrNil
                  currency:(nullable NSString *)currencyOrNil
                  success:(nullable NSNumber *)purchaseSucceededOrNil
                  itemName:(nullable NSString *)itemNameOrNil
                  itemType:(nullable NSString *)itemTypeOrNil
                  itemId:(nullable NSString *)itemIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logPurchaseWithPrice:itemPriceOrNil currency:currencyOrNil success:purchaseSucceededOrNil itemName:itemNameOrNil itemType:itemTypeOrNil itemId:itemIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logLevelStart:(nullable NSString *)levelNameOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logLevelStart:levelNameOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logLevelEnd:(nullable NSString *)levelNameOrNil
                  score:(nullable NSNumber *)scoreOrNil
                  success:(nullable NSNumber *)levelCompletedSuccesfullyOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logLevelEnd:levelNameOrNil score:scoreOrNil success:levelCompletedSuccesfullyOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logAddToCart:(nullable NSDecimalNumber *)itemPriceOrNil
                  currency:(nullable NSString *)currencyOrNil
                  itemName:(nullable NSString *)itemNameOrNil
                  itemType:(nullable NSString *)itemTypeOrNil
                  itemId:(nullable NSString *)itemIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logAddToCartWithPrice:itemPriceOrNil currency:currencyOrNil itemName:itemNameOrNil itemType:itemTypeOrNil itemId:itemIdOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logStartCheckout:(nullable NSDecimalNumber *)totalPriceOrNil
                  currency:(nullable NSString *)currencyOrNil
                  itemCount:(nullable NSNumber *)itemCountOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logStartCheckoutWithPrice:totalPriceOrNil currency:currencyOrNil itemCount:itemCountOrNil customAttributes:customAttributesOrNil];
}

RCT_EXPORT_METHOD(logRating:(nullable NSNumber *)ratingOrNil
                  contentName:(nullable NSString *)contentNameOrNil
                  contentType:(nullable NSString *)contentTypeOrNil
                  contentId:(nullable NSString *)contentIdOrNil
                  customAttributes:(nullable ANS_GENERIC_NSDICTIONARY(NSString *, id) *)customAttributesOrNil){
  [Answers logRating:ratingOrNil contentName:contentNameOrNil contentType:contentTypeOrNil contentId:contentIdOrNil customAttributes:customAttributesOrNil];
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

@end