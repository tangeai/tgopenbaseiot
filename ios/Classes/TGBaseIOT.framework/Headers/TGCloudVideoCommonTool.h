//
//  TGCloudVideoCommonTool.h
//  TGBaseIOT
//
//  Created by liubin on 2023/10/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <DAAudioVideo/DAAudioVideo.h>
#import "TGCameraDeviceModel.h"
#import "TGIOTCameraDevice.h"
#import "TGCameraDefine.h"
#import "jifcd.h"


NS_ASSUME_NONNULL_BEGIN

@interface TGCloudVideoCommonTool : NSObject

//云回放
+ (DACameraP2PVideoData *)videoDataWithFrameHeader:(McFrameHeader *)frameHeader data:(unsigned char *)data dataLength:(unsigned int)dataLength;
+ (DACameraP2PAudioData *)audioDataWithFrameHeader:(McFrameHeader *)frameHeader data:(unsigned char *)data dataLength:(unsigned int)dataLength;

+ (int)decoderVideo:(DACameraP2PVideoData *)video device:(TGCameraDeviceModel *)device keyFrame:(BOOL)keyFrame hardwareDecoderEnable:(BOOL *)hardwareDecoderEnable hardwareVideoDecoder:(DAVideoHardwareDecoder *_Nullable*_Nullable)hardwareVideoDecoder softwareVideoDecoder:(DAVideoSoftwareDecoder *_Nullable*_Nullable)softwareVideoDecoder ctxd:(JifCtx *_Nullable*_Nullable)ctxd;

+ (BOOL)rotateVideoImageWithVideo:(DACameraP2PVideoData *)video degress:(CGFloat)degress;

@end

NS_ASSUME_NONNULL_END
