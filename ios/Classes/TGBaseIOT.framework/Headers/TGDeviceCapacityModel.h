//
//  TGDeviceCapacityModel.h
//  TGBaseIOT
//
//  Created by Darren on 2023/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceCapacityModel : NSObject

/* 是否可使用超分功能 */
@property (nonatomic, assign) BOOL superResolutionAvalable;

+ (instancetype)defaultModel;

@end

NS_ASSUME_NONNULL_END
