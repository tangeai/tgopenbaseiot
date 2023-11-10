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

/// 检查AP是否可用
/// - Parameters:
///   - controller: 承载VC
///   - wifiArrayMsg: 未打开wifi提示 ,不传默认英文，格式[titile,message,confirm,cancel]
///   - netArrayMsg: 本地网络授权提示 ，不传默认英文，格式[titile,message,confirm,cancel]
///   - cancleCallback: 取消回调
///   - avaiableCallback: 可用回调
- (void)checkBroadcastAvaiableWithController:(UIViewController *)controller wifiNotOPenArrayMsg:(nullable NSArray *)wifiArrayMsg localNetwrokNotAuthArrayMsg:(nullable NSArray *)netArrayMsg cancleCallback:(void(^)(void))cancleCallback avaiableCallback:(void(^)(void))avaiableCallback;
- (void)broadCastToPort:(int)broadcastPort sendString:(NSString *)sendString complteBlock:(void(^)(void))complteBlock receiveCallBlock:(BOOL(^)(NSString *receiveString))receiveCallBlock;
- (NSArray *)gatewayAddress;

@end

NS_ASSUME_NONNULL_END
