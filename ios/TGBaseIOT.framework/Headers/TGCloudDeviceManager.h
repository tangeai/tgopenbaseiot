//
//  TGCloudDeviceManager.h
//  TGIOT
//
//  Created by Darren on 2020/11/23.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGCloudDownloadModel.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import <TGBaseIOT/TGCameraDeviceModel.h>
//#import <TGCommonBaseModule/TGCommonBaseDefineHeader.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TGCloudRecordOrderType) {
    TGCloudRecordOrderType_Desc,    //降序
    TGCloudRecordOrderType_Asce     //升序
};

typedef NS_ENUM(NSInteger, TGCloudManagerErrorType) {
    TGCloudManagerErrorType_Ok,
    TGCloudManagerErrorType_NoFile,
    TGCloudManagerErrorType_NetworkError
};

@protocol TGCloudDeviceManagerDelegate <NSObject>

@optional
- (void)cloudDeviceManagerDidPlayDecoderVideoData:(DACameraP2PVideoData *)videoData;
- (void)cloudDeviceManagerDidDoorbellMsgRecordWithFilePath:(NSString *)filePath;
- (void)cloudDeviceManagerDidRecordVideoWithDuration:(NSInteger)duration;

@end

@interface TGCloudDeviceManager : NSObject

@property (nonatomic, strong) TGCameraDeviceModel *device;
@property (nonatomic, weak) id <TGCloudDeviceManagerDelegate>delegate;
@property (nonatomic, assign) TGCameraPlaySpeedLevel level;
@property (nonatomic, copy) void(^successDownloadCallback)(NSInteger timeInterval);
@property (nonatomic, copy) void(^failedDownloadCallback)(NSInteger timeInterval);
@property (nonatomic, copy) void(^stopRecordCallback)(NSString *filePath);

- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;

- (void)getDeviceCloudRecordWithDateString:(NSString *)dateString order:(TGCloudRecordOrderType)order successBlock:(void(^)(NSArray *normalArray,NSArray *eventArray))successBlock failureBlock:(void(^)(id error))failureBlock;

- (void)startPlayWithTimeInterval:(NSTimeInterval)timeInterval;

- (void)downloadAndPlayCloudFileWithModel:(TGCloudDownloadModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack;

- (void)stopDownload;

- (void)stopPlay;
- (void)muteAudio;
- (void)cancleMute;

- (void)startRecordWithFileName:(NSString *)fileName recordType:(TGVideoRecordType)recordType;
- (void)stopRecord;

@end

NS_ASSUME_NONNULL_END
