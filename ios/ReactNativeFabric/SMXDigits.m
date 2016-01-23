#import "SMXDigits.h"
#import <DigitsKit/DigitsKit.h>

@implementation SMXDigits
@synthesize bridge = _bridge;

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}

RCT_EXPORT_METHOD(authenticate:(NSDictionary *)options)
{

}

@end
