#import "SMXTwitter.h"
#import "RCTBridgeModule.h"
#import "RCTEventDispatcher.h"
#import "RCTBridge.h"
#import <TwitterKit/TwitterKit.h>

@implementation SMXTwitter
@synthesize bridge = _bridge;

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(login:(RCTResponseSenderBlock)callback)
{
  [[Twitter sharedInstance] logInWithCompletion:^(TWTRSession *session, NSError *error) {
    if (session) {
      NSDictionary *body = @{@"authToken": session.authToken,
                             @"authTokenSecret": session.authTokenSecret,
                             @"userID":session.userID,
                             @"userName":session.userName};
      callback(@[[NSNull null], body]);
    } else {
      NSLog(@"error: %@", [error localizedDescription]);
      callback(@[[error localizedDescription]]);
    }
  }];
}

RCT_EXPORT_METHOD(logOut)
{
  TWTRSessionStore *store = [[Twitter sharedInstance] sessionStore];
    NSString *userID = store.session.userID;

    [store logOutUserID:userID];
}


- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}

@end
