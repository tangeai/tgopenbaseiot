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

@property (nonatomic, assign) NSInteger channel;                    // 通道数
@property (nonatomic, assign) NSInteger width;                      // 采集宽
@property (nonatomic, assign) NSInteger height;                     // 采集高
@property (nonatomic, assign) NSInteger fps;                        // 帧率，默认15
@property (nonatomic, assign) BOOL frontCamera;                     // YES 为前置摄像头 NO为后置，默认前置
@property (nonatomic, strong) UIView *cameraView;                   // 绑定预览画面view
@property (nonatomic, assign) DAMediaCodeID codecId;                // 编码格式

@property (nonatomic, assign) BOOL needRescale;                     // 是否需要拉升
@property (nonatomic, assign) NSInteger rotate;                     // 旋转度数（用于DAMediaCodeID_Video_JPEG模式下，可控制输出图像旋转度数）

@property (nonatomic, assign) NSInteger gopSize;                    // 关键帧间隔 非jpeg
@property (nonatomic, assign) NSInteger bitrate;                    // 码率 非jpeg（单位bps）
@property (nonatomic, assign) CGFloat imageCompress;                // 图片压缩比，适用于DAMediaCodeID_Video_JPEG 模式下，取值0.0-1.0（从低到高）

@end

NS_ASSUME_NONNULL_END
