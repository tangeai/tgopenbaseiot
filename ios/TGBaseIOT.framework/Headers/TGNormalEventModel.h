//
//  TGNormalEventModel.h
//  TGIOT
//
//  Created by Darren on 2019/3/6.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <TGCommonBaseModule/TGCommonBaseDefineHeader.h>
#import "TGBaseIOTDefine.h"
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGNormalEventModel : NSObject

@property (nonatomic, assign) TGDeviceRecordType type;
@property (nonatomic, copy) NSString *startTime;  //2019-01-16 16:18:07                                          
@property (nonatomic, copy) NSString *endTime;  //2019-01-16 19:24:47
@property (nonatomic, copy) NSString *imagePath;  //图片地址
@property (nonatomic, copy) NSString *iconPath;
@property (nonatomic, copy) NSString *tag;  //区分正常录像和事件录像
@property (nonatomic, copy) NSString *tagName;  //区分正常录像和事件录像
@property (nonatomic, copy) NSString *tagMessage;
@property (nonatomic, assign) NSInteger startHmsInterval;  //开始时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger endHmsInterval;  //结束时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger recordDuration;  //时长 单位s
@property (nonatomic, copy) NSString *hourMinusSecStr;  //16:18:10
@property (nonatomic, copy) NSString *durationMinusSecStr;
@property (nonatomic, assign) BOOL isSelected;
@property (nonatomic, copy) NSString *ossId;
@property (nonatomic, assign) unsigned char flags;
@property (nonatomic, assign) NSInteger startTs;
@property (nonatomic, assign) NSInteger endTs;

+ (instancetype)modelWithInfo:(NSDictionary *)info;
+ (instancetype)modelWithSAvExEvent:(SAvExEvent)event;

@end

NS_ASSUME_NONNULL_END
