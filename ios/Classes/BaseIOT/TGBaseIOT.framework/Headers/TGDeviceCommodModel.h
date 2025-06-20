//
//  TGDeviceCommodModel.h
//  TGBaseIOT
//
//  Created by liubin on 2024/1/4.
//

#import <Foundation/Foundation.h>
#import "TGCameraDefine.h"
#import "TGCommondDefineHeader.h"
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceCommodModel : NSObject

@property (nonatomic, assign) int cmd;
@property (nonatomic, assign) int error;

- (instancetype)initWithMsgBaseResp:(SMsgBaseResp *)resp;

@end

@interface TGDeviceCommodResultModel : NSObject

@property (nonatomic, assign) int result;   // 1 ok , !1 no ok
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceBaseInstruction : NSObject

@property (nonatomic, copy) NSDictionary *abilities;

@end

@interface TGDeviceBaseInfor : NSObject

@property (nonatomic, copy) NSString *model;                        //IPCam mode
@property (nonatomic, copy) NSString *vendor;                       ///< IPCam manufacturer
@property (nonatomic, assign) int version;                          ///< IPCam firmware version    ex. v1.2.3.4 => 0x01020304;  v1.0.0.2 => 0x01000002
@property (nonatomic, assign) int channel;                          ///< Camera index
@property (nonatomic, assign) int total;                            ///< 0: No cards been detected or an unrecognizeable sdcard that could not be re-formatted.
///< -1: if camera detect an unrecognizable sdcard, and could be re-formatted
///< otherwise: return total space size of sdcard (MBytes)
@property (nonatomic, assign) int free;                             ///< Free space size of sdcard (MBytes)
@property (nonatomic, copy) NSString *reserved;                   ///< reserved

@end

@interface TGDeviceSDFormatModel : NSObject

@property (nonatomic, assign) int storage;                      // Storage index
@property (nonatomic, assign) int result;                   // 0: success;
// -1: format command is not supported.
// otherwise: failed.
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceSDStorageModel : NSObject

@property (nonatomic, assign) int channel;
@property (nonatomic, assign) int total;                    // 总容量，单位 M, >0: total space size of sdcard (MBytes), 0: 无卡,-1: 卡状态错，需要格式化,-2: SD卡状态为只读(可回放但不能继续写入), -3: 正在格式化，-4：正在初始化
@property (nonatomic, assign) int free;                     // Free space size of sdcard (MBytes)
@property (nonatomic, copy) NSString *reserved;

@end

#pragma mark - 视频翻转

@interface TGDeviceGetVideoModel : NSObject

@property (nonatomic, assign) int channel;
@property (nonatomic, assign) ENUM_VIDEO_MODE model;
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceSetVideoFlipModel : NSObject

@property (nonatomic, assign) int channel;
@property (nonatomic, assign) int result;
@property (nonatomic, copy) NSString *reserved;

@end

#pragma mark - 白光灯

@interface TGDeviceGetwhiteLightModel : NSObject

@property (nonatomic, assign) int channel;
@property (nonatomic, assign) int support;
@property (nonatomic, assign) TGVideoWhiteLightModel model;
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceSetWhiteLightModel : NSObject

@property (nonatomic, assign) int result;   // 1 ok , !1 no ok
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceLedStatusModel : NSObject

@property (nonatomic, assign) int status;   // 0-关闭，1-打开
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceAlarmLightStateModel : NSObject

@property (nonatomic, assign) int channel;
@property (nonatomic, assign) int state;    // 0:关; 1:开; 2:自动; 3:按定时设置

@end

@interface TGDeviceGetDayNightModel : NSObject

@property (nonatomic, assign) int channel;      // Camera Index
@property (nonatomic, assign) int support;      // 0不支持，2支持两种模式，3支持三种模式； — ???
@property (nonatomic, assign) int mode;        // 当前模式，mode: 0- auto 1- day,2- night
@property (nonatomic, copy) NSString *reserved;

@end

@interface TGDeviceGetEnableDormancyModel : NSObject

@property (nonatomic, assign) int enable;
@property (nonatomic, assign) int reserved;

@end

@interface TGDevicePassivityGetMaxAwakeModel : NSObject

@property (nonatomic, assign) int max_awake_time;
@property (nonatomic, assign) int reserved;

@end

