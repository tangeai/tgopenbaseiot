//
//  TGBaseIOTReportType.h
//  TGBaseIOT
//
//  Created by liubin on 2025/3/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const TGBASEIOT_client_lifeCycle;
extern NSString * const TGBASEIOT_client_basic;
extern NSString * const TGBASEIOT_client_device_connect;
extern NSString * const TGBASEIOT_client_media_control;
extern NSString * const TGBASEIOT_client_media_monitor;
extern NSString * const TGBASEIOT_client_media_player;
extern NSString * const TGBASEIOT_client_talkback;
extern NSString * const TGBASEIOT_client_command;
extern NSString * const TGBASEIOT_client_device_binding;

extern NSString * const TGBASEIOT_client_lifecycle_initDoneID;
extern NSString * const TGBASEIOT_client_lifecycle_VCChangeID;
extern NSString * const TGBASEIOT_client_basic_APIID;
extern NSString * const TGBASEIOT_client_basic_ID;
extern NSString * const TGBASEIOT_client_device_connect_connectInforID;
extern NSString * const TGBASEIOT_client_device_connect_beginConnectID;
extern NSString * const TGBASEIOT_client_device_connect_disConnectID;
extern NSString * const TGBASEIOT_client_device_connect_sendWakeUpID;
extern NSString * const TGBASEIOT_client_device_connect_wakeUpTimeOutID;
extern NSString * const TGBASEIOT_client_device_connect_wakeUpSuccessID;
extern NSString * const TGBASEIOT_client_device_connect_sendDevicePasswordID;
extern NSString * const TGBASEIOT_client_device_connect_passwordDoneID;
extern NSString * const TGBASEIOT_client_device_connect_connectSuccessID;
extern NSString * const TGBASEIOT_client_device_connect_connectStatueUpdateID;
extern NSString * const TGBASEIOT_client_device_connect_connectDetailID;

extern NSString * const TGBASEIOT_client_media_control_beginLiveVideoID;
extern NSString * const TGBASEIOT_client_media_control_stopLiveVideoID;
extern NSString * const TGBASEIOT_client_media_control_setMediaArticulationID;
extern NSString * const TGBASEIOT_client_media_control_beginSDVideoID;
extern NSString * const TGBASEIOT_client_media_control_stopSDVideoID;
extern NSString * const TGBASEIOT_client_media_control_beginCloudVideoID;
extern NSString * const TGBASEIOT_client_media_control_cloudVideoFailureID;

extern NSString * const TGBASEIOT_client_media_monitor_firstVideoFrameID;
extern NSString * const TGBASEIOT_client_media_monitor_firstAudioFrameID;
extern NSString * const TGBASEIOT_client_media_monitor_videoDataID;
extern NSString * const TGBASEIOT_client_media_monitor_audioDataID;
extern NSString * const TGBASEIOT_client_media_monitor_videoFrameTimeFailureID;
extern NSString * const TGBASEIOT_client_media_monitor_videoLostFrameID;
extern NSString * const TGBASEIOT_client_media_monitor_videoUTCFrameID;
extern NSString * const TGBASEIOT_client_media_monitor_videoCacheID;

extern NSString * const TGBASEIOT_client_media_player_benginVideoDecodeID;
extern NSString * const TGBASEIOT_client_media_player_firstVideoFrameID;

extern NSString * const TGBASEIOT_client_talkback_beginTalkID;
extern NSString * const TGBASEIOT_client_talkback_endTalkID;

extern NSString * const TGBASEIOT_client_command_sendCommandId;
extern NSString * const TGBASEIOT_client_command_sendFailureId;
extern NSString * const TGBASEIOT_client_command_reviceCommandId;

extern NSString * const TGBASEIOT_client_device_binding_getTokenID;
extern NSString * const TGBASEIOT_client_device_binding_sendWifiInforID;


typedef NS_ENUM(NSInteger,TGBaseIOTLogLevel) {
    TGBaseIOT_DEBUG,  // 调试等级
    TGBaseIOT_NOTICE, // 注意或者错误
    TGBaseIOT_INFO    // 一般信息
};

@interface TGBaseIOTReportType : NSObject

@end

NS_ASSUME_NONNULL_END
