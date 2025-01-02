//
//  TGBaseIOTDefine.h
//  TGBaseIOT
//
//  Created by liubin on 2022/11/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#ifndef TGBaseIOTDefine_h
#define TGBaseIOTDefine_h

typedef NS_ENUM(NSInteger,TGCardRecordOrderType) {
    TGCardRecordOrderType_Desc,    //降序
    TGCardRecordOrderType_Asce     //升序
};

typedef NS_ENUM(NSInteger,TGDeviceRecordType) {
    TGDeviceRecordType_NoRecord,
    TGDeviceRecordType_CloudRecord,
    TGDeviceRecordType_SDCardRecord
};

typedef NS_ENUM(NSInteger, TGDeviceNetworkType) {
    TGDeviceNetworkType_WiFi,
    TGDeviceNetworkType_Sim
};

typedef NS_ENUM(NSInteger, TGZoomTimesUnknownDirection) {
    TGZoomTimesUnknownDirection_UnKnown,
    TGZoomTimesUnknownDirection_Up,
    TGZoomTimesUnknownDirection_Down
};

typedef NS_ENUM(NSInteger, TGZoomFocusDirection) {
    TGZoomFocusDirection_UnKnown,
    TGZoomFocusDirection_Far,
    TGZoomFocusDirection_Near
};

typedef NS_ENUM(NSInteger,TGConnectSessionStatus) {
    TGConnectSessionStatus_Unknown,
    TGConnectSessionStatus_Connecting,                              //连接中
    TGConnectSessionStatus_ConnectFailed,                           //连接失败
    TGConnectSessionStatus_Connected,                               //连接成功
    TGConnectSessionStatus_ConnectClosed,                           //session已被关闭
};

//绑定关系（1：主人 ，2：被分享）
typedef NS_ENUM(NSInteger,TGDeviceBindType) {
    TGDeviceBindType_Master,
    TGDeviceBindType_Shared
};

typedef NS_OPTIONS(NSInteger, TGCameraDeviceFlag) {
    TGCameraDeviceFlag_LiveListSplit        = 1 << 0,
    TGCameraDeviceFlag_SplitSimulation      = 1 << 1
};

typedef NS_ENUM(NSInteger, TGDeviceConnectMode) {
    TGDeviceConnectMode_Remote,                                     // 远程连接
    TGDeviceConnectMode_Local                                       // 本地连接
};

typedef NS_ENUM(NSInteger,TGDeviceButtonListFlag) {
    TGDeviceButtonListFlag_Unknown,
    TGDeviceButtonListFlag_AlertMsg,
    TGDeviceButtonListFlag_SimService,
    TGDeviceButtonListFlag_DriveEfence,
    TGDeviceButtonListFlag_DriveService,
    TGDeviceButtonListFlag_LocationRoute,
    TGDeviceButtonListFlag_DrsimLocalRecord,
    TGDeviceButtonListFlag_CloudService,
    TGDeviceButtonListFlag_SmartService,
    TGDeviceButtonListFlag_ShareDevice,
    TGDeviceButtonListFlag_LockOperateList,
    TGDeviceButtonListFlag_DeviceSetting,
    TGDeviceButtonListFlag_DeviceUpgrade,
    TGDeviceButtonListFlag_LearnAssistant,
    TGDeviceButtonListFlag_LearnService,
    TGDeviceButtonListFlag_MessageAgent,
    TGDeviceButtonListFlag_VipService,
    TGDeviceButtonListFlag_CloudRecord,
    TGDeviceButtonListFlag_RecognizeBird,
    TGDeviceButtonListFlag_Statistics,
    TGDeviceButtonListFlag_WechatPush
};

typedef NS_ENUM(NSInteger, TGPlayChannelType) {
    TGPlayChannelType_LiveChannelZero = 0,
    TGPlayChannelType_LiveChannelOne = 1,
    TGPlayChannelType_LiveChannelTwo = 2,
    TGPlayChannelType_LiveChannelThree = 3,
    TGPlayChannelType_CloudChannelZero = 0,
    TGPlayChannelType_CloudChannelOne = 1,
    TGPlayChannelType_CloudChannelTwo = 2,
    TGPlayChannelType_CloudChannelThree = 3,
    TGPlayChannelType_SDCardChannelZero = 0,
    TGPlayChannelType_SDCardChannelOne = 1,
    TGPlayChannelType_SDCardChannelTwo = 2,
    TGPlayChannelType_SDCardChannelThree = 3
};

