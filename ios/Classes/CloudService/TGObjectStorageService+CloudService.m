//
//  TGObjectStorageService+CloudService.m
//  TGBaseIOT
//
//  Created by liubin on 2024/6/18.
//

#import "TGObjectStorageService+CloudService.h"
#import "NSString+TGBaseIOTString.h"
#import "TGMagicLogManager.h"
#import "TGBaseIOTRequestService.h"

static const void *OssClient = &OssClient;
static const void *AliRequest = &AliRequest;
static const void *CtyRequest = &CtyRequest;
static const void *TxRequest = &TxRequest;
static const void *UploadRequest = &UploadRequest;

@implementation TGObjectStorageService (CloudService) 

#pragma mark reloadAction

- (void)initOOS {
    [OSSLog disableLog];
    [QCloudLogManager sharedInstance].shouldShowLog = NO;
    [QCloudLogger sharedLogger].logLevel = QCloudLogLevelNone;
}

- (void)configCloudServiceWithType:(NSString *)type accessId:(NSString *)accessId accessKey:(NSString *)accesskey token:(NSString *)token bucket:(NSString *)bucket endPoint:(NSString *)endPoint {
    if ([type tgbaseiot_ignoreCaseIsEqualToString:@"ctyun"]) {
        //endPoint：oos-hazz.ctyunapi.cn
        OOSStaticCredentialsProvider *provider = [[OOSStaticCredentialsProvider alloc] initWithAccessKey:accessId secretKey:accesskey securityToken:token];
        OOSServiceConfiguration *configuration = [[OOSServiceConfiguration alloc] initWithRegion:OOSRegionZhengZhou credentialsProvider:provider];
        //configuration.baseURL = [NSURL URLWithString:@"https://oos-hazz.ctyunapi.cn"];
        configuration.maxRetryCount = 3;
        configuration.timeoutIntervalForRequest = 15;
        configuration.timeoutIntervalForResource = 15;
        [OOSServiceManager defaultServiceManager].defaultServiceConfiguration = configuration;
    }else if ([type tgbaseiot_ignoreCaseIsEqualToString:@"txyun"]) {
        //endPoint：https://cn-nanjing-device-private-1259475310.cos.ap-nanjing.myqcloud.com
        NSMutableString *endPointUrl = [NSMutableString stringWithString:endPoint];
        if ([endPointUrl hasPrefix:@"https://"]
            || [endPointUrl hasPrefix:@"http://"]) {
            NSRange range = [endPointUrl rangeOfString:@"://"];
            [endPointUrl insertString:[NSString stringWithFormat:@"%@.",bucket] atIndex:range.location + 3];
        }
        NSString *endPointUrlString = [NSString stringWithString:endPointUrl];
        if ([endPointUrlString hasPrefix:@"https://"]) {
            endPointUrlString = [endPointUrlString stringByReplacingOccurrencesOfString:@"https://" withString:@""];
        }else if ([endPointUrlString hasPrefix:@"http://"]) {
            endPointUrlString = [endPointUrlString stringByReplacingOccurrencesOfString:@"http://" withString:@""];
        }
        QCloudServiceConfiguration *configure = [[QCloudServiceConfiguration alloc] init];
        configure.signatureProvider = nil;
        QCloudCOSXMLEndPoint *endpoint1 = [[QCloudCOSXMLEndPoint alloc] initWithLiteralURL:[NSURL URLWithString:endPointUrlString]];
        configure.endpoint = endpoint1;
        [QCloudCOSTransferMangerService registerCOSTransferMangerWithConfiguration:configure withKey:bucket];
    }else if ([type tgbaseiot_ignoreCaseIsEqualToString:@"aliyun"]){
        //endPoint：https://test-media-cloud-user-private.tange365.com
        OSSClientConfiguration *configure = [[OSSClientConfiguration alloc] init];
        configure.maxRetryCount = 2;                    //网络请求遇到异常失败后的重试次数
        configure.timeoutIntervalForRequest = 5;        //网络请求的超时时间
        configure.timeoutIntervalForResource = 5;       //允许资源传输的最长时间
        id <OSSCredentialProvider> provider = [[OSSStsTokenCredentialProvider alloc] initWithAccessKeyId:accessId secretKeyId:accesskey securityToken:token];
        self.ossClient = [[OSSClient alloc] initWithEndpoint:endPoint credentialProvider:provider clientConfiguration:configure];
    }
}

