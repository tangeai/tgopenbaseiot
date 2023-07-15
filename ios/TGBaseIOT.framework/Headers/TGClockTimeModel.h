//
//  TGClockTimeModel.h
//  TGIOT
//
//  Created by Darren on 2023/2/10.
//

#import <Foundation/Foundation.h>
#import "TGCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGClockTimeModel : NSObject<NSMutableCopying>

@property (nonatomic, assign) unsigned int hour;
@property (nonatomic, assign) unsigned int minute;
@property (nonatomic, assign) unsigned int second;
@property (nonatomic, assign) unsigned int reserved;

+ (instancetype)modelWithTime:(CLOCKTIME)time;
+ (instancetype)modelWithTimeInfo:(NSDictionary *)timeInfo;

@end

NS_ASSUME_NONNULL_END
