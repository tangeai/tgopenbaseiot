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

NS_ASSUME_NONNULL_BEGIN

typedef void(^TGSDCardRecordListBlock)(const char * __nullable data,int ctrolType,int errorCode);

@class TGCameraDeviceModel,TGIOTCameraDevice,TGDeviceAlarmSoundModel,DACameraP2PVideoData,DACameraP2PAudioData,TGMoveDetectZoneModel,TGMoveDetectPointModel,TGDevicePSPModel,TGWatchPosModel,DAMP4RecordManager,DAAudioUnitPCMPlayer,DAAudioSessionManager,TGDeviceLightModel,TGHintToneModel,TGDeviceTrackModel,TGMoveDetectPolygonModel,TGResolutionModel,TGTimerTaskModel;

@protocol TGIOTCameraDeviceDelegate <NSObject>

@optional
- (void)camera:(TGIOTCameraDevice *)camera didConnectSessionStatusChanged:(TGConnectSessionStatus)sessionStatus;
- (void)camera:(TGIOTCameraDevice *)camera didReceiveIOCtrlWithType:(NSInteger)type Data:(const char*)data DataSize:(NSInteger)size;

- (void)camera:(TGIOTCameraDevice *)camera didPlayCameraLiveVideo:(DACameraP2PVideoData *)videoData;
- (void)camera:(TGIOTCameraDevice *)camera didPlayCameraSDCardVideo:(DACameraP2PVideoData *)videoData;

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

- (void)connectDevice;
- (void)connectWithCallback:(void(^)(TGConnectSessionStatus sessionStatus))callback;
- (void)exitConnectedSession;
- (void)sendIOCtrl:(int)controlCMD Data:(char *)buffer DataSize:(int)size;

- (void)startLiveChannelZeroVideoWithResolution:(TGResolutionModel *)resolution;
- (void)stopLiveChannelZeroVideo;
- (void)startCameraLiveAudio;
- (void)stopCameraLiveAudio;
- (void)startLiveChannelOneVideoWithResolution:(TGResolutionModel *)resolution;
- (void)stopLiveChannelOneVideo;

- (void)startDeviceLiveSpeak;
- (void)stopDeviceLiveSpeak;
- (void)startCameraLiveRecordWithFileName:(NSString *)fileName;
- (void)stopCameraLiveRecord;

- (void)getCameraSDCardRecordListWithDate:(NSString *)date callBack:(nullable TGSDCardRecordListBlock)callBack;
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint;

- (void)startCameraSDCardPlay;
- (void)stopCameraSDCardPlay;
- (void)startCameraSDCardRecordWithFileName:(NSString *)fileName;
- (void)stopCameraSDCardRecord;
- (void)cameraSDCardMute;
- (void)cancleCameraSDCardMute;

