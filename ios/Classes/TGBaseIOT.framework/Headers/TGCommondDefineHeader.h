//
//  TGCommondDefineHeader.h
//  Pods
//
//  Created by liubin on 2024/1/2.
//

#ifndef TGCommondDefineHeader_h
#define TGCommondDefineHeader_h

typedef NS_ENUM(NSInteger, TGCommondRespType) {
    TGCommonRespType,
    TGSpecificRespType
};

typedef NS_ENUM(NSInteger, TGVIDEOFLIPMODE) {
    TCIC_VIDEOMODE_NORMAL,  //正常
    TCIC_VIDEOMODE_FLIP,    //上下翻转
    TCIC_VIDEOMODE_MIRROR,  //左右镜像
    TCIC_VIDEOMODE_FLIP_MIRROR //旋转180度
};

typedef NS_ENUM(int, TGVideoWhiteLightModel) {
    TCIC_VideoWhitLightMode_Close    =  0,  //  关闭（白光不工作）
    TCIC_VideoWhitLightMode_Open     =  1,   //  打开（全彩色）
    TCIC_VideoWhitLightMode_AI       =  2,     //  智能模式（移动侦测触发自动白光）
    TCIC_VideoWhitLightMode_Timer    = 3//  定时开关(DoubleLight 能力要有 "Timer" 属性)
};

typedef void(^commondDataResqSuccessBlock)(char * commondDataResq,TGCommondRespType ctrolType,int controlCMD);
typedef void(^commonDataRespErrorBlock)(SMsgBaseResp *ErrorResp);


#endif /* TGCommondDefineHeader_h */
