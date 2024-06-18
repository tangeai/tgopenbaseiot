//
//  TGObjectStorageService+CloudService.h
//  TGBaseIOT
//
//  Created by liubin on 2024/6/18.
//

#import <TGBaseIOT/TGObjectStorageService.h>
#import <QCloudCOSXML/QCloudCOSXML.h>
#import <AliyunOSSiOS/AliyunOSSiOS.h>
#import <OOS/OOS.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGObjectStorageService (CloudService)<QCloudSignatureProvider>
@property (nonatomic, strong) OSSClient *ossClient;
@property (nonatomic, strong) OSSGetObjectRequest *aliRequest;
@property (nonatomic, strong) OOSTransferManagerDownloadRequest *ctyRequest;
@property (nonatomic, strong) QCloudCOSXMLDownloadObjectRequest *txRequest;
@property (nonatomic, strong) OSSPutObjectRequest *uploadRequest;

@end

NS_ASSUME_NONNULL_END
