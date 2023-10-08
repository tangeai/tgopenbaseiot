//
//  DAAudioConfigModel.h
//  DAAudioVideo
//
//  Created by Darren on 2021/8/20.
//

#import <Foundation/Foundation.h>
#import "DAAudioVideoDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface DAAudioConfigModel : NSObject

@property (nonatomic, assign) int channel;      //通道数
@property (nonatomic, assign) int sampleRate;   //采样率
@property (nonatomic, assign) int sampleSize;   //位深
@property (nonatomic, assign) DAMediaCodeID codecId;

//默认单通道、8K采样率、16位深
+ (instancetype)defaultConfig;

@end

NS_ASSUME_NONNULL_END