//设备信息
- (void)getDeviceInfoCMD;
//防闪烁
- (void)getEnvInfoCMD;
//视频清晰度
- (void)getStreamCtrlCMD;
//视频翻转
- (void)getVideoFlipCtrlCMD;
//储存卡录像模式
- (void)getRecordTypeCMD;
//设置50HZ，60HZ
- (void)setDeviceFrequency:(ENUM_ENVIRONMENT_MODE)mode;
//格式化SD卡
- (void)formatSDCard;
//设置SD卡录像模式
- (void)setSDCardVideoRecordMode:(int)mode;
//设置视频高清低清
- (void)setLiveVideoQuality:(ENUM_QUALITY_LEVEL)level;
- (void)setLivePIPVideoQuality:(ENUM_QUALITY_LEVEL)level;
//设置屏幕翻转
- (void)setVideoFlipMode:(int)mode;
//获取Wifi列表
- (void)getWifiList;
//连接Wifi
- (void)connectToWifiWithSSID:(NSString *)ssid passwd:(NSString *)passwd userId:(NSString *)userId bindToken:(NSString *)bindToken;
//查询设备硬件能力
- (void)getDeviceFeature;
//查询设备移动追踪模式
- (void)getDeviceMoveTrack;
//设置设备移动追踪模式
- (void)setDeviceMoveTrackMode:(int)mode;
//查询设备夜视模式
- (void)getDeviceDayNight;
//设置设备夜视模式
- (void)setDeviceDayNight:(int)mode;
//查询设备白光灯模式
- (void)getDeviceWhiteLight;
//设置设备白光灯模式
- (void)setDeviceWhiteLight:(int)mode;
//重启设备
- (void)rebootDevice;
//云台短按操作
- (void)devicePTZShortTurnToDirectionWithChannel:(TGPlayChannelType)channel direction:(TGPTZViewTurnDirection)direction;
//云台长按操作
- (void)devicePTZLongTurnToDirectionWithChannel:(TGPlayChannelType)channel direction:(TGPTZViewTurnDirection)direction;
//云台长按结束
- (void)devicePTZLongTurnStopWithChannel:(TGPlayChannelType)channel;
- (void)devicePTZMoveWithPSPModel:(TGDevicePSPModel *)model;
- (void)createPSPWithModel:(TGDevicePSPModel *)model;
- (void)deletePSPWithArray:(NSArray <TGDevicePSPModel *>*)pspArray;
- (void)getDeviceWatchPosWithChannel:(TGPlayChannelType)channel;
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
- (void)setMoveDetectSensitivity:(int)sensitivity;
- (void)setMoveDetectZonesWithZoneArray:(NSArray <TGMoveDetectZoneModel *>*)zonesArray;
- (void)setMoveDetectPolygonWithPolygonArray:(NSArray <TGMoveDetectPolygonModel *>*)polygonsArray excludeZone:(BOOL)excludeZone;
- (void)getMoveDetectAreaState;
- (void)setMoveDetectAreaStateWithState:(int)state;
- (void)getMoveDetectBodyMarkState;
- (void)setMoveDetectBodyMarkStateWithState:(int)state;
//获取布防设置
- (void)getDefenceSetting;
- (void)setDefenceSmart;
- (void)setDefenceAllDay;
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
- (void)getDevicePrimaryClannel;
- (void)setDevicePrimaryWithChannel:(TGPlayChannelType)channel;
- (void)getCameraStatus;
- (void)setCameraStatus:(int)status;
- (void)setSDCardPlaySpeedLevel:(TGCameraPlaySpeedLevel)level;
- (void)getAlarmToneInfo;
- (void)setAlarmSoundWithModel:(TGDeviceAlarmSoundModel *)model;
- (void)playCurrentAlarmSound;
- (void)playAlarmSoundWithModel:(TGDeviceAlarmSoundModel *)model;
- (void)getSdCardEventRecordDuration;
- (void)setSDCardEventRecordDuration:(int)duration;
- (void)getSdCardVideoQuality;
- (void)setSDCardVideoQuality:(int)quality;
- (void)getDeviceLedStatus;
- (void)setDeviceLedStatus:(int)status;
- (void)getBatteryStatus;
- (void)getWifiSignalLevel;
- (void)getDrivingGsensorSensitive;
- (void)setDrivingGsensorSensitive:(int)sensitive;
- (void)getParkingGsensorSensitive;
- (void)setParkingGsensorSensitive:(int)sensitive;
- (void)getPIRSensitive;
- (void)setPIRSensitive:(int)sensitive;
//获取设备拾音器灵敏度
- (void)getDeviceMicSensitivity;
- (void)setDeviceMicWithSensitivity:(int)sensitivity;
//获取设备喇叭音量
- (void)getDeviceSpeakerVolume;
- (void)setDeviceSpeakerVolume:(int)volume;
- (void)getAlarmLightStatus;
- (void)setAlarmLightStatus:(int)status;
- (void)deviceInterruptSleep;
- (void)deviceRestoreSleep;
- (void)getAIStatus;
- (void)setAIStatusWithMask:(unsigned int)mask flags:(unsigned int)flags;
- (void)getDeviceMicMuteMode;
- (void)answerDoorbellDevice;
- (void)rejectDoorbellDevice;
- (void)handUpDoorbellDevice;
- (void)getDeviceOSD;
- (void)setOSDWithItemDict:(NSMutableDictionary *)itemDict;
- (void)getSoundEventState;
- (void)setSoundEventWithState:(int)state;
- (void)getTimeLapseState;
- (void)setTimeLapseWithState:(int)state interval:(int)interval;
- (void)getLockBellStatus;
- (void)openLockBellWithPassword:(NSString *)password;
- (void)getEnableCloseUp;
- (void)setCloseUpModeWithMode:(int)mode;
- (void)getDeviceLightState;
- (void)setDeviceLightWithModel:(TGDeviceLightModel *)model;
- (void)getSitDetectSensitive;
- (void)setSitDetectSensitive:(int)sensitive;
- (void)getDeviceHintTone;
- (void)setDeviceHintToneWithModel:(TGHintToneModel *)model;
- (void)getDeviceRecordState;
- (void)getDeviceMaxTrackCountWithChannel:(TGPlayChannelType)channel;
- (void)getDeviceTrackWithChannel:(TGPlayChannelType)channel;
- (void)startTrackWithModel:(TGDeviceTrackModel *)model;
- (void)stopTrackWithModel:(TGDeviceTrackModel *)model;
- (void)setTrackStayTimeWithTime:(NSInteger)time channel:(int)channel;
- (void)deleteTracksWithArray:(NSArray <TGDeviceTrackModel *>*)trackArray;
- (void)createTrackWithModel:(TGDeviceTrackModel *)model;
- (void)getDeviceVoicePrompt;
- (void)setDeviceVoicePromptMode:(int)mode;
- (void)getParkMonitorStatus;
- (void)setParkMonitorStatus:(int)status;
- (void)getParkMonitorSettings;
- (void)setParkMonitorWorkTime:(int)workTime;
- (void)setParkMonitorSensitive:(int)sensitive;
- (void)setLocInPicWithChannel:(TGPlayChannelType)channel pos:(PtzPos)pos;
- (void)deviceShortFocusWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusBeginWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusEndWithChannel:(TGPlayChannelType)channel direction:(TGZoomFocusDirection)direction;
- (void)getTimerTaskWithObject:(unsigned int)object identity:(unsigned int)identity;
- (void)saveTimerTaskWithTaskArray:(NSArray <TGTimerTaskModel *>*)taskArray object:(unsigned int)object identity:(unsigned int)identity;
- (void)resetDevicePTZWithChannel:(TGPlayChannelType)channel;

@end

NS_ASSUME_NONNULL_END