@interface TGDeviceTimeModel : NSObject

@property (nonatomic, assign) int hour;
@property (nonatomic, assign) int minute;
@property (nonatomic, assign) int second;
@property (nonatomic, assign) int reserved;

@end

@interface TGDeviceClockTimeModel : NSObject

@property (nonatomic, strong) TGDeviceTimeModel *from;      // 起始时间点
@property (nonatomic, strong) TGDeviceTimeModel *to;        // 结束时间点
@property (nonatomic, assign) int day_mask;                 // 日期
@property (nonatomic, assign) int enabled;                  // 开关

@end

@interface TGDeviceAwakeTimeModel : NSObject

@property (nonatomic, assign) int n_tr;     // 时间段数
@property (nonatomic, copy) NSArray<TGDeviceClockTimeModel *> *trArray;    //时间段数组

@end

@interface TGDeviceRecordingModel : NSObject

@property (nonatomic, assign) int channel;      // Camera Index:0~N-1
@property (nonatomic, assign) ENUM_RECORD_TYPE recordType;      // 录像模式
@property (nonatomic, assign) int recordStream;                 // SD卡录像清晰度:0-高清，1-标清. 要求 RecordConf = "res"
@property (nonatomic, assign) int flags;                        // not used (2021-9-18)
@property (nonatomic, assign) int reserved;

@end

@interface TGDeviceSetRecordingRespModel : NSObject

@property (nonatomic, assign) int result;   // 0 ok , !0 no ok
@property (nonatomic, copy) NSString *reserved;

@end

#pragma mark - 电池电量、4g/wifi信号强度、电源频率

@interface TGDeviceBatteryStatusModel : NSObject

@property (nonatomic, assign) int batteryMode;          // 电池工作模式0–放电，1–充电
@property (nonatomic, assign) int batteryPower;         // 电池电量0-100(%),-1未知
@property (nonatomic, assign) int batteryLow;           // 电量低标志.1:低电;0:有电。APP要检查收到的应答长度。>=12时才有此域

@end

@interface TGDeviceGetWiFiLevelModel : NSObject

@property (nonatomic, assign) int activeNetIntf;        // 0:有线;1-Wifi;2-4G
@property (nonatomic, assign) int signalLevel;          // 信号强度 0~100(%);-1(未知)

@end

@interface TGDeviceSetFrequencyModel : NSObject

@property (nonatomic, assign) int channel;              // Camera Index
@property (nonatomic, assign) int result;               // 0: success; otherwise: failed.

@end

@interface TGDeviceFrequencyModel : NSObject

@property (nonatomic, assign) int channel;              // Camera Index
@property (nonatomic, assign) ENUM_ENVIRONMENT_MODE mode;

@end

#pragma mark - wifi列表

@interface TGDeviceWiFiInforModel : NSObject

@property (nonatomic, copy) NSString *ssid;             // WiFi ssid
@property (nonatomic, copy) NSString *password;         // if exist, WiFi password
@property (nonatomic, assign) int mode;                 // 工作模式 ENUM_AP_MODE
@property (nonatomic, assign) int enctype;              // 加密方式 ENUM_AP_ENCTYPE
@property (nonatomic, assign) int signal;               // signal intensity 0–100%
@property (nonatomic, assign) int status;               // 0 : invalid ssid or disconnected 1 : connected with default gateway 2 : unmatched password 3 : weak signal and connected

@end

#pragma mark - 网络配置

@interface TGDeviceNetConfigModel : NSObject

@property (nonatomic, copy) NSString *interface;        // 活动接口名
@property (nonatomic, assign) int dhcpConfig;           // 0:手动配置; 1:自动配置; 2:自动配置ip/gateway,手动dns
@property (nonatomic, copy) NSString *ipAddress;        // IP地址
@property (nonatomic, copy) NSString *netMask;          // 子网掩码
@property (nonatomic, copy) NSString *gateway;          // 网关
@property (nonatomic, copy) NSString *dns1;             // dns服务器1
@property (nonatomic, copy) NSString *dns2;             // dns服务器2
@property (nonatomic, copy) NSString *macAddress;       // Mac地址，只读

@end

@interface TGDeviceWiFiListModel : NSObject

@property (nonatomic, assign) int number;               // wifi数量
@property (nonatomic, strong) NSArray<TGDeviceWiFiInforModel *> *wifiList;      // wifi列表

