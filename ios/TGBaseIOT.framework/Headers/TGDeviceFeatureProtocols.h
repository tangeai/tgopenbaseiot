//
//  TGDeviceFeatureProtocols.h
//  TGIOT
//
//  Created by Darren on 2021/9/27.
//
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class DAAudioConfigModel;

@protocol TGDeviceFeatureProtocols <NSObject>

/* 双目和画中画摄像机，两个镜头是联动的(即只有一个云台)*/
@property (nonatomic, assign, readonly) BOOL devicePTZLinked;
/* 通道0画面是否支持云台(水平方向和垂直方向) */
@property (nonatomic, assign, readonly) BOOL channelZeroPTZEnable;
/* 通道0画面是否仅支持水平方向云台 */
@property (nonatomic, assign, readonly) BOOL channelZeroPTZHorizontalOnly;
/* 通道0画面是否仅支持垂直方向云台 */
@property (nonatomic, assign, readonly) BOOL channelZeroPTZVerticalOnly;
/* 通道1画面是否支持云台(水平方向和垂直方向) */
@property (nonatomic, assign, readonly) BOOL channelOnePTZEnable;
/* 通道1画面是否仅支持水平方向云台 */
@property (nonatomic, assign, readonly) BOOL channelOnePTZHorizontalOnly;
/* 通道1画面是否仅支持垂直方向云台 */
@property (nonatomic, assign, readonly) BOOL channelOnePTZVerticalOnly;
/* 通道0画面是否支持预置位 */
@property (nonatomic, assign, readonly) BOOL channelZeroPSPEnable;
/* 通道1画面是否支持预置位 */
@property (nonatomic, assign, readonly) BOOL channelOnePSPEnable;
/* 通道0画面是否支持看守位 */
@property (nonatomic, assign, readonly) BOOL channelZeroWatchPosEnable;
/* 通道1画面是否支持看守位 */
@property (nonatomic, assign, readonly) BOOL channelOneWatchPosEnable;
/* 通道0画面是否支持巡航 */
@property (nonatomic, assign, readonly) BOOL channelZeroTrackEnable;
/* 通道1画面是否支持巡航 */
@property (nonatomic, assign, readonly) BOOL channelOneTrackEnable;
/* 通道0画面是否支持枪球联动 */
@property (nonatomic, assign, readonly) BOOL channelZeroLocInPicEnable;
/* 通道1画面是否支持枪球联动 */
@property (nonatomic, assign, readonly) BOOL channelOneLocInPicEnable;
/* 通道0画面是否支持云台校准 */
@property (nonatomic, assign, readonly) BOOL channelZeroResetEnable;
/* 通道1画面是否支持云台校准 */
@property (nonatomic, assign, readonly) BOOL channelOneResetEnable;

/* 通道0画面变焦描述 */
@property (nonatomic, copy, readonly) NSString *channelZeroZoomString;
/* 通道1画面变焦描述 */
@property (nonatomic, copy, readonly) NSString *channelOneZoomString;
/* 通道0画面是否支持非滑动变焦 */
@property (nonatomic, assign, readonly) BOOL channelZeroZoomTimeUnknownEnable;
/* 通道1画面是否支持非滑动变焦 */
@property (nonatomic, assign, readonly) BOOL channelOneZoomTimeUnknownEnable;
/* 通道0画面是否支持滑动变焦 */
@property (nonatomic, assign, readonly) BOOL channelZeroZoomTimesKnownEnable;
/* 通道1画面是否支持滑动变焦 */
@property (nonatomic, assign, readonly) BOOL channelOneZoomTimesKnownEnable;
/* 通道0画面是否支持双目(远景、近景) */
@property (nonatomic, assign, readonly) BOOL channelZeroDoubleLensesEnable;
/* 通道1画面是否支持双目(远景、近景) */
@property (nonatomic, assign, readonly) BOOL channelOneDoubleLensesEnable;
/* 通道0画面是否支持聚焦 */
@property (nonatomic, assign, readonly) BOOL channelZeroFocusEnable;
/* 通道1画面是否支持聚焦 */
@property (nonatomic, assign, readonly) BOOL channelOneFocusEnable;
/* 通道0画面默认清晰度，返回-1表示为配置 */
@property (nonatomic, assign, readonly) int channelZeroDefaultQuality;
/* 通道1画面默认清晰度，返回-1表示为配置 */
@property (nonatomic, assign, readonly) int channelOneDefaultQuality;

