//
//  TGCloudVideoCommonTool.h
//  TGBaseIOT
//
//  Created by liubin on 2023/10/9.
//

#import <Foundation/Foundation.h>
#import <DAAudioVideo/DAAudioVideo.h>
#import "TGCameraDeviceModel.h"
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGCloudVideoCommonTool : NSObject

//云回放
+ (DACameraP2PVideoData *)videoDataWithFrameHeader:(McFrameHeader *)frameHeader data:(unsigned char *)data dataLength:(unsigned int)dataLength;
+ (DACameraP2PAudioData *)audioDataWithFrameHeader:(McFrameHeader *)frameHeader data:(unsigned char *)data dataLength:(unsigned int)dataLength;

- (int)decoderVideo:(DACameraP2PVideoData *)video device:(TGCameraDeviceModel *)device keyFrame:(BOOL)keyFrame;
- (void)cleanDecoder;

@end

NS_ASSUME_NONNULL_END
