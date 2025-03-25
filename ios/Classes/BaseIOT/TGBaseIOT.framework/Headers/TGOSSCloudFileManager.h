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

- (void)startPlayCloudVideoWithModel:(TGOSSDownloadInfoModel *)model callBack:(void(^)(BOOL success, id _Nullable errorInfo))callBack;
- (void)stopPlay;

- (void)startRecordWithModel:(TGOSSVideoRecordModel *)recordModel;
- (void)stopRecord;

- (void)muteAudio;
- (void)cancleMute;

@end

NS_ASSUME_NONNULL_END
