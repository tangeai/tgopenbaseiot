#ifdef SWIG
%module Relayer
#endif

#pragma once

#include "ec_const.h"

#ifdef __cplusplus
extern "C" {
#endif

/*包头的 sequence number 和头u尾标志位 */
#define FIRSTFRAG_BIT 0x80000000
#define LASTFRAG_BIT  0x40000000
#define SEQNO(u32) (u32&0x3fffffff) //low 32 bits


/*For device*/
int rcInit();
void rcRun();

struct rconn;
typedef struct rconn RCONN;

struct rconn_pkt {
    int chn;
    unsigned char *pdata;
    int len, has_seq;
    unsigned int flag_seq; // low 30 bits
};

//应用层命令请求和应答
struct rconn_cmd_pkt {
    uint16_t cmd;
    uint16_t reqno;
    int is_resp;

    uint8_t *data; //command requesst or response
    int data_len;
};
void RcParseCmdPkt(const struct rconn_pkt *pkt, struct rconn_cmd_pkt *cmd_pkt);

/** callbak prototype.
 * \param code error/event code defined as following(ECONN_E_xxx, ECONN_EVT_xxx)
 * \param data  Interpreted by code. when code==0, a pointer to struct rconn_pkt.
 * \param arg  user's pointer
 */
typedef void (*RCONNCALLBACK)(RCONN *conn, int code, void *data, void *arg);

#define RCONN_EVT_CONNECTED              2
#define RCONN_EVT_GET_AUTHINFO           1    //data: AuthWithServer *

#define RCONN_E_OK                       0    //data: struct rconn_pkt *
/* As status(absolute value) return from server */
#define RCONN_E_NOT_ONLINE              -1
#define RCONN_E_INVALID_UUID            -2
#define RCONN_E_ACCESS_DENIED           -3
/* local error */
#define RCONN_E_FAILED_CONNECT_SERVER   -4
#define RCONN_E_INVALID_PARAM           -5
#define RCONN_E_BROKEN_CONNECTION       -6
#define RCONN_E_PEER_CLOSED             -7
#define RCONN_E_INVALID_HANDLE          -8
#define RCONN_E_TIMEOUTED               -9
#define RCONN_E_UNEXPECTED_DATA         -10
#define RCONN_E_NETWORK_BLOCKED         -11 //发送超时

#define RCONN_E_SYSTEM_ERROR            -98
#define RCONN_E_CANCELED                -99  //used internally


typedef enum { ROLE_DEV, ROLE_APP } RCROLE;
/** connect. 用于设备端
 * \param hosts IP strings of relayers
 * \param buf_size 最大数据包长度
 * \param cb callback to receive events and data
 * \param arg Caller's pointer
 * \retval >=0 Meaning connection is on-going
 * \retval -1  error
 */
int RconnConnect(const char *hosts[], int size, RCROLE role, int buf_siz, RCONNCALLBACK cb, void *arg);

void RconnSetUserPtr(RCONN *rconn, void *pUser);
void *RconnGetUserPtr(RCONN *rconn);

/** 发送一个完整数据包.
 * \param rconn 从回调中收到
 * \param chn 通道号 1~255
 * \param v 指向 iovec 数组
 * \param size 数组 v 大小
 * \return
 */
int RconnSendV(RCONN *rconn, uint8_t chn, const struct iovec *v, int size);

/** 发送一个完整数据包.
 * \param rconn 从回调中收到
 * \param chn 通道号 1~255
 * \param data
 * \param len
 * \return
 */
int RconnSend(RCONN *rconn, uint8_t chn, const void *data, int len);

typedef struct FRAMEHEADER
{
    unsigned short mt;           ///< 非0. Media type defined in @ref TCMEDIA
#define KEYFRAME_BIT  0x01
    unsigned char flags;         ///< 
    unsigned char cam_index;     ///< 0 (>0 may be used in future)

    unsigned int timestamp;        ///< Timestamp of the frame, in milliseconds
} FRAMEHEADER;

struct rconn_frame_pkt {
    FRAMEHEADER hdr;
    uint8_t *frame;
    int     frame_len;
};
void RcParseFramePkt(const struct rconn_pkt *pkt, struct rconn_frame_pkt *frm_pkt);

/** Send frame to APP.
 */
int RconnSendFrame(RCONN *rc, uint8_t chn, TCMEDIA mt, uint32_t ts, int flag, const void *frame, int length);

/** @def MK_CMDHDR(cmd, reqno, is_resp)
 * \param cmd
 * \param seqno
 * \param is_resp
 */
#define MK_CMDHDR(cmd, reqno, is_resp) htonl((((uint32_t)(cmd))<<16)|((reqno)<<1)|((is_resp)?1:0))

/** _MK_CMDHDR(cmd, reqno, is_resp)
 * \param cmd
 * \param seqno
 * \param is_resp
 */
uint32_t _MK_CMDHDR(uint16_t cmd, uint16_t reqno, int is_resp);

/** 发送命令/应答到对端(设备或APP)
 * \param chn command channel: 1~255
 * \param cmdhdr make by MK_CMDHDR
 */
int RconnSendCmd(RCONN *rc, int chn, unsigned int cmdhdr, const void *data,  int len);

/* 客户端最先调用 */
int RcltStart();

/* 客户端 */
int RcltConnect(const char *hosts[], int size, const char *uuid, const char *token, int buf_siz, RCONNCALLBACK cb, void *arg, RCONN **ppRconn);

/* 客户端 */
int RcltClose(RCONN *rc);

#ifdef __cplusplus
} /* extern "C" */
#endif
