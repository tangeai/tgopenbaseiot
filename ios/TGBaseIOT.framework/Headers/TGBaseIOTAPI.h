//
//  TGBaseIOTAPI.h
//  Pods-TGBaseIOT_Example
//
//  Created by liubin on 2022/10/7.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TGCameraDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGBaseIOTAPI : NSObject

+ (instancetype)shareBaseIOTAPI;

- (void)tg_initWithToken:(NSString *)token userId:(NSString *)userId;

- (NSString *)tg_getUserToken;
- (NSString *)tg_getUserId;


#pragma mark - log

/// 启动log日志
- (void)tg_startLog;

#pragma mark - addDevice

/// 仅在两种情况下存在token  配网二维码设置后，连接Ap热点后；其他情况返回@“”；
- (NSString *)tg_getBindToken;

/// 查询设备类型
/// @param uuidStr 设备uuid
/// @param successBlock 成功后返回
/// @param failureBlock 失败后返回
- (void)tg_searchDeviceType:(NSString *)uuidStr successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询AP是否可用
/// @param controller 当前vc
/// @param cancleCallback 取消
/// @param avaiableCallback 可用返回
- (void)tg_checkBroadcastAvaiableWithController:(UIViewController *)controller cancleCallback:(void(^)(void))cancleCallback avaiableCallback:(void(^)(void))avaiableCallback;

/// 是否开启了本地权限
/// @param authcCallBack 返回授权
- (void)tg_isLocationAuthorizedWithCallBack:(void (^)(BOOL isAuthed))authcCallBack;

///去权限页面开启本地网络权限
/// @param controller vc
/// @param cancleCallback 返回授权
- (void)tg_locationNotAuthTipWithController:(UIViewController *)controller title:(NSString *)title message:(NSString *)message cancleCallback:(nullable void(^)(void))cancleCallback;

/// 获取AP热点或WiFi
- (void)tg_searchWiFiOrAP:(void(^)(BOOL isSuccess,NSString * __nullable ssid))ssidCallBack;


/// 手机连接AP设备
/// - Parameters:
///   - ssid: AP热点
///   - complteBlock: 链接成功返回
- (void)tg_connectCameraWithSsid:(NSString *)ssid  complteBlock:(void(^)(TGCameraDeviceModel *deviceModel))complteBlock;

/// 手机连接AP设备
/// - Parameters:
///   - broadcastPort: 端口
///   - sendString: <#sendString description#>
///   - complteBlock: 完成
///   - receiveCallBlock: 接收回调
- (void)tg_broadCastToPortComplteBlock:(void(^)(void))complteBlock receiveCallBlock:(BOOL(^)(NSString *receiveString))receiveCallBlock;

/// http绑定AP设备
/// @param ipAddress ip地址
/// @param ssid wifi
/// @param password wifi密码
/// @param userId 用户id
/// @param successBlock 成功
/// @param failureBlock 失败
- (void)tg_sendSetWifiInfoToDeviceWithIpAddress:(NSString *)ipAddress ssid:(NSString *)ssid password:(NSString *)password userId:(NSString *)userId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 生成配网二维码
/// @param name wifi名称
/// @param password wifi密码
/// @param userId 用户id
/// @param size 二维码图片大小
- (UIImage *)tg_createQRWithWiFiName:(NSString *)name WiFiPaasword:(NSString *)password userId:(NSString *)userId imageSize:(CGSize)size;

/// 绑定WiFI设备
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_configurationWiFiDeviceWithWiFiSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 绑定4G设备或有线设备
/// @param typeStr 查询类型 目前支持两种类型 "lan"（连线绑定）,"scan"（扫码绑定）两种，不传默认为scan
/// @param uuidStr 设备uuid类型
/// @param successBlock 成功返回
/// @param failureBlock 失败返回 Code 51934 设备已绑定，其他失败
- (void)tg_configurationNoWiFiDeviceWithType:(NSString *)typeStr uuid:(NSString *)uuidStr successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;


#pragma mark - information

/// 获取单个设备信息
/// @param deviceId 设备id
/// @param successBlock 成功
/// @param failureBlock 失败
- (void)tg_getOneDevicesInfoWith:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取指定页码指定数量的设备信息列表
/// @param page 页码
/// @param limit 设备数
/// @param successBlock 成功
/// @param failureBlock 失败
- (void)tg_getDevicesListWithPage:(NSInteger)page limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取所有设备信息列表
- (void)tg_getAllDevicesListSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 设置设备名称
/// @param deviceId 设备id
/// @param deviceName 设备名称
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_setDevicesNameWithDeviceId:(NSString *)deviceId name:(NSString *)deviceName successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取设备消息列表
/// - Parameters:
///   - deviceIds: 设备id集合
///   - msgTags: 设备类型
///   - startTime: 起始时间
///   - endTime: 结束时间
///   - page: 页码
///   - limit: 数据量
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_queryAlarmMsgListWithDeviceIds:(NSString *)deviceIds msgTags:(NSString *)msgTags startTime:(NSString *)startTime endTime:(NSString *)endTime page:(NSInteger)page limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取设备消息列表
/// - Parameters:
///   - deviceId: 设备id
///   - msgTags: 设备类型
///   - startTime: 起始时间
///   - endTime: 结束时间
///   - page: 页码
///   - limit: 数据量
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_queryAlarmMsgListWithDeviceId:(NSString *)deviceId msgTags:(NSString *)msgTags startTs:(NSInteger)startTs endTs:(NSInteger)endTs page:(NSInteger)page limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

@end

NS_ASSUME_NONNULL_END
