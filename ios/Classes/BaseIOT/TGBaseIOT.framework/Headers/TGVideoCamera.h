//
//  TGVideoCamera.h
//  TGBaseIOT
//
//  Created by liubin on 2023/10/1.
//

#import <Foundation/Foundation.h>
#import "TGVideoConfigModel.h"
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TGVideoCameraDelegate <NSObject>

- (void)videoSessionManagerDidRecordWithData:(void *)data length:(unsigned int)length config:(TGVideoConfigModel *)config frameFlag:(ENUM_FRAMEFLAG)flag;

@end

@interface TGVideoCamera : NSObject

@property (nonatomic, weak) id <TGVideoCameraDelegate>delegate;
//+ (instancetype)shareVideoCamera;

//采集参数设置
-(int)doCapturePrepare:(TGVideoConfigModel *)config;

// 开始采样
- (void)start:(TGVideoConfigModel *)config;
// 结束采样
- (void)stop;
// 切换摄像头
- (void)switchCamera;

+ (BOOL)tg_isHardwareDecodeSupportedH265 ;


- (void)setupVideoRecordingWithPath:(NSString *)path;
- (void)startRecording;
- (void)stopRecording;
- (void)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end

NS_ASSUME_NONNULL_END
