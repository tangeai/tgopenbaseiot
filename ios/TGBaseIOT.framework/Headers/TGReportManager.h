//
//  TGReportManager.h
//  TGBaseIOT
//
//  Created by Darren on 2023/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define TG_Params_Key_Event                 @"event"
#define TG_Params_Key_EventEnd              @"event_end"
#define TG_Params_Key_EventStart            @"event_start"
#define TG_Params_Key_EventTime             @"event_time"
#define TG_Params_Key_EventTimeUsed         @"event_time_used"
#define TG_Params_Key_SocketId              @"socket_id"
#define TG_Params_Key_Status                @"status"
#define TG_Params_Key_Detail                @"detail"
#define TG_Params_Key_ConnectType           @"connect_type"
#define TG_Params_Key_Uuid                  @"uuid"

#define TG_Params_Value_Connect             @"connect"
#define TG_Params_Value_DisConnect          @"disconnect"

#define TG_Params_ConnectType_P2P           @"p2p"
#define TG_Params_ConnectType_WebRTC        @"webrtc"

#define TG_Event_Type_SocketConnect         @"socket_connect"
#define TG_Event_Type_SocketDisConnect      @"socket_disconnect"
#define TG_Event_Type_P2PConnect            @"p2p_connect"
#define TG_Event_Type_WebRTCSwitchP2P       @"switch_webrtc_ppcs"
#define TG_Event_Type_P2PLive               @"p2p_live"
#define TG_Event_Type_P2PSendPwd            @"p2p_send_pwd"
#define TG_Event_Type_FirstFrame            @"first_avframe"
#define TG_Event_Type_P2PVideo              @"p2p_video"
#define TG_Event_Type_P2PError              @"p2p_error"


@interface TGReportManager : NSObject

+ (void)reportWithParams:(NSDictionary *)params;
+ (void)reportWithParams:(NSDictionary *)params startDate:(NSDate *)startDate endDate:(NSDate *)endDate;

@end

NS_ASSUME_NONNULL_END