@end

@interface TGDeviceSetWiFiModel : NSObject

@property (nonatomic, assign) int result;               // wifi 0: wifi connected; 1: failed to connect

@end

#pragma mark - 移动追踪

@interface TGDeviceMotionModel : NSObject

@property (nonatomic, assign) int channel;              // Camera Index
@property (nonatomic, assign) int support;              // 0不支持，非0支持 — ??? not used in get_setting
@property (nonatomic, assign) int model;                // 当前模式，mode: 1- on, 0- off

@end

@interface TGDeviceSetMotionModel : NSObject

@property (nonatomic, assign) int result;               // wifi 1 ok , !1 no ok

@end

#pragma mark - AI功能开关

@interface TGDeviceAICommonModel : NSObject

@property (nonatomic, assign) unsigned int ait_mask;             // AI类型掩码 的组合。 获取时为当前支持的AI功能; 设置时为要修改状态的AI功能
@property (nonatomic, assign) unsigned int ai_flags;             // 对应位为1表示使能

@end

#pragma mark - PIR

@interface TGDevicePIRModel : NSObject

@property (nonatomic, assign) int channel;                      // id of PIR：0
@property (nonatomic, assign) int sens;                         // 0:关闭; 1:低; 2:中; 3:高

@end

#pragma mark - 移动侦测

//区域的表示方式:
//  left/width: 区域的左上角坐标/宽度转成浮点数据，除以图片宽，再乘10000后取整
//  top/height: 区域的右上角坐标/高度转成浮点数据，除以图片高，再乘10000后取整
//  例如 { 5000,5000,5000,5000 } 表示右下角1/4矩形
@interface TGMdZone : NSObject

@property (nonatomic, assign) int left;
@property (nonatomic, assign) int top;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;

@end

@interface TGPoint : NSObject

@property (nonatomic, assign) int x;
@property (nonatomic, assign) int y;

@end


@interface TGMdPlogon : NSObject;

@property (nonatomic, assign) int nPoints;
@property (nonatomic, strong) NSArray<TGPoint *> *pointArray;

@end

@interface TGFake_MdZoneVLA : NSObject

@property (nonatomic, assign) int nZones;
@property (nonatomic, strong) NSArray<TGMdZone *> *mdZoneArray;

@end

@interface TGFake_MdPolygonVLA : NSObject
@property (nonatomic, assign) int nPolygons;
@property (nonatomic, strong) NSArray<TGMdPlogon *> *mdPlogonArray;

@end
@interface TGFake_RectPolygonVLA : NSObject

@property (nonatomic, strong) TGFake_MdZoneVLA *mdZoneVLA;
@property (nonatomic, strong) TGFake_MdPolygonVLA *mdPolygonVLA;

@end

@interface TGDeviceMotionDetectModel : NSObject

@property (nonatomic, assign) int channel;                      // Camera Index: 0~N-1
@property (nonatomic, assign) int enabled;                      // 是否开启 1:enabled; 0:disabled
@property (nonatomic, assign) int sensitivity;                  //下面的域根据设备能力设置。如果设备本身不支持，其值会被忽略 1~5
@property (nonatomic, assign) int hasZone;                      // 是否有区域 1: nZones/zones has valid setting; 0: ignore zones
@property (nonatomic, assign) int excludeZone;                  // 是否侦测区域外 0: 检测区域内；1: 检测区域外
//@property (nonatomic, assign)】】
@property (nonatomic, assign) int flags;                        // MD_AT_RECTS 低字节为 移动侦测区域表示标志; 最高位为是否支持[区域排除]的标志位
@property (nonatomic, strong) TGFake_MdZoneVLA *mdZoneVLA;      // 矩形区域 (flags&0x03)== MD_AT_RECTS 0
@property (nonatomic, strong) TGFake_MdPolygonVLA *mdPolygonVLA;   // 多边形区域 (flags&0x03)== MD_AT_POLYGON 1
@property (nonatomic, strong) TGFake_RectPolygonVLA *rectPolygonVLA; // 多边形区域+矩形区域 (flags&0x03)== MD_AT_RECTSWITHPOLYGON 2 的伪数据结构

@end

@interface TGDeviceSetMotionDetectReqModel : NSObject