- (void)downLoadFileWithCloudType:(NSString *)type objectKey:(NSString *)objectKey ossId:(NSString *)ossId block:(void (^)(NSData * _Nonnull, NSError * _Nonnull))block {
    if ([type tgbaseiot_ignoreCaseIsEqualToString:@"ctyun"]) {
        NSString *downloadingFilePath = [NSTemporaryDirectory() stringByAppendingPathComponent:@"temp.data"];
        NSURL *downloadingFileURL = [NSURL fileURLWithPath:downloadingFilePath];
        OOSTransferManager *manager = [OOSTransferManager defaultTransferManager];
        self.ctyRequest = [[OOSTransferManagerDownloadRequest alloc] init];
        self.ctyRequest.bucket = self.bucket;
        self.ctyRequest.key = objectKey;
        self.ctyRequest.downloadingFileURL = downloadingFileURL;
        [[manager download:self.ctyRequest] continueWithBlock:^id _Nullable(OOSTask * _Nonnull task) {
            NSError *error = task.error;
            if (error) {
                DDLogError(@"下载云文件失败--objectKey:%@--error:%@", objectKey, error);
                if (block) {
                    block(nil,error);
                }
            }else{
                NSData *downloadData = [NSData dataWithContentsOfURL:downloadingFileURL];
                if (block) {
                    block(downloadData,nil);
                }
            }
            return task;
        }];
    }else if ([type tgbaseiot_ignoreCaseIsEqualToString:@"txyun"]) {
        NSString *downloadingFilePath = [NSTemporaryDirectory() stringByAppendingPathComponent:@"temp.data"];
        NSURL *downloadingFileURL = [NSURL fileURLWithPath:downloadingFilePath];
        self.txRequest = [[QCloudCOSXMLDownloadObjectRequest alloc] init];
        self.txRequest.bucket = self.bucket;
        self.txRequest.object = objectKey;
        self.txRequest.downloadingURL = downloadingFileURL;
        __weak typeof(self) weakSelf = self;
        [self.txRequest setDownProcessBlock:^(int64_t bytesDownload, int64_t totalBytesDownload, int64_t totalBytesExpectedToDownload) {
            //DDLogInfo(@"bytesDownload:%lld--totalBytesDownload:%lld--totalBytesExpectedToDownload:%lld",bytesDownload,totalBytesDownload,totalBytesExpectedToDownload);
        }];
        [self.txRequest setFinishBlock:^(id  _Nullable outputObject, NSError * _Nullable error) {
            NSDictionary *downloadInfo = (NSDictionary *)outputObject;
            NSString *requestId = [NSString tgbaseiot_getValueFromDictionary:downloadInfo WithKey:@"x-cos-request-id"];
            if (error) {
                if (error.code == 403) {
                    DDLogError(@"OSStoken过期--objectKey:%@--error:%@--requestId:%@", objectKey, error, requestId);
                    [weakSelf getAccessTokenAndInitOSSWithDeviceId:weakSelf.deviceId ossId:ossId callBack:^(id error) {
                        if (!error) {
                            [weakSelf downLoadFileWithObjectKey:objectKey ossId:ossId block:block];
                        }else{
                            DDLogError(@"OSStoken过期，重新获取失败--objectKey:%@--error:%@--requestId:%@", objectKey, error, requestId);
                            if (block) {
                                block(nil,error);
                            }
                        }
                    }];
                }else{
                    DDLogError(@"下载云文件失败--objectKey:%@--error:%@--errorCode:%ld--requestId:%@", objectKey, error, (long)error.code, requestId);
                    if (block) {
                        block(nil,error);
                    }
                }
            }else{
                NSData *downloadData = [NSData dataWithContentsOfURL:downloadingFileURL];
                if (block) {
                    block(downloadData,nil);
                }
            }
        }];
        [[QCloudCOSTransferMangerService costransfermangerServiceForKey:self.bucket] DownloadObject:self.txRequest];
    }
    else if ([type tgbaseiot_ignoreCaseIsEqualToString:@"aliyun"]) {
        self.aliRequest = [[OSSGetObjectRequest alloc] init];
        self.aliRequest.bucketName = self.bucket;
        self.aliRequest.objectKey = objectKey;
        OSSTask *task = [self.ossClient getObject:self.aliRequest];
        [task continueWithBlock:^id _Nullable(OSSTask * _Nonnull task) {
            OSSGetObjectResult *result = task.result;
            NSError *error = task.error;
            if (error) {
                if (error.code == -403) {
                    DDLogError(@"OSStoken过期--objectKey:%@--error:%@", objectKey, error);
                    [self getAccessTokenAndInitOSSWithDeviceId:self.deviceId ossId:ossId callBack:^(id error) {
                        if (!error) {
                            [self downLoadFileWithObjectKey:objectKey ossId:ossId block:block];
                        }else{
                            DDLogError(@"OSStoken过期，重新获取失败--objectKey:%@--error:%@", objectKey, error);
                            if (block) {
                                block(nil,error);
                            }
                        }
                    }];
                }else{
                    DDLogError(@"下载云文件失败--objectKey:%@--error:%@", objectKey, error);
                    if (block) {
                        block(nil,error);
                    }
                }
            }else{
                if (block) {
                    block(result.downloadedData,nil);
                }
            }
            return nil;
        }];
        //等待Task完成以实现同步等待
        //[task waitUntilFinished];
    }
}

