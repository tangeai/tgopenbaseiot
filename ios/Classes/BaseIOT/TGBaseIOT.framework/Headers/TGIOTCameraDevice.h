//
//  TGIOTCameraDevice.h
//  TGBaseIOT
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
#import "TGCommondDefineHeader.h"
#import "TGDeviceCommodModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TGSDCardRecordListBlock)(const char * __nullable data,int ctrolType,int errorCode);
typedef void(^TGSDCardRecordFileStartBlock)(NSInteger startTime,DACameraP2PVideoData *videoData);
typedef void(^TGSDCardRecordFileEndBlock)(NSInteger endTime,DACameraP2PVideoData *videoData);

@class TGCameraDeviceModel,TGIOTCameraDevice,TGDeviceAlarmSoundModel,DACameraP2PVideoData,DACameraP2PAudioData,TGMoveDetectZoneModel,TGMoveDetectPointModel,TGDevicePSPModel,TGWatchPosModel,DAMP4RecordManager,DAAudioUnitPCMPlayer,DAAudioSessionManager,TGDeviceLightModel,TGHintToneModel,TGDeviceTrackModel,TGMoveDetectPolygonModel,TGResolutionModel,TGTimerTaskModel;

@protocol TGIOTCameraDeviceDelegate <NSObject>

@optional

/// 连接状态代理回掉
/// - Parameters:
///   - camera: 备交互实例
///   - sessionStatus: 连接状态
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

/// 通过命令和视频通道获取自定义信息 （需要实时推送的部分信息）
/// - Parameters:
///   - manager: 设备交互实例
///   - model: 自定义信息model
- (void)camera:(TGIOTCameraDevice *)camera didReceiveNotification:(TGDeviceNotificationModel *)model;

/// 麦克风采集返回的原始数据
/// - Parameters:
///   - data: 数据
///   - length: 长度
///   - config: 配置项，此项不用设置，直接使用即可
- (void)tg_audioSessionManagerDidRecordWithData:(void *)data length:(unsigned int)length config:(DAAudioConfigModel *)config;
/// 播放器缓存开始--实时播放
- (void)camera:(TGIOTCameraDevice *)camera didReceiveVideoCacheStart:(DACameraP2PVideoData *)videoData;
/// 播放器缓存结束--实时播放
- (void)camera:(TGIOTCameraDevice *)camera didReceiveVideoCacheEnd:(DACameraP2PVideoData *)videoData;
/// sd播放器缓存开始--实时播放
- (void)camera:(TGIOTCameraDevice *)camera didReceiveSdVideoCacheStart:(DACameraP2PVideoData *)videoData;
/// sd播放器缓存结束--实时播放
- (void)camera:(TGIOTCameraDevice *)camera didReceiveSdVideoCacheEnd:(DACameraP2PVideoData *)videoData;
// sd直播播完
- (void)cameraSdVideoEnd:(TGIOTCameraDevice *)camera;

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

@property (nonatomic, strong) NSMutableDictionary *commondSuccessDataResqArray;
@property (nonatomic, strong) NSMutableDictionary *commondFailDataResqArray;

+ (instancetype)cameraWithDevice:(TGCameraDeviceModel *)device;
- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;

#pragma mark - deviceConnect 设备连接

// 连接设备
- (void)connectDevice;
- (void)connectWithCallback:(void(^)(TGConnectSessionStatus sessionStatus))callback;
// 退出连接
- (void)exitConnectedSession;
// 发送自定义指令
- (void)sendIOCtrl:(int)controlCMD Data:(char *)buffer DataSize:(int)size;

#pragma mark - 缓存设置

// 设置缓冲空间（直播和卡录像）例如 ：100 * 1024 * 1024 ；100M 设置0则不起用缓存，默认0
- (void)setCacheSize:(NSUInteger)cacheSize;
// 设置缓冲时间（直播和卡录像），单位s
- (void)setCacheBufferTime:(NSTimeInterval)time;
//音视频通话缓冲通道设置 注，默认是16000，如果音视频通话过程卡顿可以调整该参数，参数需>16000,例如设置为16000*1.8；调大后将优先保证音频，缓冲内将丢视频帧；如果>channelBufferSize,将开始音视频上传丢帧
- (void)setChannelBufferSize:(unsigned int)channelBufferSize;
// 获取服务器差值
- (void)getFromServerSynchronizationTime;
// 获取服务器差值 单位毫米支持正负数
- (void)makeServerSynchronizationTime:(int)time;

