//
//  TGDeviceTrackModel.h
//  TGBaseIOT
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
@property (nonatomic, assign) NSInteger trackNo;  // ACTIVE_TRACK_DEFAULT   0xffff  ///< 活动轨迹为缺省轨迹 ACTIVE_TRACK_AUTO_SCAN 0xfffe  ///< 活动轨迹为水平线扫
@property (nonatomic, assign) NSInteger act;                            // 0
@property (nonatomic, assign) NSInteger pspCount;
@property (nonatomic, strong) NSMutableArray *pspNoArray;
@property (nonatomic, assign) TGPlayChannelType channel;
@property (nonatomic, assign) NSInteger type;                           // TRACK_BY_NO 1  轨迹由预置位号表示. 设备端保存轨迹名称 TRACK_BY_NO_NONAME 2 轨迹由预置位号表示，没有名字
@property (nonatomic, assign) NSInteger stayTime;
@property (nonatomic, assign) BOOL isActive;

+ (instancetype)defaultTrack;
+ (instancetype)horizontalTrack;
+ (instancetype)modelWithTrackInfo:(NSDictionary *)trackInfo type:(NSInteger)type;

- (BOOL)isDefaultTrack;
- (BOOL)isHorizontalTrack;

@end

NS_ASSUME_NONNULL_END
