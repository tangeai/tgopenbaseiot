//
//  TGOSSDownloadInfoModel.h
//  TGBaseIOT
//
//  Created by Darren Xia on 2025/3/14.
//

#import <Foundation/Foundation.h>
#import "TGOSSCloudRecordModel.h"
#import <TGBaseIOT/TGBaseIOTDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSDownloadInfoModel : NSObject

// 开始播放时间戳
@property (nonatomic, assign) NSInteger startTs;
// 结束播放时间戳
@property (nonatomic, assign) NSInteger endTs;
// 播放文件的ossId
@property (nonatomic, copy) NSString *ossId;
// 视频宽度
@property (nonatomic, assign) int width;
// 视频高度
@property (nonatomic, assign) int height;
// 视频文件名称
@property (nonatomic, copy) NSString *fileName;
// 文件丢失时是否继续写数据
@property (nonatomic, assign) BOOL writeWhenDataLose;
@property (nonatomic, assign) TGVideoRecordType recordType;
@property (nonatomic, copy, readonly) NSString *sessionId;

@end

NS_ASSUME_NONNULL_END