#pragma mark - 音视频同步
// 默认是开启状态；音视频同步设置，enable=YES，将开始音视频同步，当音视频时差在300s内将音频丢帧 注》对于低功耗设备或者网络差的设备可以不开启此功能，优先保证音频不卡顿，但会造成音频略有延迟
- (void)videoAndAudioSynchronization:(BOOL)enable;

#pragma mark - 实时性要求
// 默认是开启状态；即保持实时性，如果设备网络能力较差可以关闭，关闭可以保持流畅性，但直播视频会有延时现象
- (void)setClosePunctuality:(BOOL)enable;

#pragma mark - 实时直播

/**
 * 指定清晰度播放视频通道0实时视频，请搭配使用stopLiveChannelZeroVideo方法停止播放
 * @param resolution 清晰度
 * 已废弃，请使用新接口startLiveVideoWithResolution:channel:，指定播放通道，不指定默认TGPlayChannelType_LiveChannelZero
 */
- (void)startLiveChannelZeroVideoWithResolution:(TGResolutionModel *)resolution DEPRECATED_MSG_ATTRIBUTE("Use -startLiveVideoWithResolution:channel: instead");
/**
 * 停止播放视频通道0实时视频，请搭配使用startLiveChannelZeroVideoWithResolution:方法
 * 已废弃，请使用新接口stopLiveVideoWithChannel:，指定播放通道
 */
- (void)stopLiveChannelZeroVideo DEPRECATED_MSG_ATTRIBUTE("Use -stopLiveVideoWithChannel: instead");

// 开启音频直播
- (void)startCameraLiveAudio;
// 关闭音频直播
- (void)stopCameraLiveAudio;
// 静音 yes 为静音 no为不静音
- (void)liveMuteOpen:(BOOL)open;
/// 音频播放降噪水平设置
/// @param levelType 降噪水平参数，默认是最高
- (void)setNoiseReductionLevel:(TGNoisereDuctionType)levelType;
/**
 * 指定清晰度播放视频通道1实时视频，请搭配使用stopLiveChannelOneVideo方法停止播放
 * @param resolution 清晰度
 * 已废弃，请使用新接口startLiveVideoWithResolution:channel:，指定播放通道，不指定默认TGPlayChannelType_LiveChannelZero
 */
- (void)startLiveChannelOneVideoWithResolution:(TGResolutionModel *)resolution DEPRECATED_MSG_ATTRIBUTE("Use -startLiveVideoWithResolution:channel: instead");
/**
 * 停止播放视频通道1实时视频，请搭配使用startLiveChannelOneVideoWithResolution:方法
 * 已废弃，请使用新接口stopLiveVideoWithChannel:，指定播放通道
 */
- (void)stopLiveChannelOneVideo DEPRECATED_MSG_ATTRIBUTE("Use -stopLiveVideoWithChannel: instead");

// 开启对讲
- (void)startDeviceLiveSpeak;
// 关闭对讲
- (void)stopDeviceLiveSpeak;
/// 启动自定义语音，启动后将会在代理中返回录制的原始语音数据，需要客户编辑好数据后再传输（tg_setAudioSessionManagerDidRecordWithData）给设备
/// - Parameter Open: yes打开，no关闭
- (void)openAudioDeine:(BOOL)Open;
/// 传输接口，用于自定义语音后把数据传输给设备
/// - Parameters:
///   - data: 编辑后的data
///   - length: 编辑后的长度
///   - config: 配置，保持和代理中的返回一致即可
- (void)tg_setAudioSessionManagerDidRecordWithData:(void *)data length:(unsigned int)length config:(DAAudioConfigModel *)config;

// 开启双向视频
- (void)startDeviceLiveSpeakAndVideo:(TGVideoConfigModel *)model;
// 切换摄像头
- (void)switchSpeakAndVideoCamera;
// 关闭双向视频
- (void)stopDeviceLiveSpeakAndVideo;

#pragma mark - 设备基础信息

// 查询设备硬件能力
- (void)getDeviceFeature;
// 设备信息
- (void)getDeviceInfoCMD;