@property (nonatomic, assign) int channel;                      // Camera Index: 0~N-1
@property (nonatomic, assign) int enabled;                      // 是否开启 1:enabled; 0:disabled
@property (nonatomic, assign) int sensitivity;                  //下面的域根据设备能力设置。如果设备本身不支持，其值会被忽略 1~5
@property (nonatomic, assign) int hasZone;                      // 是否有区域 1: nZones/zones has valid setting; 0: ignore zones
@property (nonatomic, assign) int excludeZone;                  // 是否侦测区域外 0: 检测区域内；1: 检测区域外
//@property (nonatomic, assign)】】
@property (nonatomic, assign) int flags;                        // 0 矩形 1 多边形 2 矩形+多边形 MD_AT_RECTS 低字节为 移动侦测区域表示标志; 最高位为是否支持[区域排除]的标志位

@end

@interface TGDeviceMotionDetectRespModel : NSObject

@property (nonatomic, assign) int result;                       // 0: success; otherwise: failed.

@end

@interface TGDeviceMotionAreaState : NSObject

@property (nonatomic, assign) int channel;                      // 视频通道(Camera Index) 0~N-1
@property (nonatomic, assign) int state;                        // 0x00:隐藏；0x01: 显示
    
@end

#pragma mark - 警报语音

@interface TGDeviceAlarmToneCapModel : NSObject

@property (nonatomic, assign) int nSamplePerSec;                // 采样频率
@property (nonatomic, assign) int nBitsPerSample;               // 采样位宽
@property (nonatomic, assign) int nChannels;                    // 通道数
@property (nonatomic, assign) int nExpectedFileFormats;         // 期望的文件格式数
@property (nonatomic, copy) NSArray *ExpectedFileFormats;      // 期望的音频格式 AUDIOFILEFMT 集合
@property (nonatomic, assign) int nSupportedAudioCodecs;        // 支持的音频格式数
@property (nonatomic, copy) NSArray *SupportedAudioCodecs;     // 支持的音频格式 TCMEDIA集合
@property (nonatomic, assign) int idAlarmTone;                  // 当前报警音标识. 0 - 默认
@property (nonatomic, assign) int uiFileSizeLmt;                // 文件大小上限(单位KB)。对APP来说，当收到的应答长度>=36时才存在这个信息

@end

@interface TGDeviceSetAlarmToneModel : NSObject

@property (nonatomic, assign) int idAlarmTone;                           // 0: 默认声音; 其它:声音内容标识
@property (nonatomic, assign) int type;                         // 0:data为音频内容; 1:data为下载音频文件的url
@property (nonatomic, assign) AUDIOFILEFMT af_fmt;              // AF_FMT_WAV .wav ;AF_FMT_AMR.amr ;AF_FMT_MP3 .mp3 ;AF_FMT_M4A .m4a
@property (nonatomic, assign) TCMEDIA a_codec;
@property (nonatomic, copy) NSData *data;                       // 语音

@end

@interface TGDeviceAlarmBellModel : NSObject

@property (nonatomic, assign) uint8_t version;                  // 0. *** 接收者要检查version的值。当前为0对应本结构定义 *** !!!!
@property (nonatomic, assign) uint32_t event_mask;              // 事件类型掩码.bit0:所有事件; bit1:移动侦测; bit2:人体检测; ...[参看 ECEVENT 定义]. 如果bitN为1, 表示相应事件将触发警铃
@property (nonatomic, assign) uint32_t event_mask2;             // 0. 用作值大于31的事件掩码

@end

#pragma mark - 云台

@interface TGDeviceGetPresetPointsReqModel : NSObject

@property (nonatomic, assign) uint16_t flags;                   //  0: 返回全部预置位 1: 返回能力
@property (nonatomic, assign) uint16_t channel;                 // 视频通道号(camera index)(2022.12.15)

@end

@interface TGPsp_cap : NSObject

@property (nonatomic, assign) uint16_t cbSize;                  // 本结构大小 = sizeof(struct psp_cap)。目前为12
@property (nonatomic, assign) uint8_t zero;                     // 0
@property (nonatomic, assign) uint8_t channel;                  // 与 TCI_CMD_GET_PSP 请求匹配的通道号(Camera Index)
@property (nonatomic, assign) uint16_t max_psp;                 // 支持的预置位数。有效预置位编号 1~max_psp. 0保留
@property (nonatomic, assign) uint16_t type;                    // 预置位类型  宏 PSP_BY_NO 等（可全局检索）
@property (nonatomic, assign) int flags;                   // 0x01: 预置位保存到设备端(app要调用 TCI_CMD_SET_PSP)

