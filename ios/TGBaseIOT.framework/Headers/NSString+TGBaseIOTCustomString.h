//
//  NSString+TGBaseIOTCustomString.h
//  Pods
//
//  Created by liubin on 2022/11/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TGBaseIOTCustomString)

- (BOOL)tg_ignoreCaseIsEqualToString:(NSString *)string;

+ (NSString *)tg_getCurrentAppVersion;
+ (NSString *)tg_getCurrentBuildVersion;
+ (NSString *)tg_getAppBundleIdentifier;
+ (NSString *)tg_getCurrentSDKVersion;
+ (NSString *)tg_getAppDisplayName;
+ (NSString *)tg_deviceModelName;
+ (NSString *)tg_localCountryCode;

+ (BOOL)tg_isEmptyWithString:(NSString *)string;
+ (NSString *)tg_getValueFromDictionary:(NSDictionary *)dictionary WithKey:(NSString *)key;

+ (NSString *)tg_randomStringWithLength:(NSInteger)length;
+ (NSString *)tg_randomStringFirstIsNotNumberWithLength:(NSInteger)length;

+ (NSDateFormatter *)defaultFormat;
+ (NSDateFormatter *)formatWithTimeZone:(NSString *)timeZone;
+ (NSDateFormatter *)formatWithDateFormat:(NSString *)dateFormat;
+ (NSDateFormatter *)formatWithTimeZone:(NSString *)timeZone dateFormat:(NSString *)dateFormat;

@end

NS_ASSUME_NONNULL_END
