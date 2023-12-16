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

- (instancetype)initWithDeviceId:(NSString *)deviceId ossId:(NSString *)ossId callBack:(void(^)(id error))callBack;
- (void)downLoadFileWithObjectKey:(NSString *)objectKey ossId:(NSString *)ossId block:(void(^)(NSData *data,NSError *error))block;
- (void)cancleTask;
- (void)uploadAppLogWithSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

@end

NS_ASSUME_NONNULL_END
