//
//  TGCameraDeviceModel.h
//  TGBaseIOT
//
//  Created by Darren on 2019/1/11.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGBaseIOTDefine.h"
#import <DAAudioVideo/DAAudioVideo.h>
//#import "TGDeviceCapacityModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGCameraDeviceModel : NSObject

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, assign) BOOL isBinded;

#pragma mark - listData
// 是否设备的主人
@property (nonatomic, assign) BOOL is_owner;
// 设备ID
@property (nonatomic, copy) NSString *deviceId;
// 设备昵称
@property (nonatomic, copy) NSString *deviceName;
// 设备联网方式，例如：lan(有线连接)、wifi、sim(4G卡)
@property (nonatomic, copy) NSString *connectWay;
// 设备产品标识
@property (nonatomic, copy) NSString *productKey;
// 设备归属产品名称，例如：越南IPC
@property (nonatomic, copy) NSString *productName;
// 设备品类标识，例如：ipc
@property (nonatomic, copy) NSString *categoryKey;
// 设备品类，例如：普通IPC
@property (nonatomic, copy) NSString *categoryName;

// 设备属性，例如："{\"category\":\"ipc\",\"network\":\"wifi\",\"os\":\"linux\"}"
@property (nonatomic, strong) NSDictionary *attrs;
// 设备能力集，例如："{\"Microphone\":\"Yes\",\"RecordConf\":\"res\"}"
@property (nonatomic, strong) NSDictionary *abilities;
// 设备扩展属性，例如："{\"model\":\"TG-IPC-001\"}"
@property (nonatomic, strong) NSDictionary *extAttrs;
// 设备AI能力集，例如："{\"hw_ai\":[{\"flags\":1,\"type\":\"bd\"}],\"sw_ai\":[\"mt\"]}"
@property (nonatomic, strong) NSDictionary *aiAbilities;
// 设备属性扩展黑盒，可以是任意数据格式
@property (nonatomic, strong) id extends;
// 设备目数
@property (nonatomic, assign) NSInteger multiChannels; // 目数

#pragma mark - timezone

@property (nonatomic, copy) NSString *timeZone;
@property (nonatomic, copy) NSString *time;

#pragma mark - updateInfor

@property (nonatomic, copy) NSString *currentVersion;
@property (nonatomic, copy) NSString *currentModelId;
@property (nonatomic, copy) NSString *currentSdkver;
@property (nonatomic, copy) NSString *targetVersion;
@property (nonatomic, copy) NSString *targetContent;
@property (nonatomic, copy) NSString *targetDownload_link;
@property (nonatomic, assign) double targetFileSize;
@property (nonatomic, copy) NSString *md5;

#pragma mark - onlineInfor

@property (nonatomic, assign) BOOL isOnline;                    // 是否在线
@property (nonatomic, copy) NSString *up_at;                    // 上线时间戳
@property (nonatomic, copy) NSString *down_at;                  // 下线时间戳
@property (nonatomic, assign) NSInteger up_time;                // 上线时间戳
@property (nonatomic, assign) NSInteger down_time;              // 下线时间戳
@property (nonatomic, assign) BOOL is_alive;                    // 电池设备---是否保活中
@property (nonatomic, assign) NSInteger live_time;              // 长电设备(在线时值为-1、离线值为0)、低功耗设备(在线时值为进入休眠前的倒计时，离线时值为0)
@property (nonatomic, copy) NSString *last_heartbeat_data;      // 电池设备---心跳数据
@property (nonatomic, assign) NSInteger last_heartbeat_time;    // 电池设备---最近心跳时间戳
@property (nonatomic, assign) NSInteger sleep_login_time;       // 电池设备---最近登录休眠服务器的时间戳
@property (nonatomic, assign) NSInteger last_offline_time;      // 电池设备---最近退出休眠服务器时间戳

#pragma mark - connectInfor

@property (nonatomic, copy) NSString *connectInfor;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *relay;
@property (nonatomic, copy) NSString *p2pId;
@property (nonatomic, copy) NSString *p2pType;
@property (nonatomic, copy) NSString *p2p_platform;
@property (nonatomic, copy) NSString *p2pStateServer;
@property (nonatomic, copy) NSArray *webrtcInfo;
@property (nonatomic, copy) NSString *webrtcInfo2;

#pragma mark - coreImage

@property (nonatomic, copy) NSString *imagePath;
@property (nonatomic, copy) NSString *imgTimeStamp;

#pragma mark - used info

@property (nonatomic, strong) NSMutableDictionary *deviceInfo;
@property (nonatomic, strong) NSMutableDictionary *featureInfo;
@property (nonatomic, strong) NSMutableDictionary *customInfo;
//@property (nonatomic, strong) TGDeviceCapacityModel *capacityModel;

#pragma mark - local

@property (nonatomic, strong) NSString *ipAddress;
@property (nonatomic, strong) NSString *setWiFi;

#pragma mark - other 以下参数均为定制兼容请勿使用，如需使用请自己实现其方法

@property (nonatomic, strong) NSString *des_key;
@property (nonatomic, copy) NSString *deviceType;
@property (nonatomic, assign) BOOL isPreConnect;
@property (nonatomic, copy, nullable) void(^deviceUpdateProgress)(void);

#pragma mark - V2-Action

// 设备列表实例方法
+ (instancetype)modelWithDeviceInfo:(NSDictionary *)deviceInfo;
// 更新设备信息
- (void)updateDeviceInfo:(NSDictionary *)deviceInfo;
// 更新设备时区
- (void)updateTimeZone:(NSDictionary *)timeZoneDic;
// 更新设备升级信息
- (void)updateInfor:(NSDictionary *)updateDic;
// 更新设备连接信息
- (void)updateConnectInfor:(NSString *)connectInfor;
// 更新设备在线信息
- (void)updateOnlineInfor:(NSDictionary *)onlineInfor;
// 更新设备封面信息
- (void)updateImageInfor:(NSDictionary *)imageInfo;
// 更新设备完整信息
- (void)updateDataWithNewDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
