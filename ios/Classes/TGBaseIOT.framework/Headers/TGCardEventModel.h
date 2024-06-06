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

@interface TGCardEventModel : NSObject

@property (nonatomic, assign) TGDeviceRecordType type;
@property (nonatomic, copy) NSString *startTime;                //2019-01-16 16:18:07
@property (nonatomic, copy) NSString *endTime;                  //2019-01-16 19:24:47
@property (nonatomic, copy) NSString *tag;                      //卡时间类型
@property (nonatomic, assign) NSInteger startHmsInterval;       //开始时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger endHmsInterval;         //结束时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger recordDuration;         //时长 单位s
@property (nonatomic, copy) NSString *hourMinusSecStr;          //16:18:10
@property (nonatomic, copy) NSString *durationMinusSecStr;
@property (nonatomic, assign) unsigned char flags;
@property (nonatomic, assign) NSInteger startTs;                //开始时间戳
@property (nonatomic, assign) NSInteger endTs;                  //结束时间戳
@property (nonatomic, assign) BOOL isEventImageExist;           //是否存在缩略图
@property (nonatomic, assign) NSInteger eventTime;                //事件时间戳（与平台事件时间戳一致）
@property (nonatomic, copy) NSString *eventId;                  //事件id，可通过此id查询事件详情得到缩略图

#pragma mark -- other

@property (nonatomic, assign) BOOL isSelected;                  // 不建议使用

+ (instancetype)modelWithSAvExEvent:(SAvExEvent)event;
+ (instancetype)modelWithSAvEvent2:(SAvEvent2)event deviceId:(NSString *)deviceId;

@end

NS_ASSUME_NONNULL_END
