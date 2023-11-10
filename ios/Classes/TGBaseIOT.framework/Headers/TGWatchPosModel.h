//
//  TGWatchPosModel.h
//  TGIOT
//
//  Created by Darren on 2021/11/3.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGCameraDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGWatchPosModel : NSObject

@property (nonatomic, assign) int channel;
@property (nonatomic, assign) int num;
@property (nonatomic, assign) int idleTime;
@property (nonatomic, assign) BOOL isCanClose;
@property (nonatomic, assign) BOOL isToClose;

+ (instancetype)modelWithCameraDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
