//
//  TGDeviceInforRequestService.h
//  TGCamera
//
//  Created by liubin on 2022/9/28.
//
#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceInforRequestService : NSObject

/// 获取指定设备的信息
/// @param deviceId 设备号
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
+ (void)getOneDeviceInfoWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取规定的页码设备条数的设备信息列表
/// @param page 页码
/// @param limit 数据条数
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
+ (void)getDeviceListWithPage:(NSInteger)page limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取所有设备信息列表
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
+ (void)getAllDeviceListWithSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 设置设备名称
/// @param deviceId 设备id
/// @param deviceName 设备名称
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
+ (void)deviceSetNameWithDeviceId:(NSString *)deviceId deviceName:(NSString *)deviceName successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;


//获取某一设备某一天的所有云录像记录，2019-01-20
+ (void)getAllDeviceCloudRecordWithDateString:(NSString *)dateString timeZone:(NSString *)timeZone deviceId:(NSString *)deviceId order:(NSString *)order successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

+ (void)getLockDeviceUnlockTokenWithUuid:(NSString *)uuid successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;


/// 获取消息列表
/// - Parameters:
///   - deviceIds: 设备id集合
///   - msgTags: 设备类型
///   - startTime: 起始时间
///   - endTime: 结束时间
///   - page: 页码
///   - limit: 数据量
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
+ (void)queryAlarmMsgListWithDeviceIds:(NSString *)deviceIds msgTags:(NSString *)msgTags startTime:(NSString *)startTime endTime:(NSString *)endTime page:(NSInteger)page limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取消息列表
/// - Parameters:
///   - deviceId: 设备id
///   - msgTags: 设备类型
///   - startTime: 起始时间
///   - endTime: 结束时间
///   - page: 页码
///   - limit: 数据量
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
+ (void)queryAlarmMsgListWithDeviceId:(NSString *)deviceId msgTags:(NSString *)msgTags startTs:(NSInteger)startTs endTs:(NSInteger)endTs page:(NSInteger)page limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

+ (void)getOSSAccessTokenWithDeviceId:(NSString *)deviceId ossId:(NSString *)ossId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

+ (void)getUploadAppLogTokenWithSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

@end

NS_ASSUME_NONNULL_END
