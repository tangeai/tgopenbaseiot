//
//  TGCameraDefine.h
//  TGBaseIOT
//
//  Created by Darren on 2019/10/25.
//  Copyright © 2019 Darren. All rights reserved.
//

//#import "ec_const.h"
#include "ec_const.h"

#ifndef TGCameraDefine_h
#define TGCameraDefine_h

typedef struct{
    unsigned int type;                                              // 0 pass -1 no pass
    unsigned int size;                                              // 0 pass -1 no pass
}SMsgBaseReq;

typedef struct{
    unsigned int cmd;                                               // 0 pass -1 no pass
    unsigned int error;                                             // 0 pass -1 no pass
} __attribute__((__packed__)) SMsgBaseResp;

/** @name 通用错误码
  Tcis_ErrorResp::err 取值, 用于 TciSendCmdRespStatus() 的 status 参数
  @{*/
#define TCI_OK                  0 ///< 命令成功执行
#define TCI_E_INPROCESSING      1 ///< 操作进行中
#define TCI_E_CMDHDR            2 ///< 错误命令头
#define TCI_E_UNSUPPORTED_CMD   3 ///< 不支持的命令
#define TCI_E_INVALID_PARAM     4 ///< 无效参数
#define TCI_E_LACKOF_RESOURCE   5 ///< 资源(内存)不足
#define TCI_E_INTERNEL          6 ///< 设备内部错误
#define TCI_E_NOT_ALLOWED       7 ///< 操作不允许

#define TCI_Command_Define      2 ///< 自定义命令

#define IOTYPE_USER_CMD_SET_SCREEN_DISPLAY_REQ             0x0382  // 设置屏幕显示
#define IOTYPE_USER_CMD_SET_SCREEN_DISPLAY_RESP            0x0383  // 设置屏幕显示
#define IOTYPE_USER_CMD_GET_SCREEN_DISPLAY_REQ             0x0384  // 获取屏幕显示设置
#define IOTYPE_USER_CMD_GET_SCREEN_DISPLAY_RESP            0x0385  // 获取屏幕显示设置

#define IOTYPE_USER_CMD_SET_POWER_STRATEGY                 0x048C   // 设置电池供电时电源策略
#define IOTYPE_USER_CMD_SET_POWER_STRATEGY_RETRUE          0x048D   // 设置电池供电时电源策略返回
#define IOTYPE_USER_CMD_GET_POWER_STRATEGY                 0x048E   // 获取电池供电时电源策略
#define IOTYPE_USER_CMD_GET_POWER_STRATEGY_RETRUE          0x048F   // 获取电池供电时电源策略返回

#define IOTYPE_USER_CMD_FEEDER_GET_CONFIG                  0x0500   // 喂食器配置
#define IOTYPE_USER_CMD_FEEDER_GET_CONFIG_RETRUE           0x0501   // 返回·喂食器配置
#define IOTYPE_USER_CMD_FEEDER_SET_TIMERS                  0x0502   // 设置喂食定时.  req: Tcis_FeederTimers; resp: generic
#define IOTYPE_USER_CMD_FEEDER_GET_TIMERS                  0x0504   // 获取喂食定时器设置. req: none; resp: Tcis_FeederTimers
#define IOTYPE_USER_CMD_FEEDER_GET_TIMERS_RETRUE           0x0505   // 获取喂食定时器设置 返回数据
#define IOTYPE_USER_CMD_FEEDER_FEED_FOOD                   0x0506   // 手工喂食

/* CODEC ID */
typedef enum{
    MEDIA_CODEC_UNKNOWN                                 = 0x00,
    MEDIA_CODEC_VIDEO_IJPG                              = 0x0A,     // Private inter-frame jpeg codec
    MEDIA_CODEC_VIDEO_MPEG4                             = 0x4C,
    MEDIA_CODEC_VIDEO_H263                              = 0x4D,
    MEDIA_CODEC_VIDEO_H264                              = 0x4E,
    MEDIA_CODEC_VIDEO_MJPEG                             = 0x4F,
    MEDIA_CODEC_VIDEO_HEVC                              = 0x50,

    MEDIA_CODEC_AUDIO_AAC_RAW                           = 0x86,     // 2017-05-04 add AAC Raw data audio codec definition
    MEDIA_CODEC_AUDIO_AAC_ADTS                          = 0x87,     // 2017-05-04 add AAC ADTS audio codec definition
    MEDIA_CODEC_AUDIO_AAC_LATM                          = 0x88,     // 2017-05-04 add AAC LATM audio codec definition
    MEDIA_CODEC_AUDIO_AAC                               = 0x88,     // 2014-07-02 add AAC LATM audio codec definition
    MEDIA_CODEC_AUDIO_G711U                             = 0x89,     // g711 u-law
    MEDIA_CODEC_AUDIO_G711A                             = 0x8A,     // g711 a-law
    MEDIA_CODEC_AUDIO_ADPCM                             = 0X8B,
    MEDIA_CODEC_AUDIO_PCM                               = 0x8C,
    MEDIA_CODEC_AUDIO_SPEEX                             = 0x8D,
    MEDIA_CODEC_AUDIO_MP3                               = 0x8E,
    MEDIA_CODEC_AUDIO_G726                              = 0x8F,
}ENUM_CODECID;

//typedef enum {
//    TCMEDIA_INVALID                                     = 0,
//    TCMEDIA_VIDEO_H264                                  = 1,
//    TCMEDIA_AUDIO_G711A                                 = 2,
//    TCMEDIA_AUDIO_ALAW                                  = TCMEDIA_AUDIO_G711A,
//
//    //----------------------------------
//    TCMEDIA_VIDEO_MPEG                                  = 11,
//    TCMEDIA_VIDEO_MJPEG                                 = 12,
//    TCMEDIA_VIDEO_H265                                  = 13,
//    TCMEDIA_VIDEO_MAX,
//
//    TCMEDIA_AUDIO_ULAW                                  = 51,
//    TCMEDIA_AUDIO_G711U                                 = TCMEDIA_AUDIO_ULAW,
//    TCMEDIA_AUDIO_PCM                                   = 52,
//    TCMEDIA_AUDIO_ADPCM                                 = 53,
//    TCMEDIA_AUDIO_ADPCM_IMA                             = TCMEDIA_AUDIO_ADPCM,
//    TCMEDIA_AUDIO_ADPCM_DVI4                            = 54,
//    TCMEDIA_AUDIO_G726_16                               = 55,
//    TCMEDIA_AUDIO_G726_24                               = 56,
//    TCMEDIA_AUDIO_G726_32                               = 57,
//    TCMEDIA_AUDIO_G726_40                               = 58,
//    TCMEDIA_AUDIO_AAC                                   = 59,
//    TCMEDIA_AUDIO_MP3                                   = 60,
//    TCMEDIA_AUDIO_AMR                                   = 61,
//    TCMEDIA_AUDIO_MAX
//} TCMEDIA;

/* FRAME Flag */
typedef enum{
    IPC_FRAME_FLAG_PBFRAME                              = 0x00,     // A/V P/B frame..
    IPC_FRAME_FLAG_IFRAME                               = 0x01,     // A/V I frame.
    IPC_FRAME_FLAG_MD                                   = 0x02,     // For motion detection.
    IPC_FRAME_FLAG_IO                                   = 0x03,     // For Alarm IO detection.
}ENUM_FRAMEFLAG;

/* Audio Frame: flags =  (samplerate << 2) | (databits << 1) | (channel) */

