//
//  TGOSSCloudFileManager.h
//  TGBaseIOT
//
//  Created by Darren on 2020/11/23.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGOSSVideoRecordModel.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import <TGBaseIOT/TGCameraDeviceModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TGOSSPlayVideoInfoModel,TGOSSDownloadInfoModel,TGDownloadChannelModel;

@protocol TGOSSCloudFileManagerDelegate <NSObject>

@optional
// 播放视频代理方法
- (void)ossCloudFileManagerDidPlayDecoderVideoData:(DACameraP2PVideoData *)videoData;
// 录像进度代理方法
- (void)ossCloudFileManagerDidRecordVideoWithDuration:(NSInteger)duration;
// 下载录像代理方法
- (void)ossCloudFileManagerDidDownloadDoneWithFilePath:(NSString *)filePath channelModel:(TGDownloadChannelModel *)channelModel;

@end

@interface TGOSSCloudFileManager : NSObject

@property (nonatomic, strong) TGCameraDeviceModel *device;
// 设置倍速播放
@property (nonatomic, assign) TGCameraPlaySpeedLevel level;
// 设置主画面
@property (nonatomic, assign) TGPlayChannelType primaryChannel;

@property (nonatomic, weak) id <TGOSSCloudFileManagerDelegate>delegate;
// 下载成功回调
@property (nonatomic, copy) void(^successDownloadCallback)(NSInteger timeStamp);
// 下载失败回调
@property (nonatomic, copy) void(^failedDownloadCallback)(NSInteger timeStamp);
// 停止录像回调
@property (nonatomic, copy) void(^stopRecordCallback)(NSString *filePath);

- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;

// 开始播放
- (void)startPlayCloudVideoWithModel:(TGOSSPlayVideoInfoModel *)model callBack:(void(^)(BOOL success, id _Nullable errorInfo))callBack;
// 暂停播放
- (void)pausePlay;
// 恢复播放
- (void)resumePlay;
// 停止播放
- (void)stopPlay;

// 静音
- (void)muteAudio;
// 取消静音
- (void)cancleMute;

// 开始录像
- (void)startRecordWithModel:(TGOSSVideoRecordModel *)recordModel;
// 停止录像
- (void)stopRecord;


// 下载云文件
- (void)downloadCloudVideoWithModel:(TGOSSDownloadInfoModel *)model callBack:(void(^)(BOOL success, id _Nullable errorInfo))callBack;
// 停止下载
- (void)stopDownload;

@end

NS_ASSUME_NONNULL_END
