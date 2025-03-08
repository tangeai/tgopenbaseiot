//
//  TGBaseIOTPreConnectDeviceManager.h
//  TGBaseIOT
//
//  Created by liubin on 2025/3/5.
//

#import <Foundation/Foundation.h>
#import "TGIOTCameraDevice.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TGBaseIOTPreConnectDeviceManagerDelegate <NSObject>
/// 预连接状态
/// - Parameter status: 状态
- (void)tg_preConnectSessionStatus:(TGConnectSessionStatus)status;

/// 低功耗设备设备暂停休眠和恢复休眠状态
/// - Parameter status: 状态
- (void)tg_preConnectBatteryDeviceStatus:(TGBatteryDeviceStatus)status;

/// 连接设备对象
/// - Parameter camera: 设备对象
- (void)tg_preConnectCamera:(TGIOTCameraDevice *)camera;
@end

@interface TGBaseIOTPreConnectDeviceManager : NSObject

@property (nonatomic, weak) id<TGBaseIOTPreConnectDeviceManagerDelegate> delegate;
@property (nonatomic, assign) TGConnectSessionStatus sessionStatus;

/// 初始化
/// - Parameter deviceId: 设备id
- (instancetype)initPreConnectDeviceManagerWith:(NSString *)deviceId;

/// 连接
- (void)tg_connect;

/// 断开
- (void)tg_disConnnect;
//- (void)tg_setConnectModel:(TGDeviceConnectMode *)connectModel;

/// 低功耗设备设置活跃时间，默认60s
/// - Parameter time: 活跃时间
- (void)tg_setPreConnect:(NSInteger)time;

/// 结束预连接（设备发送出图指令时调用）
- (void)tg_endPre;

@end

NS_ASSUME_NONNULL_END
