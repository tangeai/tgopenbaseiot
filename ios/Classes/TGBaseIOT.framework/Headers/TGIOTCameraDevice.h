//
//  TGIOTCameraDevice.h
//  TGIOT
//
//  Created by Darren on 2018/12/25.
//  Copyright © 2018年 Darren. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGCameraDeviceModel.h"
#import "TGCameraDefine.h"
#import "TGBaseIOTDefine.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import "TGVideoCamera.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TGSDCardRecordListBlock)(const char * __nullable data,int ctrolType,int errorCode);

@class TGCameraDeviceModel,TGIOTCameraDevice,TGDeviceAlarmSoundModel,DACameraP2PVideoData,DACameraP2PAudioData,TGMoveDetectZoneModel,TGMoveDetectPointModel,TGDevicePSPModel,TGWatchPosModel,DAMP4RecordManager,DAAudioUnitPCMPlayer,DAAudioSessionManager,TGDeviceLightModel,TGHintToneModel,TGDeviceTrackModel,TGMoveDetectPolygonModel,TGResolutionModel,TGTimerTaskModel;

@protocol TGIOTCameraDeviceDelegate <NSObject>

@optional
- (void)camera:(TGIOTCameraDevice *)camera didConnectSessionStatusChanged:(TGConnectSessionStatus)sessionStatus;

/// 接收指令方法
/// - Parameters:
///   - camera: 设备交互实例
///   - type: 接收指令类型，一般分为指令类型，1，其他；指令类型一般指获取项,1一般指设置项，可用SMsgBaseResp来接收，其他可略去
///   - data: 数据
///   - size: 数据大小
- (void)camera:(TGIOTCameraDevice *)camera didReceiveIOCtrlWithType:(NSInteger)type Data:(const char*)data DataSize:(NSInteger)size;

- (void)camera:(TGIOTCameraDevice *)camera didPlayCameraLiveVideo:(DACameraP2PVideoData *)videoData;
- (void)camera:(TGIOTCameraDevice *)camera didPlayCameraSDCardVideo:(DACameraP2PVideoData *)videoData;

/// 直播流更新速率
/// - Parameters:
///   - camera: 设备交互实例
///   - bitRate: 字节每秒（B）
///   - frameRate: 帧每秒
- (void)camera:(TGIOTCameraDevice *)camera didLiveVideoBpsUpdateWithBitRate:(unsigned int)bitRate frameRate:(unsigned int)frameRate;

- (void)camera:(TGIOTCameraDevice *)camera didRecordWithRecordType:(TGVideoRecordType)type second:(NSInteger)second;
- (void)camera:(TGIOTCameraDevice *)camera didStopRecordWithRecordType:(TGVideoRecordType)type filePath:(NSString * _Nonnull)filePath;

@end

@interface TGIOTCameraDevice : NSObject

@property (nonatomic, weak) id<TGIOTCameraDeviceDelegate> delegate;
@property (nonatomic, copy) void (^receiveCtrolCallBack) (int ctrolType, int errorCode);
@property (nonatomic, copy) void (^sendCtrolCallBack) (int ctrolType, int errorCode);
@property (nonatomic, strong) TGCameraDeviceModel *device;
@property (nonatomic, copy, nullable) void(^connectCallback)(TGConnectSessionStatus sessionStatus);
@property (nonatomic, assign) TGConnectSessionStatus sessionStatus;
@property (nonatomic, assign) TGDeviceConnectMode connectMode;
@property (nonatomic, assign) BOOL isNeedReconnect;
@property (nonatomic, assign) NSInteger maxReconnectCount;

@property (nonatomic, assign) BOOL isChannelZeroSwitchingCamera;
@property (nonatomic, assign) BOOL isChannelOneSwitchingCamera;
@property (nonatomic, assign) BOOL isChannelZeroReceiveFlagFrame;
@property (nonatomic, assign) BOOL isChannelOneReceiveFlagFrame;
@property (nonatomic, assign) BOOL isChannelZeroStepOneComplete;
@property (nonatomic, assign) BOOL isChannelOneStepOneComplete;

