//
//  TGNetworkManager.h
//  TGIOT
//
//  Created by Darren on 2021/7/19.
//
#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGNetworkManager : NSObject

+ (instancetype)shareManager;
- (void)checkBroadcastAvaiableWithController:(UIViewController *)controller cancleCallback:(void(^)(void))cancleCallback avaiableCallback:(void(^)(void))avaiableCallback;
- (void)broadCastToPort:(int)broadcastPort sendString:(NSString *)sendString complteBlock:(void(^)(void))complteBlock receiveCallBlock:(BOOL(^)(NSString *receiveString))receiveCallBlock;
- (NSArray *)gatewayAddress;

@end

NS_ASSUME_NONNULL_END
