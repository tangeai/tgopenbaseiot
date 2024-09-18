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

- (void)videoSessionManagerDidRecordWithData:(char *)data length:(unsigned int)length frameId:(uint32_t)frameId config:(TGVideoConfigModel *)config frameFlag:(ENUM_FRAMEFLAG)flag;

@end

@interface TGVideoCamera : NSObject

@property (nonatomic, weak) id <TGVideoCameraDelegate>delegate;

//采集参数设置
- (int)doCapturePrepare:(TGVideoConfigModel *)config;

// 开始采样
- (void)start:(TGVideoConfigModel *)config;
// 结束采样
- (void)stop;
// 切换摄像头
- (void)switchCamera;

- (BOOL)setupAssetWriterWithURL:(NSURL *)url;
- (void)startRecording;
- (void)stopRecording;

@end

NS_ASSUME_NONNULL_END