// AVIOCTRL Message Type
typedef enum{
    IOTYPE_USER_IPCAM_START_REQ                         = 0x01FF,
    IOTYPE_USER_IPCAM_STOP_REQ                          = 0x02FF,
    
    IOTYPE_USER_IPCAM_SEND_META_START_REQ               = 0x0200,
    IOTYPE_USER_IPCAM_SEND_META_STOP_REQ                = 0x0201,
    
    IOTYPE_USER_IPCAM_PUSH_STREAMING_START_REQ          = 0x0210,
    IOTYPE_USER_IPCAM_PUSH_STREAMING_START_RESP         = 0x0211,
    IOTYPE_USER_IPCAM_PUSH_STREAMING_FINISH_REQ         = 0x0212,
    IOTYPE_USER_IPCAM_PUSH_STREAMING_FINISH_RESP        = 0x0213,
    IOTYPE_USER_IPCAM_PUSH_STREAMING_CLOSE_REQ          = 0x0214,
    
    IOTYPE_USER_IPCAM_AUDIOSTART_REQ                    = 0x0300,
    IOTYPE_USER_IPCAM_AUDIOSTOP_REQ                     = 0x0301,

    IOTYPE_USER_IPCAM_SETRECORD_REQ                     = 0x0310,
    IOTYPE_USER_IPCAM_SETRECORD_RESP                    = 0x0311,
    IOTYPE_USER_IPCAM_GETRECORD_REQ                     = 0x0312,
    IOTYPE_USER_IPCAM_GETRECORD_RESP                    = 0x0313,
    
    TCI_CMD_SET_TIMELAPSE_RECORD_REQ                    = 0x0314,
    TCI_CMD_SET_TIMELAPSE_RECORD_RESP                   = 0x0315,
    TCI_CMD_GET_TIMELAPSE_RECORD_REQ                    = 0x0316,
    TCI_CMD_GET_TIMELAPSE_RECORD_RESP                   = 0x0317,

    IOTYPE_USER_IPCAM_LISTEVENT_REQ                     = 0x0318,
    IOTYPE_USER_IPCAM_LISTEVENT_RESP                    = 0x0319,
    
    IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL_REQ            = 0x031A,
    IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL_RESP           = 0x031B,

    TCI_CMD_SET_EVENT_STATE_REQ                         = 0x031C,
    TCI_CMD_SET_EVENT_STATE_RESP                        = 0x031D,
    TCI_CMD_GET_EVENT_STATE_REQ                         = 0x031E,
    TCI_CMD_GET_EVENT_STATE_RESP                        = 0x031F,
    
    IOTYPE_USER_IPCAM_SETSTREAMCTRL_REQ                 = 0x0320,
    IOTYPE_USER_IPCAM_SETSTREAMCTRL_RESP                = 0x0321,
    IOTYPE_USER_IPCAM_GETSTREAMCTRL_REQ                 = 0x0322,
    IOTYPE_USER_IPCAM_GETSTREAMCTRL_RESP                = 0x0323,
    
    TCI_CMD_SETMOTIONDETECT_REQ                         = 0x0324,   // 移动侦测
    TCI_CMD_SETMOTIONDETECT_RESP                        = 0x0325,
    TCI_CMD_GETMOTIONDETECT_REQ                         = 0x0326,
    TCI_CMD_GETMOTIONDETECT_RESP                        = 0x0327,
    
    TCI_CMD_SET_DEFENCE_REQ                             = 0x0328,   // 布防设置
    TCI_CMD_SET_DEFENCE_RESP                            = 0x0329,
    TCI_CMD_GET_DEFENCE_REQ                             = 0x032A,
    TCI_CMD_GET_DEFENCE_RESP                            = 0x032B,
    
    TCI_CMD_SET_AI_STATUS_REQ                           = 0x032C,   // 设置人形过滤
    TCI_CMD_SET_AI_STATUS_RESP                          = 0x032D,
    TCI_CMD_GET_AI_STATUS_REQ                           = 0x032E,   // 获取人形过滤
    TCI_CMD_GET_AI_STATUS_RESP                          = 0x032F,
    
    IOTYPE_USER_IPCAM_DEVINFO_REQ                       = 0x0330,
    IOTYPE_USER_IPCAM_DEVINFO_RESP                      = 0x0331,
    
    TCI_CMD_START_TALK_REQ                              = 0x0332,
    TCI_CMD_START_TALK_RESP                             = 0x0333,
    
    TCI_CMD_LEAVE_SETUP_REQ                             = 0x0336,   // 低功耗设备恢复休眠
    TCI_CMD_ENTER_SETUP_REQ                             = 0x0338,   // 低功耗设备暂停休眠
    
    TCI_CMD_SET_MDAREA_STATE_REQ                        = 0x033A,   // 设置侦测区域状态（显示|隐藏）Req: @ref Tcis_MdAreaState, Resp: generic
    TCI_CMD_SET_MDAREA_STATE_RESP                       = 0x033B,
    TCI_CMD_GET_MDAREA_STATE_REQ                        = 0x033C,   // 获取侦测区域状态 Req: @ref Tcis_GetMdAreaStateReq, Resp: Tcis_MdAreaState
    TCI_CMD_GET_MDAREA_STATE_RESP                       = 0x033D,
    
    TCI_CMD_SET_ENABLE_CLOSEUP_REQ                      = 0x033E,   // 跟踪功能开启特写   req: @ref Tcis_EnableCloseup; resp: generic. @see Feature_Cap-AI
    TCI_CMD_SET_ENABLE_CLOSEUP_RESP                     = 0x033F,
    TCI_CMD_GET_ENABLE_CLOSEUP_REQ                      = 0x034C,
    TCI_CMD_GET_ENABLE_CLOSEUP_RESP                     = 0x034D,
    
    IOTYPE_USER_IPCAM_LISTWIFIAP_REQ                    = 0x0340,
    IOTYPE_USER_IPCAM_LISTWIFIAP_RESP                   = 0x0341,
    IOTYPE_USER_IPCAM_SETWIFI_REQ                       = 0x0342,
    IOTYPE_USER_IPCAM_SETWIFI_RESP                      = 0x0343,
    IOTYPE_USER_IPCAM_GETWIFI_REQ                       = 0x0344,
    IOTYPE_USER_IPCAM_GETWIFI_RESP                      = 0x0345,
    IOTYPE_USER_IPCAM_SETWIFI_REQ_2                     = 0x0346,
    IOTYPE_USER_IPCAM_GETWIFI_RESP_2                    = 0x0347,
    
    TCI_CMD_SET_SHOW_BOX_REQ                            = 0x0348,   // 显示人形/人脸边框. req: @ref Tcis_SetShowBoxReq; resp: generic
    TCI_CMD_SET_SHOW_BOX_RESP                           = 0x0349,
    TCI_CMD_GET_SHOW_BOX_REQ                            = 0x034A,   // 获取人形/人脸边框设置状态. req: @ref Tcis_GetShowBoxReq; resp: @ref Tcis_GetShowBoxResp
    TCI_CMD_GET_SHOW_BOX_RESP                           = 0x034B,
    
    IOTYPE_USER_IPCAM_SPEAKERSTART_REQ                  = 0x0350,
    IOTYPE_USER_IPCAM_SPEAKERSTOP_REQ                   = 0x0351,
    
    TCI_CMD_SET_LIGHT_STATE_REQ                         = 0x0352,
    TCI_CMD_SET_LIGHT_STATE_RESP                        = 0x0353,
    TCI_CMD_GET_LIGHT_STATE_REQ                         = 0x0354,
    TCI_CMD_GET_LIGHT_STATE_RESP                        = 0x0355,
    
    TCI_CMD_PLAY_AUDIO_REQ                              = 0x0356,
    TCI_CMD_PLAY_AUDIO_RESP                             = 0x0357,
    
    TCI_CMD_SET_VOICE_PROMPT_STATUS_REQ                 = 0x0358,
    TCI_CMD_SET_VOICE_PROMPT_STATUS_RESP                = 0x0359,
    TCI_CMD_GET_VOICE_PROMPT_STATUS_REQ                 = 0x035A,
    TCI_CMD_GET_VOICE_PROMPT_STATUS_RESP                = 0x035B,
    
    IOTYPE_USER_IPCAM_SET_ENVIRONMENT_REQ               = 0x0360,
    IOTYPE_USER_IPCAM_SET_ENVIRONMENT_RESP              = 0x0361,
    IOTYPE_USER_IPCAM_GET_ENVIRONMENT_REQ               = 0x0362,
    IOTYPE_USER_IPCAM_GET_ENVIRONMENT_RESP              = 0x0363,
    
    TCI_CMD_SET_PARKING_DET_REQ                         = 0x0364,   // 设置停车监控
    TCI_CMD_SET_PARKING_DET_RESP                        = 0x0365,
    TCI_CMD_GET_PARKING_DET_REQ                         = 0x0366,   // 获取停车监控
    TCI_CMD_GET_PARKING_DET_RESP                        = 0x0367,
    
    IOTYPE_USER_IPCAM_SET_VIDEOMODE_REQ                 = 0x0370,   // Set Video Flip Mode
    IOTYPE_USER_IPCAM_SET_VIDEOMODE_RESP                = 0x0371,
    IOTYPE_USER_IPCAM_GET_VIDEOMODE_REQ                 = 0x0372,   // Get Video Flip Mode
    IOTYPE_USER_IPCAM_GET_VIDEOMODE_RESP                = 0x0373,
    
    TCI_CMD_SET_DEVICE_OSD_REQ                          = 0x0374,
    TCI_CMD_SET_DEVICE_OSD_RESP                         = 0x0375,
    TCI_CMD_GET_DEVICE_OSD_REQ                          = 0x0376,
    TCI_CMD_GET_DEVICE_OSD_RESP                         = 0x0377,
    
    IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_REQ              = 0x0380,   // Format external storage
    IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_RESP             = 0x0381,
    
    TCI_CMD_LIST_RECORDDAYS                             = 0x800A,   // < 返回SD卡上有录像的日期. req: none; resp: @ref Tcis_DaysList
    
    TCI_CMD_GET_EXTERNAL_STORAGE_REQ                    = 0x8030,  // 查询设备sd卡状态
    TCI_CMD_GET_EXTERNAL_STORAGE_RESP                   = 0x8031,
    
    TCI_CMD_GET_RUNTIME_STATE_REQ                       = 0x0388,   // 获取设备端运行状态
    TCI_CMD_GET_RUNTIME_STATE_RESP                      = 0x0389,
    
    IOTYPE_USER_IPCAM_GET_FLOWINFO_REQ                  = 0x0390,
    IOTYPE_USER_IPCAM_GET_FLOWINFO_RESP                 = 0x0391,
    IOTYPE_USER_IPCAM_CURRENT_FLOWINFO_REQ              = 0x0392,
    
    IOTYPE_USER_IPCAM_GET_TIMEZONE_REQ                  = 0x03A0,
    IOTYPE_USER_IPCAM_GET_TIMEZONE_RESP                 = 0x03A1,
    IOTYPE_USER_IPCAM_SET_TIMEZONE_REQ                  = 0x03B0,
    IOTYPE_USER_IPCAM_SET_TIMEZONE_RESP                 = 0x03B1,
    
    IOTYPE_USER_IPCAM_GET_EVENTCONFIG_REQ               = 0x0400,   // Get Event Config Msg Request
    IOTYPE_USER_IPCAM_GET_EVENTCONFIG_RESP              = 0x0401,   // Get Event Config Msg Response
    IOTYPE_USER_IPCAM_SET_EVENTCONFIG_REQ               = 0x0402,   // Set Event Config Msg req
    IOTYPE_USER_IPCAM_SET_EVENTCONFIG_RESP              = 0x0403,   // Set Event Config Msg resp
    
    TCI_CMD_SET_PTZ_POS_REQ                             = 0x0408,
    TCI_CMD_SET_PTZ_POS_RESP                            = 0x0409,
    TCI_CMD_GET_PTZ_POS_REQ                             = 0x040A,
    TCI_CMD_GET_PTZ_POS_RESP                            = 0x040B,
    
    TCI_CMD_SET_ENABLE_BT_REQ                           = 0x0410,   // AI人形追踪
    TCI_CMD_SET_ENABLE_BT_RESP                          = 0x0411,
    TCI_CMD_GET_ENABLE_BT_REQ                           = 0x0412,
    TCI_CMD_GET_ENABLE_BT_RESP                          = 0x0413,
    
    TCL_CMD_SET_CAMERA_STATUS_REQ                       = 0x0414,   // 设备开关
    TCL_CMD_SET_CAMERA_STATUS_RESP                      = 0x0415,
    TCL_CMD_GET_CAMERA_STATUS_REQ                       = 0x0416,
    TCL_CMD_GET_CAMERA_STATUS_RESP                      = 0x0417,
    
    TCI_CMD_GET_ALARMTONE_CAP_REQ                       = 0x041C,   // 获取支持的报警音频文件格式信息
    TCI_CMD_GET_ALARMTONE_CAP_RESP                      = 0x041D,
    TCI_CMD_SET_ALARMTONE_REQ                           = 0x041E,   // 设置报警音频
    TCI_CMD_SET_ALARMTONE_RESP                          = 0x041F,
    
    TCI_CMD_PLAY_ALARMTONE_REQ                          = 0x0420,   // 播放报警音
    TCI_CMD_PLAY_ALARMTONE_RESP                         = 0x0421,
    
    TCI_CMD_SET_LED_STATUS_REQ                          = 0x0422,
    TCI_CMD_SET_LED_STATUS_RESP                         = 0x0423,
    TCI_CMD_GET_LED_STATUS_REQ                          = 0x0424,
    TCI_CMD_GET_LED_STATUS_RESP                         = 0x0425,
    
    TCI_CMD_GET_BATTERY_STATUS_REQ                      = 0x0426,
    TCI_CMD_GET_BATTERY_STATUS_RESP                     = 0x0427,
    
    TCI_CMD_GET_WIFI_SIGNALLEVEL_REQ                    = 0x0428,
    TCI_CMD_GET_WIFI_SIGNALLEVEL_RESP                   = 0x0429,
    
    TCI_CMD_SET_MAX_AWAKE_TIME_REQ                      = 0x042A,
    TCI_CMD_SET_MAX_AWAKE_TIME_RESP                     = 0x042B,
    TCI_CMD_GET_MAX_AWAKE_TIME_REQ                      = 0x042C,
    TCI_CMD_GET_MAX_AWAKE_TIME_RESP                     = 0x042D,
    
    TCI_CMD_SET_GSENSOR_REQ                             = 0x0432,
    TCI_CMD_SET_GSENSOR_RESP                            = 0x0433,
    TCI_CMD_GET_GSENSOR_REQ                             = 0x0434,
    TCI_CMD_GET_GSENSOR_RESP                            = 0x0435,
    
    TCI_CMD_SET_ENABLE_DORMANCY_REQ        = 0x044A, ///< 设置允许或禁止休眠. 参数 @ref Tcis_DormancyState
    TCI_CMD_SET_ENABLE_DORMANCY_RESP       = 0x044B, ///< 设置允许或禁止休眠. 参数 @ref Tcis_DormancyState
    TCI_CMD_GET_ENABLE_DORMANCY_REQ        = 0x044C, ///< 获取当前休眠开关, 返回 @ref Tcis_DormancyState
    TCI_CMD_GET_ENABLE_DORMANCY_RESP        = 0x044D, ///< 获取当前休眠开关, 返回 @ref Tcis_DormancyState
    
    TCI_CMD_SET_AWAKE_TIME_REQ             = 0x0470,
    
    TCI_CMD_GET_AWAKE_TIME_REQ                 = 0x0472,
    TCI_CMD_GET_AWAKE_TIME_RESP            =  0x0473, ///< 获取设备的主动唤醒时间设置。参数 @ref Tcis_GetAwakeTimeReq, 应答 @ref Tcis_GetAwakeTimeRes
    
    TCI_CMD_SET_DEVICE_VOLUME_REQ                       = 0x0436,   // 设置设备喇叭音量
    TCI_CMD_SET_DEVICE_VOLUME_RESP                      = 0x0437,
    TCI_CMD_GET_DEVICE_VOLUME_REQ                       = 0x0438,   // 获取设备当前喇叭音量
    TCI_CMD_GET_DEVICE_VOLUME_RESP                      = 0x0439,
    
    TCI_CMD_SET_MIC_LEVEL_REQ                           = 0x043A,   // 设置拾音器灵敏度
    TCI_CMD_SET_MIC_LEVEL_RESP                          = 0x043B,
    TCI_CMD_GET_MIC_LEVEL_REQ                           = 0x043C,   // 获取拾音器灵敏度
    TCI_CMD_GET_MIC_LEVEL_RESP                          = 0x043D,
    
    TCI_CMD_SET_PRIMARY_VIEW_REQ                        = 0x043E,   // 设置画中画主面面通道
    TCI_CMD_SET_PRIMARY_VIEW_RESP                       = 0x043F,
    TCI_CMD_GET_PRIMARY_VIEW_REQ                        = 0x0440,   // 获取画中画主面面通道
    TCI_CMD_GET_PRIMARY_VIEW_RESP                       = 0x0441,
    
    TCI_CMD_SET_ALARMLIGHT_REQ                          = 0x0442,   // 设置报警灯状态
    TCI_CMD_SET_ALARMLIGHT_RESP                         = 0x0443,
    TCI_CMD_GET_ALARMLIGHT_REQ                          = 0x0444,   // 获取报警灯状态
    TCI_CMD_GET_ALARMLIGHT_RESP                         = 0x0445,
    
    TCI_CMD_GET_ALARM_BELL             = 0x041A, ///< 取警铃开关状态 see @ref Tcis_SetAlarmBell
    TCI_CMD_GET_ALARM_BELL_RESP        = 0x041B, ///< 取警铃开关状态 see @ref Tcis_SetAlarmBell
    TCI_CMD_SET_ALARM_BELL             = 0x0418, ///< 警铃开关 see @ref Tcis_SetAlarmBell
    TCI_CMD_SET_ALARM_BELL_RESP        = 0x0419, ///< 警铃开关 see @ref Tcis_SetAlarmBell
    
    TCI_CMD_SET_PIR_SENSITIVE_REQ                       = 0x0446,   // 设置Pir灵敏度
    TCI_CMD_SET_PIR_SENSITIVE_RESP                      = 0x0447,
    TCI_CMD_GET_PIR_SENSITIVE_REQ                       = 0x0448,   // 获取Pir灵敏度
    TCI_CMD_GET_PIR_SENSITIVE_RESP                      = 0x0449,
    
    TCI_CMD_ACSWERTOCALL_REQ                            = 0x0450,   // 门铃接听拒绝
    TCI_CMD_ACSWERTOCALL_RESP                           = 0x0451,
    
    TCI_CMD_GET_DEVICE_PSP_REQ                          = 0x0452,   // 获取设备预置位
    TCI_CMD_GET_DEVICE_PSP_RESP                         = 0x0453,
    TCI_CMD_SET_DEVICE_PSP_REQ                          = 0x0454,   // 设置设备预置位
    TCI_CMD_SET_DEVICE_PSP_RESP                         = 0x0455,
    
    TCI_CMD_SET_WATCH_POS_REQ                           = 0x0456,   // 设置设备看守位
    TCI_CMD_SET_WATCH_POS_RESP                          = 0x0457,
    TCI_CMD_GET_WATCH_POS_REQ                           = 0x0458,   // 获取设备看守位
    TCI_CMD_GET_WATCH_POS_RESP                          = 0x0459,
    
    TCI_CMD_UNLOCK_LOCKBELL_REQ                         = 0x045A,
    TCI_CMD_UNLOCK_LOCKBELL_RESP                        = 0x045B,
    TCI_CMD_GET_LOCK_STATE_REQ                          = 0x045C,
    TCI_CMD_GET_LOCK_STATE_RESP                         = 0x045D,
    
    TCI_CMD_SET_PTZ_TRACK_REQ                           = 0x0474,
    TCI_CMD_SET_PTZ_TRACK_RESP                          = 0x0475,
    TCI_CMD_GET_PTZ_TRACK_REQ                           = 0x0476,   // 获取巡航设置
    TCI_CMD_GET_PTZ_TRACK_RESP                          = 0x0477,
    
    TCI_CMD_SET_SITPOSE_SENS_REQ                        = 0x0478,   // 设置坐姿检测灵敏度
    TCI_CMD_SET_SITPOSE_SENS_RESP                       = 0x0479,
    TCI_CMD_GET_SITPOSE_SENS_REQ                        = 0x047A,   // 获取坐姿检测灵敏度
    TCI_CMD_GET_SITPOSE_SENS_RESP                       = 0x047B,
    
    TCI_CMD_SET_HINTTONE_REQ                            = 0x0480,   // 设置提示音
    TCI_CMD_SET_HINTTONE_RESP                           = 0x0481,
    TCI_CMD_GET_HINTTONE_REQ                            = 0x0482,   // 获取提示音
    TCI_CMD_GET_HINTTONE_RESP                           = 0x0483,
    
    TCI_CMD_SET_PARKING_MONITOR_REQ                     = 0x0484,   // 设置停车监控开关
    TCI_CMD_SET_PARKING_MONITOR_RESP                    = 0x0485,
    TCI_CMD_GET_PARKING_MONITOR_REQ                     = 0x0486,   // 获取停车监控开关
    TCI_CMD_GET_PARKING_MONITOR_RESP                    = 0x0487,
    
    TCI_CMD_SET_TIMER_TASK_REQ                          = 0x0488,   // 设置定时任务
    TCI_CMD_SET_TIMER_TASK_RESP                         = 0x0489,
    TCI_CMD_GET_TIMER_TASK_REQ                          = 0x048A,   // 获取定时任务
    TCI_CMD_GET_TIMER_TASK_RESP                         = 0x048B,
    
    
    // dropbox support
    IOTYPE_USER_IPCAM_GET_SAVE_DROPBOX_REQ              = 0x0500,
    IOTYPE_USER_IPCAM_GET_SAVE_DROPBOX_RESP             = 0x0501,
    IOTYPE_USER_IPCAM_SET_SAVE_DROPBOX_REQ              = 0x0502,
    IOTYPE_USER_IPCAM_SET_SAVE_DROPBOX_RESP             = 0x0503,
    
    /*------------------------自定义----------------------------------------------*/
    IOTYPE_USEREX_IPCAM_LISTEVENT_REQ                   = 0x8000,   // SD卡回放列表
    IOTYPE_USEREX_IPCAM_LISTEVENT_RESP                  = 0x8001,
    
    TCI_CMD_CHECK_PASSWORD_REQ                          = 0x8002,   // 校验密码
    TCI_CMD_CHECK_PASSWORD_RESP                         = 0x8003,
    
    IOTYPE_USEREX_IPCAM_APLINK_SETWIFI_REQ              = 0x8006,   // 设置密码
    IOTYPE_USEREX_IPCAM_APLINK_SETWIFI_RESP             = 0x8007,
    
    IOTYPE_USEREX_IPCAM_DEV_REBOOT_REQ                  = 0x8010,   // 重启设备
    IOTYPE_USEREX_IPCAM_DEV_REBOOT_RESP                 = 0x8011,
    
    TCI_CMD_GET_WHITELIGHT_REQ                          = 0x8012,   // 白光灯
    TCI_CMD_GET_WHITELIGHT_RESP                         = 0x8013,
    TCI_CMD_SET_WHITELIGHT_REQ                          = 0x8014,
    TCI_CMD_SET_WHITELIGHT_RESP                         = 0x8015,
    
    TCI_CMD_GET_DAYNIGHT_REQ                            = 0x8016,   // 夜视
    TCI_CMD_GET_DAYNIGHT_RESP                           = 0x8017,
    TCI_CMD_SET_DAYNIGHT_REQ                            = 0x8018,
    TCI_CMD_SET_DAYNIGHT_RESP                           = 0x8019,
    
    IOTYPE_USEREX_IPCAM_GET_MOTION_TRACKER_REQ          = 0x8020,   // 移动追踪
    IOTYPE_USEREX_IPCAM_GET_MOTION_TRACKER_RESP         = 0x8021,
    IOTYPE_USEREX_IPCAM_SET_MOTION_TRACKER_REQ          = 0x8022,
    IOTYPE_USEREX_IPCAM_SET_MOTION_TRACKER_RESP         = 0x8023,
    
    IOTYPE_USEREX_IPCAM_GET_FEATURE_REQ                 = 0x8024,   // 查询设备硬件能力
    IOTYPE_USEREX_IPCAM_GET_FEATURE_RESP                = 0x8025,
    
    IOTYPE_USEREX_IPCAM_GET_CLOUD_VIDEO_QUALITY_REQ     = 0x8026,   // 上传云录像清晰度
    IOTYPE_USEREX_IPCAM_GET_CLOUD_VIDEO_QUALITY_RESP    = 0x8027,
    IOTYPE_USEREX_IPCAM_SET_CLOUD_VIDEO_QUALITY_REQ     = 0x8028,
    IOTYPE_USEREX_IPCAM_SET_CLOUD_VIDEO_QUALITY_RESP    = 0x8029,
    
    TCI_CMD_GET_MICROPHONE_REQ                          = 0x8032,   // 查询麦克风开关
    TCI_CMD_GET_MICROPHONE_RESP                         = 0x8033,
    TCI_CMD_SET_MICROPHONE_REQ                          = 0x8034,
    TCI_CMD_SET_MICROPHONE_RESP                         = 0x8035,
    
    TCI_CMD_GET_BUZZER_REQ                              = 0x8036,   // 蜂鸣器
    TCI_CMD_GET_BUZZER_RESP                             = 0x8037,
    TCI_CMD_SET_BUZZER_REQ                              = 0x8038,
    TCI_CMD_SET_BUZZER_RESP                             = 0x8039,
    
    
    TCI_CMD_PTZ_SHORT_COMMAND_REQ                       = 0x1000,
    TCI_CMD_PTZ_LONG_COMMAND_REQ                        = 0x1001,   // P2P PTZ Command Msg
    
    TCI_CMD_LOCATE_IN_PIC_REQ                           = 0x1002,   // Send from client, used to talk to device that
                                                                    // client had received the first I frame
    IOTYPE_USER_IPCAM_EVENT_REPORT_REQ                  = 0x1FFF,   // Device Event Report Msg
    /*---------------------------------------------------------------------------*/
    
    IOTYPE_USER_CMD_MAX
    
}ENUM_AVIOCTRL_MSGTYPE;

// AVIOCTRL Quality Type
typedef enum{
    AVIOCTRL_QUALITY_UNKNOWN                            = 0x00,
    AVIOCTRL_QUALITY_MAX                                = 0x01,     // ex. 640*480, 15fps, 320kbps (or 1280x720, 5fps, 320kbps)
    AVIOCTRL_QUALITY_HIGH                               = 0x02,     // ex. 640*480, 10fps, 256kbps
    AVIOCTRL_QUALITY_MIDDLE                             = 0x03,     // ex. 320*240, 15fps, 256kbps
    AVIOCTRL_QUALITY_LOW                                = 0x04,     // ex. 320*240, 10fps, 128kbps
    AVIOCTRL_QUALITY_MIN                                = 0x05,     // ex. 160*120, 10fps, 64kbps
}ENUM_QUALITY_LEVEL;

typedef enum ENUM_RECORD_TYPE
{
    AVIOTC_RECORDTYPE_OFF                = 0x00, ///< 不录像
    AVIOTC_RECORDTYPE_ALARM              = 0x01, ///< 报警录像
    AVIOTC_RECORDTYPE_FULLTIME           = 0x02, ///< 全天录像
    AVIOTC_RECORDTYPE_AUTO               = 0x03, ///< 自动录像
} ENUM_RECORD_TYPE;

