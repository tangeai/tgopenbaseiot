#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#ifdef JICDW_EXPORTS
#define JICD_API __declspec(dllexport)
#else
#define JICD_API __declspec(dllimport)
#endif
#else
#define JICD_API
#endif



struct JifCtx;
typedef struct JifCtx JifCtx;


typedef struct jicEncOut {
    int      isKey;
    unsigned char *data;
    int len;
} jicEncOut;

JICD_API JifCtx *JifCtxCreate(int encode);
JICD_API void JifCtxDestroy(JifCtx *ctx);
JICD_API int interf_compress(JifCtx *ctx, const unsigned char* pic, int len, int keyFlag, jicEncOut* out);
JICD_API void interf_set_lossless(int lossless);


typedef
struct YuvPic {
    int width, height;
    int buff_size; //pointed by pY
    int fmt;  //0:i420; 1:yuv422 planar
    unsigned int uYStride, uUVStride;
    unsigned char* pY, * pU, * pV;
} YuvPic;


//#define OUTPUTBMP
#ifdef OUTPUTBMP
#include "bmppic.h"
#define OUTPIC BmpPic
JICD_API void BMPWriteFile(OUTPIC* bmp, const char* filename);
#else
#define OUTPIC YuvPic
#endif

JICD_API int interf_decompress(JifCtx* ctx, int type, const unsigned char* pic, int len, OUTPIC* pPic);

//void YuvToJpg(const YuvPic *pic, int quality, struct jpeg_dest *dst);
JICD_API int YuvToJpgM(const YuvPic *pic, int quality, /*out*/unsigned char **mem);
#include <stdio.h>
JICD_API void YuvToJpgF(const YuvPic *pic, int quality, FILE *fp);

#ifdef __cplusplus
} /* extern "C" */
#endif
