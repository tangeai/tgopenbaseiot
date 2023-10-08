//
//  TGDeviceStatesProtocols.h
//  TGIOT
//
//  Created by Darren on 2021/9/27.
//

//#import <TGCommonBaseModule/TGCustomDefine.h>
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN


@protocol TGDeviceStatesProtocols <NSObject>

/* 通道0变焦z值 */
@property (nonatomic, assign, readonly) CGFloat channelZeroZValue;
/* 通道1变焦z值 */
@property (nonatomic, assign, readonly) CGFloat channelOneZValue;
/* 画中画设备实时主画面通道数 */
@property (nonatomic, assign, readonly) TGPlayChannelType livePrimaryChannel;
/* 画中画设备云录像主画面通道数 */
@property (nonatomic, assign, readonly) NSInteger cloudPrimaryChannel;
/* 画中画设备卡录像实时主画面通道数 */
@property (nonatomic, assign, readonly) NSInteger sdCardPrimaryChannel;
/* 门锁开锁状态 */
@property (nonatomic, assign, readonly) NSInteger lockBellState;
/* 设备型号 */
@property (nonatomic, copy, readonly) NSString *model;

@end

NS_ASSUME_NONNULL_END
