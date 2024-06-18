//
//  TGCameraDeviceBaseInforModel.h
//  TGBaseIOT
//
//  Created by liubin on 2024/5/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGCameraDeviceBaseInforModel : NSObject

@property (nonatomic, copy) NSString *device_category_key;          // 种类
@property (nonatomic, assign) NSInteger sdk_version;                // 设备SDK的版本
@property (nonatomic, copy) NSString *firmware_id;                  // 固件标识
@property (nonatomic, copy) NSString *firmware_version;             // 固件版本
@property (nonatomic, copy) NSString *category;                     // 目数
@property (nonatomic, copy) NSString *network;                      // 网络类型 sim wifi
@property (nonatomic, copy) NSString *os;                           // 系统
@property (nonatomic, copy) NSString *power;                        // 用电类型 无代表长电 battery电池

+ (instancetype)modelWithDeviceBaseInfo:(NSDictionary *)deviceInfo;

@end

NS_ASSUME_NONNULL_END
