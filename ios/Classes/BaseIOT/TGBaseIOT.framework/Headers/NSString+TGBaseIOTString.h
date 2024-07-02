//
//  NSString+TGBaseIOTString.h
//  TGBaseIOT
//
//  Created by liubin on 2022/11/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TGBaseIOTString)

- (BOOL)tgbaseiot_ignoreCaseIsEqualToString:(NSString *)string;

+ (NSString *)tgbaseiot_getCurrentAppVersion;
+ (NSString *)tgbaseiot_getCurrentBuildVersion;
+ (NSString *)tgbaseiot_getAppBundleIdentifier;
+ (NSString *)tgbaseiot_getAppDisplayName;
+ (NSString *)tgbaseiot_deviceModelName;
+ (NSString *)tgbaseiot_localCountryCode;

+ (BOOL)tgbaseiot_isEmptyWithString:(NSString *)string;
+ (NSString *)tgbaseiot_getValueFromDictionary:(NSDictionary *)dictionary WithKey:(NSString *)key;
+ (NSString *)tgbaseiot_randomStringWithLength:(NSInteger)length;
+ (NSString *)tgbaseiot_randomStringFirstIsNotNumberWithLength:(NSInteger)length;

+ (NSDateFormatter *)tgbaseiot_formatWithTimeZone:(NSString *)timeZone dateFormat:(NSString *)dateFormat;

+ (NSDateFormatter *)tgbaseiot_defaultFormat;
+ (NSDateFormatter *)tgbaseiot_formatWithTimeZone:(NSString *)timeZone;
+ (NSDateFormatter *)tgbaseiot_formatWithDateFormat:(NSString *)dateFormat;

+ (NSInteger)tgbaseiot_timeIntervalWithTimeString:(NSString *)timeString;
+ (BOOL)tgbaseiot_isEarlyWithDateStr:(NSString *)dateString relativeDateStr:(NSString *)relativeDateStr;
+ (BOOL)tgbaseiot_isLaterWithDateStr:(NSString *)dateString relativeDateStr:(NSString *)relativeDateStr;
+ (NSString *)tgbaseiot_changeCharWithBytes:(const void *)bytes length:(NSUInteger)length;
@end

NS_ASSUME_NONNULL_END
