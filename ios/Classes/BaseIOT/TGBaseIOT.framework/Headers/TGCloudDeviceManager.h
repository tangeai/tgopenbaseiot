//
//  TGCloudDeviceManager.h
//  TGBaseIOT
//
//  Created by Darren on 2020/11/23.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGCloudDownloadModel.h"
#import "TGCloudEventModel.h"
#import <DAAudioVideo/DAAudioVideo.h>
#import "TGCameraDeviceModel.h"
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TGCloudRecordOrderType) {
    TGCloudRecordOrderType_Desc,    //降序
    TGCloudRecordOrderType_Asce     //升序
};
typedef NS_ENUM(NSInteger, TGCloudManagerErrorType) {
    TGCloudManagerErrorType_Ok,
    TGCloudManagerErrorType_NoFile,
    TGCloudManagerErrorType_NetworkError,
    TGCloudManagerErrorType_NoPermitted,
    TGCloudManagerErrorType_TooBig
};

@protocol TGCloudDeviceManagerDelegate <NSObject>

@optional

#pragma mark -- play
// 播放回调
- (void)cloudDeviceManagerDidPlayDecoderVideoData:(DACameraP2PVideoData *)videoData;
// 播放缓存开始回调
- (void)didReceiveVideoCacheStart:(DACameraP2PVideoData *)videoData;
// 播放缓存结束回调
- (void)didReceiveVideoCacheEnd:(DACameraP2PVideoData *)videoData;
// 播放缓存结束回调
- (void)cloudVideoEnd;

#pragma mark -- other
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

#pragma mark -- 云录像列表
/// 查询某一天的云录像列表，不区分全时还是事件视频类型 (推荐使用)(内置缓存，请求完成后，调用后云录操作将使用该接口的缓存数据)
/// - Parameters:
///   - dateString: 日期
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)getNoTagDeviceCloudRecordWithDateString:(NSString *)dateString successBlock:(void(^)(NSArray *allArray))successBlock failureBlock:(void(^)(id error))failureBlock;

///  查询某一天的云录像列表，不区分全时还是事件视频类型 (推荐使用)（无内置缓存，和绑定数据源搭配使用）
/// - Parameters:
///   - dateString: 日期
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)getNoCacheAndTagDeviceCloudRecordWithDateString:(NSString *)dateString successBlock:(void(^)(NSArray *allArray))successBlock failureBlock:(void(^)(id error))failureBlock;
/// 绑定数据源（如不调用将默认使用最后一次调用云录像列表的数据）绑定后，云录像操作将使用绑定数据源进行操作
/// - Parameters:
///   - dateString:日期（2024-01-01）
///   - allArray: 云录像列表处理过的云录像集合列表
- (void)setCloudCardDataSourceWithDateString:(NSString *)dateString allArray:(NSArray *)allArray;

/// 返回云录像列表，区分事件类型（逐渐废弃）
/// - Parameters:
///   - dateString: 日期
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)getDeviceCloudRecordWithDateString:(NSString *)dateString successBlock:(void(^)(NSArray *normalArray,NSArray *eventArray))successBlock failureBlock:(void(^)(id error))failureBlock DEPRECATED_MSG_ATTRIBUTE("Use -getNoTagDeviceCloudRecordWithDateString: instead");
#pragma mark -- 云录像缩略图
/// 生成缩略图方法
/// - Parameters:
///   - cloudArray: 云录像列表
///   - dateString: 日期
///   - callBack: 回调
- (void)makeCloudGifImageWithArray:(NSArray <TGCloudEventModel *> *)cloudArray date:(NSString *)dateString callBack:(void(^)(BOOL done))callBack;

/// 展示动图方法
/// - Parameters:
///   - index: cloudArray 中的位置
///   - dateString: 日期
///   - imageView: 需要展示的图片的ImageView
- (void)showImageWithIndex:(NSInteger)index date:(NSString *)dateString inImageView:(UIImageView *)imageView;