+ (instancetype)camneraWithDevice:(TGCameraDeviceModel *)device;
- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;

#pragma mark - deviceConnect 设备连接

// 连接设备
- (void)connectDevice;
- (void)connectWithCallback:(void(^)(TGConnectSessionStatus sessionStatus))callback;
// 退出连接
- (void)exitConnectedSession;
// 发送自定义指令
- (void)sendIOCtrl:(int)controlCMD Data:(char *)buffer DataSize:(int)size;

#pragma mark - 实时直播

// 使用0通道进行直播
- (void)startLiveChannelZeroVideoWithResolution:(TGResolutionModel *)resolution;
// 停止0通道直播
- (void)stopLiveChannelZeroVideo;
// 开启音频直播
- (void)startCameraLiveAudio;
// 关闭音频直播
- (void)stopCameraLiveAudio;
// 开启1通道视频直播 （一般双摄会使用到）
- (void)startLiveChannelOneVideoWithResolution:(TGResolutionModel *)resolution;
// 关闭1通道视频直播
- (void)stopLiveChannelOneVideo;
// 开启对讲
- (void)startDeviceLiveSpeak;
// 关闭对讲
- (void)stopDeviceLiveSpeak;

// 开始实时录制，请搭配使用stopCameraLiveRecord停止录制
// 已废弃，请使用新接口startCameraVideoRecordWithFileName，指定录制通道，不指定默认TGVideoRecordType_LiveChannelZero
- (void)startCameraLiveRecordWithFileName:(NSString *)fileName;
// 停止实时录制，请搭配使用startCameraLiveRecordWithFileName
// 已废弃，请使用新接口stopCameraVideoRecord停止录制
- (void)stopCameraLiveRecord;

// 开启双向视频
- (void)startDeviceLiveSpeakAndVideo:(TGVideoConfigModel *)model;
// 关闭双向视频
- (void)stopDeviceLiveSpeakAndVideo;

#pragma mark - sd卡
// 获取卡录像列表返回以TGCardEventModel为单元的数组，数组为空则无数据,normalArray为全时录像，eventArray为事件录像
- (void)getCameraSDCardRecordModelListWithDate:(NSString *)date successBlock:(void(^)(NSArray *normalArray, NSArray *eventArray))successBlock;
// 获取卡录像列表，返回数据，可自行解析
- (void)getCameraSDCardRecordListWithDate:(NSString *)date callBack:(void(^__nullable)(const char *data,int ctrolType,int errorCode))callBack;
// 设置当前时间点的卡录像播放资源
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint;
// 播放卡录像
- (void)startCameraSDCardPlay;
// 暂停卡录像
- (void)pauseCameraSDCardPlay;
// 继续播放卡录像
- (void)continueCameraSDCardPlay;
// 停止卡录像播放
- (void)stopCameraSDCardPlay;

// 开始卡回放录制，请搭配使用stopCameraSDCardRecord停止录制
// 已废弃，请使用新接口startCameraVideoRecordWithFileName，指定录制通道，不指定默认TGVideoRecordType_SDCardChannelZero
- (void)startCameraSDCardRecordWithFileName:(NSString *)fileName;
// 停止卡回放录制，请搭配使用stopCameraSDCardRecord
// 已废弃，请使用新接口stopCameraVideoRecord停止录制
- (void)stopCameraSDCardRecord;

// 静音
- (void)cameraSDCardMute;
// 取消静音
- (void)cancleCameraSDCardMute;
// 格式化SD卡
- (void)formatSDCard;
// 查询SD卡状态
- (void)getSDCardSatue;
// 设置SD卡录像模式
- (void)setSDCardVideoRecordMode:(int)mode;
// 录像模式 设备唤醒后的最大工作时长(单位：秒). 0为一直工作
- (void)getSdCardEventRecordDuration;
- (void)setSDCardEventRecordDuration:(int)duration;
// 录像清晰度 SD卡录像清晰度:0-高清，1-标清
- (void)getSdCardVideoQuality;
- (void)setSDCardVideoQuality:(int)quality;
// 倍数播放 卡录像1、2、4倍
- (void)setSDCardPlaySpeedLevel:(TGCameraPlaySpeedLevel)level;