- (void)uploadAppLogWithSuccessBlock:(void (^)(id _Nonnull))successBlock failureBlock:(void (^)(id _Nonnull))failureBlock{
    [TGObjectStorageService getUploadAppLogTokenWithSuccessBlock:^(id  _Nonnull result) {
        self.accessId = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"AccessKeyId"];
        self.accessKey = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"AccessKeySecret"];
        self.securityToken = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"SecurityToken"];
        self.bucket = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"bucket"];
        self.endPoint = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"endPoint"];
        self.rootPath = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"rootPath"];
        self.from = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"from"];
        self.ossId = [NSString tgbaseiot_getValueFromDictionary:result WithKey:@"ossid"];
        
        OSSClientConfiguration *configure = [[OSSClientConfiguration alloc] init];
        configure.maxRetryCount = 2;                    //网络请求遇到异常失败后的重试次数
        configure.timeoutIntervalForRequest = 5;        //网络请求的超时时间
        configure.timeoutIntervalForResource = 5;       //允许资源传输的最长时间
        id <OSSCredentialProvider> provider = [[OSSStsTokenCredentialProvider alloc] initWithAccessKeyId:self.accessId secretKeyId:self.accessKey securityToken:self.securityToken];
        self.ossClient = [[OSSClient alloc] initWithEndpoint:self.endPoint credentialProvider:provider clientConfiguration:configure];
        
        NSString *filePath = [TGMagicLogManager shareManager].currentLogFilePath;
        NSDate *date = [NSDate date];
        NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
        [formatter setDateFormat:@"yyyy-MM-dd_HH:mm:ss"];
        [formatter setTimeZone:[NSTimeZone timeZoneWithAbbreviation:@"UTC"]];
        [formatter setLocale:[NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"]];
        [formatter setCalendar:[[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian]];
        //获取当前时间日期展示字符串 如：2019-05-23-13:58:59
        NSString *dateString = [formatter stringFromDate:date];
        NSString *rootPath = [NSString stringWithString:self.rootPath];
        if([self.rootPath hasPrefix:@"/"]) {
            NSArray *rootPathArray = [rootPath componentsSeparatedByString:@"/"];
            rootPath = [rootPathArray lastObject];
        }
        NSString *objectKey = [NSString stringWithFormat:@"%@/%@-ios.log", rootPath, dateString];
        
        self.uploadRequest = [[OSSPutObjectRequest alloc] init];
        self.uploadRequest.bucketName = self.bucket;
        self.uploadRequest.uploadingFileURL = [NSURL fileURLWithPath:filePath];
        self.uploadRequest.objectKey = objectKey;
        self.uploadRequest.uploadProgress = ^(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend) {
            //DDLogInfo(@"bytesSent:%lld--totalBytesSent:%lld--totalBytesExpectedToSend:%lld", bytesSent, totalBytesSent, totalBytesExpectedToSend);
        };
        
        OSSTask *task = [self.ossClient putObject:self.uploadRequest];
        [task continueWithBlock:^id _Nullable(OSSTask * _Nonnull task) {
            NSError *error = task.error;
            if (error) {
                if (failureBlock) {
                    dispatch_sync(dispatch_get_main_queue(), ^{
                        failureBlock(error);
                    });
                }
            }else{
                if (successBlock) {
                    dispatch_sync(dispatch_get_main_queue(), ^{
                        NSMutableDictionary *uploadInfo = [NSMutableDictionary dictionary];
                        [uploadInfo setValue:filePath forKey:@"localPath"];
                        [uploadInfo setValue:self.uploadRequest.objectKey forKey:@"uploadPath"];
                        successBlock(uploadInfo);
                    });
                }
            }
            return nil;
        }];
    } failureBlock:^(id  _Nonnull error) {
        if (failureBlock) {
            failureBlock(error);
        }
    }];
}