typedef NS_ENUM(NSInteger,TGVideoPlayDirection) {
    TGVideoPlayDirection_Portrait,
    TGVideoPlayDirection_LandscapeLeft,
    TGVideoPlayDirection_LandscapeRight
};

typedef NS_ENUM(NSInteger, TGBaseIOTServerEnvType) {
    TGBaseIOTServerEnvType_Release,
    TGBaseIOTServerEnvType_Test,
    TGBaseIOTServerEnvType_Prerelease
};

typedef NS_ENUM(NSInteger,TGVideoRecordType) {
    TGVideoRecordType_Unknown,
    TGVideoRecordType_LiveChannelZero,
    TGVideoRecordType_LiveChannelOne,
    TGVideoRecordType_LiveChannelTwo,
    TGVideoRecordType_LiveChannelThree,
    TGVideoRecordType_CloudChannelZero,
    TGVideoRecordType_CloudChannelOne,
    TGVideoRecordType_CloudChannelTwo,
    TGVideoRecordType_CloudChannelThree,
    TGVideoRecordType_SDCardChannelZero,
    TGVideoRecordType_SDCardChannelOne,
    TGVideoRecordType_SDCardChannelTwo,
    TGVideoRecordType_SDCardChannelThree
};

typedef NS_ENUM(NSInteger,TGPTZViewTurnDirection) {
    TGPTZViewTurnDirection_Unknown,
    TGPTZViewTurnDirection_Left,
    TGPTZViewTurnDirection_Up,
    TGPTZViewTurnDirection_Right,
    TGPTZViewTurnDirection_Down
};

typedef NS_ENUM(NSInteger,TGCameraPlaySpeedLevel) {
    TGCameraPlaySpeedLevel_OneTimes         = 1 << 0,
    TGCameraPlaySpeedLevel_TwoTimes         = 1 << 1,
    TGCameraPlaySpeedLevel_FourTimes        = 1 << 2,
    TGCameraPlaySpeedLevel_EightTimes       = 1 << 3
};

typedef NS_ENUM(NSInteger, TGDevicePTZStyle) {
    TGDevicePTZStyle_UnKnown,
    TGDevicePTZStyle_Default,
    TGDevicePTZStyle_Horizontal,
    TGDevicePTZStyle_Vertical
};

typedef NS_ENUM(NSInteger, TGBluetoothConnectState) {
    TGBluetoothConnectState_Unknown,
    TGBluetoothConnectState_ConnectComplete,
    TGBluetoothConnectState_ConnectFailed,
    TGBluetoothConnectState_DisConnected
};

typedef NS_ENUM(NSInteger, TGBaseIOTReportStreamingType) {
    TGBaseIOTStreamingLiveType,
    TGBaseIOTStreamingSdcardType,
    TGBaseIOTStreamingCloudType
};

typedef NS_ENUM(NSInteger, TGAddDeviceErrorCode) {
    TGAddDeviceErrorCode_Unknown,
    TGAddDeviceErrorCode_InnerError,
    TGAddDeviceErrorCode_TimeOut
};

typedef NS_ENUM(NSInteger,TGDeviceNotificationType) {
    TGDeviceNotificationType_command,      //命令通道
    TGDeviceNotificationType_videoLive,    //直播通道
    TGDeviceNotificationType_audioLive,
    TGDeviceNotificationType_videoSdCard,
    TGDeviceNotificationType_audioSdCard
};

typedef NS_ENUM(NSInteger,TGAddDeviceBindType) {
    TGAddDeviceBindType_scan,               //扫码方式
    TGAddDeviceBindType_4g,                 //4g添加方式
    TGAddDeviceBindType_lan,                //已联网线设备
    TGAddDeviceBindType_device              //设备配网添加
};

#define TGBaseIOTAddDeviceErrorDomain                   @"com.tange365.TGBaseIOTAddDeviceErrorDomain"

