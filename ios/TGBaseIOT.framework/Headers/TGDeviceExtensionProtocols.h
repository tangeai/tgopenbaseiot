//
//  TGDeviceExtensionProtocols.h
//  TGIOT
//
//  Created by Darren on 2022/5/17.
//

#import <UIKit/UIKit.h>
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TGDeviceExtensionProtocols <NSObject>

/* 是否是4G行车记录仪 */
@property (nonatomic, assign, readonly) BOOL isDrSimDevice;
/* 是否是4G电池行车记录仪 */
@property (nonatomic, assign, readonly) BOOL isLpDrSimDevice;
/* 是否是4G摄像机 */
@property (nonatomic, assign, readonly) BOOL isSimDevice;
/* 是否是4G微功耗摄像机、4G电池摄像机 */
@property (nonatomic, assign, readonly) BOOL isLpSimDevice;
/* 是否是WiFi摄像机 */
@property (nonatomic, assign, readonly) BOOL isWifiDevice;
/* 是否是WiFi行车记录仪 */
@property (nonatomic, assign, readonly) BOOL isDrWifiDevice;
/* 是否是WiFi电池摄像机 */
@property (nonatomic, assign, readonly) BOOL isLpWifiDevice;
/* 是否是WiFi门铃 */
@property (nonatomic, assign, readonly) BOOL isDoorBellWifiDevice;
/* 是否是WiFi电池门铃 */
@property (nonatomic, assign, readonly) BOOL isLpDoorBellWifiDevice;
/* 是否是WiFi门锁 */
@property (nonatomic, assign, readonly) BOOL isLockBellDevice;
/* 是否是WiFi电池门锁 */
@property (nonatomic, assign, readonly) BOOL isLpLockBellDevice;
/* 是否是WiFi喂鸟器 */
@property (nonatomic, assign, readonly) BOOL isBirdFeederWifiDevice;
/* 是否是WiFi电池喂鸟器 */
@property (nonatomic, assign, readonly) BOOL isLpBirdFeederWifiDevice;
/* 是否是4G喂鸟器 */
@property (nonatomic, assign, readonly) BOOL isBirdFeederSimDevice;
/* 是否是4G电池喂鸟器 */
@property (nonatomic, assign, readonly) BOOL isLpBirdFeederSimDevice;
/* 图片服务，支持图片和声音 */
@property (nonatomic, assign, readonly) BOOL isPicServiceDevice;
/* 图片服务，仅支持图片 */
@property (nonatomic, assign, readonly) BOOL isPictureOnlyDevice;
/* 是否是WiFi台灯 */
@property (nonatomic, assign, readonly) BOOL isWifiLampDevice;
/* 是否支持行车服务 */
@property (nonatomic, assign, readonly) BOOL carServiceAvaiable;
/* 是否支持包看服务 */
@property (nonatomic, assign, readonly) BOOL simServiceAvaiable;
/* 是否支持智能识别 */
@property (nonatomic, assign, readonly) BOOL smartServiceAvaiable;
/* 是否支持云录像服务 */
@property (nonatomic, assign, readonly) BOOL cloudServiceAvaiable;
/* 是否支持学习服务 */
@property (nonatomic, assign, readonly) BOOL learnServiceAvaiable;
/* 是否支持VIP服务，用于门锁门铃 */
@property (nonatomic, assign, readonly) BOOL vipServiceAvaiable;
/* 是否支持VIP服务，用于喂鸟器 */
@property (nonatomic, assign, readonly) BOOL birdServiceAvaiable;
/* 设备列表更多 */
@property (nonatomic, strong, readonly) NSArray *moreModelArray;
/* 是否是内建服务 */
@property (nonatomic, assign, readonly) BOOL isBuiltInService;
/* 是否支持呼叫 */
@property (nonatomic, assign, readonly) BOOL isDoorbellAvaiable;
/* 是否支持开锁 */
@property (nonatomic, assign, readonly) BOOL deviceUnlockAvaiable;
@property (nonatomic, assign, readonly) TGDeviceNetworkType networkType;

@end

NS_ASSUME_NONNULL_END