@end

@interface TGPSP_BY_NO : NSObject

@property (nonatomic, assign) uint16_t flags;                   // 预置标志. 0 或 PSP_F_DISABLED 或 其它 PSP_F_xxx 的组合
@property (nonatomic, assign) uint16_t num;                     // 预置位编号: 1~n_psp. 0保留
@property (nonatomic, copy) NSString *name;                     // 预置位名称

@end

@interface TGPSPN_NoName : NSObject

@property (nonatomic, assign) uint16_t flags;                   // 预置标志. 0 或 PSP_F_DISABLED 或 其它 PSP_F_xxx 的组合
@property (nonatomic, assign) uint16_t num;                     // 预置位编号: 1~n_psp. 0保留

@end

@interface TGPTZPos : NSObject

@property (nonatomic, assign) float x;                          // x,y,z: 取值0.0~1.0, 分别表示云台水平、垂直、纵深方向的位置点各自方向最大范围的比率。 例如x=0.5表示去云台水平居中；z=0.0表示纵深处在x1的位置 x,y 小于0.0或大于1.0时无意义(程序忽略)。 z值仅在变焦倍数可知时有意义。z小于0.0或大于1.0时另行定义
@property (nonatomic, assign) float y;
@property (nonatomic, assign) float z;

@end

@interface TGPSP_BY_POS : NSObject

@property (nonatomic, assign) uint16_t flags;                   // 预置标志. 0 或 PSP_F_DISABLED 或 其它 PSP_F_xxx 的组合
@property (nonatomic, assign) uint16_t num;                     // ID, 用于删除或修改时作标识. 0保留不可删除(双目变焦设备用于镜头切换)
@property (nonatomic, strong) TGPTZPos *pos;
@property (nonatomic, copy) NSString *name;                     // 预置位名称

@end

@interface TGPSPP_NoName : NSObject

@property (nonatomic, assign) uint16_t flags;                   // 预置标志. 0 或 PSP_F_DISABLED 或 其它 PSP_F_xxx 的组合
@property (nonatomic, assign) uint16_t num;                     // ID, 用于删除或修改时作标识. 0保留不可删除(双目变焦设备用于镜头切换)
@property (nonatomic, strong) TGPTZPos *pos;

@end

@interface TGUNionPSPModel : NSObject

@property (nonatomic, strong) TGPSP_BY_NO *psp_by_no;           // type = PSP_BY_NO, 用编号表示的预置位
@property (nonatomic, strong) TGPSPN_NoName *pspn_noname;       // type = PSP_BY_NO_NONAME, 用编号表示的预置位
@property (nonatomic, strong) TGPSP_BY_POS *psp_by_pos;         // type = PSP_BY_POS, 用位置表示的预置位
@property (nonatomic, strong) TGPSPP_NoName *pspp_noname;       // type = PSP_BY_POS_NONAME, 用位置表示的预置位

@end

@interface TGPresetPointArray : NSObject

@property (nonatomic, assign) uint16_t n_psp;                   // 预置位数组大小
@property (nonatomic, assign) uint8_t type;                   // 预置位类型  宏 PSP_BY_NO 等（可全局检索）
@property (nonatomic, assign) uint8_t channel;                   // 在TCI_CMD_GET_PSP 的应答中，为与请求匹配的通道号(Camera index)。设置时为0，因为请求结构中有定义channel字段
@property (nonatomic, strong) NSArray<TGUNionPSPModel *> *u;                 // 预置位数组

@end

@interface TGDevicePresetPointsRespModel : NSObject

@property (nonatomic, strong) TGPsp_cap *psp_cap;                       // 预置位能力(Tcis_GetPresetPointsReq::flags == 1)
@property (nonatomic, strong) TGPresetPointArray *presetPointArray;   // Tcis_GetPresetPointsReq::flags == 0 预置位数组
 
@end

@interface TGDeviceSetPresetPointsRespModel : NSObject

@property (nonatomic, assign) int channel;                       // Camera Index: 0~N-1
@property (nonatomic, strong) TGPresetPointArray *pspa;     // 预置位数组(一般一次设置一个位置，即数组大小为1)

