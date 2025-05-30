//
//  TGBaseIOTReportEvent.h
//  TGBaseIOT
//
//  Created by liubin on 2024/5/27.
//

#import <Foundation/Foundation.h>
#import "TGBaseIOTReportEventModel.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const TGBASEIOT_EVENT_START_CONNECT;
extern NSString * const TGBASEIOT_EVENT_START_MEDIA;
extern NSString * const TGBASEIOT_EVENT_PWD_PASS;
extern NSString * const TGBASEIOT_EVENT_PWD_SENT;
extern NSString * const TGBASEIOT_EVENT_PWD_ERROR;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_SUCCESS;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_SUCCESS_INFO;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_ING;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_START;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_FAILED;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_FAILED_INFO;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_DISCONNECTED;
extern NSString * const TGBASEIOT_EVENT_CONNECT_STATUS_OTHER;
extern NSString * const TGBASEIOT_EVENT_DEVICE_ATTRIBUTES;
extern NSString * const TGBASEIOT_EVENT_CONNECT_SESSION_ID;
extern NSString * const TGBASEIOT_EVENT_CORE_CONNECT_SUCCESS;
extern NSString * const TGBASEIOT_EVENT_WAKE_UP_BY_SERVER_START;
extern NSString * const TGBASEIOT_EVENT_WAKE_UP_BY_SERVER_SENT;
extern NSString * const TGBASEIOT_EVENT_LISTEN_ON_WAKE_UP_SERVER;
extern NSString * const TGBASEIOT_EVENT_WAKE_UP_BY_SERVER_SUCCESS;
extern NSString * const TGBASEIOT_EVENT_WAKE_UP_BY_SERVER_TIMEOUT;
extern NSString * const TGBASEIOT_EVENT_SUCCESSBLOCK_COMMAND_ADD;
extern NSString * const TGBASEIOT_EVENT_FAILUREBLOCK_COMMAND_ADD;
extern NSString * const TGBASEIOT_EVENT_VIDEO_RECEIVED_DELAY;
extern NSString * const TGBASEIOT_EVENT_AUDIO_RECEIVED_DELAY;
extern NSString * const TGBASEIOT_EVENT_VIDEO_DROPPED;
extern NSString * const TGBASEIOT_EVENT_VIDEO_INITIAL_UTC_FRAME;
extern NSString * const TGBASEIOT_EVENT_VIDEO_INITIAL_KEY_FRAME;
extern NSString * const TGBASEIOT_EVENT_AUDIO_INITIAL_FRAME;
extern NSString * const TGBASEIOT_EVENT_VIDEO_AVG_FPS;
extern NSString * const TGBASEIOT_EVENT_AUDIO_AVG_FPS;
extern NSString * const TGBASEIOT_EVENT_VIDEO_AVG_BITRATE;
extern NSString * const TGBASEIOT_EVENT_VIDEO_CODEC_TYPE;
extern NSString * const TGBASEIOT_EVENT_VIDEO_DECODER_CREATE;
extern NSString * const TGBASEIOT_EVENT_VIDEO_SIZE_CHANGED;
extern NSString * const TGBASEIOT_EVENT_INSTRUCTION_SENT;
extern NSString * const TGBASEIOT_EVENT_QUERY_DEVICE_FEATURE;
extern NSString * const TGBASEIOT_EVENT_TALK_BACK_START;
extern NSString * const TGBASEIOT_EVENT_QUERY_DEVICE_SETTING;
extern NSString * const TGBASEIOT_EVENT_INSTRUCTION_REC;
extern NSString * const TGBASEIOT_EVENT_VIDEO_FRAME_INTERNAL_ERROR;
extern NSString * const TGBASEIOT_EVENT_AUDIO_FRAME_INTERNAL_ERROR;
extern NSString * const TGBASEIOT_EVENT_OSS_TOKEN_INFO;
extern NSString * const TGBASEIOT_EVENT_CLOUD_FILE_DOWNLOAD_START;
extern NSString * const TGBASEIOT_EVENT_CLOUD_FILE_DOWNLOAD_ERROR;
extern NSString * const TGBASEIOT_EVENT_CLOUD_FILE_DOWNLOAD_SUCCESS;
extern NSString * const TGBASEIOT_EVENT_CLOUD_FILE_DOWNLOAD_NOT_FOUND;
extern NSString * const TGBASEIOT_EVENT_VIDEO_BUFFERING_INIT;
extern NSString * const TGBASEIOT_EVENT_VIDEO_BUFFERING_FINISH;
extern NSString * const TGBASEIOT_EVENT_MEDIA_TIME_DIFF_AVG;
extern NSString * const TGBASEIOT_EVENT_MEDIA_TIME_DIFF_TOO_BIG;
extern NSString * const TGBASEIOT_EVENT_VIDEO_RENDER_QUEUE_EMPTY;
extern NSString * const TGBASEIOT_EVENT_AUDIO_DATA_ERROR;
extern NSString * const TGBASEIOT_EVENT_AUDIO_DATA_DROPPED;
extern NSString * const TGBASEIOT_EVENT_WEBRTC_CONNECT_STEP;
extern NSString * const TGBASEIOT_EVENT_P2P_SERVER_LOGGING;
extern NSString * const TGBASEIOT_CLOUD_VIDEO_DECODE_ERROR;
extern NSString * const TGBASEIOT_EVENT_VIDEO_TRAFFIC_STATISTICS;
extern NSString * const TGBASEIOT_EVENT_SWITCH_WEBRTC2_WEBRTC;
extern NSString * const TGBASEIOT_EVENT_SWITCH_WEBRTC2_RELAY;
extern NSString * const TGBASEIOT_EVENT_SWITCH_WEBRTC2_PPCS;
extern NSString * const TGBASEIOT_EVENT_SWITCH_WEBRTC_RELAY;
extern NSString * const TGBASEIOT_EVENT_SWITCH_WEBRTC_PPCS;
extern NSString * const TGBASEIOT_EVENT_SWITCH_RELAY_PPCS;
extern NSString * const TGBASEIOT_EVENT_SOCKET_INOF;
extern NSString * const TGBASEIOT_EVENT_ACCOUNT_STATUS_CHANGE ;
extern NSString * const TGBASEIOT_EVENT_APP_TERMINNATE;
// 前置声明
void _TGBASEIOTAddReportEvent(NSInteger level,
                             NSString *deviceId,
                             NSString *eventName,
                             NSString *eventInfor,
                             id object,
                             const char *file,
                             const char *function,
                             NSUInteger line);

// 宏定义
#define TGBASEIOTAddReportEvent(level, deviceId, eventName, eventInfor, object) \
    _TGBASEIOTAddReportEvent(level, deviceId, eventName, eventInfor, object, __FILE__, __PRETTY_FUNCTION__, __LINE__)

#define TGAddReportEvent(...) \
    [[TGBaseIOTReportEvent shareReportEvent] addReportEvent:__VA_ARGS__ \
    file:__FILE__ \
    function:__PRETTY_FUNCTION__ \
    line:__LINE__]

@interface TGBaseIOTReportEvent : NSObject

+ (instancetype)shareReportEvent;

/// 埋点方法
/// - Parameter array: [日志级别，设备id，事件名称，事件描述，所属类对象]
- (void)addReportEvent:(NSArray *)array;

- (void)addReportEvent:(NSArray *)array file:(const char *)file function:(const char *)function line:(NSUInteger)line;

- (TGBaseIOTReportEventModel *)getReportEvent;

@end

NS_ASSUME_NONNULL_END
