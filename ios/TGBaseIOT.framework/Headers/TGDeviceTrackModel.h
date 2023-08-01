//
//  TGDeviceTrackModel.h
//  TGIOT
//
//  Created by Darren on 2022/7/21.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceTrackModel : NSObject<NSMutableCopying>

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *descript;
@property (nonatomic, assign) NSInteger trackNo;
@property (nonatomic, assign) NSInteger act;
@property (nonatomic, assign) NSInteger pspCount;
@property (nonatomic, strong) NSMutableArray *pspNoArray;
@property (nonatomic, assign) TGPlayChannelType channel;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger stayTime;
@property (nonatomic, assign) BOOL isActive;

+ (instancetype)defaultTrack;
+ (instancetype)horizontalTrack;
+ (instancetype)modelWithTrackInfo:(NSDictionary *)trackInfo type:(NSInteger)type;

- (BOOL)isDefaultTrack;
- (BOOL)isHorizontalTrack;

@end

NS_ASSUME_NONNULL_END