@end

// 守望位
@interface TGDeviceWatchPosModel : NSObject

@property (nonatomic, assign) int channel;          // Camera Index
@property (nonatomic, assign) int num;              // 预置位编号. -1:禁用; >0:设置预置位num为守望位
@property (nonatomic, assign) int idle_time;        // 回到守望位前的云台无动作时间，单位: 秒

@end

// 巡航设置
@interface TGGetPtzTrackReqModel : NSObject

@property (nonatomic, assign) int16_t flags;        // 0: 获取全部巡航轨迹; 1-查询巡航轨迹能力
@property (nonatomic, assign) int16_t channel;      // 视频通道号(Camera Index)

@end

@interface TGPtzTrackNoNameArray : NSObject

@property (nonatomic, assign) int16_t track_no;     // 编号。>0
@property (nonatomic, assign) int16_t act;          // 动作: 0:设置；1:删除
@property (nonatomic, assign) int16_t n_psp;        // 本轨迹中的预置位数
@property (nonatomic, strong) NSArray *pspn;        // 预置位编号数组

@end

@interface TGPtzTrackNoArray : NSObject

@property (nonatomic, copy) NSString *name;         // 轨迹名。以'\0'结束
@property (nonatomic, assign) int16_t track_no;     // 编号。>0
@property (nonatomic, assign) int16_t act;          // 动作: 0:设置；1:删除
@property (nonatomic, assign) int16_t n_psp;        // 本轨迹中的预置位数
@property (nonatomic, strong) NSArray *pspn;         // 预置位编号数组

@end

@interface TGPtzTrackArrayUnionModel : NSObject

@property (nonatomic, strong) NSArray<TGPtzTrackNoNameArray *> *trck_nn;  // type = TRACK_BY_NO_NONAME
@property (nonatomic, strong) NSArray<TGPtzTrackNoArray *> *trck; // type = TRACK_BY_NO
 
@end

@interface TGPTZTrackUnionCapModel : NSObject

@property (nonatomic, assign) int16_t max_tracks;   // 0: 获取全部巡航轨迹; 1-查询巡航轨迹能力
@property (nonatomic, assign) int16_t type;         // 轨迹的表示方式类型 可搜索宏定义 TRACK_BY_NO   1 TRACK_BY_NO_NONAME   2

@end

@interface TGPtzTrackArrayModel : NSObject

@property (nonatomic, assign) int16_t type;         // 轨迹的表示方式类型 可搜索宏定义 TRACK_BY_NO   1 TRACK_BY_NO_NONAME   2
@property (nonatomic, assign) int16_t n_track;      // 轨迹数组大小
@property (nonatomic, assign) int16_t stay_time;    // 在每个预置位停留的时间(s)

/* 置时(TCI_CMD_SET_PTZ_TRACK )忽略(为0)。
 获取时(TCI_CMD_GET_PTZ_TRACK ) 为当前正执行的巡航轨迹:
 0:没有巡航
 1~max_track: 轨迹编号(Tcis_PtzCmd::control=TCIC_PTZ_CALL_TRACK, Tcis_PtzCmd::point=1~255)
 0xffff: 缺省轨迹(Tcis_PtzCmd::control=TCIC_PTZ_CALL_TRACK, Tcis_PtzCmd::point=0)
 0xfffe: 水平线扫(Tcis_PtzCmd::control=TCIC_PTZ_AUTO_SCAN)*/
@property (nonatomic, assign) int16_t active_track;

@property (nonatomic, strong) TGPtzTrackArrayUnionModel *u;

@end

@interface TGPTZTrackUnionModel : NSObject

@property (nonatomic, strong) TGPTZTrackUnionCapModel *cruise_cap; // 预置位能力(resp_type == 1)
@property (nonatomic, strong) TGPtzTrackArrayModel *pta;           // 巡航轨迹(resp_type = 0) 巡航航迹数组(resp_type == 0)/
@end

@interface TGGetPtzTrackRespModel : NSObject

@property (nonatomic, assign) int16_t resp_type;   // 0: 获取全部巡航轨迹; 1-查询巡航轨迹能力
@property (nonatomic, assign) int16_t channel;
@property (nonatomic, strong) TGPTZTrackUnionModel *u; // 应答数据

@end