#define TGBaseIOT_SCREENWIDTH                           (MIN([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height))
#define TGBaseIOT_SCREENHEIGHT                          (MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height))
#define TGBaseIOT_RelativeWidthX(value)                 (TGBaseIOT_SCREENWIDTH * value / 375.0f)
#define TGBaseIOT_RelativeHeightX(value)                (TGBaseIOT_SCREENHEIGHT * value / 812.0f)
#define TGBaseIOT_OEMSVGIconSize50                      (CGSizeMake(TGBaseIOT_RelativeHeightX(50), TGBaseIOT_RelativeHeightX(50)))

#define TGBaseIOTSDKVersion                             @"24130000"
#define TG_CurrentLogLevel                              @"TG_CurrentLogLevel"

#define TG_CameraZoomDefaultStep                        50
#define TG_DefaultBroadcastPort                         7997
#define TG_DefaultBroadcastString                       @"SEARCH * CTP/1.0\r\n\r\n\\"
#define TG_BroadcastResponsePrefix                      @"REPLY * CTP/1.0"

#define TG_DeviceType_DrSim                             @"drsim"
#define TG_DeviceType_LpDrSim                           @"lpdrsim"
#define TG_DeviceType_Sim                               @"sim"
#define TG_DeviceType_LpSim                             @"lpsim"
#define TG_DeviceType_Wifi                              @"wifi"
#define TG_DeviceType_DrWifi                            @"drwifi"
#define TG_DeviceType_LpWifi                            @"lpwifi"
#define TG_DeviceType_DoorbellWifi                      @"doorbellwifi"
#define TG_DeviceType_LpDoorbellWifi                    @"lpdoorbellwifi"
#define TG_DeviceType_Lockbell                          @"lockbell"
#define TG_DeviceType_LpLockbell                        @"lplockbell"
#define TG_DeviceType_LampWifi                          @"lampcamwifi"
#define TG_DeviceType_BirdFeederWifi                    @"birdfeederwifi"
#define TG_DeviceType_LpBirdFeederWifi                  @"lpbirdfeederwifi"
#define TG_DeviceType_BirdFeederSim                     @"birdfeedersim"
#define TG_DeviceType_LpBirdFeederSim                   @"lpbirdfeedersim"

#define TG_LocalConnectP2PId                            @"TANGE-000500-CYEEJ"
#define TG_LocalConnectPwd                              @"12345"

#define TGBaseIOT_CurrentEnvType                        @"TG_CurrentEnvType"
#define TGBaseIOT_LastEpReturnRegion                    @"TG_LastEpReturnRegion"
#define TGBaseIOT_CloudDownloadDataPlayOver             @"TG_CloudDownloadDataPlayOver"
#define TGBaseIOT_DeviceReceivedWebRTCInfo              @"TG_DeviceReceivedWebRTCInfo"
#define TGBaseIOT_SocketIODidConnectSuccess             @"TG_SocketIODidConnectSuccess"
#define TGBaseIOT_DeviceOnlineStatusChanged             @"TG_DeviceOnlineStatusDidChanged"
#define TGBaseIOT_DeviceAddStatusChanged                @"TG_DeviceAddStatusDidChanged"
#define TGBaseIOT_AccountStatusChanged                  @"TG_AccountStatusDidChanged"
#define TGBaseIOT_DeviceUpdateStatusChanged             @"TG_DeviceUpdateStatusDidChanged"
#define TGBaseIOT_DeviceShareStatusChanged              @"TG_DeviceShareStatusChanged"
#define TGBaseIOT_DeviceConnectWayDidChanged            @"TG_DeviceConnectWayDidChanged"
#define TGBaseIOT_DeviceServiceDidChanged               @"TG_DeviceServiceDidChanged"
#define TGBaseIOT_DoorBellMsgReceivedToSpeak            @"TG_DoorBellMsgReceivedToSpeak"
#define TGBaseIOT_DidReceiveUploadAppLog                @"TG_DidReceiveUploadAppLog"

#define TGBaseIOT_DeviceEventChangeStatus               @"TGBaseIOT_DeviceEventChangeStatus"
#define TGBaseIOT_NetWorkChange                         @"TGBASEIOT_NOTICE_NETWORK_STATUS_CHANGED"

#endif /* TGBaseIOTDefine_h */
