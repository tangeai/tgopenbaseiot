//
//  TGVideoConfigModel.h
//  TGBaseIOT
//
//  Created by liubin on 2023/10/6.
//

#import <Foundation/Foundation.h>
#import <DAAudioVideo/DAAudioVideo.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGVideoConfigModel : NSObject

@property (nonatomic, assign) int channel;      //通道数
@property (nonatomic, assign) int32_t width;    //采集宽
@property (nonatomic, assign) int32_t height;   //采集高
@property (nonatomic, assign) int32_t fps;      //帧率
@property (nonatomic, assign) int32_t bitrate;  //码率
@property (nonatomic, assign) int32_t keyFrameIntervalSec; // 关键帧间隔
@property (nonatomic, assign) DAMediaCodeID codecId;  // 编码格式
@property (nonatomic, strong) UIView *cameraView;     // 绑定预览画面view
@property (nonatomic, assign) BOOL frontOrBack; //yes 为前置摄像头 no为后置，默认前置

@end

NS_ASSUME_NONNULL_END
