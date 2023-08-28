//
//  DACameraP2PVideoData.h
//  DAAudioVideo
//
//  Created by Darren on 2020/6/2.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DACameraP2PVideoData : NSObject

@property (nonatomic, assign) unsigned int frameId;
@property (nonatomic, assign) unsigned int flags;      //表示是否是I帧
@property (nonatomic, assign) unsigned int exFlags;
@property (nonatomic, assign) DAVideoFrameType type;
@property (nonatomic, assign) DAMediaCodeID codecId;
@property (nonatomic, assign) unsigned int timeStamp;   //用于视频播放时休眠
@property (nonatomic, assign) NSInteger timeInterval;   //用于视频播放时UI上展示当前的播放时间点
@property (nonatomic, assign) NSInteger dataInterval;   //用于云回放标记该帧在哪一个5秒的文件中
@property (nonatomic, assign) NSInteger utcTimeStamp;
@property (nonatomic, assign) unsigned int dataLength;
@property (nonatomic, assign) unsigned int channel;
@property (nonatomic, assign, nullable) unsigned char *buffer;
@property (nonatomic, assign, nullable) CMSampleBufferRef sampleBuffer;
@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic, assign) NSInteger sessionId;

- (BOOL)isHardwareDecoderSupport;

@end

NS_ASSUME_NONNULL_END
