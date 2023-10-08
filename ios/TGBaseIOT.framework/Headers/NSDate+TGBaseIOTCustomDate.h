//
//  NSDate+TGBaseIOTCustomDate.h
//  TGBaseIOT
//
//  Created by liubin on 2022/11/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#define TG_DateFormat_yMdHms    @"yyyy-MM-dd HH:mm:ss"
#define TG_DateFormat_yMd_Hms   @"yyyy-MM-dd_HH:mm:ss"
#define TG_DateFormat_yMdHmsS   @"yyyy-MM-dd HH:mm:ss.SSS"
#define TG_DateFormat_HmsS      @"HH:mm:ss.SSS"

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TGBaseIOTCustomDate)

+ (NSInteger)TGTimeIntervalWithTimeString:(NSString *)timeString;
+ (BOOL)TGIsEarlyWithDateStr:(NSString *)dateString relativeDateStr:(NSString *)relativeDateStr;
+ (BOOL)TGIsLaterWithDateStr:(NSString *)dateString relativeDateStr:(NSString *)relativeDateStr;
+ (NSTimeInterval)TGGetMilliSecondFrom1970;
- (NSString *)dateStringWithFormat:(NSString *)format;

@end

NS_ASSUME_NONNULL_END
