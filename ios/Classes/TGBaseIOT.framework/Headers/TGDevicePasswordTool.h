//
//  TGDevicePasswordTool.h
//  TGBaseIOT
//
//  Created by Darren on 2022/3/24.
//
#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGDevicePasswordTool : NSObject

+ (NSString *)awakeDevicePasswordWithUuid:(NSString *)uuid;
+ (NSString *)sercurityLockPwdWithPassword:(NSString *)pwd uuid:(NSString *)uuid userId:(NSString *)userId;
+ (void)checkLockPasswordWithPassword:(NSString *)pwd uuid:(NSString *)uuid callBlock:(void(^)(NSString * sercurityPwd, id error))callBlock;

@end

NS_ASSUME_NONNULL_END