@interface TGGetPtzPosRespModel : NSObject

@property (nonatomic, strong) TGPTZPos *pos;    ///< 位置
@property (nonatomic, assign) int channel;      ///< 通道
@property (nonatomic, assign) int psp_num;      ///< 如果是要转到预置位，此为预置位编号，否则为0 [2021.11.2]

@end

#pragma mark - 喇叭音量

@interface TGDeviceVolume : NSObject

@property (nonatomic, assign) int flags;                // 0: 音量调节范围不可知，1：音量调节范围可知
@property (nonatomic, assign) int volume;               // 音量：flags为0=> 1:音量加，-1:音量减 flags为1=> 0-100之间的等级

@end

@interface TGDeviceMicLevel : NSObject

@property (nonatomic, assign) int sensitivity;          // 灵敏度：[0-100]

@end

@interface TGDeviceMicroModel : NSObject

@property (nonatomic, assign)  int channel;          // Camera Index
@property (nonatomic, assign)  int status;           // 当前当前麦克风状态，status: 0- 关, 1- 开

@end

@interface TGDeviceSetMicroRespModel : NSObject

@property (nonatomic, assign) int result;   // 1 ok , !1 no ok

@end

@interface TGDeviceEventState : NSObject

@property (nonatomic, assign) int event;            // ECEVENT
@property (nonatomic, assign) int enabled;          // 1:enabled; 0:disabled

@end

@interface TGDeviceSDDaysModel : NSObject

@property (nonatomic, assign) int year;             // 年
@property (nonatomic, assign) int month;            // 月1-12
@property (nonatomic, assign) int day;              // 日1-31

@end

@interface TGDeviceSDVideoAvailableDaysModel : NSObject

@property (nonatomic, assign) int n_day;
@property (nonatomic, copy) NSArray <TGDeviceSDDaysModel *> *daysArray;

@end


@interface TGDeviceNotificationModel : NSObject

@property (nonatomic, assign) TGDeviceNotificationType notificationType; // 来源
@property (nonatomic, assign) RTMTYPE type;                 // 消息类型  RTM_USER = 255
@property (nonatomic, assign) unsigned int data1;           // 消息类型相关数据1
@property (nonatomic, assign) unsigned int data2;           // 消息类型相关数据2
@property (nonatomic, assign, nullable) unsigned char *buffer; // 自定义消息数据
@property (nonatomic, assign) unsigned int dataLength;         // 长度
@property (nonatomic, assign) unsigned int channel;            // 通道

@end

@interface TGDeviceAnswerToCallSetModel : NSObject

@property (nonatomic, assign) ECALLSTATE state;
@property (nonatomic, assign) int more;                     // for HANGUP, 0:normal hangup; 1:connection broken

@end

@interface TGDeviceAnswerToCallGetModel : NSObject

@property (nonatomic, assign) int state;                   // 0表示可发起通话，1=表示通话被占用

@end

@interface TGDeviceScreenDisplayModel : NSObject

@property (nonatomic, assign) int disp_off_time;  ///非呼叫原因(例如设置)点亮屏幕后转熄屏的时间，单位:秒.                             ///<   - \c 0 - 表示永不熄屏

@end

@interface TGDeviceBuzzerGetModel : NSObject

@property (nonatomic, assign) int status;  // 当前蜂鸣器状态，status: 0- 关, 1- 开
@property (nonatomic, assign) int channel;

@end

@interface TGDeviceBuzzerSetModel : NSObject

@property (nonatomic, assign) int result;  // 0失败，1成功

@end

@interface TGDeviceSdCardStartPlayModel : NSObject

@property (nonatomic, assign) int command;  //Play record command. refer to ENUM_PLAYCONTROL
@property (nonatomic, assign) int result;   // Depends on command
                                            // when is AVIOCTRL_RECORD_PLAY_START:
                                            //    result>=0   real channel no used by device for playback
                                            //    result <0    error
                                            //            -1    playback error
                                            //            -2    exceed max allow client amount

@end

@interface TGDevicePowerStrategy : NSObject

@property (nonatomic, assign) int strategy;  // 当前工作模式 SMsgAVIoctrlPOWERSTRATEGY
@property (nonatomic, assign) int rec_len;   // strategy=SMsgAVIoctrlPS_USER_DEFINED时的自定义录像(工作)时长. 非自定义模式时为0
@property (nonatomic, strong) TGDeviceAwakeTimeModel *timePlans;

