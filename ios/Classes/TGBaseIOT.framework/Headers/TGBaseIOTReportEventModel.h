//
//  TGBaseIOTReportEventModel.h
//  TGBaseIOT
//
//  Created by liubin on 2024/5/27.
//

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TGBaseIOTLogLevel) {
    TGBaseIOT_DEBUG,  // 调试等级
    TGBaseIOT_NOTICE, // 注意或者错误
    TGBaseIOT_INFO    // 一般信息
};


@interface TGBaseIOTReportEventModel : NSObject

@property (nonatomic, assign) TGBaseIOTLogLevel level;
@property (nonatomic, strong) NSString *deviceId;
@property (nonatomic, assign) NSString *name;
@property (nonatomic, assign) NSString *detail;
@property (nonatomic, assign) NSString *time;
@property (nonatomic, assign) NSString *className;


@end

NS_ASSUME_NONNULL_END