#pragma mark - sd卡
// 获取卡录像列表返回以TGCardEventModel为单元的数组，数组为空则无数据,array为全部录像
- (void)getAllCameraSDCardRecordModelListWithDate:(NSString *)date cardRecordOrderType:(TGCardRecordOrderType)type successBlock:(void(^)(NSArray *array))successBlock;
// 获取卡录像列表返回以TGCardEventModel为单元的数组，数组为空则无数据,normalArray为全时录像，eventArray为事件录像
- (void)getCameraSDCardRecordModelListWithDate:(NSString *)date cardRecordOrderType:(TGCardRecordOrderType)type successBlock:(void(^)(NSArray *normalArray, NSArray *eventArray))successBlock;
// 获取卡录像列表返回以TGCardEventModel为单元的数组，数组为空则无数据,normalArray为全时录像，eventArray为事件录像
- (void)getCameraSDCardRecordModelListWithDate:(NSString *)date successBlock:(void(^)(NSArray *normalArray, NSArray *eventArray))successBlock;
// 获取卡录像列表，返回数据，可自行解析
- (void)getCameraSDCardRecordListWithDate:(NSString *)date callBack:(TGSDCardRecordListBlock)callBack;
/// 设置播放模式
/// - Parameter type: 播放模式
- (void)setSDCardProductionMode:(TGSDCardPlayModelType)type;
///// 开启片段模式（实时返回卡列表某个片段的开始及结束监控,支持跨天播放）
///// - Parameters:
/////   - open: 是否开启，yes 实时返回卡列表某个片段的开始及结束监控,支持跨天播放  no 不支持监控
/////   - startBlock: 片段开始
/////   - endBlock: 片段结束
//- (void)openSdCardFileObserveEnable:(BOOL)open start:(TGSDCardRecordFileStartBlock)startBlock end:(TGSDCardRecordFileEndBlock)endBlock;
// 设置当前时间点的卡录像播放资源
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint;
// 设置当前时间点卡录像播放资源，可设置channel
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint channel:(int)channel;
// 设置当前时间点的卡录像播放资源
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint completeBlock:(void(^)(BOOL success))completeBlock;
// 设置当前时间点卡录像播放资源，可设置channel
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint channel:(int)channel completeBlock:(void(^)(BOOL success))completeBlock;

// 播放卡录像
- (void)startCameraSDCardPlay;
// 暂停卡录像
- (void)pauseCameraSDCardPlay;
// 继续播放卡录像
- (void)continueCameraSDCardPlay;
// 继续播放卡录像(非爱佳设备使用此方法)
- (void)continueCameraSDCardPlayWithTivs;
// 停止卡录像播放
- (void)stopCameraSDCardPlay;

/**
 * 开始实时录制，请搭配使用stopCameraLiveRecord方法停止录制
 * 已废弃，请使用新接口startCameraVideoRecordWithFileName:recordType:，指定录制通道，不指定默认TGVideoRecordType_LiveChannelZero
 */
- (void)startCameraLiveRecordWithFileName:(NSString *)fileName DEPRECATED_MSG_ATTRIBUTE("Use -startCameraVideoRecordWithFileName:recordType: instead");
/**
 * 停止实时录制，请搭配使用startCameraLiveRecordWithFileName:方法
 * 已废弃，请使用新接口stopCameraVideoRecord停止录制
 */
- (void)stopCameraLiveRecord DEPRECATED_MSG_ATTRIBUTE("Use -stopCameraVideoRecord instead");

/**
 * 开始卡回放录制，请搭配使用stopCameraSDCardRecord方法停止录制
 * 已废弃，请使用新接口startCameraVideoRecordWithFileName:recordType:，指定录制通道，不指定默认TGVideoRecordType_SDCardChannelZero
 */
- (void)startCameraSDCardRecordWithFileName:(NSString *)fileName DEPRECATED_MSG_ATTRIBUTE("Use -startCameraVideoRecordWithFileName:recordType: instead");
/**
 * 停止卡回放录制，请搭配使用startCameraSDCardRecordWithFileName:方法
 * 已废弃，请使用新接口stopCameraVideoRecord停止录制
 */
- (void)stopCameraSDCardRecord DEPRECATED_MSG_ATTRIBUTE("Use -stopCameraVideoRecord instead");

/**
 * 开始录制视频
 * @param fileName 文件名称
 * @param recordType 录制类型
 */
- (void)startCameraVideoRecordWithFileName:(NSString *)fileName recordType:(TGVideoRecordType)recordType;

/**
 * 开始录制指定分辨率的视频
 * @param fileName 文件名称
 * @param recordType 录制类型
 * @param width  宽
 * @param height 高
 */
- (void)startCameraVideoRecordWithFileName:(NSString *)fileName recordType:(TGVideoRecordType)recordType widthPixel:(int)width heightPixel:(int)height;

/**
 * 停止录制
 */
- (void)stopCameraVideoRecord;

/**
 * 按照指定清晰度播放指定通道实时视频
 * @param resolution 视频清晰度
 * @param channel 视频通道
 */