@end

@interface TGFeederConfigModel : NSObject

@property (nonatomic, assign) int max_timers;               // 支持的定时配置数
@property (nonatomic, assign) int max_servings;             // 最大供食份数

@end

@interface TGFeederTimerModel : NSObject
@property (nonatomic, strong) TGDeviceTimeModel *clock;     // 喂食时间
@property (nonatomic, assign) int state;                    // 0：禁止（或单次定时器已执行）；1：有效
@property (nonatomic, assign) int repeat;                   // weekdays mask. bit0:Sunday; bit1-Monday; ...
@property (nonatomic, assign) int serving;                  // 食物份数

@end

@interface TGHandFeederModel : NSObject
@property (nonatomic, assign) int  nServing;                // 投喂份数 >= 1

@end

@interface TGABPOSModel : NSObject

@property (nonatomic, assign) short x;          // osd区域在画面中的坐标. 解释受alignment的取值影响
@property (nonatomic, assign) short y;          // osd区域在画面中的坐标. 解释受alignment的取值影响
@property (nonatomic, assign) uint8_t alignment;// 对齐方式常数的组合(https://device-sdk-docs.tange365.com/TgCloudCmd_8h.html#alignment)
@property (nonatomic, strong) NSData *reserved;

@end

@interface TGOSDItemModel : NSObject
@property (nonatomic, assign) uint16_t  itemId; // cis_GetOsdResp::nMaxOsdItems - 1. 毎个条目有唯一id
@property (nonatomic, assign) uint16_t  flags; // 0 或 OsdItem(https://device-sdk-docs.tange365.com/TgCloudCmd_8h.html#osd_flags) 标志 的组合
@property (nonatomic, assign) OSDTYPE  type;
@property (nonatomic, assign) int pos;  // flags==0: OSDPOSITION
@property (nonatomic, strong) TGABPOSModel *abPos;
@property (nonatomic, assign) int  len;  //data 中的数据长度
/*
 data: 内容与 type 相关。长度填充到4的倍数，使下一个结构4字节边界对齐。例如len = 3, data则填充到4.
 举例： item 指向一个 OsdItem ，下一个 OsdItem 为

 (struct OsdItem*)(item->data + ((item->len + 3) & 0xfffc)
 或者

 (struct OsdItem*)((long)(item->data + item->len + 3) & ~3L)
 type=OSDT_DATETIME
 为格式字符串(参考strftime())；为空时，取设备默认格式
 type=OSDT_TEXT
 自定义文本. 字符编码参见 Tcis_GetOsdResp::eCharEncoding
 type=OSDT_BMP32/OSDT_BMP1555
 带alpha属性的 bmp 文件
 */
@property (nonatomic, strong) NSData  *data;
@property (nonatomic, strong) NSString  *dataStr;//item->type 是 OSDT_DATETIME 或 OSDT_TEXT时，会将data转化为dataStr
 
@end

@interface TGOSDRespModel : NSObject

@property (nonatomic, assign) int  fSupportedTypes; //支持的OSDTYPE的位组合. 如果支持类型T, 则第T位置1. 例如支持TEXT和BMP32: (1<<OSDT_TEXT) | (1<<OSDT_BMP32)
@property (nonatomic, assign) CHAR_ENCODING  eCharEncoding; // 支持OSDT_TEXT时，对应的字符编码 CHAR_ENCODING(https://device-sdk-docs.tange365.com/TgCloudCmd_8h.html#a7dc1cd0b8822d7b766a0be71a1a733bc)
@property (nonatomic, assign) uint16_t  nMaxTextLength;// OSDT_TEXT 允许的最大字节数. 如果为0的话，默认为32字节
@property (nonatomic, assign) int  nMaxOsdItems;// 支持最大osd条数
@property (nonatomic, assign) int nItems;// osd条目数(items大小)
@property (nonatomic, strong) NSArray <TGOSDItemModel *> *items; //osd条目数组

@end

@interface TGPTZShortTurnModel : NSObject

@property (nonatomic, assign) int x;    // >0: right; <0: left
@property (nonatomic, assign) int y;    // >0: up; <0:down
@property (nonatomic, assign) int channel;

@end

NS_ASSUME_NONNULL_END
