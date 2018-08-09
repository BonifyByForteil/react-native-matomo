//
//  Piwik
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#if __has_include(<React/RCTBridgeModule.h>)
#import <React/RCTBridgeModule.h>
#elif __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#elif __has_include("React/RCTBridgeModule.h")
#import "React/RCTBridgeModule.h"   // Required when used as a Pod in a Swift project
#endif

@interface Piwik : NSObject <RCTBridgeModule>
-(void) initTracker: (NSString*)url id:(NSNumber* _Nonnull) id;
-(void) trackScreen: (NSString* _Nonnull)screen title:(NSString*) title;
-(void) setUserId:(NSString* _Nonnull)userID;
-(void) setAppOptOut:(BOOL)isOptedOut;
-(void) trackGoal: (NSUInteger)goal values:(NSDictionary* _Nonnull) values;
-(void) trackEvent: (NSString* _Nonnull)category action:(NSString* _Nonnull) action values:(NSDictionary* _Nonnull) values;
-(void) trackAppDownload;
@end
