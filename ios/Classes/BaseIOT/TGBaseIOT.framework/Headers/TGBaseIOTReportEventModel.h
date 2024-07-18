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

@property (nonatomic, assign) TGBaseIOTLogLevel level;      // 日志级别
@property (nonatomic, copy) NSString *deviceId;             // 设备id
@property (nonatomic, copy) NSString *name;                 // 事件名称
@property (nonatomic, copy) NSString *detail;               // 事件描述
@property (nonatomic, copy) NSString *time;                 // 事件时间
@property (nonatomic, copy) NSString *className;            // 所处的类

@end

@interface TGBaseIOTReportEventConfigModel : NSObject

@property (nonatomic, copy) NSString *level;                // 日志级别
@property (nonatomic, assign) NSInteger exception_log;      // 日志上报开关 1开 0关
@property (nonatomic, assign) NSInteger preview_stat;       // 日志统计开关 1开 0关

@end

NS_ASSUME_NONNULL_END