// AVIOCTRL Play Record Command
typedef enum{
    AVIOCTRL_RECORD_PLAY_PAUSE                          = 0x00,
    AVIOCTRL_RECORD_PLAY_STOP                           = 0x01,
    AVIOCTRL_RECORD_PLAY_STEPFORWARD                    = 0x02,     // now, APP no use
    AVIOCTRL_RECORD_PLAY_STEPBACKWARD                   = 0x03,     // now, APP no use
    AVIOCTRL_RECORD_PLAY_FORWARD                        = 0x04,     // now, APP no use
    AVIOCTRL_RECORD_PLAY_BACKWARD                       = 0x05,     // now, APP no use
    AVIOCTRL_RECORD_PLAY_SEEKTIME                       = 0x06,     // now, APP no use
    AVIOCTRL_RECORD_PLAY_END                            = 0x07,
    AVIOCTRL_RECORD_PLAY_CONTINUE                       = 0x08,
    AVIOCTRL_RECORD_PLAY_START                          = 0x10,
}ENUM_PLAYCONTROL;

// AVIOCTRL Environment Mode
typedef enum{
    AVIOCTRL_ENVIRONMENT_INDOOR_50HZ                    = 0x00,    // 50Hz 电源
    AVIOCTRL_ENVIRONMENT_INDOOR_60HZ                    = 0x01,    // 60Hz 电源
    AVIOCTRL_ENVIRONMENT_OUTDOOR                        = 0x02,
    AVIOCTRL_ENVIRONMENT_NIGHT                          = 0x03,
}ENUM_ENVIRONMENT_MODE;

// AVIOCTRL Video Flip Mode
typedef enum{
    AVIOCTRL_VIDEOMODE_NORMAL                           = 0x00,     ///< 正常
    AVIOCTRL_VIDEOMODE_FLIP                             = 0x01,     ///< 上下翻转
    AVIOCTRL_VIDEOMODE_MIRROR                           = 0x02,     ///< 左右镜像
    AVIOCTRL_VIDEOMODE_FLIP_MIRROR                      = 0x03,     ///< 旋转180度 
}ENUM_VIDEO_MODE;

/** PTZ Command Value */
typedef enum ENUM_PTZCMD
{
    TCIC_PTZ_STOP                      = 0, ///< 停止
    TCIC_PTZ_UP                        = 1, ///< 向上
    TCIC_PTZ_DOWN                      = 2, ///< 向下
    TCIC_PTZ_LEFT                      = 3, ///< 向左
    TCIC_PTZ_LEFT_UP                   = 4, ///< 左上
    TCIC_PTZ_LEFT_DOWN                 = 5, ///< 左下
    TCIC_PTZ_RIGHT                     = 6, ///< 向右
    TCIC_PTZ_RIGHT_UP                  = 7, ///< 右上
    TCIC_PTZ_RIGHT_DOWN                = 8, ///< 右下
 
    TCIC_PTZ_AUTO_SCAN                 = 9, ///< 自动线扫
    TCIC_PTZ_CALL_TRACK                = 10, ///< 调用巡航. Tcis_PtzCmd::point 为巡航轨迹号. 0为默认轨迹
    //TCIC_PTZ_SET_POINT                 = 10,
    //TCIC_PTZ_CLEAR_POINT               = 11,
    TCIC_PTZ_GOTO_POINT                = 12, ///< 调用预置位. Tcis_PtzCmd::point 为预置位编号
#if 0
    TCIC_PTZ_SET_MODE_START            = 13,
    TCIC_PTZ_SET_MODE_STOP             = 14,
    TCIC_PTZ_MODE_RUN                  = 15,
 
    TCIC_PTZ_MENU_OPEN                 = 16,
    TCIC_PTZ_MENU_EXIT                 = 17,
    TCIC_PTZ_MENU_ENTER                = 18,
#endif
    TCIC_PTZ_FLIP                      = 19,
    TCIC_PTZ_START                     = 20,
 
    TCIC_LENS_APERTURE_OPEN            = 21,
    TCIC_LENS_APERTURE_CLOSE           = 22,
 
    TCIC_LENS_ZOOM_IN                  = 23, ///< Zoom In
    TCIC_LENS_ZOOM_OUT                 = 24, ///< Zoom Out
 
    TCIC_LENS_FOCAL_NEAR               = 25, ///< Focus Near
    TCIC_LENS_FOCAL_FAR                = 26, ///< Focus Far
#if 0
    TCIC_AUTO_PAN_SPEED                = 27,
    TCIC_AUTO_PAN_LIMIT                = 28,
    TCIC_AUTO_PAN_START                = 29,
 
    TCIC_PATTERN_START                 = 30,
    TCIC_PATTERN_STOP                  = 31,
    TCIC_PATTERN_RUN                   = 32,
 
    TCIC_SET_AUX                       = 33,
    TCIC_CLEAR_AUX                     = 34,
#endif
    TCIC_MOTOR_RESET_POSITION          = 35, ///< 云台复位. 本指令要求在复位完成后给一个通用结构的应答
 
} ENUM_PTZCMD;

/*
 TCI_CMD_GET_WHITELIGHT_RESP        = 0x8013,
** @struct SMsgAVIoctrlGetWhiteLightResq
*/
typedef struct{
    unsigned int channel;    // Camera Index
    unsigned int support;    // 0:不支持，2:支持两种模式，3:支持三种模式； — ???
    unsigned char mode;      // 当前模式:0 - 关闭（白光不工作）1 - 打开（全彩色）2 - 智能模式（移动侦测触发自动白光）3 - 定时开关(DoubleLight 能力要有 "Timer" 属性
    unsigned char reserved[3];
}SMsgAVIoctrlGetWhiteLightResp;

/*
 TCI_CMD_SET_WHITELIGHT_RESP        = 0x8015,0x8019
** @struct SMsgAVIoctrlSetWhiteLightResp
*/
typedef struct{
    unsigned int result;    // 1 ok , !1 no ok
    unsigned char reserved[4];
}SMsgAVIoctrlSetWhiteLightResp,Tcis_SetDayNightResp;

/*
 TCI_CMD_SET_LED_STATUS         = 0x0422,0x0424
** @struct SMsgAVIoctrlSetLedStausReq
*/
typedef struct{
    unsigned int status;    // 0-关闭，1-打开
    unsigned char reserved[4];
}SMsgAVIoctrlSetLedStausReq,SMsgAVIoctrlGetLedStausResp;

/*
 TCI_CMD_SET_ALARMLIGHT         = 0x0442,0x0444
** @struct SMsgAVIoctrlSetWhiteLightResq
*/
typedef struct{
    unsigned int channel;    // id of light: 0
    unsigned int state;       // 0:关; 1:开; 2:自动; 3:按定时设置
}SMsgAVIoctrlSetAlarmLightReq,SMsgAVIoctrlGetAlarmLightResp;

/*
IOTYPE_USER_IPCAM_START_REQ                 = 0x01FF,
IOTYPE_USER_IPCAM_STOP_REQ                     = 0x02FF,
IOTYPE_USER_IPCAM_AUDIOSTART_REQ             = 0x0300,
IOTYPE_USER_IPCAM_AUDIOSTOP_REQ             = 0x0301,
IOTYPE_USER_IPCAM_SPEAKERSTART_REQ             = 0x0350,
IOTYPE_USER_IPCAM_SPEAKERSTOP_REQ             = 0x0351,
IOTYPE_USER_IPCAM_PUSH_STREAMING_START_REQ  = 0x600,
IOTYPE_USER_IPCAM_PUSH_STREAMING_STOP   = 0x601,
** @struct SMsgAVIoctrlAVStream
*/
typedef struct{
    unsigned int avIndex; // p2p通道号
    unsigned int channel; // 视频通道号
} SMsgAVIoctrlAVStream;

/*
IOTYPE_USER_IPCAM_GETSTREAMCTRL_REQ        = 0x0322,
** @struct SMsgAVIoctrlGetStreamCtrlReq
*/
typedef struct{
    unsigned int channel;    // Camera Index
    unsigned char reserved[4];
}SMsgAVIoctrlGetStreamCtrlReq;

/*
IOTYPE_USER_IPCAM_SETSTREAMCTRL_REQ        = 0x0320,
IOTYPE_USER_IPCAM_GETSTREAMCTRL_RESP    = 0x0323,
** @struct SMsgAVIoctrlSetStreamCtrlReq, SMsgAVIoctrlGetStreamCtrlResq
*/
typedef struct{
    unsigned int  channel;    // Camera Index
    unsigned char quality;    //refer to ENUM_QUALITY_LEVEL
    unsigned char reserved[3];
} SMsgAVIoctrlSetStreamCtrlReq, SMsgAVIoctrlGetStreamCtrlResq;

/*
IOTYPE_USER_IPCAM_SETSTREAMCTRL_RESP    = 0x0321,
** @struct SMsgAVIoctrlSetStreamCtrlResp
*/
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
}SMsgAVIoctrlSetStreamCtrlResp;

/*
IOTYPE_USER_IPCAM_SETMOTIONDETECT_RESP    = 0x0325,
** @struct SMsgAVIoctrlSetMotionDetectResp
*/
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
}SMsgAVIoctrlSetMotionDetectResp;

/*
IOTYPE_USER_IPCAM_DEVINFO_REQ            = 0x0330,
** @struct SMsgAVIoctrlDeviceInfoReq
*/
typedef struct{
    unsigned char reserved[4];
}SMsgAVIoctrlDeviceInfoReq;

/*
IOTYPE_USER_IPCAM_DEVINFO_RESP            = 0x0331,
** @struct SMsgAVIoctrlDeviceInfo
*/
typedef struct{
    unsigned char model[16];    // IPCam mode
    unsigned char vendor[16];    // IPCam manufacturer
    unsigned int version;        // IPCam firmware version    ex. v1.2.3.4 => 0x01020304;  v1.0.0.2 => 0x01000002
    unsigned int channel;        // Camera index
    unsigned int total;            // 0: No cards been detected or an unrecognizeable sdcard that could not be re-formatted.
                                // -1: if camera detect an unrecognizable sdcard, and could be re-formatted
                                // otherwise: return total space size of sdcard (MBytes)
                                
    unsigned int free;            // Free space size of sdcard (MBytes)
    unsigned char reserved[8];    // reserved
}SMsgAVIoctrlDeviceInfoResp;

/*
IOTYPE_USER_IPCAM_SETPASSWORD_REQ        = 0x0332,
** @struct SMsgAVIoctrlSetPasswdReq
*/
typedef struct{
    char oldpasswd[32];            // The old security code
    char newpasswd[32];            // The new security code
}SMsgAVIoctrlSetPasswdReq;

/*
IOTYPE_USER_IPCAM_SETPASSWORD_RESP        = 0x0333,
** @struct SMsgAVIoctrlSetPasswdResp
*/
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
}SMsgAVIoctrlSetPasswdResp;



/** 休眠状态
 TCI_CMD_SET_GSENSOR_REQ                             = 0x0432,
 TCI_CMD_GET_GSENSOR_REQ                             = 0x0434,
 */
typedef struct SMsgAVIoctrlDormancyState {
    int enable;    ///< 1:允许休眠; 0:禁止休眠
    int reserved;
} SMsgAVIoctrlDormancyState;

