//
//  TGHintToneModel.h
//  TGIOT
//
//  Created by Darren on 2022/6/25.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//#import <TGCommonBaseModule/TGCommonBaseDefineHeader.h>
#import "TGCameraDefine.h"
#import "TGCameraDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGHintToneModel : NSObject<NSMutableCopying>

@property (nonatomic, assign) BOOL enable;
@property (nonatomic, assign) ENUMHINTTONE type;
@property (nonatomic, assign) NSInteger hintId;

+ (instancetype)modelWithCameraDevice:(TGCameraDeviceModel *)device;

@end

NS_ASSUME_NONNULL_END
