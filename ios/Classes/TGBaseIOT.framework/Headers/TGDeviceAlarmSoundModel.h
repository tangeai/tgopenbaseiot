//
//  TGDeviceAlarmSoundModel.h
//  TGIOT
//
//  Created by Darren on 2020/2/28.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//#import <TGCommonBaseModule/TGCommonBaseDefineHeader.h>
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceAlarmSoundModel : NSObject

#pragma mark -- set命令所需参数
@property (nonatomic, copy) NSString *bellID;
@property (nonatomic, assign) AUDIOFILEFMT fileFormat;
@property (nonatomic, assign) TCMEDIA codecId;
@property (nonatomic, strong, nullable) NSData *fileData;

#pragma mark -- 其他参数
@property (nonatomic, assign) int type;
@property (nonatomic, assign) BOOL isCustomAudio;
@property (nonatomic, copy) NSString *describe;
@property (nonatomic, strong, nullable) NSURL *url;//带协议类型

@property (nonatomic, assign) BOOL hasCreateAudio;

@property (nonatomic, assign) BOOL isSelect;
@property (nonatomic, assign) CGFloat cellHeight;
@property (nonatomic, assign) CGSize describeSize;

+ (instancetype)modelWithBellInfo:(NSDictionary *)bellInfo;

@end

NS_ASSUME_NONNULL_END