/*
IOTYPE_USER_IPCAM_LISTWIFIAP_REQ        = 0x0340,
** @struct SMsgAVIoctrlListWifiApReq
*/
typedef struct{
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlListWifiApReq;

typedef struct{
    char ssid[32];                 // WiFi ssid
    char mode;                     // refer to ENUM_AP_MODE
    char enctype;                  // refer to ENUM_AP_ENCTYPE
    char signal;                   // signal intensity 0--100%
    char status;                   // 0 : invalid ssid or disconnected
                                // 1 : connected with default gateway
                                // 2 : unmatched password
                                // 3 : weak signal and connected
                                // 4 : selected:
                                //        - password matched and
                                //        - disconnected or connected but not default gateway
} __attribute__((__packed__)) SWifiAp;

/*
IOTYPE_USER_IPCAM_LISTWIFIAP_RESP        = 0x0341,
** @struct SMsgAVIoctrlListWifiApResp
*/
typedef struct{
    unsigned int number; // MAX number: 1024(IOCtrl packet size) / 36(bytes) = 28
    SWifiAp stWifiAp[1];
} __attribute__((__packed__)) SMsgAVIoctrlListWifiApResp;

/*
IOTYPE_USER_IPCAM_SETWIFI_REQ            = 0x0342,
** @struct SMsgAVIoctrlSetWifiReq
*/
typedef struct{
    unsigned char ssid[32];            //WiFi ssid
    unsigned char password[32];        //if exist, WiFi password
    unsigned char mode;                //refer to ENUM_AP_MODE
    unsigned char enctype;            //refer to ENUM_AP_ENCTYPE
    unsigned char reserved[10];
} __attribute__((__packed__)) SMsgAVIoctrlSetWifiReq;

//IOTYPE_USER_IPCAM_SETWIFI_REQ_2        = 0x0346,
typedef struct{
    unsigned char ssid[32];        // WiFi ssid
    unsigned char password[64];    // if exist, WiFi password
    unsigned char mode;            // refer to ENUM_AP_MODE
    unsigned char enctype;        // refer to ENUM_AP_ENCTYPE
    unsigned char reserved[10];
} __attribute__((__packed__)) SMsgAVIoctrlSetWifiReq2;

/*
IOTYPE_USER_IPCAM_SETWIFI_RESP            = 0x0343,
** @struct SMsgAVIoctrlSetWifiResp
*/
typedef struct{
    int result; //0: wifi connected; 1: failed to connect
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlSetWifiResp;

/*
IOTYPE_USER_IPCAM_GETWIFI_REQ            = 0x0344,
** @struct SMsgAVIoctrlGetWifiReq
*/
typedef struct{
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlGetWifiReq;

/*
IOTYPE_USER_IPCAM_GETWIFI_RESP            = 0x0345,
** @struct SMsgAVIoctrlGetWifiResp //if no wifi connected, members of SMsgAVIoctrlGetWifiResp are all 0
*/
typedef struct{
    unsigned char ssid[32];        // WiFi ssid
    unsigned char password[32]; // WiFi password if not empty
    unsigned char mode;            // refer to ENUM_AP_MODE
    unsigned char enctype;        // refer to ENUM_AP_ENCTYPE
    unsigned char signal;        // signal intensity 0--100%
    unsigned char status;        // refer to "status" of SWifiAp
} __attribute__((__packed__)) SMsgAVIoctrlGetWifiResp;

//changed: WI-FI Password 32bit Change to 64bit
//IOTYPE_USER_IPCAM_GETWIFI_RESP_2    = 0x0347,
typedef struct{
 unsigned char ssid[32];     // WiFi ssid
 unsigned char password[64]; // WiFi password if not empty
 unsigned char mode;    // refer to ENUM_AP_MODE
 unsigned char enctype; // refer to ENUM_AP_ENCTYPE
 unsigned char signal;  // signal intensity 0--100%
 unsigned char status;  // refer to "status" of SWifiAp
} __attribute__((__packed__)) SMsgAVIoctrlGetWifiResp2;

/*
IOTYPE_USER_IPCAM_GETRECORD_REQ            = 0x0312,
** @struct SMsgAVIoctrlGetRecordReq
*/
typedef struct{
    unsigned int channel; // Camera Index
    unsigned char reserved[4];
}SMsgAVIoctrlGetRecordReq;

/*
IOTYPE_USER_IPCAM_SETRECORD_REQ            = 0x0310,
IOTYPE_USER_IPCAM_GETRECORD_RESP        = 0x0313,
** @struct SMsgAVIoctrlSetRecordReq, SMsgAVIoctrlGetRecordResq
*/
typedef struct{
    unsigned int channel;           // Camera Index:0
    unsigned int recordType;        // Refer to @ref ENUM_RECORD_TYPE
    unsigned char recordStream;     // SD卡录像清晰度:0-高清，1-标清
    unsigned char flags;            // "Misc"能力bit0为1时, flags为0x01表示不录声音。 其余忽略(录声音)
    unsigned char reserved[2];
} __attribute__((__packed__)) SMsgAVIoctrlSetRecordReq, SMsgAVIoctrlGetRecordResq;

/*
IOTYPE_USER_IPCAM_SETRECORD_RESP        = 0x0311,
** @struct SMsgAVIoctrlSetRecordResp
*/
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlSetRecordResp;

/*
IOTYPE_USER_IPCAM_GETRCD_DURATION_REQ    = 0x0316,
** @struct SMsgAVIoctrlGetRcdDurationReq
*/
typedef struct{
    unsigned int channel; // Camera Index
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlGetRcdDurationReq;

/*
IOTYPE_USER_IPCAM_SETRCD_DURATION_REQ    = 0x0314,
IOTYPE_USER_IPCAM_GETRCD_DURATION_RESP  = 0x0317,
** @struct SMsgAVIoctrlSetRcdDurationReq, SMsgAVIoctrlGetRcdDurationResp
*/
typedef struct{
    unsigned int channel;         // Camera Index
    unsigned int presecond;     // pre-recording (sec)
    unsigned int durasecond;    // recording (sec)
} __attribute__((__packed__)) SMsgAVIoctrlSetRcdDurationReq, SMsgAVIoctrlGetRcdDurationResp;

/*
IOTYPE_USER_IPCAM_SETRCD_DURATION_RESP  = 0x0315,
** @struct SMsgAVIoctrlSetRcdDurationResp
*/
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlSetRcdDurationResp;

//typedef struct{
//    unsigned short year;    // The number of year.
//    unsigned char month;    // The number of months since January, in the range 1 to 12.
//    unsigned char day;        // The day of the month, in the range 1 to 31.
//    unsigned char wday;        // The number of days since Sunday, in the range 0 to 6. (Sunday = 0, Monday = 1, ...)
//    unsigned char hour;     // The number of hours past midnight, in the range 0 to 23.
//    unsigned char minute;   // The number of minutes after the hour, in the range 0 to 59.
//    unsigned char second;   // The number of seconds after the minute, in the range 0 to 59.
//} __attribute__((__packed__)) STimeDay;

/** 日期表示 */
typedef struct {
    unsigned short year;  ///< year
    unsigned char  month; ///< month: 1~12
    unsigned char  day;   ///< day: 1~31
} __attribute__((__packed__)) SDay;

typedef struct{
    unsigned short year;    // The number of year.
    unsigned char month;    // The number of months since January, in the range 1 to 12.
    unsigned char day;        // The day of the month, in the range 1 to 31.
    unsigned char wday;        // The number of days since Sunday, in the range 0 to 6. (Sunday = 0, Monday = 1, ...)
    unsigned char hour;     // The number of hours past midnight, in the range 0 to 23.
    unsigned char minute;   // The number of minutes after the hour, in the range 0 to 59.
    unsigned char second;   // The number of seconds after the minute, in the range 0 to 59.
} __attribute__((__packed__)) STimeDay;

/*
IOTYPE_USER_IPCAM_LISTEVENT_REQ            = 0x0318,
** @struct SMsgAVIoctrlListEventReq
*/
typedef struct{
    unsigned int channel;         // Camera Index
    STimeDay stStartTime;         // Search event from ...
    STimeDay stEndTime;              // ... to (search event)
    unsigned char event;          // event type, refer to ENUM_EVENTTYPE
    unsigned char status;         // 0x00: Recording file exists, Event unreaded
                                // 0x01: Recording file exists, Event readed
                                // 0x02: No Recording file in the event
    unsigned char reserved[2];
}SMsgAVIoctrlListEventReq;

typedef struct{
    STimeDay stTime;
    unsigned char event;
    unsigned char status;    // 0x00: Recording file exists, Event unreaded
                            // 0x01: Recording file exists, Event readed
                            // 0x02: No Recording file in the event
    unsigned char reserved[2];
}SAvEvent;
    
/*
IOTYPE_USER_IPCAM_LISTEVENT_RESP        = 0x0319,
** @struct SMsgAVIoctrlListEventResp
*/
typedef struct{
    unsigned int  channel;        // Camera Index
    unsigned int  total;        // Total event amount in this search session
    unsigned char index;        // package index, 0,1,2...;
                                // because avSendIOCtrl() send package up to 1024 bytes one time, you may want split search results to serveral package to send.
    unsigned char endflag;        // end flag; endFlag = 1 means this package is the last one.
    unsigned char count;        // how much events in this package
    unsigned char reserved[1];
    SAvEvent stEvent[1];        // The first memory address of the events in this package
}SMsgAVIoctrlListEventResp;

/*
IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL_REQ     = 0x031A,
** @struct SMsgAVIoctrlPlayRecord
*/
typedef struct{
    unsigned int avIndex;       ///< avIndex
    unsigned int command;       ///< play record command. refer to @ref ENUM_PLAYCONTROL
    unsigned int Param;         ///< command param. Depend on \c command
    STimeDay stTimeDay;         ///< Event time from ListEventi @ref STimeDay
    unsigned int channel;
    /**< 在 ENUM_PLAYCONTROL::TCIC_RECORD_PLAY_START/ENUM_PLAYCONTROL::TCIC_RECORD_PLAY_STOP 里用于选择视频通道
         *  - 0 所有通道
         *  - >0 通道号+1. 例如为1时选择通道0
         */
    
} __attribute__((__packed__)) SMsgAVIoctrlPlayRecord;

/*
IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL_RESP     = 0x031B,
** @struct SMsgAVIoctrlPlayRecordResp
*/
typedef struct{
    unsigned int command;    // Play record command. refer to ENUM_PLAYCONTROL
    unsigned int result;     // Depends on command
                            // when is AVIOCTRL_RECORD_PLAY_START:
                            //    result>=0   real channel no used by device for playback
                            //    result <0    error
                            //            -1    playback error
                            //            -2    exceed max allow client amount
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlPlayRecordResp; // only for play record start command


/*
IOTYPE_USER_IPCAM_PTZ_LONG_COMMAND    = 0x1001,    // P2P Ptz Command Msg
** @struct Tcis_PtzCmd
*/
typedef struct Tcis_PtzCmd {
    unsigned char control;    ///< PTZ control command, refer to @ref ENUM_PTZCMD
    unsigned char speed;      ///< PTZ control speed
    unsigned char point;      ///< 预置位(control=TCIC_PTZ_GOTO_POINT)或巡航轨迹号(control=TCIC_PTZ_CALL_TRACK)
    unsigned char limit;      ///< 0
    unsigned char aux;        ///< 0
    unsigned char channel;    ///< camera index
    unsigned char reserve[2];
} __attribute__((__packed__)) Tcis_PtzCmd;

typedef struct{
    int x;
    int y;
    int zoom;
} __attribute__((__packed__)) PtzSpace_t;

typedef struct{
    PtzSpace_t space;
    int channel;            //通道号
    int focus;              //>0，far，<0，near
} __attribute__((__packed__)) SMsgAVIoctrlPtzShortCmd;

/*
IOTYPE_USER_IPCAM_EVENT_REPORT_REQ    = 0x1FFF,    // Device Event Report Msg
*/
/** @struct SMsgAVIoctrlEvent
 */
typedef struct{
    STimeDay stTime;
    unsigned long time;     // UTC Time
    unsigned int  channel;     // Camera Index
    unsigned int  event;     // Event Type
    unsigned char reserved[4];
} SMsgAVIoctrlEvent;


#if 0

/*     IOTYPE_USER_IPCAM_GET_EVENTCONFIG_REQ    = 0x0400,    // Get Event Config Msg Request
 */
/** @struct SMsgAVIoctrlGetEventConfig
 */
typedef struct{
    unsigned int    channel;           //Camera Index
    unsigned char   externIoOutIndex; //extern out index: bit0->io0 bit1->io1 ... bit7->io7;=1: get this io value or not get
    unsigned char   externIoInIndex;  //extern in index: bit0->io0 bit1->io1 ... bit7->io7; =1: get this io value or not get
    char reserved[2];
} SMsgAVIoctrlGetEventConfig;
 
/*
    IOTYPE_USER_IPCAM_GET_EVENTCONFIG_RESP    = 0x0401,    // Get Event Config Msg Response
    IOTYPE_USER_IPCAM_SET_EVENTCONFIG_REQ    = 0x0402,    // Set Event Config Msg req
*/
/* @struct SMsgAVIoctrlSetEventConfig
 * @struct SMsgAVIoctrlGetEventCfgResp
 */
typedef struct{
    unsigned int    channel;        // Camera Index
    unsigned char   mail;           // enable send email
    unsigned char   ftp;            // enable ftp upload photo
    unsigned char   externIoOutStatus;   // enable extern io output //bit0->io0 bit1->io1 ... bit7->io7; 1:on; 0:off
    unsigned char   p2pPushMsg;             // enable p2p push msg
    unsigned char   externIoInStatus;    // enable extern io input  //bit0->io0 bit1->io1 ... bit7->io7; 1:on; 0:off
    char            reserved[3];
}SMsgAVIoctrlSetEventConfig, SMsgAVIoctrlGetEventCfgResp;

/*
    IOTYPE_USER_IPCAM_SET_EVENTCONFIG_RESP    = 0x0403,    // Set Event Config Msg resp
*/
/** @struct SMsgAVIoctrlSetEventCfgResp
 */
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned int result;    // 0: success; otherwise: failed.
}SMsgAVIoctrlSetEventCfgResp;

#endif

/*
IOTYPE_USER_IPCAM_SET_ENVIRONMENT_REQ        = 0x0360,
** @struct SMsgAVIoctrlSetEnvironmentReq
*/
typedef struct{
    unsigned int channel;        // Camera Index
    unsigned char mode;            // refer to ENUM_ENVIRONMENT_MODE
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlSetEnvironmentReq;


/*
IOTYPE_USER_IPCAM_SET_ENVIRONMENT_RESP        = 0x0361,
** @struct SMsgAVIoctrlSetEnvironmentResp
*/
typedef struct{
    unsigned int channel;         // Camera Index
    unsigned char result;        // 0: success; otherwise: failed.
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlSetEnvironmentResp;


/*
IOTYPE_USER_IPCAM_GET_ENVIRONMENT_REQ        = 0x0362,
** @struct SMsgAVIoctrlGetEnvironmentReq
*/
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlGetEnvironmentReq;

/*
IOTYPE_USER_IPCAM_GET_ENVIRONMENT_RESP        = 0x0363,
** @struct SMsgAVIoctrlGetEnvironmentResp
*/
typedef struct{
    unsigned int channel;         // Camera Index
    unsigned char mode;            // refer to ENUM_ENVIRONMENT_MODE
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlGetEnvironmentResp;

/*
IOTYPE_USER_IPCAM_SET_VIDEOMODE_REQ            = 0x0370,
** @struct SMsgAVIoctrlSetVideoModeReq
*/
typedef struct{
    unsigned int channel;    // Camera Index
    unsigned char mode;        // refer to ENUM_VIDEO_MODE
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlSetVideoModeReq;


/*
IOTYPE_USER_IPCAM_SET_VIDEOMODE_RESP        = 0x0371,
** @struct SMsgAVIoctrlSetVideoModeResp
*/
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char result;    // 0: success; otherwise: failed.
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlSetVideoModeResp;


/*
IOTYPE_USER_IPCAM_GET_VIDEOMODE_REQ            = 0x0372,
** @struct SMsgAVIoctrlGetVideoModeReq
*/
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlGetVideoModeReq;


/*
IOTYPE_USER_IPCAM_GET_VIDEOMODE_RESP        = 0x0373,
** @struct SMsgAVIoctrlGetVideoModeResp
*/
typedef struct{
    unsigned int  channel;     // Camera Index
    unsigned char mode;        // refer to ENUM_VIDEO_MODE
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlGetVideoModeResp;

/*
/IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_REQ            = 0x0380,
** @struct SMsgAVIoctrlFormatExtStorageReq
*/
typedef struct{
    unsigned int storage;     // Storage index (ex. sdcard slot = 0, internal flash = 1, ...)
    unsigned char reserved[4];
} __attribute__((__packed__)) SMsgAVIoctrlFormatExtStorageReq;


/*
IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_REQ        = 0x0381,
** @struct SMsgAVIoctrlFormatExtStorageResp
*/
typedef struct{
    unsigned int  storage;     // Storage index
    unsigned char result;    // 0: success;
                            // -1: format command is not supported.
                            // otherwise: failed.
    unsigned char reserved[3];
} __attribute__((__packed__)) SMsgAVIoctrlFormatExtStorageResp;

/*
 TCI_CMD_GET_EXTERNAL_STORAGE_REQ        =   0x8030,
** @struct TCI_CMD_GET_EXTERNAL_STORAGE_RESP   =   0x8031
*/
typedef struct{
    unsigned int  channel;                  // 0
    int  total;                             // 总容量，单位 M, >0: total space size of sdcard (MBytes), 0: 无卡, -1: 卡状态错，需要格式化,-2: SD卡状态为只读(可回放但不能继续写入), -3: 正在格式化
    int free;                               // Free space size of sdcard (MBytes)
    unsigned char reserved[8];
} __attribute__((__packed__)) SMsgAVIoctrlStorageResp;



/* IOTYPE_USER_IPCAM_GET_TIMEZONE_REQ               = 0x3A0
 * IOTYPE_USER_IPCAM_GET_TIMEZONE_RESP              = 0x3A1
 * IOTYPE_USER_IPCAM_SET_TIMEZONE_REQ               = 0x3B0
 * IOTYPE_USER_IPCAM_SET_TIMEZONE_RESP              = 0x3B1
 */
typedef struct{
    int cbSize;                            // the following package size in bytes, should be sizeof(SMsgAVIoctrlTimeZone)
    int nIsSupportTimeZone;
    int nGMTDiff;                        // the difference between GMT in hours
    char szTimeZoneString[256];            // the timezone description string in multi-bytes char format
}SMsgAVIoctrlTimeZone;

/*----------------------------------自定义结构体----------------------------------------------------*/

/* Audio/Video Frame Header Info */
typedef struct _FRAMEINFO{
    unsigned short codec_id;    // Media codec type defined in sys_mmdef.h,MEDIA_CODEC_AUDIO_PCMLE16 for audio,MEDIA_CODEC_VIDEO_H264 for video.
    
    unsigned char flags;        // Combined with IPC_FRAME_xxx.
    unsigned char cam_index;    // 0 - n
    
    unsigned char rt_flags;     // bit0: 是否在录像
    unsigned char seq_no[3];    // 1~0xffffff,sequency number for frame, used internallu by sdk to detect frame loss
    
    unsigned int frame_size;    // size of frame
    unsigned int timestamp;     // Timestamp of the frame, in milliseconds
}FRAMEINFO_t;

/** 插入到媒体流中的信息类型 .*/
typedef enum {
    /** 回放中的时间同步帧, 用于告诉播放器下一帧发生时的的UTC时间. 在时间戳中断时（例如自动跳到下一个文件）发送
     *  - data1 = 0;
     *  - data2 = 下一帧发生时的UTC时间;
     *  - frame_size = 0;
     *  SDK 提供辅助宏 @ref TciSendPbSyncFrame() 来发送这个帧
     */
    RTM_SYNCTIME = 0,

    /** 多目摄像机在变焦过程中发生镜头切换，在切换完成后、新镜头的第一个I帧前发送此标志
     *  - data1 = 视频通道号;
     *  - data2 = 码流编号;
     *  - frame_size = 0;
     *
     *  \n使用辅助宏 @ref TciSendLiveMsg_LensSwitch() （或旧的 TciSendLensSwitchFlag()）发送
     */
    RTM_LENS_SWITCH = 1,

    /** 同 @ref MSG_SYNCTIME, 但在响应 @ref TCI_CMD_RECORD_PLAYCONTROL 命令发生跳转的第一帧前发送
     *  - data1 = 0;
     *  - data2 = 下一帧发生时的UTC时间;
     *  - frame_size = 0;
     */
    RTM_SYNCTIME_RESPONSE_TO_USER = 2,

    /** 到达预置位.
     * 响应APP调用预置位命令, 在转到预置位置时在实时流中发送.用于通知APP更新预置位图片。 \n
     * 当App端没有预置位缩略图时(分享、换手机、第三方设置了预置位等)，依赖此特性自动更新。
     * - data1: 视频通道号(或摄像头索引)
     * - data2: 预置位编号(>0)
     * - frame_size: 0
     * \n使用辅助宏 @ref TciSendLiveMsg_ReachPsp()  来发送这个消息
     */
    RTM_REACH_PSP = 3,

    /** 缩时录像回放启停标志.
     * 在sd卡回放时进入和退出缩时录像发送此标志。
     * - data1: 1:缩时录像回放开始; 0:缩时录像回放结束
     * - data2: 0 或 倍速
     * - frame_size: 0
     * \n使用辅助宏 @ref TciSendPbTimelapseFlag() 发送本消息
     */
    RTM_TIME_LAPSED = 4,
    
    /** 呼叫结束
     * 呼叫事件在设备端超时，或者接听者挂断，向所有(别的)连接发送此通知
     * - data1: 状态 @ref ECALLSTATE
     */
    RTM_UPDATE_CALL_STATE = 5,
    
    /** 设备休眠通知. APP收到命令后要退出实时视频
     * - data1: 0
     * - data2: 0
     * - frame_size: 0
     */
    RTM_GOINGTO_SLEEP = 6,
    
    /** 回放: 事件结束标志
        * 事件(单文件)(参见 @ref TCIC_RECORD_PLAY_START)回放模式下，当事件(文件)播放结束时发送此标志。
        * 支持单文件模式时必需发送
        * - data1: 0
        * - data2: 0
        * - extra_len: 0
        * \n使用辅助宏 @ref TciSendPbEndOfEvent() 发送本消息
        */
    RTM_END_OF_EVENT = 7,
    
    /** 命令: 取消呼叫小程序. 这个是发给转发服务器的内部消息 */
    RTM_CANCEL_CALL = 8,
    
    /** 用户自定义的消息 */
    RTM_USER = 255
} RTMTYPE;

/** \ingroup api_structure
 * @{*/

/** 在媒体流中插入的 消息/数据帧 帧头.
 * 本结构与 @ref FRAMEINFO_t 一样有相同的长度，并用 codec_id来区分结构体内容；frame_size 为结构后的数据长度。 \n
 * 插放器遇到不能识别的 codec_id 时，可以跳过本结构和后面的 frame_size 字节。 \n
 * 设备端调用 TciSendRtMsg() 或 TciSendPbRtMsg() 分别在实时流或回放流中插入消息
 */
typedef struct RTMSGHEAD_t {
    unsigned short codec_id;    ///< 0: 标志本结构
    unsigned short type;        ///< 消息类型。 @ref RTMTYPE
    unsigned int data1;         ///< 消息类型相关数据1
    unsigned int frame_size;    ///< Size of frame
    unsigned int data2;         ///< 消息类型相关数据2
} RTMSGHEAD_t;

typedef struct {
    uint16_t mediaType;
    uint16_t keyFrame;
    uint32_t length;
    uint32_t timestamp;
    uint32_t flags;//表示是否加密
} __attribute__((__packed__)) McFrameHeader;

typedef struct{
    STimeDay    livetime;
    unsigned char password[48];
    unsigned char reserved[4];
    char timezone[0];       // 结构长度大于60时存在timezone成员。以'\0'结尾
}SMsgAVIoctrlExPassWordReq;

typedef struct  {
    int result;    //0 pass -1 no pass
    unsigned char reserved[4];
} SMsgAVIoctrlExPassWordResp;

typedef struct{
    STimeDay stStartTime;   // Search event from ...
    STimeDay stEndTime;     // ... to (search event)
    unsigned int channel;   // Camera Index
    unsigned char event;    // event type, refer to ENUM_EVENTTYPE
    unsigned char reserved[2];
}SMsgAVIoctrlExListEventReq;

/** 上报事件类型.
 * 事件可能需要携带额外参数。参数通过 EVENTPARAM::evt_data 传递，内容与具体事件相关
 */
typedef enum ECEVENT {
    ECEVENT_NONE = 0,             ///< [] none
    ECEVENT_MOTION_DETECTED,      ///< [motion] is detected (=1)
    ECEVENT_HUMAN_BODY,           ///< [body] human body is detected (=2)
    ECEVENT_SOUND,                ///< [sound] (=3)
    ECEVENT_PIR,                  ///< [pir](=4)

    ECEVENT_SMOKE,                ///< [smoke] (=5)
    ECEVENT_TEMPERATURE_L,        ///< [tempL] temperature low(=6). 参数: MKEVTDATA_Temperatur()
    ECEVENT_TEMPERATURE_H,        ///< [tempH] temperature high(=7). 参数: MKEVTDATA_Temperatur()
    ECEVENT_HUMIDITY_L,           ///< [humidL] humidity low(=8). 参数: MKEVTDATA_Humidity()
    ECEVENT_HUMIDITY_H,           ///< [humidH] humidity high(=9). 参数: MKEVTDATA_Humidity()
    ECEVENT_GENERIC_SENSOR,       ///< [generic] 通用传感器类消息 (=10)

    ECEVENT_DR_BEGIN,             ///< 行车记录仪事件范围开始(=11)
    ECEVENT_G_SENSOR = ECEVENT_DR_BEGIN,   ///< [g-sensor] G-Sensor(碰撞事件)(=11). 参数: NULL or EVTDATA_SERIOUS_COLLISION
    ECEVENT_COLLISION = ECEVENT_G_SENSOR,  ///< = @ref ECEVENT_G_SENSOR(=11)
    ECEVENT_SETOFF,                 ///< [set-off] set off car (=12)
    ECEVENT_PARK,                   ///< [park] car parked(=13)
    ECEVENT_SPEED_UP,             ///< [speed-up] speed burstly up(=14)
    ECEVENT_SPEED_DOWN,           ///< [speed-down] speed burstly down(=15)
    ECEVENT_DR_END = ECEVENT_SPEED_DOWN, ///< 行车记录仪事件范围结束(=15)

    ECEVENT_CALL,                 ///< [call] (=16)
    ECEVENT_DOORBELL = ECEVENT_CALL, ///< 保留旧的命名 = ECEVENT_CALL
    ECEVENT_PASSBY,                ///< [passby] 有人路过(=17)
    ECEVENT_STAY,                  ///< [stay] 有人停留(=18)

    //ECEVENT_OBJECT,                ///< object recognization
    //ECEVENT_CAR = ECEVENT_OBJECT,                   ///<

    ECEVENT_LOCK,                 ///< [lock] 门锁消息(大类)(=19). 细分消息在data部分

    ECEVENT_CRY,                  ///< [cry] 检测到哭声(=20)
    ECEVENT_ENTER,                ///< [enter] 进入区域(=21)
    //参数: MKEVTDAT_SitPoseSens()。这个在sdk内部处理
    ECEVENT_SITPOSE,              ///< [bad_posture] sitting pose. 坐姿检测.(=22)

    ECEVENT_LEAVE,                ///< [leave] 离开区域 "leave". 由sdk生成?(=23)
    ECEVENT_TUMBLE,               ///< [tumble] 摔倒(=24)

    ECEVENT_SNAPSHOT,             ///< [snapshot] 手动抓拍(=25)
    ECEVENT_CALL2,                ///< [call.2]呼叫按键2(=26)

    ECEVENT_MAX,
    ECEVENT_USER_DEFINED = 255    ///< 自定义事件。使用方式见文档
} ECEVENT;

/** \brief 录像条目 */
typedef struct SAvExEvent {
    STimeDay   start_time;    ///< 录像开始时间
    unsigned int   file_len;  ///< time length: in second
    unsigned char event;      ///< 事件类型 @ref ECEVENT
#define AVE_F_TIMELAPSE    0x01 ///< 缩时录像标志
    unsigned char flags;      ///< 录像条目其它标志. 0x01:缩时录像
    unsigned char reserved[2]; ///< 0
}  __attribute__((__packed__)) SAvExEvent;

/** \brief 录像条目, 带事件的时间戳 */
typedef struct SAvEvent2 {
    STimeDay      start_time;    ///< 录像开始时间
    unsigned int  file_len;      ///< time length: in second
    unsigned char event;         ///< 事件类型 @ref ECEVENT
#define AVE_F_TIMELAPSE    0x01  ///< 缩时录像标志
    unsigned char flags;         ///< 录像条目其它标志. 0x01:缩时录像
    unsigned char reserved[2];   ///< =0
    unsigned int  t_event;        ///< 本段录像对应的事件的时间(要与上报给云端的事件时间一致). 没有事件时传0
}  __attribute__((__packed__)) SAvEvent2;

/** \brief SD卡录像查询返回结构 */
/** @ref TCI_CMD_LISTEVENT_RESP
 * */
typedef struct Tcis_ExListEventResp {
    unsigned int  channel;      ///< Camera Index: 0~
    unsigned int  num;          ///< 录像条目总数
    unsigned char index;        ///< ignored
    unsigned char endflag;      ///< 为1是表示是最后一个包
    unsigned char count;        ///< 本包包含中的事件数
    unsigned char estype;       ///< 0:录像记录为SAvExEvent数组; 1:录像记录为SAvEvent2数组
    union {
        SAvExEvent stExEvent[1];   ///< 录像条目数组 see @ref SAvExEvent. 一次发送最多 50 条记录
        SAvEvent2  stEvent2[1];    ///< 带事件时间戳的录像条目数组 see @ref SAvEvent2. 一次发送最多 50 条记录
    };
}  __attribute__((__packed__)) SMsgAVIoctrlExListEventResp;

typedef struct {
    char ssid[64];
    char key[64];
    unsigned int userid;
    char bind_token[48]; // userid+time
    char reserved[64];
}  EcpQrcodeContent;

//查询设备硬件能力
typedef struct {
    char feature[1024];
}SMsgAVIoctrlGetFeatureReq;

typedef struct {
    char feature[1024];
}SMsgAVIoctrlGetFeatureResp;

//重启设备
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
}SMsgAVIoctrlDevRebootReq;

typedef struct{
    unsigned int result;                //1 ok , !1    no ok
    unsigned char reserved[4];
}SMsgAVIoctrlDevRebootResp;

//移动追踪
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
}SMsgAVIoctrlGetMotionTrackerReq;

typedef struct{
    unsigned int channel;         // Camera Index
    unsigned int support;       //0不支持，非0支持
    unsigned char mode;            //当前模式，mode: 0- on, 1- off
    unsigned char reserved[3];
}SMsgAVIoctrlGetMotionTrackerResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned int mode;
    unsigned char reserved[4];
}SMsgAVIoctrlSetMotionTrackerReq;

typedef struct{
    unsigned int result;                //1 ok , !1    no ok
    unsigned char reserved[4];
}SMsgAVIoctrlSetMotionTrackerResp;

//夜视
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
}SMsgAVIoctrlGetDayNightReq;

typedef struct{
    unsigned int channel;         // Camera Index
    unsigned int support;       //0不支持，2支持两种模式，3支持三种模式；
    unsigned char mode;            //当前模式，mode: 0- auto 1- day,2- night
    unsigned char reserved[3];
}SMsgAVIoctrlGetDayNightResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned int mode;        //当前模式，mode: 0- auto 1- day,2- night
    unsigned char reserved[4];
}SMsgAVIoctrlSetDayNightReq;

typedef struct{
    unsigned int result;                //1 ok , !1    no ok
    unsigned char reserved[4];
}SMsgAVIoctrlSetDayNightResp;

//白光灯
typedef struct{
    unsigned int channel;           // Camera Index
    unsigned char reserved[4];
}Tcis_GetWhiteLightReq;

typedef struct{
    unsigned int channel;           // Camera Index
    unsigned int support;           //0不支持，2支持两种模式，3支持三种模式；
    unsigned char mode;             //当前模式，0-关闭（白光不工作）;1-打开（全彩色）;2-智能模式（移动侦测触发自动白光）
    unsigned char reserved[3];
}Tcis_GetWhiteLightResp;

typedef struct{
    unsigned int channel;           // Camera Index
    unsigned int mode;              //当前模式，0-关闭（白光不工作）;1-打开（全彩色）;2-智能模式（移动侦测触发自动白光）
    unsigned char reserved[4];
}Tcis_SetWhiteLightReq;

typedef struct{
    unsigned int result;                //1 ok , !1    no ok
    unsigned char reserved[4];
}Tcis_SetWhiteLightResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
}Tcis_GetMicroPhoneReq;

typedef struct{
    unsigned int channel;         // Camera Index
    unsigned char status;        //当前当前麦克风状态，status: 0- 关, 1- 开
}Tcis_GetMicroPhoneResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned int status;        //当前麦克风状态，status: 0- 关, 1- 开
}Tcis_SetMicroPhoneReq;

typedef struct{
    unsigned int result;         // 0失败，1成功
    unsigned char reserved[4];
}Tcis_SetMicroPhoneResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
}Tcis_GetBuzzerReq;

typedef struct{
    unsigned int channel;         // Camera Index
    unsigned char status;        //当前蜂鸣器状态，status: 0- 关, 1- 开
    unsigned char reserved[3];
}Tcis_GetBuzzerResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char status;        //当前蜂鸣器状态，status: 0- 关, 1- 开
    unsigned char reserved[3];
}Tcis_SetBuzzerReq;