// 开始录制
- (void)startCameraVideoRecordWithFileName:(NSString *)fileName recordType:(TGVideoRecordType)recordType;
// 停止录制
- (void)stopCameraVideoRecord;

#pragma mark - deviceSetting 设置
// 设备信息
- (void)getDeviceInfoCMD;
// 防闪烁
- (void)getEnvInfoCMD;
// 视频清晰度
- (void)getStreamCtrlCMD;
// 视频翻转
- (void)getVideoFlipCtrlCMD;
// 储存卡录像模式
- (void)getRecordTypeCMD;
// 设置50HZ，60HZ
- (void)setDeviceFrequency:(ENUM_ENVIRONMENT_MODE)mode;

// 设置视频高清低清-0通道
- (void)setLiveVideoQuality:(ENUM_QUALITY_LEVEL)level;
// 设置视频高清低清-1通道，画中画
- (void)setLivePIPVideoQuality:(ENUM_QUALITY_LEVEL)level;
// 设置屏幕翻转（0-3） 
- (void)setVideoFlipMode:(int)mode;
// 获取Wifi列表
- (void)getWifiList;
// 连接Wifi(V2版本废弃)
- (void)connectToWifiWithSSID:(NSString *)ssid passwd:(NSString *)passwd userId:(NSString *)userId bindToken:(NSString *)bindToken;
// 连接Wifi
- (void)connectToWifiWithSSID:(NSString *)ssid passwd:(NSString *)passwd userId:(NSString *)userId;
// 查询设备硬件能力
- (void)getDeviceFeature;
// 查询设备移动追踪模式
- (void)getDeviceMoveTrack;
// 设置设备移动追踪模式
- (void)setDeviceMoveTrackMode:(int)mode;
// 查询设备夜视模式
- (void)getDeviceDayNight;
// 设置设备夜视模式
- (void)setDeviceDayNight:(int)mode;
//查询设备白光灯模式
- (void)getDeviceWhiteLight;
//设置设备白光灯模式
- (void)setDeviceWhiteLight:(int)mode;
//重启设备
- (void)rebootDevice;
// 云台短按操作
- (void)devicePTZShortTurnToDirectionWithChannel:(TGPlayChannelType)channel direction:(TGPTZViewTurnDirection)direction;
// 云台长按操作
- (void)devicePTZLongTurnToDirectionWithChannel:(TGPlayChannelType)channel direction:(TGPTZViewTurnDirection)direction;
// 云台长按结束
- (void)devicePTZLongTurnStopWithChannel:(TGPlayChannelType)channel;
// 设置云台位置
- (void)devicePTZMoveWithPSPModel:(TGDevicePSPModel *)model;
// 设置预置位置
- (void)createPSPWithModel:(TGDevicePSPModel *)model;
// 删除预置位置
- (void)deletePSPWithArray:(NSArray <TGDevicePSPModel *>*)pspArray;
// 获取守望点
- (void)getDeviceWatchPosWithChannel:(TGPlayChannelType)channel;
// 设置守望点
- (void)setDeviceWatchPosWithModel:(TGWatchPosModel *)model;
//查询上传云录像清晰度
- (void)getCloudVideoQuality;
//设置上传云录像清晰度
- (void)setCloudVideoQuality:(int)quality;
//查询设备当前连接的WiFi
- (void)getDeviceCurrentSsid;
//查询设备麦克风开关
- (void)getMicrophoneMuteState;
//设置设备麦克风开关
- (void)setDeviceMicrophoneMuteState:(int)state;
//查询设备蜂鸣器开关
- (void)getDeviceBuzzer;
//设置设备蜂鸣器开关
- (void)setDeviceBuzzerMode:(int)mode;
//获取移动侦测
- (void)getMoveDetect;
// 移动侦测灵敏度
- (void)setMoveDetectSensitivity:(int)sensitivity;
// 设置移动侦测区域
- (void)setMoveDetectZonesWithZoneArray:(NSArray <TGMoveDetectZoneModel *>*)zonesArray;
- (void)setMoveDetectPolygonWithPolygonArray:(NSArray <TGMoveDetectPolygonModel *>*)polygonsArray excludeZone:(BOOL)excludeZone;
// 获取侦测区域状态
- (void)getMoveDetectAreaState;
// 设置侦测区域状态
- (void)setMoveDetectAreaStateWithState:(int)state;
// 获取人形/人脸边框设置状态
- (void)getMoveDetectBodyMarkState;
// 设置人形/人脸边框设置状态
- (void)setMoveDetectBodyMarkStateWithState:(int)state;
// 获取布防设置
- (void)getDefenceSetting;
// 设置布防设置
- (void)setDefenceSmart;
// 全天布放
- (void)setDefenceAllDay;
// 设置布放时段
- (void)setDefenceRegularWithItem:(DEFENCEITEM)item;
//AI人形追踪
- (void)setAIMoveTrackMode:(int)mode;
- (void)getAIMoveTrackMode;
//变焦控制
- (void)getDevicePtzPosWithChannel:(TGPlayChannelType)channel;
- (void)getDevicePSPWithChannel:(TGPlayChannelType)channel;
- (void)getDeviceMaxPSPCountWithChannel:(TGPlayChannelType)channel;

