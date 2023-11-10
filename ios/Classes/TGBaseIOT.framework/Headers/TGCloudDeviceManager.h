//
//  TGCloudDeviceManager.h
//  TGIOT
//
//  Created by Darren on 2020/11/23.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGCloudDownloadModel.h"
#import "TGCloudEventModel.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import <TGBaseIOT/TGCameraDeviceModel.h>

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

// 播放回调
- (void)cloudDeviceManagerDidPlayDecoderVideoData:(DACameraP2PVideoData *)videoData;
// 返回门铃录制存储地址
- (void)cloudDeviceManagerDidDoorbellMsgRecordWithFilePath:(NSString *)filePath;
// 返回下载地址
- (void)cloudDeviceManagerDownloadFilePath:(NSString *)filePath;
// 录制时长
- (void)cloudDeviceManagerDidRecordVideoWithDuration:(NSInteger)duration;

@end

@interface TGCloudDeviceManager : NSObject

@property (nonatomic, strong) TGCameraDeviceModel *device;
@property (nonatomic, weak) id <TGCloudDeviceManagerDelegate>delegate;
@property (nonatomic, assign) TGCameraPlaySpeedLevel level;                             // 倍速播放 云录像1、2、4、8倍
@property (nonatomic, copy) void(^successDownloadCallback)(NSInteger timeInterval);     // 下载成功
@property (nonatomic, copy) void(^failedDownloadCallback)(NSInteger timeInterval);      // 下载失败回调
@property (nonatomic, copy) void(^stopRecordCallback)(NSString *filePath);              // 录制地址回调

- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;

// 查询某一天的云录像列表，不区分全时还是事件视频类型 (推荐使用)
- (void)getNoTagDeviceCloudRecordWithDateString:(NSString *)dateString successBlock:(void(^)(NSArray *allArray))successBlock failureBlock:(void(^)(id error))failureBlock;

// 返回云录像列表（逐渐废弃）
- (void)getDeviceCloudRecordWithDateString:(NSString *)dateString successBlock:(void(^)(NSArray *normalArray,NSArray *eventArray))successBlock failureBlock:(void(^)(id error))failureBlock;

// 开始播放
- (void)startPlayWithTimeInterval:(NSTimeInterval)timeInterval;

//设置升降序播放
- (void)setUpCloudRecordOrder:(TGCloudRecordOrderType)order;

/// 播放一个start->end的视频  开始播放
/// - Parameters:
///   - startHmsInterval: //开始时间距离当天00:00:00的秒数
///   - endHmsInterval: //结束时间距离当天00:00:00的秒数
///   - model: 云事件&云录像model
///   - errorCallBack:返回错误
- (void)startPlayWithTimeInterval:(NSInteger)startHmsInterval endTime:(NSInteger)endHmsInterval   model:(TGCloudEventModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack;

/// 播放一个start->end的视频  开始播放
/// - Parameters:
///   - startHmsInterval: //开始时间距离当天00:00:00的秒数
///   - endHmsInterval: //结束时间距离当天00:00:00的秒数
///   - model: 云事件&云录像model
///   - errorCallBack:返回错误
///   - successDownLoadBlock 返回该时间段下载成功的所有文件名称
///   - failureDownLoadBlock 返回该时间段下载失败的所有报错信息
- (void)startPlayWithTimeInterval:(NSInteger)startHmsInterval endTime:(NSInteger)endHmsInterval   model:(TGCloudEventModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack successDownLoadInfor:(void(^)(NSArray *successInforArray))successDownLoadBlock failureDownLoadErrorInfor:(void(^)(NSArray *failureInforArray))failureDownLoadBlock;

/// 下载
/// - Parameters:
///   - startHmsInterval: //开始时间距离当天00:00:00的秒数
///   - endHmsInterval: //结束时间距离当天00:00:00的秒数
///   - model: 云事件&云录像model
///   - errorCallBack:返回错误
- (void)startDownloadWithTimeInterval:(NSInteger)startHmsInterval endTime:(NSInteger)endHmsInterval model:(TGCloudEventModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack;

// 下载并播放
- (void)downloadAndPlayCloudFileWithModel:(TGCloudDownloadModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack;

// 停止下载
- (void)stopDownload;

// 暂停播放
- (void)pausePlay;

// 继续播放
- (void)continuePlay;

// 开始播放
- (void)stopPlay;
// 禁音
- (void)muteAudio;
// 取消禁音
- (void)cancleMute;

// 开始录像
- (void)startRecordWithFileName:(NSString *)fileName recordType:(TGVideoRecordType)recordType;
// 结束录制
- (void)stopRecord;

// 设置云回放主画面
- (void)setCloudPrimaryWithChannel:(TGPlayChannelType)channel;

@end

NS_ASSUME_NONNULL_END