- (void)cancleTask{
    @try {
        if (self.aliRequest) {
            [self.aliRequest cancel];
        }
        if (self.ctyRequest) {
            [self.ctyRequest cancel];
        }
        if (self.txRequest) {
            [self.txRequest cancel];
        }
        [[TGBaseIOTRequestService shareService] cancelAllOperations];
    } @catch (NSException *exception) {
        DDLogError(@"exception:%@", exception);
    } @finally {
        self.aliRequest = nil;
        self.ctyRequest = nil;
        self.txRequest = nil;
    }
}

#pragma mark  delegate

- (void)signatureWithFields:(QCloudSignatureFields *)fileds request:(QCloudBizHTTPRequest *)request urlRequest:(NSMutableURLRequest *)urlRequst compelete:(QCloudHTTPAuthentationContinueBlock)continueBlock{
    QCloudCredential *credential = [[QCloudCredential alloc] init];
    credential.secretID = self.accessId;
    credential.secretKey = self.accessKey;
    credential.token = self.securityToken;
    QCloudAuthentationV5Creator *creator = [[QCloudAuthentationV5Creator alloc] initWithCredential:credential];
    QCloudSignature *signature = [creator signatureForData:urlRequst];
    continueBlock(signature, nil);
}

#pragma mark set&get

- (OSSClient *)ossClient {
    return objc_getAssociatedObject(self, OssClient);
}

- (void)setOssClient:(OSSClient *)ossClient {
    objc_setAssociatedObject(self, OssClient, ossClient, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
- (OSSGetObjectRequest *)aliRequest {
    return objc_getAssociatedObject(self, AliRequest);
}

- (void)setAliRequest:(OSSGetObjectRequest *)aliRequest {
    objc_setAssociatedObject(self, AliRequest, aliRequest, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
- (OOSTransferManagerDownloadRequest *)ctyRequest {
    return objc_getAssociatedObject(self, CtyRequest);
}

- (void)setCtyRequest:(OOSTransferManagerDownloadRequest *)ctyRequest {
    objc_setAssociatedObject(self, CtyRequest, ctyRequest, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
- (QCloudCOSXMLDownloadObjectRequest *)txRequest {
    return objc_getAssociatedObject(self, TxRequest);
}

- (void)setTxRequest:(QCloudCOSXMLDownloadObjectRequest *)txRequest {
    objc_setAssociatedObject(self, TxRequest, txRequest, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
- (OSSPutObjectRequest *)uploadRequest {
    return objc_getAssociatedObject(self, UploadRequest);
}

- (void)setUploadRequest:(OSSPutObjectRequest *)uploadRequest {
    objc_setAssociatedObject(self, UploadRequest, uploadRequest, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end
