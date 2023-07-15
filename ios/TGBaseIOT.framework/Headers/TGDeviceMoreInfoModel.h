//
//  TGDeviceMoreInfoModel.h
//  TGIOT
//
//  Created by Darren on 2022/1/12.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceMoreInfoModel : NSObject

@property (nonatomic, copy) NSString *iconName;
@property (nonatomic, strong) UIImage *iconImage;
@property (nonatomic, copy) NSString *title; // 解耦
@property (nonatomic, assign) TGDeviceButtonListFlag flag;
@property (nonatomic, assign) BOOL isToReceive;
@property (nonatomic, assign) BOOL isToActive;
@property (nonatomic, copy) NSString *desc;

+ (instancetype)modelWithIconName:(NSString *)iconName title:(NSString *)title flag:(TGDeviceButtonListFlag)flag;

@end

NS_ASSUME_NONNULL_END
