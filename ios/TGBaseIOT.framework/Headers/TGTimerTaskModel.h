//
//  TGTimerTaskModel.h
//  TGIOT
//
//  Created by Darren on 2023/2/10.
//

#import <Foundation/Foundation.h>
#import "TGCameraDefine.h"

@class TGClockTimeModel;

NS_ASSUME_NONNULL_BEGIN

@interface TGTimerTaskModel : NSObject<NSMutableCopying>

@property (nonatomic, assign) unsigned int object;
@property (nonatomic, assign) unsigned int identity;
@property (nonatomic, strong) TGClockTimeModel *from;
@property (nonatomic, strong) TGClockTimeModel *to;
@property (nonatomic, assign) unsigned int state;
@property (nonatomic, assign) unsigned int repeat;
@property (nonatomic, assign) uint32_t actionSize;
@property (nonatomic, assign, nullable) uint32_t *action;
@property (nonatomic, assign) BOOL isEditing;
@property (nonatomic, assign) BOOL isSelected;

+ (instancetype)modelWithAction:(TgTimeAction *)action object:(unsigned int)object identity:(unsigned int)identity;
+ (instancetype)modelWithTaskInfo:(NSDictionary *)taskInfo object:(unsigned int)object identity:(unsigned int)identity;

@end

NS_ASSUME_NONNULL_END
