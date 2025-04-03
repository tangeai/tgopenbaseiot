//
//  TGOSSVideoRecordModel.h
//  TGBaseIOT
//
//  Created by Darren Xia on 2025/3/20.
//

#import <Foundation/Foundation.h>
#import <TGBaseIOT/TGBaseIOTDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSVideoRecordModel : NSObject

// 视频文件名称
@property (nonatomic, copy) NSString *fileName;
// 视频宽度
@property (nonatomic, assign) int width;
// 视频高度
@property (nonatomic, assign) int height;
// 文件丢失时是否继续写数据
@property (nonatomic, assign) BOOL writeWhenDataLose;
// 静音时是否继续写音频数据
@property (nonatomic, assign) BOOL writeAudioWhenMute;
// 倍速播放时是否继续写音频数据
@property (nonatomic, assign) BOOL writeAudioWhenSpeed;
@property (nonatomic, assign) TGVideoRecordType recordType;

@end

NS_ASSUME_NONNULL_END