/// 清除图片缓存方法(清除指定日期的0-count-1的所有序号的本地图片)
/// - Parameters:
///   - dateString: 日期
///   - count: 数量 （会清除0-count-1的所有本地缓存）
- (void)clearCacheWithDay:(NSString *)dateString count:(NSInteger)count;

#pragma mark -- 云录像操作
/// 设置升降序播放，可以设置云录像是升序播放或降序播放
/// - Parameter order: 顺序参数
- (void)setUpCloudRecordOrder:(TGCloudRecordOrderType)order;

/// 云录像开始播放方法（此方法仅限云录像），此方法将按云录像的列表逐个自动播放
/// - Parameter timeInterval: 距离当天00:00:00的秒数
- (void)startPlayWithTimeInterval:(NSTimeInterval)timeInterval;
/// 云录像开始播放方法（此方法仅限云录像），此方法将按云录像的列表逐个自动播放
/// - Parameter timeInterval: 距离当天00:00:00的秒数
/// - Parameter completeBlock: 播放是否成功回调
/// - Parameter playNearby: 开启后将播放最接近且>timeInterval的录像
- (void)startPlayWithTimeInterval:(NSTimeInterval)timeInterval playNearby:(BOOL)open completeBlock:(void(^)(BOOL success))completeBlock;

/// 启动多目同步 （启动同步会影响出图速度）
/// - Parameters:
///   - open: 同步开关 yes打开 no关闭
- (void)openGraphicsYnchronization:(BOOL)open;

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
///   - channels:目数通道集合 @[@"0",@"1",@"2"]
///   - errorCallBack:返回错误
- (void)startDownloadWithTimeInterval:(NSInteger)startHmsInterval endTime:(NSInteger)endHmsInterval model:(TGCloudEventModel *)model channels:(NSArray *)channelArray errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack;

/// 下载
/// - Parameters:
///   - startHmsInterval: //开始时间距离当天00:00:00的秒数
///   - endHmsInterval: //结束时间距离当天00:00:00的秒数
///   - model: 云事件&云录像model
///   - errorCallBack:返回错误
- (void)startDownloadWithTimeInterval:(NSInteger)startHmsInterval endTime:(NSInteger)endHmsInterval model:(TGCloudEventModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack DEPRECATED_MSG_ATTRIBUTE("Use -startDownloadWithTimeInterval: endTime: model: channels: errorCallBack: instead");;;


/// 已废弃 下载并播放一个区间内的片段 请使用 startDownloadWithTimeInterval
/// - Parameters:
///   - model: 下载model
///   - errorCallBack: 回调
//- (void)downloadAndPlayCloudFileWithModel:(TGCloudDownloadModel *)model errorCallBack:(void(^)(TGCloudManagerErrorType error))errorCallBack DEPRECATED_MSG_ATTRIBUTE("Use -startDownloadWithTimeInterval: endTime: model: channel: errorCallBack: instead");

/// 停止下载
- (void)stopDownload;

/// 暂停播放  （注意此方法要和继续播放方法成对调用）
- (void)pausePlay;

/// 继续播放 （注意此方法要和暂停播放方法成对调用）
- (void)continuePlay;

/// 停止播放
- (void)stopPlay;
/// 该方法仅是未播放声音，录制或下载时不影响声音录入 yes静音 no非静音
- (void)muteWithAudioOpen:(BOOL)open;
/// 禁音
- (void)muteAudio;
/// 取消禁音
- (void)cancleMute;

/// 开始录制方法
/// - Parameters:
///   - fileName: 录制的文件名称
///   - recordType: 录制类型
- (void)startRecordWithFileName:(NSString *)fileName recordType:(TGVideoRecordType)recordType;

/// 停止录制
- (void)stopRecord;

#pragma mark -- 其他操作
/// 设置云回放主画面
- (void)setCloudPrimaryWithChannel:(TGPlayChannelType)channel;

@end

NS_ASSUME_NONNULL_END
