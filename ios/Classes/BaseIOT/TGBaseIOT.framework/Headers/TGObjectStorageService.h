//
//  TGObjectStorageService.h
//  TGBaseIOT
//
//  Created by Darren on 2019/1/28.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGObjectStorageService : NSObject

@property (nonatomic, copy) NSString *rootPath;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *ossId;
@property (nonatomic, copy) NSString *accessId;
@property (nonatomic, copy) NSString *accessKey;
@property (nonatomic, copy) NSString *securityToken;
@property (nonatomic, copy) NSString *bucket;
@property (nonatomic, copy) NSString *endPoint;
@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *region_id;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *expiration;
@property (nonatomic, copy) NSString *timeZone;

- (instancetype)initWithDeviceId:(NSString *)deviceId ossId:(NSString *)ossId callBack:(void(^)(id error))callBack;
- (void)downLoadFileWithObjectKey:(NSString *)objectKey ossId:(NSString *)ossId block:(void(^)(NSData *data,NSError *error))block;
- (void)initOOS;
- (void)configCloudServiceWithType:(NSString *)type accessId:(NSString *)accessId accessKey:(NSString *)accesskey token:(NSString *)token bucket:(NSString *)bucket endPoint:(NSString *)endPoint;
- (void)downLoadFileWithCloudType:(NSString *)type objectKey:(NSString *)objectKey ossId:(NSString *)ossId block:(void (^)(NSData * _Nonnull, NSError * _Nonnull))block;
- (void)cancleTask;
- (void)uploadAppLogWithSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;
- (void)uploadDeviceLogWithFilePath:(NSURL *)filePath deviceId:(NSString *)deviceId successBlock:(void (^)(id _Nonnull))successBlock failureBlock:(void (^)(id _Nonnull))failureBlock;
- (void)getAccessTokenAndInitOSSWithDeviceId:(NSString *)deviceId ossId:(NSString *)ossId callBack:(void(^)(id error))callBack;
+ (void)getUploadAppLogTokenWithSuccessBlock:(void (^)(id _Nonnull))successBlock failureBlock:(void (^)(id _Nonnull))failureBlock;

@end

NS_ASSUME_NONNULL_END
