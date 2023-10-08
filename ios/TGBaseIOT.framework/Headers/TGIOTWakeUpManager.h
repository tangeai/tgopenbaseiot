//
//  TGIOTWakeUpManager.h
//  TGBaseIOT
//
//  Created by Darren on 2023/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TGCameraDeviceModel;

@interface TGIOTWakeUpManager : NSObject

- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;
- (void)wakeUpDevice;

@end

NS_ASSUME_NONNULL_END