typedef struct{
    unsigned int result;         // 0失败，1成功
    unsigned char reserved[4];
}Tcis_SetBuzzerResp;

//上传云录像清晰度
typedef struct{
    unsigned int channel;     // Camera Index
    unsigned char reserved[4];
}SMsgAVIoctrlGetCloudVideoQualityReq;

typedef struct{
    unsigned int channel;         // Camera Index
    unsigned char quality;            //当前清晰度，mode: 0- 高清, 1- 标清
    unsigned char reserved[3];
}SMsgAVIoctrlGetCloudVideoQualityResp;

typedef struct{
    unsigned int channel;     // Camera Index
    unsigned int quality;
    unsigned char reserved[4];
}SMsgAVIoctrlSetCloudVideoQualityReq;

typedef struct{
    unsigned int result;                //1 ok , !1    no ok
    unsigned char reserved[4];
}SMsgAVIoctrlSetCloudVideoQualityResp;

//移动侦测
/*
 TCI_CMD_GETMOTIONDETECT_REQ    = 0x0326,
 ** @struct Tcis_GetMotionDetectReq
 */
typedef struct{
    unsigned int channel;     // Camera Index: 0
    unsigned char reserved[4];
} __attribute__((__packed__)) Tcis_GetMotionDetectReq;

//区域的表示方式:
//  left/width: 区域的左上角坐标/宽度转成浮点数据，除以图片宽，再乘10000后取整
//  top/height: 区域的右上角坐标/高度转成浮点数据，除以图片高，再乘10000后取整
//  例如 { 5000,5000,5000,5000 } 表示右下角1/4矩形
typedef struct {
    int left, top, width, height;
} __attribute__((__packed__)) MdZone;

/** 坐标点 */
typedef struct POINT {
    int x;  ///< x
    int y;  ///< y
} POINT;

/** @anchor md_area_type
 * @name Tcis_SetMotionDetect::flags 低2位取值.
 * 设备要支持移动侦测区域设置
 * @{*/
#define MD_AT_RECTS            0   ///< 区域用多个矩形表示
#define MD_AT_POLYCON          1   ///< 区域用多边形表示
#define MD_AT_RECTSWITHPOLYGON 2   ///< 区域用多个矩形逼近多边形，同时后面有多边形坐标

/** 最高为1时，表示支持区域排除. 仅用于从设备返回 */
#define MD_F_SUPPORT_EXCLUDE_ZONE 0x8000
/**@}*/

/** @struct MdPolygon
 * 移动侦测多边形区域的顶点坐标. */
typedef struct MdPolygon {
    int nPoints;
    /** 点的坐标为相对位置: \n
     *   \c x: X坐标 转成浮点数据，除以图片宽，再乘10000后取整.
     *   \c y: Y坐标 转成浮点数据，除以图片高，再乘10000后取整.
     */
    POINT points[0];
} MdPolygon;

/*
 TCI_CMD_SETMOTIONDETECT_REQ        = 0x0324,
 TCI_CMD_GETMOTIONDETECT_RESP        = 0x0327,
 ** @struct Tcis_SetMotionDetectReq, Tcis_GetMotionDetectResp
 */
typedef struct{
    unsigned int channel;         // Camera Index: 0
    unsigned short enabled;       // 1:enabled; 0:disabled
    unsigned short flags;         // 保留。总是0
    /*下面的域根据设备能力设置。如果设备本身不支持，其值会被忽略*/
    unsigned int sensitivity;     // 1~5
    unsigned char hasZone;        // 1: nZones/zones has valid setting; 0: ignore zones
    unsigned char excludeZone;    // 0: 检测区域内；1: 检测区域外
    union unionMdArea {
        struct Fake_MdZoneVLA {
            unsigned short nZones;    ///< 矩形个数
            MdZone zones[0];          ///< 矩形数组
        } __attribute__((__packed__)) mz; ///< (flags&0x03)==MD_AT_RECTS: 检测移动的变长矩形数组
        
        struct Fake_MdPolygonVLA {
            unsigned short nPolygons;    ///< 多边形个数
            MdPolygon polygons[0];       ///< 多边形数组
        } __attribute__((__packed__)) mp; ///< (flags&0x03)==MD_AT_POLYCON: 检测移动的变长多边形数组
        
        
        struct Fake_RectPolygonVLA {
            struct Fake_MdZoneVLA mz;      ///< 矩形变长数组
            struct Fake_MdPolygonVLA mp;   ///< 多边形变长数组
        } __attribute__((__packed__)) zp;           ///< (flags&0x03)==MD_AT_RECTSWITHPOLYGON 的伪数据结构
         
    } u;
} __attribute__((__packed__)) Tcis_SetMotionDetectReq, Tcis_GetMotionDetectResp;

/*
 TCI_CMD_SETMOTIONDETECT_RESP    = 0x0325,
 ** @struct Tcis_SetMotionDetectResp
 */
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
} __attribute__((__packed__)) Tcis_SetMotionDetectResp;

//布防设置
typedef struct {
    unsigned char hour;        //0~23
    unsigned char minute;      //0~59
    unsigned char second;      //0~59
    unsigned char reserved;    //always 0
} __attribute__((__packed__)) CLOCKTIME;
typedef struct { CLOCKTIME from, to; } TIMERANGE;

#define TG_TR2_S_DAY     1    //白天. 由设备自行判断(例如通过光敏电路)
#define TG_TR2_S_NIGHT   2    //晚上
typedef struct {
    unsigned char  tag;       //0xff
    unsigned char  spec_time; //TG_TR2_S_DAY or TG_TR2_S_NIGHT
    unsigned short flags;     //0
    uint32_t       reserved;
} __attribute__((__packed__)) TIMERANGE2;

#define TG_ECEVENT_ALL  0xffffffff
typedef struct {
    union {
        TIMERANGE    time_range;  //布防起止时间。见note
        TIMERANGE2   tr2;
    };
    uint32_t     event_mask;  //事件类型掩码. bit0:保留; bit1:移动侦测; bit2:人体检测; ...[参看ECEVENT定义]
                              //如果为TG_ECEVENT_ALL, 表示本结构应用到全部报警类型上
    uint32_t     event_mask2; //0. 用于大于31的事件值掩码
    unsigned int day_mask;    //bit-mask of week-days. bit0:Sunday; bit1-Monday; ...
} __attribute__((__packed__)) DEFENCEITEM;

/*
 TCI_CMD_GET_DEFENCE_REQ    = 0x032A,
 ** @struct Tcis_GetDefenceReq
 */
typedef struct{
    uint32_t event;     // Camera Index: 0
    uint32_t reserved[4];
}Tcis_GetDefenceReq;

typedef struct {
    unsigned int nItems;
    DEFENCEITEM items[0];
} __attribute__((__packed__)) Tcis_SetDefenceReq, Tcis_GetDefenceResp;

/*
 TCI_CMD_SET_DEFENCE_RESP    = 0x0329,
 ** @struct Tcis_SetDefenceResp
 */
typedef struct{
    int result;    // 0: success; otherwise: failed.
    unsigned char reserved[4];
}Tcis_SetDefenceResp;

/** \struct Tcis_EventState
 * 报警事件状态(禁用或使能).
 *  @ref TCI_CMD_SET_EVENT_STATE =           0x031C
 */
struct Tcis_EventState {
    int event; ///< @ref ECEVENT
    int enabled; ///<1:enabled; 0:disabled
} __attribute__((__packed__));
/** \see Tcis_EventState*/
typedef struct Tcis_EventState Tcis_SetEventStateReq;
/** \see Tcis_EventState*/
typedef struct Tcis_EventState Tcis_GetEventStateResp;

/** \struct Tcis_GetEventStateReq
 *  获取报警事件状态
 *  @ref TCI_CMD_GET_EVENT_STATE =           0x031E
 */
struct Tcis_GetEventStateReq {
    int event; ///< @ref ECEVENT
    int reserved; ///< 0
} __attribute__((__packed__));
/** \see Tci_GetEventState */
typedef struct Tcis_GetEventStateReq Tcis_GetEventStateReq;

//AI人形追踪设置
typedef struct  {
    int enable;      //1-打开; 0-关闭
    char resvered[4];
} __attribute__((__packed__)) Tcis_SetEnableBtReq;

typedef struct  {
    int enable;      //1-打开; 0-关闭
    char resvered[4];
} __attribute__((__packed__)) Tcis_GetEnableBtReq;

typedef struct  {
    int enable;      //1-打开; 0-关闭
    char resvered[4];
}Tcis_GetEnableBtResp;

/** @name 云台操作
 * @{*/

/** 云台位置结构体.
 * @ref TCI_CMD_GET_PTZ_POS        = 0x040A
 */