- (void)deviceShortZoomWithChannel:(TGPlayChannelType)channel direction:(TGZoomTimesUnknownDirection)direction;
- (void)deviceLongZoomBeginWithChannel:(TGPlayChannelType)channel direction:(TGZoomTimesUnknownDirection)direction;
- (void)deviceLongZoomEndWithChannel:(TGPlayChannelType)channel direction:(TGZoomTimesUnknownDirection)direction;

- (void)cameraSupportZoomTimesZoomToZoomWithChannel:(TGPlayChannelType)channel zValue:(CGFloat)zValue;
// 获取画中画主面面通道
- (void)getDevicePrimaryClannel;
// 设置画中画主面面通道
- (void)setDevicePrimaryWithChannel:(TGPlayChannelType)channel;
// 获取设备开关状态
- (void)getCameraStatus;
// 设置设备开关状态
- (void)setCameraStatus:(int)status;

// 获取支持的报警音频文件格式信息
- (void)getAlarmToneInfo;
// 设置报警音频
- (void)setAlarmSoundWithModel:(TGDeviceAlarmSoundModel *)model;
// 播放当前报警声音
- (void)playCurrentAlarmSound;
// 使用model播放报警声音
- (void)playAlarmSoundWithModel:(TGDeviceAlarmSoundModel *)model;

// 获取状态灯
- (void)getDeviceLedStatus;
// 设置状态灯
- (void)setDeviceLedStatus:(int)status;

// 获取电池电量
- (void)getBatteryStatus;
// 获取wifi/4g信号强度
- (void)getWifiSignalLevel;
// 获取g-sensor设置
- (void)getDrivingGsensorSensitive;
// 设置g-sensor
- (void)setDrivingGsensorSensitive:(int)sensitive;
// 获取停车监控
- (void)getParkingGsensorSensitive;
// 设置停车监控
- (void)setParkingGsensorSensitive:(int)sensitive;
// 获取Pir灵敏度
- (void)getPIRSensitive;
// 设置Pir灵敏度
- (void)setPIRSensitive:(int)sensitive;

//获取设备拾音器灵敏度
- (void)getDeviceMicSensitivity;
- (void)setDeviceMicWithSensitivity:(int)sensitivity;
//获取设备喇叭音量
- (void)getDeviceSpeakerVolume;
- (void)setDeviceSpeakerVolume:(int)volume;

