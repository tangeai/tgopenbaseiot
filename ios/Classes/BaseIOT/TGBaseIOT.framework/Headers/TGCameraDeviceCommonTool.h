//
//  TGCameraDeviceCommonTool.h
//  TGBaseIOT
//
//  Created by liubin on 2022/11/3.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "relayer.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import "TGCameraDeviceModel.h"
#import "TGIOTCameraDevice.h"
#import "PPCS_Type.h"
#import "PPCS_API.h"
#import "TGCameraDefine.h"
#import "jifcd.h"

NS_ASSUME_NONNULL_BEGIN

@class TGCameraDeviceCommonTool;

@protocol TGCameraDeviceCommonToolDelegate <NSObject>

- (BOOL)audioTool:(TGCameraDeviceCommonTool *)tool audioPlayWithBytes:(UInt32)dataBytes callBack:(void(^)(UInt32 dataByteSize, unsigned char *data))callBack;

@end

@interface TGCameraDeviceCommonTool : NSObject
//P2P
+ (DACameraP2PVideoData *)liveVideoDataWithFrameInfo:(FRAMEINFO_t)frameInfo buffer:(CHAR *)buffer;
+ (DACameraP2PVideoData *)sdcardVideoDataWithFrameInfo:(FRAMEINFO_t)frameInfo buffer:(CHAR *)buffer;
+ (DACameraP2PAudioData *)audioDataWithFrameInfo:(FRAMEINFO_t)frameInfo buffer:(CHAR *)buffer;

//Relay
+ (DACameraP2PVideoData *)videoDataWithFramePacket:(struct rconn_frame_pkt)frmpkt;
+ (DACameraP2PAudioData *)audioDataWithFramePacket:(struct rconn_frame_pkt)frmpkt;

+ (DACameraP2PVideoData *)videoDataWithFrameId:(unsigned int)frameId flags:(unsigned int)flags channel:(unsigned int)channel codeId:(DAMediaCodeID)codeId timeStamp:(unsigned int)timeStamp data:(unsigned char *)data dataLength:(unsigned int)dataLength;
+ (DACameraP2PAudioData *)audioDataWithFrameId:(unsigned int)frameId flags:(unsigned int)flags codeId:(DAMediaCodeID)codeId timeStamp:(unsigned int)timeStamp data:(unsigned char *)data dataLength:(unsigned int)dataLength;

//云回放
+ (DACameraP2PVideoData *)videoDataWithFrameHeader:(McFrameHeader *)frameHeader data:(unsigned char *)data dataLength:(unsigned int)dataLength;
+ (DACameraP2PAudioData *)audioDataWithFrameHeader:(McFrameHeader *)frameHeader data:(unsigned char *)data dataLength:(unsigned int)dataLength;

- (int)decoderVideo:(DACameraP2PVideoData *)video device:(TGCameraDeviceModel *)device keyFrame:(BOOL)keyFrame;
- (void)cleanDecoder;

@property (nonatomic, weak) id <TGCameraDeviceCommonToolDelegate>delegate;

+ (DAAudioConfigModel *)modelWithFlags:(unsigned char)flags;
+ (instancetype)audioToolWithConfig:(DAAudioConfigModel *)config;
- (void)decodeAudioWithAudioData:(DACameraP2PAudioData *)audio callBack:(void(^)(DACameraP2PAudioData *decodeAudio))callBack;
- (BOOL)startPlayAudio;
- (void)stopPlayAudio;
- (BOOL)isAudioPlaying;

@end

NS_ASSUME_NONNULL_END
