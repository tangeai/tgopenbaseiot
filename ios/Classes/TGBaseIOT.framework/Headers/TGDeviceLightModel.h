//
//  TGDeviceLightModel.h
//  TGBaseIOT
//
//  Created by Darren on 2022/5/20.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class TGCameraDeviceModel;

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceLightModel : NSObject<NSMutableCopying>

@property (nonatomic, assign) int lightId;
@property (nonatomic, assign) int mask;
@property (nonatomic, assign) BOOL on;
@property (nonatomic, assign) int mode;
@property (nonatomic, assign) int delayShutDown;
@property (nonatomic, assign) int intensity;

+ (instancetype)modelWithCameraDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