typedef struct PtzPos {
    /** x,y,z: 取值0.0~1.0, 分别表示云台水平、垂直、纵深方向的位置点各自方向最大范围的比率。
      例如x=0.5表示去云台水平居中；z=0.0表示纵深处在x1的位置
      x,y 小于0.0或大于1.0时无意义(程序忽略)。
      z值仅在变焦倍数可知时有意义。z小于0.0或大于1.0时另行定义
      */
    float x, y, z;
}  __attribute__((__packed__)) PtzPos;

/** \struct Tcis_SetPtzPosReq.
 * 设置云台位置
 * @ref TCI_CMD_SET_PTZ_POS        = 0x0408 \n
 */
typedef struct Tcis_SetPtzPosReq {
    PtzPos pos;     ///< 位置
    int    channel; ///< 通道
    int    psp_num; ///< 如果是要转到预置位，此为预置位编号，否则为0 [2021.11.2]
} __attribute__((__packed__)) Tcis_GetPtzPosResp,Tcis_SetPtzPosReq;

/** \struct Tcis_GetPtzPosReq
 * 获取云台位置. \n
 * @ref TCI_CMD_GET_PTZ_POS = 0x040A
 */
typedef struct Tcis_GetPtzPosReq {
    int channel;
} Tcis_GetPtzPosReq;

typedef struct Tcis_GetPresetPointsReq {
    uint16_t flags;                 ///<0：返回全部预置位，1：返回能力
    uint16_t channel;
    uint32_t reserved;
} Tcis_GetPresetPointsReq;

/**
 psp_type，预置位类型
 */
#define PSP_BY_NO   1               ///< 预置位类型: 索引
#define PSP_BY_POS  2               ///< 预置位类型: 位置
#define PSP_BY_NO_NONAME 3          ///< 预置位用编号表示，没有名字
#define PSP_BY_POS_NONAME 4         ///< 预置位用位置表示，没有名字

/**
 psp_flags，预置位标志
 */
#define PSP_F_ZOOMONLY   0x01       ///< 本预置位仅含变焦信息
#define PSP_F_SHORTCUT   0x02       ///< 表示这是个快捷位置，UI上有对应的按钮直达
#define PSP_F_DISABLED   0x04       ///< 用于设置命令, 按编号删除. 单独使用
#define PSP_F_CANNOT_DELETE  0x08   ///< 不可删除

/** @struct PresetPointArray
 * 预置位数组 \n\n
 *
 * 预置位有两种表示方式：\n
 *   1. 传统球机用编号表示的预置位。编号对应的具体位置保存在球机内，对外是黑盒。 本命令中用 struct PresetPointArray::unionPSP::psp_by_no 表示. \n
 *   2. 用位置表示的预置位。 本命令中用 struct PresetPointArray::unionPSP::psp_by_pos 表示. \n
 *
 * 一个预置位可以对应云台的某个朝向、镜头的某个变焦倍数，或二者组合。如果仅包含变焦信息，flags 应设置 \ref PSP_F_ZOOMONLY 。
 *
 * 对仅包含变焦信息的预置位，应该放在数组的最前面，并按变焦倍数从小到大的顺序排列。这样APP容易根据排序决定UI。 \n
 * 例如，对双目+变焦摄像机，返回两个预置位（同时设置 \ref PSP_F_ZOOMONLY 和 \ref PSP_F_SHORTCUT 标志），\n
 * 第一个位置将对应[近景]按钮， 第二个对应[远景]按扭。或者，对返回多个预置位的情形，APP在一个 \n
 * 滑动轴上，按变倍值单向排列并对每个预置位置描一个驻点。
 */
typedef struct PresetPointArray {
    uint16_t n_psp;                 ///< 预置位数组大小
    uint8_t type;                   ///< psp_type预置位类型
    uint8_t channel;                ///<在TCI_CMD_GET_PSP 的应答中，为与请求匹配的通道号。设置时为0，因为请求结构中有定义channel字段
    
    /** 预置位数组 */
    union unionPSP {
        /** 用编号表示的预置位,type=PSP_BY_NO */
        struct psp_by_no {
            uint16_t flags;         ///< 预置标志. 0 或 @ref PSP_F_DISABLED 或 其它 @ref psp_const PSP_F_xxx 的组合
            uint16_t num;           ///< 预置位编号: 1~n_psp. 0保留
            char name[32];          ///< 预置位名称
        } pspn[0];                  ///< type = @ref PSP_BY_NO, 用编号表示的预置位
        
        /** 用编号表示的预置位, 没有名字. type=PSP_BY_NO_NONAME */
        struct pspn_noname {
            uint16_t flags;         ///< 预置标志. 0 或 @ref PSP_F_DISABLED 或 其它 @ref psp_flags PSP_F_xxx 的组合
            uint16_t num;           ///< 预置位编号: 1~n_psp. 0保留
        } pspn_nn[0];               ///< type = @ref PSP_BY_NO, 用编号表示的预置位
        
        /** 用位置表示的预置位,type=PSP_BY_POS */
        struct psp_by_pos {
            uint16_t flags;         ///< 标志. 0 或 PSP_F_DISABLED 或 @ref PSP_F_DISABLED 或 其它 @ref psp_const PSP_F_xxx 的组合
            uint16_t num;           ///< ID, 用于删除或修改时作标识. 0保留不可删除(双目变焦设备用于镜头切换)
            PtzPos pos;             ///< 预置位
            char name[32];          ///< 预置位名称
        } pspp[0];                  ///< type = @ref PSP_BY_POS, 用位置表示的预置位
        
        /** 用位置表示的预置位, 没有名字. type=PSP_BY_POS_NONAME */
        struct pspp_noname {
            uint16_t flags;         ///< 标志. 0 或 PSP_F_DISABLED 或 @ref PSP_F_DISABLED 或 其它 @ref psp_flags PSP_F_xxx 的组合
            uint16_t num;           ///< ID, 用于删除或修改时作标识. 0保留不可删除(双目变焦设备用于镜头切换)
            PtzPos pos;             ///< 预置位
        } pspp_nn[0];               ///< type = @ref PSP_BY_POS, 用位置表示的预置位
    } u;                            ///< 预置位数组
} __attribute__((__packed__)) PresetPointArray;

/** @struct Tcis_GetPresetPointsResp
 * 设备端返回的预置位.
 * @ref TCI_CMD_GET_PSP  = 0x0452 \n
 * 本结构用于返回设备支持的所有预置位置.
 */
typedef struct Tcis_GetPresetPoinsResp {
    union {
        /** Tcis_GetPresetPointsReq::flags == 1 */
        struct psp_cap {
            uint16_t cbSize;        ///< 本结构大小 = sizeof(struct psp_cap)。目前为12
            uint8_t zero;           ///<0
            uint8_t channel;        ///<与 TCI_CMD_GET_PSP 请求匹配的通道号
            uint16_t max_psp;       ///支持的预置位数。有效预置位编号 1~max_psp. 0保留
            uint16_t type;          ///< @ref psp_type "预置位类型"
            int      flags;         ///< 0x01: 预置位保存到设备端(app要调用 TCI_CMD_SET_PSP)
        } __attribute__((__packed__)) psp_cap;///预置位能力(Tcis_GetPresetPointsReq::flags == 1)

        /** Tcis_GetPresetPointsReq::flags == 0 */
        PresetPointArray pspa; ///< 预置位数组
    };
} __attribute__((__packed__)) Tcis_GetPresetPointsResp;

/** @struct Tcis_SetPresetPointsReq
 * 设置设备端的预置点.
 */
typedef struct Tcis_SetPresetPointsReq {
    int channel;   ///< 0
    struct PresetPointArray pspa;  ///< 预置位数组(一般一次设置一个位置，即数组大小为1)
} __attribute__((__packed__)) Tcis_SetPresetPointsReq;

typedef struct Tcis_SetCameraStatus {
    int status;      //1-打开; 0-关闭
    char resvered[4];
} __attribute__((__packed__)) Tcis_SetCameraStatusReq, Tcis_GetCameraStatusResp;

typedef struct  {
    int enable;      //1-打开; 0-关闭
    char resvered[4];
} Tcis_GetAlarmToneReq;

/** 音频文件格式 */
typedef enum {
    AF_FMT_WAV,  ///< .wav
    AF_FMT_AMR,  ///< .amr
    AF_FMT_MP3,  ///< .mp3
    AF_FMT_M4A   ///< .m4a
} AUDIOFILEFMT;

/** 获取音频文件格式应答.
 * 音频文件格式结构体，用于协商报警音的格式. \n
 @ref  TCI_CMD_GET_ALARMTONE_CAP           = 0x041C
 */
typedef struct {
    unsigned short nSamplePerSec;           ///< 采样频率
    unsigned char  nBitsPerSample;          ///< 采样位宽
    unsigned char  nChannels;               ///< 通道数
    unsigned int   nExpectedFileFormats;    ///< 期望的文件格式数
    unsigned char  ExpectedFileFormats[8];  ///< 期望的音频格式 AUDIOFILEFMT
    unsigned int   nSupportedAudioCodecs;   ///< 支持的音频格式数
    unsigned char  SupportedAudioCodecs[8]; ///< 支持的音频格式 TCMEDIA
    unsigned int   idAlarmTone;             ///< 当前报警音标识. 0-默认;其它: 从app收到的内容标识
    //2021-05-21 新增域
    unsigned int   uiFileSizeLmt;            ///< 文件大小上限(单位KB)。对APP来说，当收到的应答长度>=36时才存在这个信息
} __attribute__((__packed__)) Tcis_GetAlarmToneCap_Resp;

/*
    TCI_CMD_SET_ALARMTONE              = 0x041E,    //设置报警音频
    TCI_CMD_PLAY_AUDIO                 = 0x0356     //播放语音不保存
    如果app传入不支持的音频或文件格式，ipc返回TCI_E_INVALID_PARAM
*/
typedef struct {
    unsigned int idAlarmTone;                //0:默认; 其它:报警音内容标识
    unsigned short type;             //0:data为音频内容; 1:data为下载音频文件的url
    unsigned char af_fmt;            //AUDIOFILEFMT
    unsigned char a_codec;           //TCMEDIA
    int           data_len;          //length of data
    char data[0];
} __attribute__((__packed__)) Tcis_SetAlarmTone_Req;

typedef struct {
    int max_awake_time;  //单位:秒
    int reserved;        //0
} __attribute__((__packed__)) Tcis_GetMaxAwakeTimeResp, Tcis_SetMaxAwakTimeReq;

typedef struct Tcis_SetLedStatus {
    int status;      //1-打开; 0-关闭
    char resvered[4];
} __attribute__((__packed__)) Tcis_SetLedStatusReq, Tcis_GetLedStatusResp;

typedef struct{
    int batteryMode;            //电池工作模式0--放电，1--充电
    int batteryPower;           //电池电量 0-100(%),-1(未知)
    int batteryLow;             //电量低标志.1:低电;0:有电。APP要检查收到的应答长度。>=12时才有此域
} __attribute__((__packed__)) Tcis_GetBatteryStatusResp;

typedef struct{
    int activeNetIntf;          //0:有线;1-Wifi;2-4G
    int signalLevel;            //信号强度 0~100(%);-1(未知)
} __attribute__((__packed__)) Tcis_GetWifiLevelResp;

/** 选择和获取主画面
 * @ref TCI_CMD_SET_PRIMARY_VIEW
 * @ref TCI_CMD_GET_PRIMARY_VIEW
 */
typedef struct Tcis_PrimaryView {
    int id;        ///< 0. 暂未使用
    int channel;   ///< 主画面通道: 0|1. GET请求时忽略
} __attribute__((__packed__)) Tcis_SetPrimaryViewReq, Tcis_GetPrimaryViewReq, Tcis_GetPrimaryViewResp;

typedef struct Tcis_PirSens {
    int channel;        //通道：0
    int sensitive;      //0:关闭; 1:低; 2:中; 3:高
} __attribute__((__packed__)) Tcis_SetPirSensReq, Tcis_GetPirSensResp;

typedef struct Tcis_SetVolume{
    int flags;                  //0: 音量调节范围不可知，1：音量调节范围可知
    int volume;                 //音量：flags为0=> 1:音量加，-1:音量减
                                //     flags为1=> 0-100之间的等级
} __attribute__((__packed__)) Tcis_SetVolumeReq, Tcis_GetVolumeResp;

typedef struct Tcis_AlarmLightState {
    int channel; //通道：0
    int state;   //0:关; 1:开; 2:自动
} __attribute__((__packed__)) Tcis_GetAlarmLightStateResp, Tcis_SetAlarmLightStateReq;

/* AI类型 */
#define TG_AIT_BODY_DET            0  ///< 人形检测
#define TG_AIT_BODY_TRACE          1  ///< 人形追踪
#define TG_AIT_FACE_DET            2  ///< 人脸检测
#define TG_AIT_FACE_RECO           3  ///< 人脸识别

/* AI类型掩码 */
#define TG_AITM_BODY_DET        (1<<TG_AIT_BODY_DET)       // 人形检测
#define TG_AITM_BODY_TRACE      (1<<TG_AIT_BODY_TRACE)     // 人形追踪
#define TG_AITM_FACE_DET        (1<<TG_AIT_FACE_DET)       // 人脸检测
#define TG_AITM_FACE_RECO       (1<<TG_AIT_FACE_RECO)      // 人脸识别

//设备本身具有和购买服务之后具有的能力
typedef struct Tcis_AiStatus {
    unsigned int ait_mask;      // AI类型掩码,可多个AITM_xxx组合. 获取时为当前支持的AI功能; 设置时为要修改状态的AI功能
    unsigned int ai_flags;      // 对应位为1表示使能
    unsigned char reserved[8];
} __attribute__((__packed__)) Tcis_SetAiStatusReq, Tcis_GetAiStatusResp;

typedef struct Tcis_SetMicLevel{
    int sensitivity;            //灵敏度 0-100
    unsigned char reserved[4];
} __attribute__((__packed__)) Tcis_SetMicLevelReq, Tcis_GetMicLevelResp;

/** Doorbell call state */
typedef enum ECALLSTATE {
    CALLSTATE_MISSED,      ///< 未接. sdk内部定时
    CALLSTATE_ANSWERED,    ///< 已接。@ref TCI_CMD_ANSWERTOCALL
    CALLSTATE_REJECTED,    ///< 拒接。@ref TCI_CMD_ANSWERTOCALL
    CALLSTATE_CANCELLED,    ///< 设备端取消呼叫(上报 TGECEVENT_DOORBELL 事件 status=0)
    CALLSTATE_HANGUP       ///< 用户结束通话挂断接听. 仅通知用户
} ECALLSTATE;

typedef struct Tcis_AnswerToCall {
    int state;   // CALLSTATE_ANSWERED 或 CALLSTATE_REJECTED
    int more;
} Tcis_AnswerToCallReq;

/** OSD内容 */
typedef enum {
    OSDT_DATETIME,      ///< 日期时间
    OSDT_TEXT,          ///< 自定义文字
    OSDT_BMP1555 = 30,  ///< rgb1555
    OSDT_BMP32 = 31,    ///< argb8888
} OSDTYPE;

/** OSD 位置 */
typedef enum {
    OSDP_LEFTTOP,      ///< 左上
    OSDP_TOPCENTER,    ///< 上部居中
    OSDP_RIGHTTOP,     ///< 右上
    OSDP_LEFTCENTER,   ///< 左中
    OSDP_MIDDLECENTER, ///< 画面正中
    OSDP_RIGHTCENTER,  ///< 右中
    OSDP_LEFTBOTTOM,   ///< 左下
    OSDP_BOTTOMCENTER, ///< 底部居中
    OSDP_RIGHTBOTTOM   ///< 右下
} OSDPOSITION;

#define OSDF_REL_POSITION    0x0000   ///< 相对位置
#define OSDF_ABS_POSITION    0x0001   ///< 绝对位置
#define OSDF_DISABLED        0x0002   ///< 禁用某条osd(与 OSDF_DELETE互斥)，禁用的item仍需要传给APP
#define OSDF_DELETED         0x0004   ///< 删除某条osd(与 OSDF_DISABLED互斥)，删除的item不要传给APP

/** OSD 对齐方式常数 */
#define ALIGNMENT_LEFT       0x00     ///< 左对齐
#define ALIGNMENT_TOP        0x00     ///< 上对齐
#define ALIGNMENT_RIGHT      0x01     ///< 右对齐
#define ALIGNMENT_BOTTOM     0x02     ///< 下部对齐

/** OSD 条目 */
typedef struct OsdItem {
    uint16_t itemId;                    ///< 0 ~ Tcis_GetOsdResp::nMaxOsdItems - 1. 毎个条目有唯一id
    uint16_t flags;                     ///< 0 或 @ref OSDF_ABS_POSITION 或 @ref OSDF_DISABLED
    uint32_t type;                      ///< @ref OSDTYPE
    union {
        int pos;                        ///< flags==0: @ref OSDPOSITION
        struct abspos {
            short x, y;                 ///< osd区域在画面中的坐标. 解释受alignment的取值影响
            uint8_t alignment;          ///< <a href="#alignment">对齐方式常数</a>的组合
            uint8_t reserved[3];        ///< 0
        } abspos;                       ///< flags == OSDF_ABS_POSITION
    };

    int len;                            ///< data 中的数据长度.

    /** data: 内容与 \c type 相关。长度填充到4的倍数，使下一个结构4字节边界对齐。例如\c len \c = \c 3, \c data则填充到4.
     *        举例： \c item 指向一个 OsdItem ，下一个 OsdItem 为
     *        @code
     *          (struct OsdItem*)(item->data + ((item->len + 3) & 0xfffc)
     *        @endcode
     *        或者
     *        @code
     *          (struct OsdItem*)((long)(item->data + item->len + 3) & ~3L)
     *        @endcode
     *  - \c type=OSDT_DATETIME \n
     *      为格式字符串(参考strftime())；为空时，取设备默认格式
     *  - \c type=OSDT_TEXT \n
     *      自定义文本. 字符编码参见 @ref Tcis_GetOsdResp::eCharEncoding
     *  - \c type=OSDT_BMP32/OSDT_BMP1555 \n
     *      带alpha属性的 bmp 文件
     */
    char data [0];
} OsdItem;

