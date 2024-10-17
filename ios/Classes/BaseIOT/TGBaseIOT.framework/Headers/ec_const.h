/** \file ec_const.h
 *  \brief 常数和错误码定义
 */

#ifndef __ec_const_h__
#define __ec_const_h__

/** \ingroup api_const
 * @{*/

/** @name Media Type
 * @{
 */
typedef enum TCMEDIA {
    TCMEDIA_INVALID             = 0,            ///< 无效类型
    TCMEDIA_VIDEO_H264          = 1,      ///< H.264   "h264"
    TCMEDIA_AUDIO_G711A         = 2,      ///< G.711A  "g711a" "alaw"
    TCMEDIA_AUDIO_ALAW	        = TCMEDIA_AUDIO_G711A,  ///< G.711A  "g711a" "alaw"

	//----------------------------------
    TCMEDIA_VIDEO_IJPG          = 10,
    TCMEDIA_VIDEO_MPEG          = 11,     ///< Mpeg    "mpeg"
    TCMEDIA_VIDEO_JPEG          = 12,     ///< jpeg    "jpeg"
    TCMEDIA_VIDEO_MJPEG         = TCMEDIA_VIDEO_JPEG,     ///< Mjpeg "jpeg"
    TCMEDIA_VIDEO_H265          = 13,     ///< H.265   "h265"
    TCMEDIA_VIDEO_MAX,

    TCMEDIA_AUDIO_ULAW	        = 51,    ///< G.711U  "g711u" "ulaw"
    TCMEDIA_AUDIO_G711U         = TCMEDIA_AUDIO_ULAW, ///< G.711U
    TCMEDIA_AUDIO_PCM           = 52,    ///< Raw PCM  "pcm"
    TCMEDIA_AUDIO_ADPCM         = 53,    ///< ADPCM    "adpcm"
    TCMEDIA_AUDIO_ADPCM_IMA     = TCMEDIA_AUDIO_ADPCM,  ///< ADPCM  "adpcm"
    TCMEDIA_AUDIO_ADPCM_DVI4    = 54,  ///< DVI4  "adpcm-dvi4"
    TCMEDIA_AUDIO_G726_16       = 55,    ///< G.726-16
    TCMEDIA_AUDIO_G726_24       = 56,    ///< G.726-24
    TCMEDIA_AUDIO_G726_32       = 57,    ///< G.726-32
    TCMEDIA_AUDIO_G726_40       = 58,    ///< G.726-40
    TCMEDIA_AUDIO_AAC           = 59,    ///< AAC  "aac"
    TCMEDIA_AUDIO_MP3           = 60,    ///< MP3  "mp3"
    TCMEDIA_AUDIO_AMR           = 61,    ///< AMR  "amr"
    TCMEDIA_AUDIO_MAX

} TCMEDIA;

/** 是否视频媒体类型 */
#define TCMEDIA_IS_VIDEO(mt) ((mt) && (((mt)<TCMEDIA_VIDEO_MAX && (mt)>TCMEDIA_AUDIO_G711A) || (mt)==TCMEDIA_VIDEO_H264))
/** 是否音频媒体类型 */
#define TCMEDIA_IS_AUDIO(mt) ((mt) && ((mt)==TCMEDIA_AUDIO_G711A || ((mt)>=TCMEDIA_AUDIO_ULAW && (mt)<TCMEDIA_AUDIO_MAX)))

/**@}*/ //name: Media Type

/** @anchor audio_sample_fmt 
 * @name 音频采样格式
 *
 * int TciSendFrame(int stream, TCMEDIA mt, const uint8_t *pFrame, int length, uint32_t ts, int uFrameFlags);
 * int TciSendFrameEx(int channel, int stream, TCMEDIA mt, const uint8_t *pFrame, int length, uint32_t ts, int uFrameFlags);
 * int TciSendPbFrame(p2phandle_t handle, uint32_t id_mt, const uint8_t *frame, int len, uint32_t timestamp, int uFrameFlags);
 *
 * TciSendFrame(..., int uFrameFlags) / TciSendFrameEx(..., int uFrameFlags) / TciSendPbFrame(..., int uFrameFlags) 的最后
 * 一个参数 \c uFrameFlags ，当媒体类型为音频时，为音频采样格式.
 *
 * 该格式由采样频率、采样位宽和声道数据组成：
 *
 * \code
 *  uFrameFlags = (samplerate << 2) | (datebits << 1) | channel
 * \endcode
 *
 * 当 \c uFrameFlags 为0时，SDK会将其改为默认配置.
 *
 * 本系统默认的音频采样格式为 8000/16位/单声道, 对应 
 * \code
 * uFrameFlags = (AUDIO_SAMPLE_8K << 2) | (AUDIO_DATABITS_16 < 1) | AUDIO_CHANNEL_MONO = 2
 * \endcode
 *
 * @{ */

