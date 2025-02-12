//
//  TGNormalEventModel.h
//  TGBaseIOT
//
//  Created by Darren on 2019/3/6.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGCameraDefine.h"
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGCloudEventModel : NSObject

@property (nonatomic, assign) TGDeviceRecordType type;

#pragma mark - cloudVideo
@property (nonatomic, copy) NSString *startTime;                //2019-01-16 16:18:07 (云录像开始时间)
@property (nonatomic, copy) NSString *endTime;                  //2019-01-16 19:24:47 (云录像结束时间)

#pragma mark - cloudVideo&CloudEvet
@property (nonatomic, copy) NSString *ossId;                    //云资源id(云录像和云事件均拥有的参数)

#pragma mark - cloudEvent
@property (nonatomic, copy) NSString *timeZone;                 //时区 "GMT+8,Asia/Shanghai"
@property (nonatomic, copy) NSString *id;                       //云事件id
@property (nonatomic, copy) NSString *deviceId;                 //设备id
@property (nonatomic, assign) BOOL playEnable;                  //仅对事件，是否可播放
@property (nonatomic, copy) NSString *cloudTime;                //2019-01-16 19:24:47 (云事件时间)
@property (nonatomic, copy) NSString *imagePath;                //图片地址
@property (nonatomic, copy) NSString *iconPath;                 //事件图片
@property (nonatomic, copy) NSString *recordingMode;            //记录模式
@property (nonatomic, copy) NSString *tag;
@property (nonatomic, copy) NSString *tagName;
@property (nonatomic, copy) NSString *tagMessage;
@property (nonatomic, copy) NSDictionary *tagExtra;             //额外数据

#pragma mark - 解析数据

@property (nonatomic, assign) NSInteger startHmsInterval;       //开始时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger endHmsInterval;         //结束时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger recordDuration;         //时长 单位s
@property (nonatomic, copy) NSString *hourMinusSecStr;          //16:18:10
@property (nonatomic, copy) NSString *durationMinusSecStr; 

@property (nonatomic, assign) NSInteger startTs;                 // 起始时间戳
@property (nonatomic, assign) NSInteger endTs;                   // 结束时间戳

#pragma mark - other

@property (nonatomic, assign) BOOL isSelected;                   // 不建议使用
@property (nonatomic, assign) NSInteger maxDownloadTime;
@property (nonatomic, assign) NSInteger maxDownloadTs;
@property (nonatomic, assign) NSInteger index;

/// 初始化
/// - Parameter info: info (云事件或云录像)
+ (instancetype)modelWithInfo:(NSDictionary *)info;
// 建议使用下面替代
+ (instancetype)modelWithInfo:(NSDictionary *)info timeZone:(NSString *)timeZone;

/// 初始化(单独使用云录像API时可使用此初始化方法，可获得deviceId) (将废弃)
/// - Parameters:
///   - info: info (云事件或云录像)
///   - deviceId: deviceId
+ (instancetype)modelWithInfo:(NSDictionary *)info deviceId:(NSString *)deviceId;
// 建议使用下面替代
+ (instancetype)modelWithInfo:(NSDictionary *)info deviceId:(NSString *)deviceId timeZone:(NSString *)timeZone;

@end

NS_ASSUME_NONNULL_END