/**
 * 设置OSD请求结构体.
 * TCI_CMD_SET_OSD_REQ  =  0x0374
 */
typedef struct {
    int channel;   ///< 0
    int nItems;    ///< items数组大小。一次可以设置/修改/删除一条或多条OSD条目
    struct OsdItem items[1]; ///< osd条目数组
} Tcis_SetOsdReq;

/**
 * 自定义文字字符集和编码. 所有语言都包含对ascii的支持 */
typedef enum {
    CHAR_ENCODING_ASCII,     ///< ascii only
    CHAR_ENCODING_ZH_UTF8,   ///< 中文utf-8
    CHAR_ENCODING_GB2312,    ///< 中文gb2312
    CHAR_ENCODING_GBK,       ///< 中文gbk
    CHAR_ENCODING_MAX
} CHAR_ENCODING;

/**
 获取OSD 设置.
 TCI_CMD_GET_OSD_REQ  =  0x0376
*/
typedef struct {
    int channel;  ///< 0
    int reserved[3];
} Tcis_GetOsdReq;

/**
 获取OSD 应答.
 TCI_CMD_GET_OSD_RESP  =  0x0377
 */
typedef struct {
    int fSupportedTypes;        ///< (1 << OSDTYPE)的组合. 例如: (1<<OSDT_TEXT) | (1<<OSDT_BMP32)
    uint16_t eCharEncoding;     ///< 支持OSDT_TEXT时，对应的字符编码 @ref CHAR_ENCODING
    uint16_t nMaxTextLength;    ///< OSDT_TEXT 允许的最大字节数. 如果为0的话，默认为32字节
    int nMaxOsdItems;           ///< 支持最大osd条数
    int nItems;                 ///< osd条目数(items大小)
    struct OsdItem items[1];    ///< osd条目数组
} __attribute__((__packed__)) Tcis_GetOsdResp;

/** 设置移动侦测区域状态
 * @ref TCI_CMD_SET_MDAREA_STATE    =       0x033A
 * 设置侦测区域状态（显示|隐藏）
 */
typedef struct Tcis_MdAreaState {
    int channel; ///< 视频通道
    int state;   ///< 0x00:隐藏；0x01: 显示
} __attribute__((__packed__)) Tcis_SetMdAreaStateReq, Tcis_GetMdAreaStateResp;

/** 获取移动侦测区域状态
 * @ref TCI_CMD_GET_MDAREA_STATE     =      0x033C
 */
typedef struct {
    int channel; ///< 视频通道
    int reserved; ///< 0
} Tcis_GetMdAreaStateReq;


/** \struct Tcis_SetShowBoxReq
 * 设置AI对象边框显示状态\n
   TCI_CMD_SET_SHOW_BOX         =      0x0348
 */
typedef struct Tcis_SetShowBoxReq {
    int ai_type;   ///< <a href="#AI_type">AI类型</a>
    int show_box;  ///< 1:显示边框; 0:不显示边框
} Tcis_SetShowBoxReq, Tcis_GetShowBoxResp;

/** \struct Tcis_GetShowBoxReq
 * 获取人形/人脸边框设置状态.
 * @ref TCI_CMD_GET_SHOW_BOX       =         0x034A
 */
typedef struct Tcis_GetShowBoxReq {
    int ai_type;   ///< <a href="#AI_type">AI类型/</a>
    int reserved; ///< 0
} Tcis_GetShowBoxReq;

/** \struct Tcis_SetWatchPosReq
 * 设置守望位. \n
 * @ref TCI_CMD_SET_WATCHPOS     =           0x0456
 */
typedef struct Tcis_SetWatchPosReq {
    int channel; ///< 通道
    int num;     ///< 预置位编号. -1:禁用; >0:设置预置位num为守望位
    int idle_time; ///< 回到守望位前的云台无动作时间，单位: 秒
} Tcis_SetWatchPosReq;

/** \struct Tcis_GetWatchPosReq
 * 获取守望位 \n
 * @ref TCI_CMD_GET_WATCHPOS      =          0x0458
 */
typedef struct Tcis_GetWatchPosReq {
    int channel;  ///< 通道
    int reserved; ///< 0
} Tcis_GetWatchPosReq;

/** \see Tcis_SetWatchPosReq */
typedef Tcis_SetWatchPosReq Tcis_GetWatchPosResp;

/** @struct Tcis_TimelapseRecordMode
 * 延时摄像设置.
    TCI_CMD_SET_TIMELAPSE_RECORD   =   0x0314
    TCI_CMD_GET_TIMELAPSE_RECORD   =   0x0316
 */
typedef struct Tcis_SetTimelapseRecordModeReq {
    int channel; ///< 0
    int when;    ///< 1:目前固定取值1, 表示停车状态
    int status;  ///< 延时摄影状态： 0-disable; 1-enable。
    int interval; ///< 录像间隔.单位:秒
} __attribute__((__packed__)) Tcis_SetTimelapseRecordModeReq;

/** @struct Tcis_GetTimelapseRecordModeReq
 * 获取延时摄像设置.
    TCI_CMD_GET_TIMELAPSE_RECORD   =   0x0316
 */
typedef struct Tcis_GetTimelapseRecordModeReq {
    int channel;  ///< 0
    int when;    ///< 1:目前固定取值1, 表示停车状态
} __attribute__((__packed__)) Tcis_GetTimelapseRecordModeReq;

/** \see Tcis_SetTimelapseRecordModeReq */
typedef struct Tcis_SetTimelapseRecordModeReq Tcis_GetTimelapseRecordModeResp;

/** @name G-sensor
 * @{*/
/** @enum GSENSORSCENE
 * g-sensor检查场景.
 */
typedef enum {
    GSENSOR_SCENE_DRIVING = 0,  ///< 车辆运行中
    GSENSOR_SCENE_PARKING = 1   ///< 停车状态
} GSENSORSCENE;

/** G-Sensor设置.
  @ref TCI_CMD_SET_GSENSOR               0x432
  */
typedef struct {
    int sensitivity;       ///< 灵敏度: 0-关闭; 1-低; 2-中; 3-高
    int scene;   ///< 如果 @ref Feature_G-Sensor "G-Sensor" 能力为 "scene", 取值 @ref GSENSORSCENE. 否则为0
} __attribute__((__packed__)) Tcis_SetGsensorReq, Tcis_GetGsensorResp;

/** 获取g-sensor设置.
  @ref TCI_CMD_GET_GSENSOR               0x434
 */
typedef struct {
    int scene;    ///< @ref GSENSORSCENE
    int reserved; ///< 0
} __attribute__((__packed__)) Tcis_GetGsensorReq;

/** 开门请求。
 * @ref TCI_CMD_UNLOCK = 0x045A  ///< 开门 Req: @ref Tcis_UnlockReq
 */
typedef struct Tcis_UnlockReq {
    int user_id;       ///< 0
    char token[0];    ///< 加密的密钥. sdk解密后推送给应用
} Tcis_UnlockReq;

typedef enum {
    ULR_OK,             ///< door is opened
    ULR_INVALID_KEY,    ///< invalid key
    ULR_HW_FAILURE,     ///< 硬件故障
    URL_SYS_FROZEN,     ///<失败次数过多，暂时锁定
    URL_TIME_SKEWED,    ///<APP端时间与设备偏差太大
    URL_VERITY_FAILED,  ///<平台验证失败
} UNLOCKRES;
/** 开门应答
 * @ref TCI_CMD_UNLOCK = 0x045A  ///< 开门 Req: @ref Tcis_UnlockReq
 */
typedef struct Tcis_UnlockResp {
    int status;   ///< 开锁应答码 @ref UNLOCKRES
} Tcis_UnlockResp;

/** 门(锁)状态(暂定). 本结构在与门锁对接后会调整
 * TCI_CMD_GET_LOCK_STATE  = 0x045C  ///< 获取门(锁状态)
 */
typedef struct Tcis_LockState {
    uint32_t state;  ///< 1:开;0:关
} Tcis_GetLockStateResp;

/** \struct Tcis_EnableCloseup
 * 跟踪特写功能设置
 * @ref TCI_CMD_SET_ENABLE_CLOSEUP    =     0x033E
 * @ref TCI_CMD_GET_ENABLE_CLOSEUP    =     0x034C
 */
typedef struct Tcis_EnableCloseup {
    int channel;  ///< 0
    int enabled;  ///< 1: enable closeup; 0: disable closeup
} Tcis_GetEnableCloseupResp, Tcis_SetEnableCloseupRep;

/** @name 台灯
 * @{*/
/** @struct Tcis_GetLightReq
 * 请求智能灯状态 \n
 * TCI_CMD_GET_LIGHT_STATE_REQ = 0x354
 */
typedef struct Tcis_GetLightReq {
    int lightId;       ///< 灯标识: 0
    int reserved; ///< 0
} __attribute__((__packed__)) Tcis_GetLightStateReq;
 
/** @anchor light_op_mask */
/** @name 灯光设置操作内容
 * @{*/
#define SETLIGHT_F_ONOFF     0x0001  ///< 设置开关 Tcis_LightState::on
#define SETLIGHT_F_MODE      0x0002  ///< 设置控制模式 Tcis_LightState::mode
#define SETLIGHT_F_INTENSITY 0x0004  ///< 设置亮度 Tcis_LightState::intensity
#define SETLIGHT_F_DELAYSHUT 0x0008  ///< 设置延时关闭 Tcis_LightState::delay_shutdown
//#define SETLIGHT_F_COLOR     0x0008  ///< 设置颜色 Tcis_LightState::color
/**@}*/
 
/** @struct Tcis_LightState
 * 智能灯状态. \n
 * TCI_CMD_SET_LIGHT_STATE_REQ = 0x352 \n
 * TCI_CMD_GET_LIGHT_STATE_REQ = 0x354 \n
 *
 * \b 举例 \n
 * - 手动开灯，并且亮度设为80
 *   \code{.c}
 *   Tcis_LightState state = {
 *      .id = 0,
 *      .fMask = SETLIGHT_F_ONOFF | SETLIGHT_F_INTENSITY,
 *      .on = 1,
 *      .intensity = 50
 *   };
 *   \endcode
 */
typedef struct Tcis_LightState {
    uint16_t lightId;        ///< 灯标识: 0
    uint16_t fMask;     ///< 结构内容掩码。见 @ref light_op_mask
    uint8_t on;         ///< 0:关闭； 1:开
    uint8_t mode;       ///< 0:manually; 1:自动控制
    uint8_t delay_shutdown; ///< 延迟关闭: 0-不延时; 1-延时
    uint8_t intensity;  ///< 强度 0~100
    //uint32_t color;   ///< 颜色0xrrggbb
} __attribute__((__packed__)) Tcis_GetLightStateResp, Tcis_SetLightStateReq;

/** @anchor audio_sample_fmt
  * @name 音频采样格式
  *
  *  - ENUM_AUDIO_SAMPLERATE  采样频率(samplerate)
  *  - ENUM_AUDIO_DATABITS    采样位宽(databits)
  *  - ENUM_AUDIO_CHANNEL     声道数(channel)
  *
  * 通过 TciSendFrame() / TciSendFrameEx() / TciSendPbFrame() 向sdk传递的音频数据时，需要通过 \c uFrameFlags
  * 参数指定声音的采样格式。这个参数的值按下面的公式组合得来:
  *
  * \code
  *  uFrameFlags = (samplerate << 2) | (datebits << 1) | channel
  * \endcode
  *
  * 本系统默认的音频采样格式为 8000/16位/单声道, 对应
  * \code
  * uFrameFlags = (AUDIO_SAMPLE_8K << 2) | (AUDIO_DATABITS_16 << 1) | AUDIO_CHANNEL_MONO = 0
  * \endcode
  *
  * @{ */
  
 /** 音频采样频率常数 */
// typedef enum ENUM_AUDIO_SAMPLERATE {
//     AUDIO_SAMPLE_8K         = 0x00, ///< 8000
//     AUDIO_SAMPLE_11K        = 0x01, ///< 11000
//     AUDIO_SAMPLE_16K        = 0x02, ///< 16000
//     AUDIO_SAMPLE_22K        = 0x03, ///< 22000
//     AUDIO_SAMPLE_24K        = 0x04, ///< 24000
//     AUDIO_SAMPLE_32K        = 0x05, ///< 32000
//     AUDIO_SAMPLE_44K        = 0x06, ///< 44000
//     AUDIO_SAMPLE_48K        = 0x07  ///< 48000
// } ENUM_AUDIO_SAMPLERATE;
  
 /** 音频采样位宽常数 */
// typedef enum ENUM_AUDIO_DATABITS {
//     AUDIO_DATABITS_X        = 0,   ///< 16 bits. 为了兼容，0也表示16位采样。8位采样用别的方式表示
//     AUDIO_DATABITS_16       = 1    ///< 16 bits
// } ENUM_AUDIO_DATABITS;
  
 /** 音频通道数 */
// typedef enum ENUM_AUDIO_CHANNEL {
//     AUDIO_CHANNEL_MONO      = 0,  ///< 单声道
//     AUDIO_CHANNEL_STERO     = 1   ///< 双声道
// } ENUM_AUDIO_CHANNEL;

/** \struct Tcis_SitPoseSens
 * 坐姿检测灵敏度.
 * TCI_CMD_SET_SITPOSE_SENS     =       0x0478
 * TCI_CMD_GET_SITPOSE_SENS     =       0x047A
 */
typedef struct Tcis_SitPoseSens {
    int mode;  ///< 灵敏度. 0:灵敏; 1:正常; 2:精准
} __attribute__((__packed__)) Tcis_SetSitPoseSensReq, Tcis_GetSitPoseSensResp;

/** 提示音类型 */
typedef enum ENUMHINTTONE {
    EHT_XXXX        = 1,        ///< 保留。以后可以将alarmtone的设置统一到这个接口
    EHT_CRY         = 2,        ///< 哭声
    EHT_BAD_POSTURE = 3         ///< 错误坐姿
} ENUMHINTTONE;
 
/** @anchor hinttone_op_mask */
/** @name 设置提示音内容掩码
 * @{*/
/** 设置提示音功能开关。要设置 @ref Tcis_SetHintToneReq 的\c enabled 和 \c ht_type 成员 */
#define SETHINTTONE_F_SWITCH      0x01
/** 设置提示音数据. 要设置 @ref Tcis_SetHintToneReq 结构中除 \c enabled 之外的所有成员 */
#define SETHINTTONE_F_DATA        0x02
/*@}*/
 
/** \struct Tcis_SetHintToneReq
 * 更通用的设置设备端提示音的结构。比 Tcis_SetAlarmTone_Req 多一个 ht_type 参数 \n
 * TCI_CMD_SET_HINTTONE      =         0x0480 \n
 * \n
 * app要先调用 @ref TCI_CMD_GET_ALARMTONE_CAP 获取设备端支持的音频格式.
 */
typedef struct Tcis_SetHintToneReq {
    unsigned char    fMask;         ///< 本结构中有效数据掩码. @ref hinttone_op_mask
 
    unsigned char    enabled;        ///< 1:使能。0:禁用
 
    unsigned short   ht_type;        ///< 提示对象。@ref ENUMHINTTONE
    unsigned int     id;             ///< 0: 默认声音; 其它:声音内容标识。设备端保存这个标识并在app查询时返回
    unsigned short type;             ///< 0:data为音频内容; 1:data为下载音频文件的url
    unsigned char af_fmt;            ///< @ref AUDIOFILEFMT
    unsigned char a_codec;           ///< @ref TCMEDIA
    int           data_len;          ///< length of data
    char data[0];
} __attribute__((__packed__)) Tcis_SetHintToneReq;
 
/** \struct Tcis_GetHintToneReq
 * 获取提示音的请求结构.
 * TCI_CMD_GET_HINTTONE               0x0482
 */
typedef struct Tcis_GetHintToneReq {
    unsigned int ht_type;    ///< 提示对象。 @ref ENUMHINTTONE
} __attribute__((__packed__)) Tcis_GetHintToneReq;
 
/** \struct Tcis_GetHintToneResp
 * 获取提示音的应答结构.
 * TCI_CMD_GET_HINTTONE               0x0482
 */
typedef struct Tcis_GetHintToneResp {
    short            enabled;        ///< 1:允许; 0:禁用
    unsigned short   ht_type;        ///< 提示对象。@ref ENUMHINTTONE
    unsigned int     id;               ///< TCI_CMD_SET_HINTTONE 的id参数
} __attribute__((__packed__)) Tcis_GetHintToneResp;

typedef enum {
    RT_STATE_RECORDING = 0   ///< 是否在录像. 参数：无。值: iState。 0-没有录像; 1-在录像
} ENUMRTSTATE;
 
/** \struct Tcis_GetRuntimeStateReq.
 * 获取设备运行时状态
 * TCI_CMD_GET_RUNTIME_STATE = 0x0388
 */
typedef struct Tcis_GetRuntimeStateReq {
    int state_name;    ///< 请求的状态名，@ref ENUMRTSTATE。状态可能会有参数，见相应状态说明
} Tcis_GetRuntimeStateReq;
/** \struct Tcis_RuntimeStateResp.
 * 设备端运行时状态的应答. 如果设备不支持相应的状态，\n
 * 在通用应答里返回 TCI_E_INVALID_PARAM .
 *
 * TCI_CMD_GET_RUNTIME_STATE   =   0x0388
 */