/** 音频采样频率常数 */
typedef enum ENUM_AUDIO_SAMPLERATE {
	AUDIO_SAMPLE_8K			= 0x00, ///< 8000
	AUDIO_SAMPLE_11K		= 0x01, ///< 11000
	AUDIO_SAMPLE_16K		= 0x02, ///< 16000
	AUDIO_SAMPLE_22K		= 0x03, ///< 22000
	AUDIO_SAMPLE_24K		= 0x04, ///< 24000
	AUDIO_SAMPLE_32K		= 0x05, ///< 32000
	AUDIO_SAMPLE_44K		= 0x06, ///< 44000
	AUDIO_SAMPLE_48K		= 0x07  ///< 48000
} ENUM_AUDIO_SAMPLERATE;

/** 音频采样位宽常数 */
typedef enum ENUM_AUDIO_DATABITS {
	AUDIO_DATABITS_X		= 0, ///< 16 bits. 为了兼容，0也表示16位采样。8位采样用别的方式表示
	AUDIO_DATABITS_16		= 1  ///< 16 bits
} ENUM_AUDIO_DATABITS;

/** 音频通道数 */
typedef enum ENUM_AUDIO_CHANNEL {
	AUDIO_CHANNEL_MONO		= 0,  ///< 单声道
	AUDIO_CHANNEL_STERO		= 1   ///< 双声道
} ENUM_AUDIO_CHANNEL;

/**@}*/

/** 上报事件类型.
 * 事件可能需要携带额外参数。参数通过 EVENTPARAM::evt_data 传递，内容与具体事件相关
 */
typedef enum TGECEVENT {
    TGECEVENT_NONE = 0,             ///< [] none
    TGECEVENT_MOTION_DETECTED,      ///< [motion] is detected (=1)
    TGECEVENT_HUMAN_BODY,           ///< [body] human body is detected (=2)
    TGECEVENT_SOUND,                ///< [sound] (=3)
    TGECEVENT_PIR,                  ///< [pir](=4)

    TGECEVENT_SMOKE,                ///< [smoke] (=5)
    TGECEVENT_TEMPERATURE_L,        ///< [tempL] temperature low(=6). 参数: MKEVTDATA_Temperatur()
    TGECEVENT_TEMPERATURE_H,        ///< [tempH] temperature high(=7). 参数: MKEVTDATA_Temperatur()
    TGECEVENT_HUMIDITY_L,           ///< [humidL] humidity low(=8). 参数: MKEVTDATA_Humidity()
    TGECEVENT_HUMIDITY_H,           ///< [humidH] humidity high(=9). 参数: MKEVTDATA_Humidity()
    TGECEVENT_GENERIC_SENSOR,       ///< [generic] 通用传感器类消息 (=10)

    TGECEVENT_DR_BEGIN,             ///< 行车记录仪事件范围开始(=11)
    TGECEVENT_G_SENSOR = TGECEVENT_DR_BEGIN,   ///< [g-sensor] G-Sensor(碰撞事件)(=11). 参数: NULL or EVTDATA_SERIOUS_COLLISION
    TGECEVENT_COLLISION = TGECEVENT_G_SENSOR,  ///< = @ref ECEVENT_G_SENSOR(=11)
    TGECEVENT_SETOFF,                 ///< [set-off] set off car (=12)
    TGECEVENT_PARK,                   ///< [park] car parked(=13)
    TGECEVENT_SPEED_UP,             ///< [speed-up] speed burstly up(=14)
    TGECEVENT_SPEED_DOWN,           ///< [speed-down] speed burstly down(=15)
    TGECEVENT_DR_END = TGECEVENT_SPEED_DOWN, ///< 行车记录仪事件范围结束(=15)

    TGECEVENT_CALL,                 ///< [call] (=16)
    TGECEVENT_DOORBELL = TGECEVENT_CALL, ///< 保留旧的命名 = ECEVENT_CALL
    TGECEVENT_PASSBY,                ///< [passby] 有人路过(=17)
    TGECEVENT_STAY,                  ///< [stay] 有人停留(=18)

    //TGECEVENT_OBJECT,                ///< object recognization
    //TGECEVENT_CAR = TGECEVENT_OBJECT,                   ///<

    TGECEVENT_LOCK,                 ///< [lock] 门锁消息(大类)(=19). 细分消息在data部分

    TGECEVENT_CRY,                  ///< [cry] 检测到哭声(=20)
    TGECEVENT_ENTER,                ///< [enter] 进入区域(=21)
    //参数: MKEVTDAT_SitPoseSens()。这个在sdk内部处理
    TGECEVENT_SITPOSE,              ///< [bad_posture] sitting pose. 坐姿检测.(=22)

    TGECEVENT_LEAVE,                ///< [leave] 离开区域 "leave". 由sdk生成?(=23)
    TGECEVENT_TUMBLE,               ///< [tumble] 摔倒(=24)

    TGECEVENT_SNAPSHOT,             ///< [snapshot] 手动抓拍(=25)
    TGECEVENT_CALL2,                ///< [call.2]呼叫按键2(=26)

    TGECEVENT_MAX,
    TGECEVENT_USER_DEFINED = 255    ///< 自定义事件。使用方式见文档
} TGECEVENT;

