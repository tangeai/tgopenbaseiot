//
//  TGDeviceCacheProtocols.h
//  TGIOT
//
//  Created by Darren on 2021/9/27.
//

#import <UIKit/UIKit.h>
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TGDeviceCacheProtocols <NSObject>

/* 实时是否静音 */
@property (nonatomic, assign, readonly) BOOL isLiveAudioMute;
/* 卡录像是否静音 */
@property (nonatomic, assign, readonly) BOOL isSDCardPlaybackAudioMute;
/* 云录像是否静音 */
@property (nonatomic, assign, readonly) BOOL isCloudPlaybackAudioMute;
/* 4G设备多长时间APP休眠 */
@property (nonatomic, assign, readonly) NSInteger sleepInterval;
@property (nonatomic, assign, readonly) BOOL isNoticeRecharge;
/* 实时画中画是否显示 */
@property (nonatomic, assign, readonly) BOOL isLivePictureInPictureShow;
/* 云录像画中画是否显示 */
@property (nonatomic, assign, readonly) BOOL isCloudPictureInPictureShow;
/* 卡录像画中画是否显示 */
@property (nonatomic, assign, readonly) BOOL isSDCardPictureInPictureShow;
@property (nonatomic, assign, readonly) BOOL isSupportFlagsFixPosition;
/* 告警消息界面选择全部设备时上一次选择的消息类型 */
@property (nonatomic, strong, readonly) NSArray *msgTypeSelectArray;
/* 实时通道0画面宽度 */
@property (nonatomic, assign, readonly) NSInteger liveChannelZeroWidth;
/* 实时通道0画面高度 */
@property (nonatomic, assign, readonly) NSInteger liveChannelZeroHeight;
/* 实时通道1画面宽度 */
@property (nonatomic, assign, readonly) NSInteger liveChannelOneWidth;
/* 实时通道1画面高度 */
@property (nonatomic, assign, readonly) NSInteger liveChannelOneHeight;
/* 云录像通道0画面宽度 */
@property (nonatomic, assign, readonly) NSInteger cloudChannelZeroWidth;
/* 云录像通道0画面高度 */
@property (nonatomic, assign, readonly) NSInteger cloudChannelZeroHeight;
/* 云录像通道1画面宽度 */
@property (nonatomic, assign, readonly) NSInteger cloudChannelOneWidth;
/* 云录像通道1画面高度 */
@property (nonatomic, assign, readonly) NSInteger cloudChannelOneHeight;
/* 卡录像通道0画面宽度 */
@property (nonatomic, assign, readonly) NSInteger sdcardChannelZeroWidth;
/* 卡录像通道0画面高度 */
@property (nonatomic, assign, readonly) NSInteger sdcardChannelZeroHeight;
/* 卡录像通道1画面宽度 */
@property (nonatomic, assign, readonly) NSInteger sdcardChannelOneWidth;
/* 卡录像通道1画面高度 */
@property (nonatomic, assign, readonly) NSInteger sdcardChannelOneHeight;
/* 是否显示电量 */
@property (nonatomic, assign, readonly) BOOL isShowEnergy;
/* 是否显示录像 */
@property (nonatomic, assign, readonly) BOOL isShowRecordState;
/* 是否显示码率 */
@property (nonatomic, assign, readonly) BOOL isShowBitRate;
/* 是否显示信号强度 */
@property (nonatomic, assign, readonly) BOOL isShowSignalLevel;
/* 是否显示帧率 */
@property (nonatomic, assign, readonly) BOOL isShowFrameRate;
/* 台灯设备是否已经提示端正坐姿 */
@property (nonatomic, assign, readonly) BOOL isLampDeviceTipSit;
/* 实时通道1清晰度 */
@property (nonatomic, assign, readonly) ENUM_QUALITY_LEVEL liveChannelOneQuality;

@end

NS_ASSUME_NONNULL_END
