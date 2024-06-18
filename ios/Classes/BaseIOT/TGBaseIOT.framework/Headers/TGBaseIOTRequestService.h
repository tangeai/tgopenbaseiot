//
//  TGBaseIOTRequestService.h
//  TGBaseIOT
//
//  Created by liubin on 2022/11/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGBaseIOTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGBaseIOTRequestService : NSObject

@property (nonatomic, copy, readonly) NSString *apiUrl;
@property (nonatomic, copy, readonly) NSString *socketUrl;
@property (nonatomic, copy, readonly) NSString *webUrl;
@property (nonatomic, copy, readonly) NSString *logUrl;
@property (nonatomic, copy, readonly) NSString *openApiUrl;
@property (nonatomic, assign, readonly) TGBaseIOTServerEnvType env;
@property (nonatomic, assign, readonly) BOOL hubServerReady;

+ (instancetype)shareService;
- (void)setVersionNumber:(NSString *)versionNumber;
- (void)cleanHubInfo;
- (void)switchToEnvType:(TGBaseIOTServerEnvType)env;
- (void)requestWithUrl:(NSString *)url params:(nullable id)params successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;
- (void)downloadFileWithUrl:(NSString *)url params:(nullable id)params savePath:(NSString *)savePath successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;
- (void)downloadFileWithUrl:(NSString *)url headers:(nullable id)headers savePath:(NSString *)savePath successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;
- (void)cancelAllOperations;
- (void)uploadFileWithUrl:(NSString *)url fileData:(NSData *)fileData name:(NSString *)name fileName:(NSString *)fileName mimeType:(NSString *)mimeType successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;
- (void)sendSetWifiInfoToDeviceWithUrl:(NSString *)url params:(nullable id)params successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

- (void)requestlogWithUrl:(NSString *)url params:(nullable id)params successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

- (void)getHubServiceUrlWithName:(nullable NSString *)name last:(nullable NSString *)last successBlock:(void(^)(void))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - POST
- (void)requestWithUrl:(NSString *)url needToken:(BOOL)needToken isRetry:(BOOL)isRetry params:(nullable id)params successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - PAT

- (void)patRequestWithUrl:(NSString *)url params:(nullable id)params needToken:(BOOL)needToken successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - Delete
- (void)deleteRequestWithUrl:(NSString *)url params:(nullable id)params needToken:(BOOL)needToken successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - Get
- (void)getRequestWithUrl:(NSString *)url params:(nullable id)params needToken:(BOOL)needToken successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

@end

NS_ASSUME_NONNULL_END