- (void)startLiveVideoWithResolution:(TGResolutionModel *)resolution channel:(TGPlayChannelType)channel;

/**
 * 设置指定通道实时视频清晰度
 * @param resolution 视频清晰度
 * @param channel 视频通道
 */
- (void)setLiveVideoResolution:(TGResolutionModel *)resolution channel:(TGPlayChannelType)channel;

/**
 * 停止播放指定通道实时视频
 * @param channel 视频通道
 */
- (void)stopLiveVideoWithChannel:(TGPlayChannelType)channel;

// 静音 yes 为静音 no为不静音
- (void)sdMuteOpen:(BOOL)open;
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

#pragma mark - deviceSetting 设置

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

/**
 * 设置视频通道0视频清晰度
 * @param level 视频清晰度
 * 已废弃，请使用新接口setLiveVideoResolution:channel:方法设置视频清晰度
 */
- (void)setLiveVideoQuality:(ENUM_QUALITY_LEVEL)level DEPRECATED_MSG_ATTRIBUTE("Use -setLiveVideoResolution:channel instead");
/**
 * 设置视频通道1视频清晰度
 * @param level 视频清晰度
 * 已废弃，请使用新接口setLiveVideoResolution:channel:方法设置视频清晰度
 */
- (void)setLivePIPVideoQuality:(ENUM_QUALITY_LEVEL)level DEPRECATED_MSG_ATTRIBUTE("Use -setLiveVideoResolution:channel instead");
// 设置屏幕翻转（0-3）
- (void)setVideoFlipMode:(int)mode;
// 获取Wifi列表
- (void)getWifiList;
// 连接Wifi(V2版本废弃)
- (void)connectToWifiWithSSID:(NSString *)ssid passwd:(NSString *)passwd userId:(NSString *)userId bindToken:(NSString *)bindToken;
// 连接Wifi
- (void)connectToWifiWithSSID:(NSString *)ssid passwd:(NSString *)passwd userId:(NSString *)userId;

// 查询设备移动追踪模式
- (void)getDeviceMoveTrack;
// 设置设备移动追踪模式
- (void)setDeviceMoveTrackMode:(int)mode;
// 查询设备夜视模式
- (void)getDeviceDayNight;
// 设置设备夜视模式
- (void)setDeviceDayNight:(int)mode;
// 查询设备白光灯模式
- (void)getDeviceWhiteLight;
// 设置设备白光灯模式
- (void)setDeviceWhiteLight:(int)mode;
// 重启设备
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
// 查询上传云录像清晰度
- (void)getCloudVideoQuality;
// 设置上传云录像清晰度
- (void)setCloudVideoQuality:(int)quality;
// 查询设备当前连接的WiFi
- (void)getDeviceCurrentSsid;
// 查询设备麦克风开关
- (void)getMicrophoneMuteState;
// 设置设备麦克风开关
- (void)setDeviceMicrophoneMuteState:(int)state;
// 查询设备蜂鸣器开关
- (void)getDeviceBuzzer;
// 设置设备蜂鸣器开关 0-关闭 1-开启
- (void)setDeviceBuzzerMode:(int)mode;
// 获取移动侦测
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
// AI人形追踪
- (void)setAIMoveTrackMode:(int)mode;
- (void)getAIMoveTrackMode;

- (void)getDevicePtzPosWithChannel:(TGPlayChannelType)channel;
- (void)getDevicePSPWithChannel:(TGPlayChannelType)channel;
- (void)getDeviceMaxPSPCountWithChannel:(TGPlayChannelType)channel;
// 变焦控制
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

// 获取设备拾音器灵敏度
- (void)getDeviceMicSensitivity;
- (void)setDeviceMicWithSensitivity:(int)sensitivity;
// 获取设备喇叭音量
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
// 设置事件使能状态，0关 1开
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
// 获取提示音
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

// 聚焦
- (void)deviceShortFocusWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusBeginWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusEndWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)getTimerTaskWithObject:(unsigned int)object identity:(unsigned int)identity;
- (void)saveTimerTaskWithTaskArray:(NSArray <TGTimerTaskModel *>*)taskArray object:(unsigned int)object identity:(unsigned int)identity;
- (void)resetDevicePTZWithChannel:(TGPlayChannelType)channel;

#pragma mark -- debugLog
// 慎用，启用后直播会重复录制30s到沙盒
- (void)openDebugLiveLog:(BOOL)debugOpen;


@end

NS_ASSUME_NONNULL_END
