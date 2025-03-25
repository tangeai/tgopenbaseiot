//
//  TGOSSDownloadInfoModel.h
//  TGIOT
//
//  Created by Darren Xia on 2025/3/14.
//

#import <Foundation/Foundation.h>
#import "TGOSSCloudRecordModel.h"
#import <TGBaseIOT/TGBaseIOTDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSDownloadInfoModel : NSObject

// 开始播放时间戳
@property (nonatomic, assign) NSInteger startTs;
// 结束播放时间戳
@property (nonatomic, assign) NSInteger endTs;
// 播放文件的ossId
@property (nonatomic, copy) NSString *ossId;
// 录像列表，传入数组元素不为空，则依次按照录像列表遍历下载
// 不传、数组为空、数组元素个数位0，则依次进行累加递增下载
@property (nonatomic, strong) NSArray <TGOSSCloudRecordModel *>*recordArray;
// 传入录像列表排序方式，提高遍历效率
@property (nonatomic, assign) TGCloudRecordOrderType recordOrder;
@property (nonatomic, copy, readonly) NSString *sessionId;

@end

NS_ASSUME_NONNULL_END
