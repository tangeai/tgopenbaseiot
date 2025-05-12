//
//  TGOSSDownloadInfoModel.h
//  TGBaseIOT
//
//  Created by Darren Xia on 2025/3/14.
//

#import <Foundation/Foundation.h>
#import "TGDownloadChannelModel.h"
#import <TGBaseIOT/TGBaseIOTDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSDownloadInfoModel : NSObject

// 开始播放时间戳
@property (nonatomic, assign) NSInteger startTs;
// 结束播放时间戳
@property (nonatomic, assign) NSInteger endTs;
// 播放文件的ossId
@property (nonatomic, copy) NSString *ossId;
// 文件丢失时是否继续写数据
@property (nonatomic, assign) BOOL writeWhenDataLose;
// 指定下载视频通道
@property (nonatomic, strong) NSArray <TGDownloadChannelModel *>*channels;
@property (nonatomic, copy, readonly) NSString *sessionId;

@end

NS_ASSUME_NONNULL_END