/** Doorbell call state */
//typedef enum ECALLSTATE {
//    CALLSTATE_MISSED,      ///< 未接. sdk内部定时
//    CALLSTATE_ANSWERED,    ///< 已接。@ref TCI_CMD_ANSWERTOCALL
//    CALLSTATE_REJECTED,    ///< 拒接。@ref TCI_CMD_ANSWERTOCALL
//
//    CALLSTATE_CANCELLED,    ///< 设备端取消呼叫(上报 TGECEVENT_DOORBELL 事件 status=0)
//
//    CALLSTATE_HANGUP       ///< 用户结束通话挂断接听. 仅通知用户
//} ECALLSTATE;

/** 云服务类型 */
typedef enum ECSERVICETYPE {
    ECGS_TYPE_STORAGE = 1, ///< 云存储服务
    ECGS_TYPE_AI = 2       ///< AI服务
} ECSERVICETYPE;

/** 4G状态 */
typedef enum ECG4STATE {
    G4STATE_IDLE,     ///< communicate by lan
    G4STATE_WORKING,  ///< communicate by 4g
    G4STATE_FAILURE   ///< 4g module has failure
} ECG4STATE;

/** 云上传缓冲区使用提示.
 * 使用buffer时，上传数据在buffer里。如果设了后备存储，上传失败时写到后备存储空间, 然后择机重传。
 * 使用buffer也可以减小写后备空间的频次。\n
 * 没有后备空间时，必须使用buffer。大的buffer容许更大的传输延迟。buffer满时就会开始丢弃数据。\n
 * 有后备时，可以选择小缓冲或无缓冲.
 */
typedef enum ECBUFFERHINT {
    BUFFERHINT_DEFAULT,   ///< 默认。双倍buffer。
    BUFFERHINT_SMALL,     ///< 单 buffer. 占用较小内存. 
    BUFFERHINT_SMALLEST   ///< 无缓冲. 数据先写卡再从卡上上传, 仅适合报警录像
} ECBUFFERHINT;

/**@}*/ //group: api_const

/** \ingroup api_structure*/
/** @name 特定事件相关参数
 * @{
 * @ref EVENTPARAM::evt_data */
#define EVTDATA_SERIOUS_COLLISION    (void*)1  ///< 仅针对 TGECEVENT_COLLISION 事件, 严重碰撞
/**@}*/

/** 事件上报参数 */
typedef struct EVENTPARAM {
    int cbSize;             ///< 本结构大小, =sizeof(EVENTPARAM)。调用者要设置此成员。用于以后结构变化

    unsigned char event;    ///< 事件类型. 参数(evt_data)见事件的说明
    long int tHappen;       ///< 事件发生时间
    int status;             ///< 1:事件开始; 0:事件结束(暂不支持)

    const char *jpg_pic;    ///< 图片指针。没有图片时为NULL
    unsigned int pic_len;   ///< 图片长度

#define EPF_RELEASE_PIC_IN_SDK         0x01
#define EPF_ONLY_AIEVENT_IF_SVCFORAI   0x02  // used internally by sdk
    int pass_ownership;     ///< 1:jpg_pic由sdk内部释放; 0:应用层自己管理jpg_pic空间

    /** 特定事件相关参数.
     *  其值是个预定义常数或cJSON字符串. 
     *  json字符串可以使用 MKEVTDATA_xxxx 辅助函数来生成。
     *  默认要设置为NULL */
    void *evt_data;

    void *pic_extra;        ///< 图片的额外参数. 目前用于ai
} EVENTPARAM;

/**@}*/


/* Error code */
#define ECP_E_OK                0      ///< No error
//300~599                       error code defined in http protocol

/** @name 本地错误
 * @{*/
#define ECP_E_COMMUNICATION     10000  ///< error in network communication
#define ECP_E_NOT_INITIALIZED   10001  ///< McFetchNewOssToken is not called
#define ECP_E_INVALID_PARAMETER 10002  ///< Invalid parameter
#define ECP_E_OUT_OF_MEMORY     10003  ///< Out of memory
#define ECP_E_UNEXPECTED_RESPONSE    10004  ///< unexpected response
#define ECP_E_TOO_FREQUENT      10005  ///< Too frequent calls
#define ECP_E_NOTALLOWED        10006  ///< Not Allowed
/**@}*/

/** @name 服务器端错误码
 * @{
 */
#define ECP_E_OHTER             20000  ///< Other errors
#define ECP_E_USERID_NOT_FOUND  20001  ///< userid 未找到
#define ECP_E_UUID_NOT_FOUND    20002  ///< uuid 不存在
#define ECP_E_UUID_ALREADY_ACTIVATED 20003
#define ECP_E_UUID_NOT_ACTIVATED 20004
#define ECP_E_UUID_IS_UNBOUND   20005
#define ECP_E_CANNOT_GET_TOKEN  20006

#define ECP_E_OSS_TIMESKEWED    20007
#define ECP_E_OSS_INVALIDACCESSKEY 20008
#define ECP_E_OSS_ACCESSDENIED  20009
/**@}*/

#endif

