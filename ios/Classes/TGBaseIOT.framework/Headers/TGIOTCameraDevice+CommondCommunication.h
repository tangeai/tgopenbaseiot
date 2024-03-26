//
//  TGIOTCameraDevice+CommondCommunication.h
//  AFNetworking
//
//  Created by liubin on 2024/1/4.
//

#import "TGIOTCameraDevice.h"
#import "TGCommondDefineHeader.h"
#import "TGDeviceCommodModel.h"
#import "TGDeviceTrackModel.h"
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGIOTCameraDevice (CommondCommunication)

#pragma mark - CustomCommond
// 发送自定义指令
- (void)sendIOCtrl:(int)controlCMD Data:(char *)buffer DataSize:(int)size receiveIOCtrl:(int)receiveControlCMD successBlock:(void(^)(char *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - BaseDeviceCommond

// 查询设备硬件能力
- (void)getDeviceFeatureSuccessBlock:(void(^)(TGDeviceBaseInstruction *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设备信息
- (void)getDeviceInfoCMDSuccessBlock:(void(^)(TGDeviceBaseInfor *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设备重启
- (void)rebootDeviceSuccessBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - sd卡
// 格式化SD卡
- (void)formatSDCardSuccessBlock:(void(^)(TGDeviceSDFormatModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 查询SD卡状态
- (void)getSDCardSatueSuccessBlock:(void(^)(TGDeviceSDStorageModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 画面
// 获取视频翻转
- (void)getVideoFlipCtrlCMDChannel:(int)channel successBlock:(void(^)(TGDeviceGetVideoModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置视频翻转
- (void)setVideoFlipMode:(ENUM_VIDEO_MODE)mode channel:(int)channel SuccessBlock:(void(^)(TGDeviceSetVideoFlipModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 云台

// 云台短按操作
- (void)tg_devicePTZShortTurnToDirectionWithChannel:(int)channel direction:(TGPTZViewTurnDirection)direction;
// 云台长按操作
- (void)tg_devicePTZLongTurnToDirectionWithChannel:(int)channel direction:(TGPTZViewTurnDirection)direction;
// 云台长按结束
- (void)tg_devicePTZLongTurnStopWithChannel:(int)channel;

// 短按变焦控制
- (void)tg_deviceShortZoomWithChannel:(int)channel direction:(TGZoomTimesUnknownDirection)direction;
// 长按变焦控制
- (void)tg_deviceLongZoomBeginWithChannel:(int)channel direction:(TGZoomTimesUnknownDirection)direction;
// 长按变焦结束
- (void)tg_deviceLongZoomEndWithChannel:(int)channel direction:(TGZoomTimesUnknownDirection)direction;

// 短按聚焦
- (void)tg_deviceShortFocusWithChannel:(int)channel direction:(TGZoomFocusDirection)direction;
// 长按聚焦
- (void)tg_deviceLongFocusBeginWithChannel:(int)channel direction:(TGZoomFocusDirection)direction;
// 长按聚焦结束
- (void)tg_deviceLongFocusEndWithChannel:(int)channel direction:(TGZoomFocusDirection)direction;

// 获取预置位
- (void)getDevicePSPWithModel:(TGDeviceGetPresetPointsReqModel *)model successBlock:(void(^)(TGDevicePresetPointsRespModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置预置位置
- (void)createPSPWithModel:(TGDeviceSetPresetPointsRespModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 删除预置位置
- (void)deletePSPWithModel:(TGDeviceSetPresetPointsRespModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取守望点
- (void)getDeviceWatchPosWithChannel:(int)channel successBlock:(void(^)(TGDeviceWatchPosModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置守望点
- (void)setDeviceWatchPosWithModel:(TGDeviceWatchPosModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取巡航设置
- (void)getDeviceTrackWithModel:(TGGetPtzTrackReqModel *)model successBlock:(void(^)(TGGetPtzTrackRespModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 创建巡航
- (void)createTrackWithModel:(TGDeviceTrackModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 删除巡航
- (void)deleteTracksWithArray:(NSArray <TGDeviceTrackModel *>*)trackArray successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;
//// 设置巡航停留时间
//- (void)setTrackStayTimeWithTime:(NSInteger)time channel:(int)channel successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 开始巡航
- (void)startDeviceTrackWithModel:(TGDeviceTrackModel *)model;
// 结束巡航
- (void)stopDeviceTrackWithModel:(TGDeviceTrackModel *)model;

#pragma mark - 灯光

//查询设备白光灯模式
- (void)getDeviceWhiteLightChannel:(int)channel successBlock:(void(^)(TGDeviceGetwhiteLightModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
//设置设备白光灯模式
- (void)setDeviceWhiteLight:(TGVideoWhiteLightModel)mode channel:(int)channel successBlock:(void(^)(TGDeviceSetWhiteLightModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取状态灯
- (void)getDeviceLedStatusSuccessBlock:(void(^)(TGDeviceLedStatusModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置状态灯
- (void)setDeviceLedStatus:(int)status successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取报警灯状态
- (void)getAlarmLightStatusSuccessBlock:(void(^)(TGDeviceAlarmLightStateModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置报警灯状态
- (void)setAlarmLightStatus:(int)status successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 夜视
// 查询设备夜视模式
- (void)getDeviceDayNightWithChannel:(int)channel successBlock:(void(^)(TGDeviceGetDayNightModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置设备夜视模式
- (void)setDeviceDayNightWithChannel:(int)channel mode:(int)mode  successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 变焦

- (void)deviceShortZoomWithChannel:(NSInteger)channel direction:(TGZoomTimesUnknownDirection)direction;
- (void)deviceLongZoomBeginWithChannel:(NSInteger)channel direction:(TGZoomTimesUnknownDirection)direction;
- (void)deviceLongZoomEndWithChannel:(NSInteger)channel direction:(TGZoomTimesUnknownDirection)direction;

#pragma mark - 聚焦

// 聚焦
- (void)deviceShortFocusWithChannel:(NSInteger)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusBeginWithChannel:(NSInteger)channel direction:(TGZoomFocusDirection)direction;
- (void)deviceLongFocusEndWithChannel:(NSInteger)channel direction:(TGZoomFocusDirection)direction;

#pragma mark - 休眠唤醒

// 低功耗设备暂停休眠
- (void)tg_deviceInterruptSleep;
// 低功耗设备恢复休眠
- (void)tg_deviceRestoreSleep;

// 设置设备允许或禁止休眠
- (void)setDeviceEnableDormancyEnable:(BOOL)enable successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取休眠开关
- (void)getDeviceEnableDormancySuccessBlock:(void(^)(TGDeviceGetEnableDormancyModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

// 设置被动唤醒后无操作的最大工作时长
- (void)setDeviceMaxTime:(int)time successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取被动唤醒后无操作的最大工作时长
- (void)getDeviceMaxTimeSuccessBlock:(void(^)(TGDevicePassivityGetMaxAwakeModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;

// 设置主动唤醒时间
- (void)setDeviceAwakeTimeWithModel:(TGDeviceAwakeTimeModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;
// 获取设备主动唤醒时间的设置
- (void)getDeviceAwakeTimeSuccessBlock:(void(^)(TGDeviceAwakeTimeModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;

#pragma mark - 录像
// 设置录像模式
- (void)setDeviceRecordWithModel:(TGDeviceRecordingModel *)model successBlock:(void(^)(TGDeviceSetRecordingRespModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取录像模式
- (void)getDeivceRecordWithChannel:(int)channel successBlock:(void(^)(TGDeviceRecordingModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 麦克风 音量

//查询设备麦克风开关
- (void)getMicrophoneMuteStateWithChannel:(int)channel successBlock:(void(^)(TGDeviceMicroModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;
//设置设备麦克风开关
- (void)setDeviceMicrophoneMuteStateWithModel:(TGDeviceMicroModel *)model successBlock:(void(^)(TGDeviceSetMicroRespModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取设备拾音器灵敏度
- (void)getDeviceMicSensitivitySuccessBlock:(void(^)(TGDeviceMicLevel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置设备拾音器灵敏度
- (void)setDeviceMicWithSensitivity:(int)sensitivity successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;
// 获取设备喇叭音量
- (void)getDeviceSpeakerVolumeSuccessBlock:(void(^)(TGDeviceVolume *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置设备喇叭音量
- (void)setDeviceSpeakerVolume:(TGDeviceVolume *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 电池电量、wifi/4g信号强度、电源频率

// 获取电池电量
- (void)getBatteryStatusSuccessBlock:(void(^)(TGDeviceBatteryStatusModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取wifi/4g信号强度
- (void)getWifiSignalLevelSuccessBlock:(void(^)(TGDeviceGetWiFiLevelModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置电源频率50HZ，60HZ（防闪烁）
- (void)setDeviceFrequencyWithChannel:(int)channel mode:(ENUM_ENVIRONMENT_MODE)mode successBlock:(void(^)(TGDeviceSetFrequencyModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取电源频率（防闪烁）
- (void)getDeviceFrequencyWithChannel:(int)channel successBlock:(void(^)(TGDeviceFrequencyModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - wifi

// 获取Wifi列表
- (void)getWifiListSuccessBlock:(void(^)(TGDeviceWiFiListModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

/// 连接wifi
/// - Parameters:
///   - ssid: wifi名称
///   - passwd: WiFi密码
///   - userId: 用户id
///   - change: 如果设备已联网需要更换其他wifi传yes，如果是初始化设备（未联网的设备）传NO
///   - successBlock: 成功
///   - failuerBlock: 失败
- (void)connectToWifiWithSSID:(NSString *)ssid passwd:(NSString *)passwd userId:(NSString *)userId change:(BOOL)change successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

//查询设备当前连接的WiFi
- (void)getDeviceCurrentSsidSuccessBlock:(void(^)(TGDeviceWiFiInforModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 移动追踪

// 查询设备移动追踪模式
- (void)getDeviceMoveTrackWithChannel:(int)channel successBlock:(void(^)(TGDeviceMotionModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;
// 设置设备移动追踪模式
- (void)setDeviceMoveTrackWithChannel:(int)channel mode:(int)mode successBlock:(void(^)(TGDeviceSetMotionModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 事件侦测

//获取移动侦测配置
- (void)getMoveDetectWithChannel:(int)channel successBlock:(void(^)(TGDeviceMotionDetectModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
//配置移动侦测
- (void)setMoveDetectSensitivity:(TGDeviceMotionDetectModel *)model successBlock:(void(^)(TGDeviceMotionDetectRespModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取侦测区域状态
- (void)getMoveDetectAreaStateWithChannel:(int)channel successBlock:(void(^)(TGDeviceMotionAreaState *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置侦测区域状态
- (void)setMoveDetectAreaStateWithStateWithModel:(TGDeviceMotionAreaState *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - AI功能开关

// 设置AI功能开关通用命令
- (void)setAICommonStatueWithModel:(TGDeviceAICommonModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 获取AI功能开关通用命令
- (void)getAICommonStatueSuccessBlock:(void(^)(TGDeviceAICommonModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - PIR

// 获取Pir灵敏度
- (void)getPIRSensitiveSuccessBlock:(void(^)(TGDevicePIRModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;;
// 设置Pir灵敏度
- (void)setPIRSensitive:(int)sensitive successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;

#pragma mark - 警戒播报

// 获取支持的报警音频文件格式信息
- (void)getAlarmToneInfoSuccessBlock:(void(^)(TGDeviceAlarmToneCapModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 设置报警音频
- (void)setAlarmSoundWithModel:(TGDeviceSetAlarmToneModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
// 播放当前报警声音
- (void)playCurrentAlarmSoundSuccessBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
////// 获取警报铃开关
//- (void)getAlarmBellSwitchSuccessBlock:(void(^)(TGDeviceAlarmBellModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
//// 设置警报铃开关
//- (void)setAlarmBellSwitchWithModel:(TGDeviceAlarmBellModel *)model successBlock:(void(^)(TGDeviceCommodModel *result))successBlock failuerBlock:(void(^)(TGDeviceCommodModel *failuer))failuerBlock;
@end

NS_ASSUME_NONNULL_END
