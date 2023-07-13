Use of decoder
===============

## 编译

解码默认输出yuv420格式(I420Pic).

如果想要输得到 RGB数据，在 jifcd.h 中放开 

```c
//#define OUTPUTBMP
```

这一行注释。输出为 BMP 结构(还没验证).



## 类型定义

实时视频帧头(现有定义，不需要修改)

```c
typedef struct FRAMEINFO_t
{
    unsigned short codec_id;    ///< 非0. Media codec type defined in @ref ENUM_CODECID

    /** For video frame, is of ENUM_FRAMEFLAG. 
     * for Audio Frame: flags =  (samplerate << 2) | (databits << 1) | (channel)
     * @ref audio_sample_fmt "音频采样格式" */
    unsigned char flags;

    unsigned char cam_index;    ///< 0 (>0 may be used in future)

    unsigned char rt_flags;     ///< bit0: 是否在录像
    unsigned char seq_no[3];    ///< 1~0xffffff. sequency number for frame, used internally by sdk to detect frame loss.

    unsigned int frame_size;    ///< Size of frame
    unsigned int timestamp;     ///< Timestamp of the frame, in milliseconds
} FRAMEINFO_t;
```

### 实时帧头 codec_id 类型

(tgp2p_av.h)

```c
    MEDIA_CODEC_VIDEO_IJPG      = 0x0A,   ///< Private inter-frame jpeg codec
```

### 云存储文件中用到的媒体类型

(ec_const.h)

```c
    TCMEDIA_VIDEO_IJPG    = 10,     ///< Private Inter-frame jpeg codec
```

## 代码示例

```c
//包含头文件
#include "jifcd.h"

//1. Create decoder context
JifCtx *ctx = JifCtxCreate(0);

while(1) {
//   帧头结构
    FRAMEINFO_t fi;
//2. Receive frame from network
    ...

//3. Decode
    if(fi.codec_id == MEDIA_CODEC_VIDEO_IJPG) {
    	I420Pic out_pic;
    	interf_decompress(ctx, fi.flags&1, frame_buff, fi.frame_size, &out_pic);

		//4. 显示yuv.  信息在out_pic，数据由sdk内部分配，不用释放
    }
}

//5. Clean
JifCtxDestroy(ctx);
```