/* 是否支持对讲 */
@property (nonatomic, assign, readonly) BOOL deviceSpeakEnable;
/* 是否支持智能追踪 */
@property (nonatomic, assign, readonly) BOOL autoTrackEnable;
/* 是否支持夜视模式 */
@property (nonatomic, assign, readonly) BOOL dayNightEnable;
/* 是否支持夜视模式自动转换 */
@property (nonatomic, assign, readonly) BOOL dayNightAutoEnable;
/* 是否支持白光灯 */
@property (nonatomic, assign, readonly) BOOL doubleLightEnable;
/* 是否支持白光灯调节亮度 */
@property (nonatomic, assign, readonly) BOOL doubleLightDimEnable;
/* 是否支持白光灯定时设置 */
@property (nonatomic, assign, readonly) BOOL doubleLightTimerEnable;
/* 是否支持警戒语音 */
@property (nonatomic, assign, readonly) BOOL alertSoundEnable;
/* 是否支持侦测区域设置 */
@property (nonatomic, assign, readonly) BOOL moveDetectZonesEnable;
/* 是否支持侦测灵敏度设置 */
@property (nonatomic, assign, readonly) BOOL moveDetectSensitiveEnable;
/* 是否支持实时画面中显示侦测区域 */
@property (nonatomic, assign, readonly) BOOL moveDetectZonesVisibleEnable;
/* 是否支持侦测区域内显示人形框 */
@property (nonatomic, assign, readonly) BOOL moveDetectBodyMarkedEnable;
/* 是否支持布防设置 */
@property (nonatomic, assign, readonly) BOOL capDefenceEnable;
/* 是否支持仅检测画面变化 */
@property (nonatomic, assign, readonly) BOOL detectPictureOnlyEnable;
/* 是否支持设备开关 */
@property (nonatomic, assign, readonly) BOOL deviceStatusEnable;
/* 是否支持回放倍速播放 */
@property (nonatomic, assign, readonly) BOOL deviceSpeedEnable;
/* 是否支持设置警戒语音 */
@property (nonatomic, assign, readonly) BOOL alarmToneEnable;
/* 是否是低功耗设备 */
@property (nonatomic, assign, readonly) BOOL isBatteryDevice;
/* 是否是支持休眠唤醒低功耗设备 */
@property (nonatomic, assign, readonly) BOOL isBatterySupportAwake;
/* 是否是支持边放电边充电低功耗设备 */
@property (nonatomic, assign, readonly) BOOL isBatterySolarEnable;
/* 是否支持设置SD卡录像清晰度 */
@property (nonatomic, assign, readonly) BOOL isSDCardDefinitionSupport;
/* 是否支持状态灯 */
@property (nonatomic, assign, readonly) BOOL ledStatusEnable;
/* 是否支持画中画 */
@property (nonatomic, assign, readonly) BOOL isPictureInPictureEnable;
/* 是否是行车记录仪 */
@property (nonatomic, assign, readonly) BOOL isDriveDevice;
/* 是否支持画面旋转 */
@property (nonatomic, assign, readonly) BOOL rotateVideoEnable;
/* 是否支持PIR侦测灵敏度 */
@property (nonatomic, assign, readonly) BOOL pirSensitivityEnable;
/* 是否支持AiSwitch */
@property (nonatomic, assign, readonly) BOOL aiSwitchEnable;
/* 是否支持修改设备喇叭音量 */
@property (nonatomic, assign, readonly) BOOL speakerVolumeModifiable;
/* 是否支持警戒灯 */
@property (nonatomic, assign, readonly) BOOL alarmLightEnable;
/* 是否支持ENABLE_BT */
@property (nonatomic, assign, readonly) BOOL aiTrackModeEnable;
/* 是否有麦克风 */
@property (nonatomic, assign, readonly) BOOL isMicrophoneEnable;
/* 是否支持麦克风开关 */
@property (nonatomic, assign, readonly) BOOL isMicMuteEnable;
/* 麦克风是否支持拾音灵敏度调节 */
@property (nonatomic, assign, readonly) BOOL micSensitivityModifiable;
/* 是否支持OSD水印 */
@property (nonatomic, assign, readonly) BOOL isOSDWaterMarkEnable;
/* 是否支持缩时录影 */
@property (nonatomic, assign, readonly) BOOL isTimeLapseEnable;
/* 是否支持G-Sensor scene */
@property (nonatomic, assign, readonly) BOOL isGSensorSceneEnable;
/* 是否支持硬件AI人形追踪 */
@property (nonatomic, assign, readonly) BOOL capAIHwMoveTrackEnable;
/* 是否支持硬件AI特写追踪 */
@property (nonatomic, assign, readonly) BOOL capAIHwCloseUpTrackEnable;
/* 是否支持硬件AI人形放大 */
@property (nonatomic, assign, readonly) BOOL capAIHwHumanEnlargeEnable;
/* 是否需要APP选择画面 */
@property (nonatomic, assign, readonly) BOOL isNeedAppRotateVideo;
/* APP选择画面角度 */
@property (nonatomic, assign, readonly) CGFloat appRotateDegree;
/* 是否是台灯设备 */
@property (nonatomic, assign, readonly) BOOL lampDeviceEnable;
/* 是否是支持灯光的台灯设备 */
@property (nonatomic, assign, readonly) BOOL lampLightEnable;
/* 是否是支持坐姿检测的台灯设备 */
@property (nonatomic, assign, readonly) BOOL lampSitDetectEnable;
/* 是否有SD卡 */
@property (nonatomic, assign, readonly) BOOL isDeviceSDCardAvaiable;
/* 是否支持信号强度 */
@property (nonatomic, assign, readonly) BOOL signalLevelEnable;
/* 是否支持坐姿灵敏度 */
@property (nonatomic, assign, readonly) BOOL isSitSensitivityEnable;
/* 是否支持回声消除 */
@property (nonatomic, assign, readonly) BOOL isMicrophoneAECEnable;
/* 实时对讲语言参数配置 */
@property (nonatomic, strong, readonly) DAAudioConfigModel *liveSpeakConfig;
/* 呼叫超时时间 */
@property (nonatomic, assign, readonly) CGFloat callTimeoutInterval;
/* 呼叫最大持续时间 */
@property (nonatomic, assign, readonly) CGFloat callExistInterval;
/* 是否支持设备播报 */
@property (nonatomic, assign, readonly) BOOL voicePromptMuteEnable;
/* 是否支持停车监控设置 */
@property (nonatomic, assign, readonly) BOOL isParkMonitorEnable;

@end

NS_ASSUME_NONNULL_END
