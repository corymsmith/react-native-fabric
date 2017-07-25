#import "SMXCrashlytics.h"
#import <Crashlytics/Crashlytics.h>

@implementation SMXCrashlytics
@synthesize bridge = _bridge;

NSString *const DefaultDomain = @"com.smixx.fabric.SMXCrashlytics";
NSInteger const DefaultCode = 100;

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}

RCT_EXPORT_METHOD(log:(NSString *)message)
{
  CLS_LOG(@"%@", message);
}

RCT_EXPORT_METHOD(recordError:(NSDictionary *)error)
{
    NSInteger code;
    NSString *domain;
    NSObject *codeObject = [error objectForKey:@"code"];
    if (codeObject && [codeObject isKindOfClass:NSNumber.class])
        code = [(NSNumber *)codeObject intValue];
    else
        code = DefaultCode;
    if ([error objectForKey:@"domain"])
        domain = [error valueForKey:@"domain"];
    else
        domain = DefaultDomain;

    NSError *error2 = [NSError errorWithDomain:domain code:code userInfo:error];
    [[Crashlytics sharedInstance] recordError:error2];
}

RCT_EXPORT_METHOD(crash)
{
  [[Crashlytics sharedInstance] crash];
}

RCT_EXPORT_METHOD(throwException)
{
  [[Crashlytics sharedInstance] throwException];
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

RCT_EXPORT_METHOD(setBool:(NSString *)key value:(BOOL)boolValue)
{
  [[Crashlytics sharedInstance] setBoolValue:boolValue forKey:key];
}

RCT_EXPORT_METHOD(setString:(NSString *)key value:(NSString *)stringValue)
{
  [[Crashlytics sharedInstance] setObjectValue:stringValue forKey:key];
}

RCT_EXPORT_METHOD(setNumber:(NSString *)key value:(nonnull NSNumber *)numberValue)
{
  if(numberValue) {
    const char *objCType = [numberValue objCType];
    if(KWObjCTypeIsFloatingPoint(objCType)) {
       [[Crashlytics sharedInstance] setFloatValue:[numberValue floatValue] forKey:key];
    } else if(KWObjCTypeIsIntegral(objCType)) {
      [[Crashlytics sharedInstance] setIntValue:[numberValue intValue] forKey:key];
    }
  }
}

RCT_EXPORT_METHOD(recordCustomExceptionName:(nonnull NSString *)name reason:(NSString *)reason frameArray:(nonnull NSArray *)frameArray)
{
  NSMutableArray *clsFrames = [[NSMutableArray alloc] init];
  if(frameArray) {
    for (NSDictionary *dict in frameArray) {
      CLSStackFrame *frame = [CLSStackFrame stackFrame];
      [frame setFileName: dict[@"fileName"]];
      [frame setLineNumber: [dict[@"lineNumber"] intValue]];
      [frame setOffset: [dict[@"columnNumber"] intValue]];
      [frame setSymbol: dict[@"functionName"]];
      [clsFrames addObject: frame];
    }
    [[Crashlytics sharedInstance] recordCustomExceptionName:name reason:reason frameArray:clsFrames];
  }
}

// These functions are borrowed from https://github.com/joecannatti/Objective-C-Koans
BOOL KWObjCTypeIsFloatingPoint(const char *objCType) {
  return strcmp(objCType, @encode(float)) == 0 || strcmp(objCType, @encode(double)) == 0;
}

BOOL KWObjCTypeIsIntegral(const char *objCType) {
  return KWObjCTypeIsSignedIntegral(objCType) || KWObjCTypeIsUnsignedIntegral(objCType);
}

BOOL KWObjCTypeIsSignedIntegral(const char *objCType) {
  return strcmp(objCType, @encode(char)) == 0 ||
  strcmp(objCType, @encode(int)) == 0 ||
  strcmp(objCType, @encode(short)) == 0 ||
  strcmp(objCType, @encode(long)) == 0 ||
  strcmp(objCType, @encode(long long)) == 0;
}

BOOL KWObjCTypeIsUnsignedIntegral(const char *objCType) {
  return strcmp(objCType, @encode(unsigned char)) == 0 ||
  strcmp(objCType, @encode(unsigned int)) == 0 ||
  strcmp(objCType, @encode(unsigned short)) == 0 ||
  strcmp(objCType, @encode(unsigned long)) == 0 ||
  strcmp(objCType, @encode(unsigned long long)) == 0;
}

//RCT_EXPORT_METHOD(setInt:(NSString *)key value:(int)integer)
//{
//  [[Crashlytics sharedInstance] setIntValue:integer forKey:key];
//}

//RCT_EXPORT_METHOD(setFloat:(NSString *)key value:(float)floatValue)
//{
//  [[Crashlytics sharedInstance] setFloatValue:floatValue forKey:key];
//}

//RCT_EXPORT_METHOD(setObject:(NSString *)key value:(NSDictionary *)obj)
//{
//  [[Crashlytics sharedInstance] setObjectValue:obj forKey:key];
//}

@end
