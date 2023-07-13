//
//  TGResolutionModel.h
//  TGIOT
//
//  Created by Darren on 2022/3/31.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGCameraDeviceModel.h"
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGResolutionModel : NSObject

@property (nonatomic, assign) int index;
@property (nonatomic, assign) int channel;
@property (nonatomic, copy) NSString *descript;
@property (nonatomic, assign) ENUM_QUALITY_LEVEL liveQuality;
@property (nonatomic, assign) int sdcardQuality;

+ (NSArray <TGResolutionModel *>*)resolutionsWithDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
