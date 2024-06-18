//
//  TGDevicePSPModel.h
//  TGBaseIOT
//
//  Created by Darren on 2021/8/17.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGDevicePSPModel : NSObject

@property (nonatomic, assign) NSInteger flags;
@property (nonatomic, assign) NSInteger num;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) BOOL isWatchPos;
@property (nonatomic, assign) TGPlayChannelType channel;
@property (nonatomic, assign) NSInteger trackIndex;

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat z;

@property (nonatomic, assign) BOOL isSimulation;
@property (nonatomic, assign) BOOL isEditing;
@property (nonatomic, assign) BOOL isSelected;

+ (instancetype)modelWithPSPInfo:(NSDictionary *)pspInfo type:(NSInteger)type channel:(TGPlayChannelType)channel;

@end

NS_ASSUME_NONNULL_END
