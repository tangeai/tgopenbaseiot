//
//  TGOSSCloudFileManager.h
//  TGIOT
//
//  Created by Darren on 2020/11/23.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGOSSVideoRecordModel.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import <TGBaseIOT/TGCameraDeviceModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TGOSSDownloadInfoModel;

@protocol TGOSSCloudFileManagerDelegate <NSObject>

@optional
- (void)ossCloudFileManagerDidPlayDecoderVideoData:(DACameraP2PVideoData *)videoData;
- (void)ossCloudFileManagerDidRecordVideoWithDuration:(NSInteger)duration;

@end

@interface TGOSSCloudFileManager : NSObject

@property (nonatomic, strong) TGCameraDeviceModel *device;
@property (nonatomic, assign) TGCameraPlaySpeedLevel level;
@property (nonatomic, assign) TGPlayChannelType primaryChannel;

@property (nonatomic, weak) id <TGOSSCloudFileManagerDelegate>delegate;

@property (nonatomic, copy) void(^successDownloadCallback)(NSInteger timeStamp);
@property (nonatomic, copy) void(^failedDownloadCallback)(NSInteger timeStamp);
@property (nonatomic, copy) void(^stopRecordCallback)(NSString *filePath);

- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;

// 开始播放
- (void)startPlayCloudVideoWithModel:(TGOSSDownloadInfoModel *)model callBack:(void(^)(BOOL success, id _Nullable errorInfo))callBack;
// 暂停播放
- (void)pausePlay;
// 恢复播放
- (void)resumePlay;
// 停止播放
- (void)stopPlay;

// 开始录像
- (void)startRecordWithModel:(TGOSSVideoRecordModel *)recordModel;
// 停止录像
- (void)stopRecord;

- (void)muteAudio;
- (void)cancleMute;

@end

NS_ASSUME_NONNULL_END
