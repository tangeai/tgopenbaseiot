//
//  TGOSSCloudRecordModel.h
//  TGBaseIOT
//
//  Created by Darren Xia on 2025/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSCloudRecordModel : NSObject

@property (nonatomic, copy) NSString *ossId;
// 开始时间戳
@property (nonatomic, assign) NSInteger startTs;
// 结束时间戳
@property (nonatomic, assign) NSInteger endTs;

+ (instancetype)modelWithRecordInfo:(NSDictionary *)recordInfo;

@end

NS_ASSUME_NONNULL_END
