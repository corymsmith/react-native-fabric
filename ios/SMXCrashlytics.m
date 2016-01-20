#import "SMXCrashlytics.h"
#import <Crashlytics/Crashlytics.h>

@implementation SMXCrashlytics
@synthesize bridge = _bridge;

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}

RCT_EXPORT_METHOD(setUserIdentifier:(NSString *)userIdentifier)
{
  [[Crashlytics sharedInstance] setUserIdentifier:userIdentifier];
}

RCT_EXPORT_METHOD(setUserName:(NSString *)userName)
{
  [[Crashlytics sharedInstance] setUserName:userName];
}

RCT_EXPORT_METHOD(setUserEmail:(NSString *)email)
{
  [[Crashlytics sharedInstance] setUserEmail:email];
}

RCT_EXPORT_METHOD(setInt:(NSString *)key value:(int)integer)
{
  [[Crashlytics sharedInstance] setIntValue:integer forKey:key];
}

RCT_EXPORT_METHOD(setBool:(NSString *)key value:(BOOL)boolValue)
{
  [[Crashlytics sharedInstance] setBoolValue:boolValue forKey:key];
}

RCT_EXPORT_METHOD(setFloat:(NSString *)key value:(float)floatValue)
{
  [[Crashlytics sharedInstance] setFloatValue:floatValue forKey:key];
}

RCT_EXPORT_METHOD(setObject:(NSString *)key value:(NSDictionary *)obj)
{
  [[Crashlytics sharedInstance] setObjectValue:obj forKey:key];
}

@end