// 获取报警灯状态
- (void)getAlarmLightStatus;
// 设置报警灯状态
- (void)setAlarmLightStatus:(int)status;
// 低功耗设备暂停休眠
- (void)deviceInterruptSleep;
// 低功耗设备恢复休眠
- (void)deviceRestoreSleep;
// 获取人形过滤
- (void)getAIStatus;
// 设置人形过滤
- (void)setAIStatusWithMask:(unsigned int)mask flags:(unsigned int)flags;
// 查询麦克风开关
- (void)getDeviceMicMuteMode;

// 门铃接听
- (void)answerDoorbellDevice;
// 门铃接听拒绝
- (void)rejectDoorbellDevice;
// 挂断门铃
- (void)handUpDoorbellDevice;
// 获取OSD 设置
- (void)getDeviceOSD;
// 设置OSD
- (void)setOSDWithItemDict:(NSMutableDictionary *)itemDict;
// 获取事件使能状态
- (void)getSoundEventState;
// 设置事件使能状态
- (void)setSoundEventWithState:(int)state;
// 获取延时摄像设置
- (void)getTimeLapseState;
// 设置延时摄像设置

- (void)setTimeLapseWithState:(int)state interval:(int)interval;
// 获取门(锁状态
- (void)getLockBellStatus;
// 使用密码开锁
- (void)openLockBellWithPassword:(NSString *)password;
// 获取跟踪功能特写设置
- (void)getEnableCloseUp;
// 设置跟踪功能特写设置
- (void)setCloseUpModeWithMode:(int)mode;

// 获取灯状态
- (void)getDeviceLightState;
// 设置灯状态
- (void)setDeviceLightWithModel:(TGDeviceLightModel *)model;

// 获取坐姿检测灵敏度
- (void)getSitDetectSensitive;
- (void)setSitDetectSensitive:(int)sensitive;
//获取提示音
- (void)getDeviceHintTone;
- (void)setDeviceHintToneWithModel:(TGHintToneModel *)model;
// 获取设备端运行状态（是否支持该项状态，例如录像状态，如要查询当前状态 可以用 videoData 中的exFlags字段来判断）
- (void)getDeviceRecordState;
// 巡航设置
- (void)getDeviceMaxTrackCountWithChannel:(TGPlayChannelType)channel;
- (void)getDeviceTrackWithChannel:(TGPlayChannelType)channel;
- (void)startTrackWithModel:(TGDeviceTrackModel *)model;
- (void)stopTrackWithModel:(TGDeviceTrackModel *)model;
- (void)setTrackStayTimeWithTime:(NSInteger)time channel:(int)channel;
- (void)deleteTracksWithArray:(NSArray <TGDeviceTrackModel *>*)trackArray;
- (void)createTrackWithModel:(TGDeviceTrackModel *)model;
// 获取提示音开关
- (void)getDeviceVoicePrompt;
- (void)setDeviceVoicePromptMode:(int)mode;
// 获取停车监控开关
- (void)getParkMonitorStatus;
- (void)setParkMonitorStatus:(int)status;
// 获取停车监控设置
- (void)getParkMonitorSettings;
// 设置停车监控工作时间
- (void)setParkMonitorWorkTime:(int)workTime;
// 设置停车监控灵敏度
- (void)setParkMonitorSensitive:(int)sensitive;
// 图像内云台定位
- (void)setLocInPicWithChannel:(TGPlayChannelType)channel pos:(PtzPos)pos;

- (void)deviceShortFocusWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusBeginWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusEndWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)getTimerTaskWithObject:(unsigned int)object identity:(unsigned int)identity;
- (void)saveTimerTaskWithTaskArray:(NSArray <TGTimerTaskModel *>*)taskArray object:(unsigned int)object identity:(unsigned int)identity;
- (void)resetDevicePTZWithChannel:(TGPlayChannelType)channel;

@end

NS_ASSUME_NONNULL_END