typedef struct Tcis_RuntimeStateResp {
    int state_name;   ///< 状态名: @ref ENUMRTSTATE
    union {
        int iState;  ///< 整型状态值
    } uState;  ///< 状态值
} Tcis_RuntimeStateResp;

/** @anchor ptz_track_type
 * @name 轨迹的表示方式
 * @{*/
#define TRACK_BY_NO   1      ///< 轨迹由预置位号表示. 设备端保存轨迹名称
#define TRACK_BY_NO_NONAME 2 ///< 轨迹由预置位号表示，没有名字
/**@}*/
 
#define ACTIVE_TRACK_DEFAULT   0xffff  ///< 活动轨迹为缺省轨迹
#define ACTIVE_TRACK_AUTO_SCAN 0xfffe  ///< 活动轨迹为水平线扫
/** \struct PtzTrackArray
 *  云台巡航轨迹数组
 */
typedef struct PtzTrackArray {
    uint16_t type;    ///< @ref ptz_track_type "轨迹表示方式"
    uint16_t n_track; ///< 轨迹数组大小
    uint16_t stay_time; ///< 在每个预置位停留的时间(s)
 
    /** 设置时(@ref TCI_CMD_SET_PTZ_TRACK )忽略(为0)。\n
     *  获取时(@ref TCI_CMD_GET_PTZ_TRACK ) 为当前正执行的巡航轨迹: \n
     * - 0:  没有巡航
     * - 1~max_track: 轨迹编号(Tcis_PtzCmd::control=TCIC_PTZ_CALL_TRACK, Tcis_PtzCmd::point=1~255)
     * - 0xffff:   缺省轨迹(Tcis_PtzCmd::control=TCIC_PTZ_CALL_TRACK, Tcis_PtzCmd::point=0)
     * - 0xfffe:   水平线扫(Tcis_PtzCmd::control=TCIC_PTZ_AUTO_SCAN)
     */
    uint16_t active_track;
 
    union {
        /** type = TRACK_BY_NO_NONAME */
        struct track_noname {
            uint16_t track_no;  ///< 编号. >0
            uint16_t act;       ///< 动作: 0:设置；1:删除
            uint16_t n_psp;     ///< 本轨迹中的预置位数
            uint16_t pspn[0];   ///< 预置位号数组
        } __attribute__((__packed__)) trck_nn[0]; ///< track_noname 轨迹数组
 
        /** type = TRACK_BY_NO */
        struct track {
            char name[32];      ///< 轨迹名。以'\0'结束
            uint16_t track_no;  ///< 编号。>0
            uint16_t act;       ///< 动作: 0:设置；1:删除
            uint16_t n_psp;     ///< 本轨迹中的预置位数
            uint16_t pspn[0];   ///< 预置位编号数组
        } __attribute__((__packed__)) trck[0];   ///< track 轨迹数组
    } u;  ///< 轨迹数组
} __attribute__((__packed__)) PtzTrackArray;
 
 
/** \struct Tcis_SetPtzTrackReq
 * 巡航设置.
 * TCI_CMD_SET_PTZ_TRACK  = 0x0474
 */
typedef struct Tcis_SetPtzTrackReq {
    int channel;   ///< 0
    struct PtzTrackArray pta;  ///< 轨迹数组(一般一次设置一个位置，即数组大小为1)
} __attribute__((__packed__)) Tcis_SetPtzTrackReq;
 
/** \struct Tcis_GetPtzTrackReq
 * 获取巡航设置.
 * TCI_CMD_GET_PTZ_TRACK  =    0x0476
 */
typedef struct Tcis_GetPtzTrackReq {
    uint16_t flags;   ///< 0: 获取全部巡航轨迹; 1-查询巡航轨迹能力
    uint16_t channel;
} __attribute__((__packed__)) Tcis_GetPtzTrackReq;
 
 
/** \struct Tcis_GetPtzTrackResp
 * 对获取巡航设置的应答.
 * TCI_CMD_GET_PTZ_TRACK  =    0x0476
 */
typedef struct Tcis_GetPtzTrackResp {
    uint16_t resp_type;         ///< 应答数据类型：=Tcis_GetPtzTrackReq::flags
    uint16_t channel;
    union {
        /** 巡航能力(resp_type = 1) */
        struct cruise_cap {
            uint16_t max_tracks; ///< 支持的轨迹数。有效轨迹编号 1~max_tracks
            uint16_t type;       ///< @ref ptz_track_type "轨迹类型"
        } __attribute__((__packed__)) cruise_cap; ///< 预置位能力(resp_type == 1)
 
        /** 巡航轨迹(resp_type = 0) */
        PtzTrackArray pta;     ///< 巡航航迹数组(resp_type == 0)
    } u; ///< 应答数据
} __attribute__((__packed__)) Tcis_GetPtzTrackResp;

/** 获取/设置提示音状态
 * @ref TCI_CMD_SET_VOICE_PROMPT_STATUS    = 0x0358 \n
 * @ref TCI_CMD_GET_VOICE_PROMPT_STATUS    = 0x035A
 */
typedef struct Tcis_VoicePromptStatus {
    int status;             ///< 0-关闭; 1-打开
    int reserved;           ///< 保留:0
} Tcis_SetVoicePromptStatusReq, Tcis_GetVoicePromptStatusResp;

/** \struct Tcis_ParkingMonitorSwitch
 * 停车监控总开关. 用于同时使能或禁用停车监控的有所功能. \n
 *
    @ref TCI_CMD_SET_PARKING_MONITOR    =    0x0484 \n
    @ref TCI_CMD_GET_PARKING_MONITOR    =    0x0486 \n

  @note 该命令影响以下子功能:
    - 停车监控设置 @ref TCI_CMD_GET_PARKING_DET/@ref TCI_CMD_SET_PARKING_DET
    - 缩时录像设置 @ref TCI_CMD_SET_TIMELAPSE_RECORD/@ref TCI_CMD_GET_TIMELAPSE_RECORD
 */
typedef struct Tcis_ParkingMonitorSwitch {
    /** - \c 0: 禁用所有子功能
        - \c 1: 打开停车监控总开关，但各子功能有其自己的设置(包括是否启用);
     */
    int enabled;
} __attribute__((__packed__)) Tcis_SetParkMonitorSwitchReq, Tcis_GetParkMonitorSwitchResp;

/** @anchor parkingdet_field_mask */
/** @name Tcis_ParkingDet::flags 停车监控域标志位
 * 设置后表示支持相应能力，并且 Tcis_ParkingDet 结构中对应成员有效
 * @{*/
#define  PARKINGDET_F_SENS             0x0001   ///< 支持 sensitivity
#define  PARKINGDET_F_WORKTIME         0x0002   ///< 支持 work_time
/**@}*/

/** 停车监控设置.
 *  TCI_CMD_SET_PARKING_DET     =       0x0364 \n
 *  TCI_CMD_GET_PARKING_DET     =       0x0366
 *
 *  本结构在GET时作返回，SET时为输入
 */
typedef struct Tcis_ParkingDet {
    int id;          ///< 0. 保留
    /** @ref parkingdet_field_mask "停车监控域标志位".
     *  获取时， flags 为支持的设置项的掩码。设置时，为结构体中有效成员的标志。\n
     *  例如，如果设备只支持灵敏度设置。设备在GET时，App在SET时，设置 flags=@ref PARKINGDET_F_SENS, sensitivity为灵敏度。
     */
    int flags;
    int sensitivity; ///< 灵敏度: 0-关闭; 1-低; 2-中; 3-高
    int work_time;   ///< 工作时间。单位 hour
} Tcis_GetParkingDetResp, Tcis_SetParkingDetReq;

/** 获取停车监控设置.
 *  TCI_CMD_GET_PARKING_DET      =       0x0366
 */
typedef struct Tcis_GetParkingDetReq {
    int id;  ///< 0. 保留
} Tcis_GetParkingDetReq;

/** 云台图片内定位
    TCI_CMD_LOCATE_IN_PIC  =  0x1002
 */
typedef struct Tcis_LocateInPic {
    int channel;      ///< 定位参照通道
    PtzPos pos;       ///< 位置。 x,y为位置坐标相对图像(高,宽)的比例；z忽略
} Tcis_LocateInPicReq;

/** @name 定时任务
 * 本处定义通用的定时任务配置机制。
 *@}*/

/** 定时任务标准动作定义 */
enum TgAction {
    TTA_OFF,  ///< 关闭/停止/...
    TTA_ON    ///< 打开/启动/...
};

/** 定时任务描述 */
typedef struct TgTimeAction {
    int       size;     ///< 本结构长度. 因为action的长度同具体动作有关。本结构是变长的

    CLOCKTIME from, to; ///< 时间范围
    uint16_t  state;    ///< 0:禁止; 1:有效(调度中); 2:单次已执行(repeat=0)
    uint16_t  repeat;   ///< weekdays mask. bit0:Sunday; bit1-Monday; ...

    /** 对象相关的动作.
     * 简单动作为一个4字节整数, 复杂动作会扩展，但长度为4的倍数.
     * 简单动作定义见 @ref TgAction */
    uint32_t  action;
} __attribute__((__packed__)) TgTimeAction;

/** \struct Tcis_TimerTask
 * 设置定时任务.
    TCI_CMD_SET_TIMER_TASK      =        0x0488
 */
typedef
struct Tcis_TimerTask {
    uint16_t object;    ///< 定时任务作用对象. @ref ETGTIMERTARGET
    uint16_t id;
    uint32_t nItems;    ///< 任务数
    TgTimeAction Items[0];  ///< 定时任务
} __attribute__((__packed__)) Tcis_GetTimerTaskResp, Tcis_SetTimerTaskReq;

/** 定时任务对象 */
typedef enum ETgTimerTarget {
    TTT_ALL = 0,       ///< 不限(全部对象)
    TTT_LIGHT,         ///< 灯光定时任务
    TTT_ALARM_TONE     ///< 警戒语音
} ETGTIMERTARGET;

/** \struct Tcis_GetTimerTask
 *  获取定时任务.
 *   TCI_CMD_GET_TIMER_TASK     =        0x048A
 */
typedef
struct Tcis_GetTimerTask {
    uint16_t object;    ///< 定时任务对象类型.  @ref ETGTIMERTARGET
    uint16_t id;        ///< 对象标识, 用于区别同种类型的多个对象. 从0开始编号
} Tcis_GetTimerTaskReq;


/** 多时间段变长数组 */
struct SMsgAVIoctrlTimeRanges {
    int n_tr;             ///< 时间段数
    TIMERANGE tr[1];      ///< 时间段数组
};

/** 设置低功耗设备主动唤醒时间.
    @ref TCI_CMD_SET_AWAKE_TIME      =        0x0470
*/
/** \see struct Fake_TimeRanges */
typedef struct SMsgAVIoctrlTimeRanges SMsgAVIoctrlSetAwakeTimeReq;


/** 获取低功耗设备主动唤醒时间.
    @ref TCI_CMD_GET_AWAKE_TIME      =        0x0472
*/
typedef struct SMsgAVIoctrlGetAwakeTimeReq {
    uint32_t reserved;
}  SMsgAVIoctrlGetAwakeTimeReq;

/** \see struct Fake_TimeRanges */
typedef struct SMsgAVIoctrlTimeRanges SMsgAVIoctrlAwakeTimeResp;

/** 设置设备警铃命令和获取设备警铃设置命令的参数结构体
  @ref TCI_CMD_SET_ALARM_BELL             = 0x0418, \n
  @ref TCI_CMD_GET_ALARM_BELL             = 0x041A,
  */
typedef struct SMsgAVIoctrlSetAlarmBell {
    uint8_t      version;     ///< 0. *** 接收者要检查version的值。当前为0对应本结构定义 *** !!!!
    uint8_t      reserved[3]; ///< all 0

    /** 事件类型掩码. bit0:所有事件; bit1:移动侦测; bit2:人体检测; ...[参看 ECEVENT 定义].
     *  如果bitN为1, 表示相应事件将触发警铃 */
    uint32_t     event_mask;
    uint32_t     event_mask2; ///< 0. 用作值大于31的事件掩码
}   SMsgAVIoctrlSetAlarmBellReq, SMsgAVIoctrlGetAlarmBellResp;
/** \see Tcis_SetAlarmBell*/

/** @struct Tcis_DaysList
* 日期列表.
* @ref TCI_CMD_LIST_RECORDDAYS = 0x800A
*/
typedef struct SMsgAVIoctrlTcis_DaysList {
    int n_day;   ///< 日期数组大小
    SDay days[1]; ///< 日期数组
} SMsgAVIoctrlTcis_DaysListResp;

// 通过命令2接收自定义通知事件
typedef struct RTMSG_t {
    unsigned int type;       // 取值: @ref RTMTYPE
    unsigned int data1;      // data1/data2 同 type 有关
    unsigned int data2;
}SMsgAVIoctrlRTMSG;


/** @name 带屏IPC
 * @{*/
/** \struct Tcis_ScreenDisplay
    @ref TCI_CMD_SET_SCREEN_DISPLAY     =     0x0382  // 设置屏幕显示
    @ref TCI_CMD_GET_SCREEN_DISPLAY     =     0x0384  // 获取屏幕显示设置
*/
typedef struct SMsgAVIoctrlTcis_ScreenDisplay {
    int disp_off_time;       ///< 非呼叫原因(例如设置)点亮屏幕后转熄屏的时间，单位:秒.
                             ///<   - \c 0 - 表示永不熄屏
} SMsgAVIoctrlTcis_ScreenDisplay;


/** \struct TIMEPLAN.  * 时间计划 */
typedef struct SMsgAVIoctrlTIMEPLAN {
    TIMERANGE time_range;   ///< 起止时间;如果结束时间<=开始时间;逻辑为跨天
    unsigned int day_mask;  ///< 重复: bit-mask of week-day.bit0-Sunday;bit1-Monday......
    int enabled;            ///<  0关闭  1启用
} __attribute__ ((__packed__))  SMsgAVIoctrlTIMEPLAN;

/** \struct TIMEPLANS 定时计划不定长数组 */
typedef struct SMsgAVIoctrlTIMEPLANS {
    unsigned int nItems;   ///< 时间计划个数
    SMsgAVIoctrlTIMEPLAN items[10];     ///<  时间计划数组, 个数由nItems决定
} __attribute__ ((__packed__)) SMsgAVIoctrlTIMEPLANS;

 
 /** 电源策略.
*  引入文档 https://tange-ai.feishu.cn/docx/M3DOddPWZoe8Mbxk1vpcf8avnqO
*/
typedef enum  {
    SMsgAVIoctrlPS_PERFORMANCE_FIRST, ///< 性能优先
    SMsgAVIoctrlPS_POWERSAVING,       ///< 省电模式. 开启ai, 录像不超过10"
     /** 超级省电模式(关闭本地pir唤醒).
    * @note App不发送关闭PIR的命令. 固件保留之前的PIR配置, \n
    *       但实际PIR不生效.
    */
    SMsgAVIoctrlPS_SUPER_POWERSAVING, ///< 超级省电模式
    SMsgAVIoctrlPS_USER_DEFINED,      ///< 用户定义录像时长
    SMsgAVIoctrlPS_POWER_CONSUMPTION,       ///< 微功耗
    SMsgAVIoctrlPS_ALWAYS_RECORDING      ///< 常电
} SMsgAVIoctrlPOWERSTRATEGY;

typedef struct SMsgAVIoctrlTcis_PowerStrategy {
    int strategy; ///< 当前工作模式 @ref POWERSTRATEGY
    int rec_len;     ///< strategy=@ref PS_USER_DEFINED时的自定义录像(工作)时长. 非自定义模式时为0
    /** 定时计划. 仅当strategy不是 @ref PS_SUPER_POWERSAVING 时定时计划才有效。 \n
   *  在定时范围内, 按当前模式工作, 定时范围外按 PS_SUPER_POWERSAVING 模式工作. \n
   *  但在 strategy=PS_SUPER_POWERSAVING 时, 设备仍然要响应指令，返回或保存定时 \n
   *  计划的内容, 以方便APP对编辑操作
   */
    SMsgAVIoctrlTIMEPLANS    plans;
}  __attribute__ ((__packed__)) SMsgAVIoctrlTcis_PowerStrategy;

/** 喂食器配置.
    * TCMD_FEEDER_GET_CONFIG     = 0x0500 \n
    * 这个结构可能扩展. App 端要检查收到的数据包的长度
    */
typedef struct SMsgAVIoctrlTcis_FeederConfig {
    int max_timers;       ///< 支持的定时配置数
    int max_servings;     ///< 最大供食份数
} __attribute__((__packed__)) SMsgAVIoctrlTcis_FeederConfigReq, SMsgAVIoctrlTcis_FeederConfigResp;

/** 手动喂食.
* TCMD_FEEDER_FEED_FOOD      = 0x0506
 */
typedef struct SMsgAVIoctrlTcis_FeedReq {
     int      nServing;     ///< 投喂份数
     int      reserved;     ///< 0
} __attribute__((__packed__))  SMsgAVIoctrlTcis_FeedReq;


typedef struct SMsgAVIoctrlFEEDERTIMER {
     CLOCKTIME  clock;    ///< 喂食时间
     uint8_t    state;    ///< 0：禁止（或单次定时器已执行）；1：有效
     uint8_t    repeat;   ///< weekdays mask. bit0:Sunday; bit1-Monday; ...
     uint16_t   serving;  ///< 食物份数
 } __attribute__ ((__packed__)) SMsgAVIoctrlFEEDERTIMER;

 /** 喂食定时设置.
  */
typedef struct SMsgAVIoctrlTcis_FeederTimers {
     int nTimers;
     SMsgAVIoctrlFEEDERTIMER tiems[10];
} __attribute__ ((__packed__)) SMsgAVIoctrlTcis_FeederTimersReq, SMsgAVIoctrlTcis_FeederTimersResp;

#endif /* TGCameraDefine_h */
