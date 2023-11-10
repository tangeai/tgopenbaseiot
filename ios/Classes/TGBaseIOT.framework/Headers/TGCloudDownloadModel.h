//
//  TGCloudDownloadModel.h
//  TGIOT
//
//  Created by Darren on 2022/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TGCloudPlayScene) {
    TGCloudPlayScene_UnKnown,
    TGCloudPlayScene_CloudList,
    TGCloudPlayScene_CloudRecord,
    TGCloudPlayScene_Message,
    TGCloudPlayScene_Doorbell
};

@interface TGCloudDownloadModel : NSObject

@property (nonatomic, copy) NSString *ossid;
@property (nonatomic, copy) NSString *startTime;                //2019-01-16 16:18:07
@property (nonatomic, copy) NSString *endTime;                  //2019-01-16 19:24:47
@property (nonatomic, assign) NSInteger startTs;                //要下载文件的开始时间戳，经过取整处理，方便后期转成时间戳处理
@property (nonatomic, assign) NSInteger endTs;                  //要下载文件的结束时间戳，经过取整处理，方便后期转成时间戳处理
@property (nonatomic, copy) NSString *dateString;               //2019-01-16
@property (nonatomic, assign) NSInteger startHmsInterval;       //开始时间距离当天00:00:00的秒数
@property (nonatomic, assign) NSInteger endHmsInterval;         //结束时间距离当天00:00:00的秒数
@property (nonatomic, assign) TGCloudPlayScene scene;

@end

NS_ASSUME_NONNULL_END
