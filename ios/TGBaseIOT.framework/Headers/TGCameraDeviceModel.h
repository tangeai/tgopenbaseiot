//
//  TGCameraDeviceModel.h
//  TGIOT
//
//  Created by Darren on 2019/1/11.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGDeviceExtension.h"
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGCameraDeviceModel : NSObject<TGDeviceFeatureProtocols,TGDeviceStatesProtocols,TGDeviceCacheProtocols,TGDeviceExtensionProtocols>

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSString *relay;

@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *actived;
@property (nonatomic, copy) NSString *expireTime;
@property (nonatomic, copy) NSString *imagePath;
@property (nonatomic, copy) NSString *imgTimeStamp;
@property (nonatomic, assign) BOOL isOnline;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *p2pId;
@property (nonatomic, copy) NSString *p2pType;
@property (nonatomic, copy) NSString *p2p_platform;
@property (nonatomic, copy) NSString *p2pStateServer;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *privateKey;
@property (nonatomic, copy) NSString *publicKey;
@property (nonatomic, assign) TGDeviceBindType bindType;
@property (nonatomic, copy) NSString *desKey;
@property (nonatomic, copy) NSString *currentVersion;
@property (nonatomic, copy) NSString *currentVersionCode;
@property (nonatomic, copy) NSString *firmwareId;
@property (nonatomic, copy) NSString *timeZone;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *connectType;
@property (nonatomic, copy) NSString *isUpgrade;
@property (nonatomic, copy) NSString *deviceType;
@property (nonatomic, copy) NSString *connectWay;
@property (nonatomic, copy) NSString *iccid;//sim卡标识，imei4G模块标识
@property (nonatomic, assign) BOOL isOpen;
@property (nonatomic, assign) BOOL simAboutToExpire;
@property (nonatomic, assign) BOOL driveAboutToExpire;
@property (nonatomic, assign) BOOL isNotice;
@property (nonatomic, assign) BOOL gpsModel;
@property (nonatomic, copy) NSString *authStatus;//0：无需实名  1：需要实名  2：已实名
@property (nonatomic, copy) NSString *isNoticeFreeCombo;
@property (nonatomic, copy) NSString *foreignIccidNotice;
@property (nonatomic, assign) BOOL isDirectional;
@property (nonatomic, assign) BOOL isPreConnect;
@property (nonatomic, assign) BOOL shouldShowSuperAi;//超级AI识别
@property (nonatomic, assign) BOOL has_doorbell_pwd; // 门锁设备是否设置过远程开锁密码
@property (nonatomic, copy) NSString *lowBattery;
@property (nonatomic, copy) NSString *latitude;
@property (nonatomic, copy) NSString *longitude;
@property (nonatomic, copy) NSString *speed;
@property (nonatomic, copy) NSString *direction;
@property (nonatomic, copy) NSString *gpsSignal;
@property (nonatomic, copy) NSString *liveTime;
@property (nonatomic, copy) NSString *foreignServiceHook;

@property (nonatomic, strong) NSDictionary *deviceNotice;
@property (nonatomic, strong) NSDictionary *attrs;
@property (nonatomic, strong) NSDictionary *batteryInfo;
@property (nonatomic, strong) NSDictionary *abilities;
@property (nonatomic, strong) NSArray *thirdPushArray;

@property (nonatomic, strong) NSMutableDictionary *serverInfo;
@property (nonatomic, strong) NSMutableDictionary *aiServerInfo;
@property (nonatomic, strong) NSMutableDictionary *simServerInfo;
@property (nonatomic, strong) NSMutableDictionary *carServerInfo;
@property (nonatomic, strong) NSMutableDictionary *serverBoughtInfo;
@property (nonatomic, strong) NSArray *webrtcInfo;

@property (nonatomic, assign) TGCameraDeviceFlag flag;
@property (nonatomic, strong) NSMutableDictionary *deviceInfo;
@property (nonatomic, strong) NSMutableDictionary *featureInfo;
@property (nonatomic, strong) NSMutableDictionary *customInfo;

@property (nonatomic, assign) NSInteger pageIndex;
@property (nonatomic, assign) NSInteger pageSize;
@property (nonatomic, assign) BOOL noMoreMessage;
@property (nonatomic, assign) BOOL isBinded;
@property (nonatomic, strong) NSMutableArray *messageArray;

/** 固件升级缓存*/
@property (nonatomic, assign) BOOL isUpgrading;
@property (nonatomic, copy) NSString *upgradeStatus;
@property (nonatomic, copy) NSString *upgradeProgress;
@property (nonatomic, assign) NSInteger upgradeTimeStamp;
@property (nonatomic, strong) NSString *upgradeFinishTime;
@property (nonatomic, copy, nullable) void(^deviceUpdateProgress)(void);

/** 设备直连缓存*/
@property (nonatomic, copy) NSString *ssid;
@property (nonatomic, strong, nullable) UIImage *coverImage;
@property (nonatomic, strong, nullable) UIImage *livePIPCoverImage;
@property (nonatomic, strong, nullable) UIImageView *imageView;

+ (instancetype)modelWithDeviceInfo:(NSDictionary *)deviceInfo;
- (void)updateDataWithNewDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
