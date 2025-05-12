//
//  TGDownloadChannelModel.h
//  TGBaseIOT
//
//  Created by Darren Xia on 2025/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGDownloadChannelModel : NSObject

// 视频宽度
@property (nonatomic, assign) int width;
// 视频高度
@property (nonatomic, assign) int height;
// 视频通道
@property (nonatomic, assign) int channel;
// 文件名称
@property (nonatomic, copy) NSString *fileName;

@end

NS_ASSUME_NONNULL_END
