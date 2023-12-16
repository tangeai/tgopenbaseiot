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
//#import "TGDeviceCapacityModel.h"
#import <DAAudioVideo/DAAudioVideo.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGCameraDeviceModel : NSObject

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, assign) BOOL isBinded;

#pragma mark - listData
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *productName;
@property (nonatomic, strong) NSString *categoryName;
@property (nonatomic, strong) NSString *categoryKey;
@property (nonatomic, strong) NSString *connectWay;
@property (nonatomic, assign) BOOL is_owner;
@property (nonatomic, strong) NSString *p2pType;

@property (nonatomic, strong) NSDictionary *attrs;
@property (nonatomic, strong) NSDictionary *abilities;
@property (nonatomic, strong) NSDictionary *extAttrs;

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

@property (nonatomic, assign) BOOL isOnline;
@property (nonatomic, copy) NSString *up_at;
@property (nonatomic, copy) NSString *down_at;

#pragma mark - connectInfor

@property (nonatomic, copy) NSString *connectInfor;
@property (nonatomic, copy) NSString *p2p_platform;
@property (nonatomic, copy) NSString *p2pId;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *relay;
@property (nonatomic, copy) NSString *webrtc;
@property (nonatomic, copy) NSString *p2pStateServer;
@property (nonatomic, strong) NSArray *webrtcInfo;

#pragma mark - coreImage

//@property (nonatomic, strong) UIImage *coverImage;
@property (nonatomic, copy) NSString *imagePath;
@property (nonatomic, copy) NSString *imgTimeStamp;

#pragma mark - des_key

@property (nonatomic, strong) NSString *des_key;

//@property (nonatomic, strong) TGDeviceCapacityModel *capacityModel;

#pragma mark - other 以下参数均为定制兼容请勿使用，如需使用请自己实现其方法

@property (nonatomic, strong) NSString *ipAddress;
@property (nonatomic, copy, nullable) void(^deviceUpdateProgress)(void);
@property (nonatomic, copy) NSString *deviceType;
@property (nonatomic, assign) BOOL isPreConnect;
@property (nonatomic, copy) NSString *speed;
@property (nonatomic, strong) NSMutableDictionary *deviceInfo;
@property (nonatomic, strong) NSMutableDictionary *featureInfo;
@property (nonatomic, strong) NSMutableDictionary *customInfo;

#pragma mark - V2-Action

// 设备列表实例方法
+ (instancetype)modelWithDeviceInfo:(NSDictionary *)deviceInfo;
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

- (void)updateDataWithNewDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
