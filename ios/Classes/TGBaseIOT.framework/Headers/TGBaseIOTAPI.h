//
//  TGBaseIOTAPI.h
//  TGBaseIOT
//
//  Created by liubin on 2022/10/7.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TGCameraDeviceModel.h"
#import "TGDeviceServicePlansModel.h"
#import "TGPeripheralInfo.h"
#import "TGCameraDefine.h"
#import "TGCameraDeviceBaseInforModel.h"
#import "TGBaseIOTReportEventModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGBaseIOTAPI : NSObject

+ (instancetype)shareBaseIOTAPI;

/// 初始化SDK
/// - Parameters:
///   - appId: appid
- (void)tg_initWithAppId:(NSString *)appId;

/// 通过token和useid初始化账户
/// - Parameters:
///   - token: token
///   - userId: userid
- (void)tg_initWithToken:(NSString *)token userId:(NSString *)userId;

/// 设置AccessToken
- (void)tg_setToken:(NSString *)token;
/// 获取AccessToken
- (NSString *)tg_getUserToken;
/// 获取用户userId
- (NSString *)tg_getUserId;

#pragma mark - log

/// 启动log日志
- (void)tg_startLog;

#pragma mark - Language

/// 设置自定义语言
/// - Parameter string: 语言参数，若传空@""则恢复为跟随系统设置，其他参数为自定义
/// 注.语言参数请按照规定填写: en-us (美) zh-cn（中）zh-tw（中文繁体）ja(日) vi(越南) ko(韩) es(西班牙) pt(葡萄牙) ru(俄) tr(土耳其) de(德) it(意) fr(法) pl(波兰) th(泰)
- (void)tg_setLanguageString:(NSString *)string;

/// 获取语言参数
- (NSString *)tg_getLanguageString;

#pragma mark - push

/// 上报手机pushid（仅支持阿里云推送）
/// - Parameters:
///   - pushId: pushId
///   - channel: 推送渠道（目前仅支持"aliyun"）
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)initDevicePushId:(NSString *)pushId channel:(NSString *)channel successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - parameterConfiguration

/// 支持测试、发布、预发布三种环境 （客户接入一般不涉及环境切换）
/// - Parameter env: 环境枚举
- (void)tg_switchToEnvType:(TGBaseIOTServerEnvType)env;

#pragma mark - 公用API通道

/// 公用API通道
/// - Parameters:
///   - type: POST、GET、PAT、DELETE
///   - url: api 例如@“/v2/device-service/order”
///   - needToken: 是否需要accessToken
///   - params: 参数 NSMutableDictionary格式
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)requestWithType:(NSString *)type Url:(NSString *)url needToken:(BOOL)needToken params:(nullable id)params successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 下载公共API
/// - Parameters:
///   - url: 全路径
///   - params: 参数
///   - savePath: 保存地址
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_downloadFileWithUrl:(NSString *)url params:(nullable id)params savePath:(NSString *)savePath successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 上传公共API
/// - Parameters:
///   - url: 全路径
///   - fileData: 文件data
///   - name: 文件名称 @“file”
///   - fileName: 文件名称
///   - mimeType: text/plain
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_uploadFileWithUrl:(NSString *)url fileData:(NSData *)fileData name:(NSString *)name fileName:(NSString *)fileName mimeType:(NSString *)mimeType successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - addDevice

/// 每次添加设备请先 获取bindToken,
- (void)tg_getNewBindTokenCompleteBlock:(void(^)(BOOL success))success;

/// 检查AP是否可用（建议使用）
/// - Parameters:
///   - controller: 当前VC
///   - wifiArrayMsg: 未打开wifi提示 ,不传默认英文，格式[titile,message,confirm,cancel]
///   - netArrayMsg: 本地网络授权提示 ，不传默认英文，格式[titile,message,confirm,cancel]
///   - cancleCallback: 取消回调
///   - avaiableCallback: 可用回调
- (void)tg_checkBroadcastAvaiableWithController:(UIViewController *)controller wifiNotOPenArrayMsg:(NSArray *)wifiArrayMsg localNetwrokNotAuthArrayMsg:(NSArray *)netArrayMsg cancleCallback:(void(^)(void))cancleCallback avaiableCallback:(void(^)(void))avaiableCallback;

/// 查询AP是否可用(废弃)
/// @param controller 当前vc
/// @param cancleCallback 取消
/// @param avaiableCallback 可用返回
- (void)tg_checkBroadcastAvaiableWithController:(UIViewController *)controller cancleCallback:(void(^)(void))cancleCallback avaiableCallback:(void(^)(void))avaiableCallback;

/// 是否开启了本地权限
/// @param authcCallBack 返回授权
- (void)tg_isLocationAuthorizedWithCallBack:(void (^)(BOOL isAuthed))authcCallBack;

///去权限页面开启本地网络权限（建议使用）
/// @param controller vc
/// @param cancleCallback 返回授权
- (void)tg_locationNotAuthTipWithController:(UIViewController *)controller title:(NSString *)title message:(NSString *)message confirm:(NSString *)confirm cancel:(NSString *)cancel cancleCallback:(nullable void(^)(void))cancleCallback;

/// 获取AP热点或WiFi
- (void)tg_searchWiFiOrAP:(void(^)(BOOL isSuccess,NSString * __nullable ssid))ssidCallBack;

/// 手机连接AP设备(建议使用)
/// - Parameters:
///   - APSsid: AP热点
///   - hotSsid: 路由wifi名称
///   - hotSsidPassword：路由wifi密码
///   - complteBlock: 如果isHttp返回yes，可直接发起WiFIf轮询绑定，如果no，可使用TGIOTCameraDevice进行连接
- (void)tg_connectCameraWithAPSsid:(NSString *)ssid hotSsid:(NSString *)hotSsid hotSsidPassword:(NSString *)hotSsidPassword complteBlock:(void(^)(BOOL isHttp, TGCameraDeviceModel *deviceModel))complteBlock;

/// 手机连接AP设备(逐渐废弃)
/// - Parameters:
///   - ssid: AP热点
///   - complteBlock: 链接成功返回
- (void)tg_connectCameraWithSsid:(NSString *)ssid complteBlock:(void(^)(TGCameraDeviceModel *deviceModel))complteBlock;

- (void)tg_sendSetWifiInfoToDeviceWithIpAddress:(NSString *)ipAddress ssid:(NSString *)ssid password:(NSString *)password userId:(NSString *)userId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

- (void)tg_broadCastToPortComplteBlock:(void(^)(void))complteBlock receiveCallBlock:(BOOL(^)(NSString *receiveString))receiveCallBlock;

/// 生成配网二维码
/// @param name wifi名称
/// @param password wifi密码
/// @param userId 用户id
/// @param size 二维码图片大小
- (UIImage *)tg_createQRWithWiFiName:(NSString *)name WiFiPaasword:(NSString *)password userId:(NSString *)userId imageSize:(CGSize)size;

/// 扫描蓝牙设备
/// @param devicePrefix 名称前缀，设置后会搜索有该前缀的所有设备
/// @param listBlock 蓝牙设备列表
/// @param bluetoothStatueBlock 系统蓝牙开启状态
- (void)tg_searchBluetoothDevicesWithDevicePrefix:(NSString *)devicePrefix listBlock:(void(^)(NSMutableArray *result))listBlock bluetoothStatueBlock:(void(^)(BOOL isBuletoothAvailable))bluetoothStatueBlock;

/// 连接蓝牙
/// - Parameters:
///   - deviceModel: 蓝牙连接预备model
///   - serverUUID:【选填】 自定义serverUUID选项，需要与设备端配合使用，选填，不填将使用默认特征值
///   - writeUUID: 【选填】 自定义writeUUID选项，需要与设备端配合使用，选填，不填将使用默认特征值
///   - readUUID: 【选填】 自定义readUUID选项，需要与设备端配合使用，选填，不填将使用默认特征值
///   - connectCallBack: 连接结果
- (void)tg_connectBluetoothDevice:(TGPeripheralInfo *)deviceModel serverUUID:(NSString *)serverUUID writeUUID:(NSString *)writeUUID readUUID:(NSString *)readUUID connectCallBack:(void(^)(TGBluetoothConnectState state, NSError *error))connectCallBack;

/// 断开当前连接蓝牙设备
- (void)tg_disconnectBluetoothDevice;

/// 给蓝牙发送设备连接的WiFi名称和密码
/// @param wifiName 设备连接的WiFi名称
/// @param password 设备连接的WiFi密码
/// @param mtu 蓝牙一次发送数据的最大字节数
/// @param callBlock 发送回调，【注】result=yes时，response才会有结果，其他情况均为nil
- (void)tg_bluetoothConfigureNetwork:(NSString *)wifiName wifiPassword:(NSString *)password mtu:(NSInteger)mtu callBlock:(void(^)(BOOL result,SMsgAVIoctrlExPassWordResp *response))callBlock;

/// 停止扫描蓝牙设备
- (void)tg_stopScanPeripheral;

/// 轮询绑定WiFI设备 （注*要和取消轮询配合使用）
/// @param timeCount 轮询时长，默认150s
/// @param intervalTime 间隔时长，默认5s
/// @param processBlock 倒计时进度
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_configurationWiFiDeviceWithTime:(NSInteger)timeCount interval:(NSInteger)intervalTime processBlock:(void(^)(NSInteger processCount))processBlock successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 轮询绑定4G设备或有线设备 （注*要和取消轮询配合使用）
/// @param timeCount 轮询时长，默认150s
/// @param intervalTime 间隔时长，默认5s
/// @param processBlock 倒计时进度
/// @param uuidStr 设备uuid（deviceID）
/// @param successBlock 成功返回
/// @param failureBlock 失败返回 Code 51934 设备已绑定，其他失败
- (void)tg_configurationNoWiFiDeviceWithTime:(NSInteger)timeCount interval:(NSInteger)intervalTime uuid:(NSString *)uuidStr processBlock:(void(^)(NSInteger processCount))processBlock successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 轮询绑定4G设备或有线设备 （注*要和取消轮询配合使用）参数可选拓展
/// @param timeCount 轮询时长，默认150s
/// @param intervalTime 间隔时长，默认5s
/// @param uuidStr 设备uuid（deviceID）
/// @param deviceName 设备名称 -----可选参数
/// @param timeZone 设备时区 -----可选参数
/// @param typeStr 添加类型 分别为 scan(扫码添加)、4g(4g添加)、lan(有线添加)、device(配网添加) ---可选参数
/// @param must_be_online 设备是否需要必须在线  ----可选参数
/// @param must_be_actived 设备是否需要必须激活 -----可选参数
/// @param processBlock 进度
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_configurationNoWiFiDeviceWithTime:(NSInteger)timeCount interval:(NSInteger)intervalTime uuid:(NSString *)uuidStr name:(NSString *)deviceName timeZone:(NSString *)timeZone method:(NSString *)typeStr must_be_online:(BOOL)must_be_online must_be_actived:(BOOL)must_be_actived processBlock:(void(^)(NSInteger processCount))processBlock successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 取消轮询
- (void)tg_cancleConfigurationTimer;

/// 绑定4G设备 （非轮询，推荐使用轮询）
/// @param typeStr 添加类型 分别为 scan(扫码添加)、4g(4g添加)、lan(有线添加)、device(配网添加) ---可选参数
/// @param uuidStr uuid
/// @param deviceName deviceName 设备名称 -----可选参数
/// @param timeZone 设备时区 -----可选参数
/// @param must_be_online 设备是否需要必须在线  ----可选参数
/// @param must_be_actived 设备是否需要必须激活 -----可选参数
/// @param successBlock 成功回调
/// @param failureBlock 失败回调
- (void)tg_configurationNoWiFiDeviceWithType:(NSString *)typeStr uuid:(nonnull NSString *)uuidStr  name:(NSString *)deviceName timeZone:(NSString *)timeZone must_be_online:(BOOL)must_be_online must_be_actived:(BOOL)must_be_actived successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - information

/// 获取单个设备信息
/// @param deviceId 设备id
/// @param successBlock 成功
/// @param failureBlock 失败
- (void)tg_getOneDevicesInfoWith:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取指定页码指定数量的设备信息列表
/// @param offset  偏移量 与limit搭配使用，参考SQL语句：select * from table limit $offset, $limit;
/// @param limit 记录数  与offset搭配使用，参考SQL语句：select * from table limit $offset, $limit;
/// @param successBlock 成功
/// @param failureBlock 失败
- (void)tg_getDevicesListWithOffset:(NSInteger)offset limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 设置设备名称
/// @param deviceId 设备id
/// @param deviceName 设备名称
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_setDevicesNameWithDeviceId:(NSString *)deviceId name:(NSString *)deviceName successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

///设备解绑
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_unbindDeviceWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取设备时区
/// @param deviceId 设备id
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceTimeZone:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 设置设备时区
/// @param deviceId 设备id
/// @param time 时间 如：GMT+8:00
/// @param zone 时区 如:   Asia/Shanghai
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_setDeviceTimeZone:(NSString *)deviceId time:(NSString *)time zone:(NSString *)zone successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取设备封面 可支持批量获取
/// @param deviceId 设备id 批量获取 id用逗号分割
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceThumbnail:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备在线状态
/// @param deviceId 设备id
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceOnline:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备连接信息
/// @param deviceId 设备id
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceConnectInfor:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询iccid卡号
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_searchIccId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备基础信息(即将废弃)
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_getDeviceBasicInfo:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;


/// 查询设备基础信息(建议使用)
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: TGCameraDeviceBaseInforModel 基础信息model 成功回调
///   - failureBlock: 失败回调
- (void)tg_getDeviceBasicInfoModelWithDeviceId:(NSString *)deviceId successBlock:(void(^)(TGCameraDeviceBaseInforModel* result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备电量
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_getDeviceBatteryInfo:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - 固件升级

/// 查询设备升级信息
/// @param deviceId 设备id
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceUpgradeInfor:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 发送设备固件升级指令
/// @param deviceId 设备id
/// @param version 版本号
/// @param immediate_upgrade  .立即升级(immediate_upgrade=true)，要求设备在线，否则会报错,下次上线时自动升级(immediate_upgrade=false)，不要求设备在线
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_sendDeviceUpgrade:(NSString *)deviceId version:(NSString *)version immediate_upgrade:(BOOL)immediate_upgrade successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备固件升级结果
/// @param deviceId 设备id
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceUpgradeResult:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 轮询查询设备固件升级结果
/// @param deviceId 设备id
/// @param timeCount 总时长
/// @param interval 间隔
/// @param processBlock 进度返回
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceUpgradeResult:(NSString *)deviceId timeCount:(NSInteger)timeCount interval:(NSInteger)interval processBlock:(void(^)(NSInteger processCount))processBlock successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备固件升级结果
/// @param deviceId 设备id
/// @param version 查询目标版本
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceUpgradeResult:(NSString *)deviceId targetVersion:(NSString *)version successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 轮询查询设备固件升级结果
/// @param deviceId 设备id
/// @param timeCount 总时长
/// @param version 查询目标版本
/// @param interval 间隔
/// @param processBlock 进度返回
/// @param successBlock 成功返回
/// @param failureBlock 失败返回
- (void)tg_getDeviceUpgradeResult:(NSString *)deviceId targetVersion:(NSString *)version timeCount:(NSInteger)timeCount interval:(NSInteger)interval processBlock:(void(^)(NSInteger processCount))processBlock successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 取消固件升级轮询操作
- (void)tg_cancelUpgradeRollPoling;

#pragma mark - 增值服务 - 套餐

/// 查询服务商的套餐列表
/// - Parameters:
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_searchServiceListFromServiceProviderSuccessBlock:(void(^)(NSArray<TGDeviceServicePlansModel *> *result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询已购买的服务
/// - Parameters:
///   - deviceId: device_id与iccid二选一
///   - iccid: device_id与iccid二选一
///   - status: 0或不传返回全部，1已过期,2生效中,3待生效,4有效的(包含生效中、待生效)
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_searchBoughtServiceList:(NSString *)deviceId iccid:(NSString *)iccid status:(NSString *)status successBlock:(void(^)(NSArray<TGDeviceServiceModel *> *result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询指定订单的服务
/// - Parameters:
///   - merchant_number: 订单号
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_searchServiceFromOrderWithMerchantNumber:(NSString *)merchantNumber successBlock:(void(^)(TGDeviceServiceModel *result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - 增值服务 - 订单

/// 生成套餐订单
/// - Parameters:
///   - serviceId: 服务id
///   - deviceId: 设备id
///   - iccid: 物联网卡号，4g设备必须
///   - countryCode: 国家码
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_createServiceOrderWithServiceId:(NSInteger)serviceId deviceId:(NSString *)deviceId iccid:(NSString *)iccid countryCode:(NSString *)countryCode successBlock:(void(^)(TGDeviceOrderModel *result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 拉去订单列表
/// - Parameters:
///   - deviceId: 设备id，可选参数
///   - iccid: 物联网id，可选参数
///   - offset: 游标，从0开始，可选参数
///   - limit: 返回诗句行数，默认10
///   - successBlock: 成功回到
///   - failureBlock: 失败回调
- (void)tg_getOrderListDeviceId:(NSString *)deviceId iccid:(NSString *)iccid offset:(NSInteger)offset limit:(NSInteger)limit successBlock:(void(^)(NSArray<TGDeviceOrderModel *> *result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询订单信息
/// - Parameters:
///   - merchantNumber: 订单号
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_searchOrderInforWithMerchantNumber:(NSString *)merchantNumber successBlock:(void(^)(TGDeviceOrderModel *result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - share

/// 主人向指定账号分享分享设备
/// - Parameters:
///   - username: 用户名
///   - deviceId: 设备id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterShareDeviceWithUsername:(NSString *)username deviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 主人取消分享
/// - Parameters:
///   - deviceId: 设备id
///   - shareId:分享id
///   - type:分享类型 0预分享、1分享、2申请共享
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterCancelShareDeviceWithDeviceId:(NSString *)deviceId shareId:(NSString *)shareId type:(NSInteger)type successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 主人查询分享列表
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterGetShareListWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 主人获取分享码
/// - Parameters:
///   - deviceId: 设备id
///   - timeSec: 有效期 （秒）
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterGetShareCodeWithDeviceId:(NSString *)deviceId timeOut:(NSInteger)timeSec successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询分享码详细信息
/// - Parameters:
///   - code: 分享码
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getShareCodeInforWithCode:(NSString *)code successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 客人使用分享码
/// - Parameters:
///   - code: 分享码
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_guestUseShareCodeWithCode:(NSString *)code successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 客人退出分享
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_guestQuitShareWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 客人申请共享设备
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_guestApplyForDeviceShareWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 主人拒绝分享设备
/// - Parameters:
///   - shareId: 分享id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterRefuseDeviceShareWithShareId:(NSString *)shareId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 主人同意分享设备
/// - Parameters:
///   - shareId: 分享id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterAgreeDeviceShareWithShareId:(NSString *)shareId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 主人向指定用户ID分享设备
/// - Parameters:
///   - userId: 分享id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_masterShareDeviceToUserID:(NSInteger)userId deviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - cloudVideo&CloudEvent

/// 查询设备截图
/// - Parameters:
///   - deviceId: deviceId
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_getDeviceScreenshot:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取云录像列表（get请求）
/// - Parameters:
///   - deviceId: 设备id
///   - dateStr: 日期字符串 示例：2022-10-24
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getCloudVidesListWithDeviceId:(NSString *)deviceId date:(NSString *)dateStr successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取云事件列表
/// - Parameters:
///   - deviceId: 设备id
///   - dateStr: 日期字符串 示例：2022-10-24
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getCloudEventListWithDeviceId:(NSString *)deviceId date:(NSString *)dateStr tag:(NSArray *)tagArray offset:(NSInteger )offset limit:(NSInteger)limit successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备某天的云录像
/// - Parameters:
///   - deviceId: 设备id
///   - dateStr: 日期字符串 示例：2022-10-24
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getSomeDayCloudVideoListWithDeviceId:(NSString *)deviceId date:(NSString *)dateStr successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询设备某天的云事件
/// - Parameters:
///   - deviceId: 设备id
///   - dateStr: 日期字符串 示例：2022-10-24
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getSomeDayCloudEventListWithDeviceId:(NSString *)deviceId date:(NSString *)dateStr successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 按云事件Id获取云事件 （get请求）
/// - Parameters:
///   - eventId: 云事件id
///   - successBlock:成功返回
///   - failureBlock: 失败返回
- (void)tg_getCloudEventListWithCloudEventId:(NSString *)eventId  successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 按云事件id删除云事件(delete请求)
/// - Parameters:
///   - eventId: 云事件id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_deleteCloudEventListWithCloudEventId:(NSArray *)eventIdArray successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 按时间删除云事件
/// - Parameters:
///   - deviceId: 设备id
///   - startTime: 开始时间戳
///   - endTime: 结束时间戳
///   - successBlock: 成功
///   - failureBlock: 失败
- (void)tg_deleteCloudEventListWithDeviceId:(NSString *)deviceId startTime:(NSString *)startTime endTime:(NSString *)endTime  successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询事件推送开关 （get请求）
/// - Parameters:
///   - deviceId: deviceId
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getPushEventSwitcWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 查询事件标签列表 （POST请求）
/// - Parameters:
///   - deviceId: 设备id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getPushEventTagListWithDeviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 更新时间推送开关
/// - Parameters:
///   - deviceId: deviceId
///   - global_status: 全局开关
///   - tagArray: 需要推送的事件
///   - disturbanceStatus: 勿扰模式开关
///   - start: 开始时间 07:00
///   - end: 结束时间 22:00
///   - interval: 间隔时间
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_updatePushEventSwitcWithDeviceId:(NSString *)deviceId global_status:(BOOL)global_status tagArray:(NSArray *)tagArray disturbanceStatus:(BOOL)disturbanceStatus start:(NSString *)start end:(NSString *)end interval:(NSInteger)interval successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

#pragma mark - serviceAccess

/// (废弃) APP 场景控制
/// - Parameter deviceId: 设备id
//- (void)tg_deviceServiceAccess:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// （废弃） APP  控制点列表（get 请求）
/// - Parameters:
///   - uuid: uuid
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
//- (void)tg_getDeviceServiceAccess:(NSString *)uuid successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;


#pragma mark - user

/// 查询token信息
/// - Parameters:
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getUserTokenInforSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 第三方账户获取access_token
/// - Parameters:
///   - userId: 用户id
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getUserTokenWithUserId:(NSString *)userId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取验证码(内置了人机验证)
/// - Parameters:
///   - scene: 获取验证码场景，目前支持三种 ：第三方登录绑定账号(BIND)、注册账号(REGISTER)、忘记密码(FORGET)、门锁设置密码(door_lock_pwd)
///   - account: 账号或手机号
///   - areaCode: 区号（账号为手机时必传）
///   - token: 绑定令牌（绑定账号时必传）
///   - robotBackView: 承载人机校验的view（连续发短信超过次数，弹出图形验证码，不传可能造成黑屏）
///   - robotState:yes，开始校验，no校验结束
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getSendCodeWithScene:(NSString *)scene account:(NSString *)account areaCode:(NSString *)areaCode token:(NSString *)token robotBackView:(UIView *)robotBackView robotState:(void(^)(BOOL state))stateBlock successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取验证码
/// - Parameters:
///   - scene: 获取验证码场景，目前支持三种 ：第三方登录绑定账号(BIND)、注册账号(REGISTER)、忘记密码(FORGET)、门锁设置密码(door_lock_pwd)
///   - account: 账号或手机号
///   - areaCode: 区号（账号为手机时必传）
///   - token: 绑定令牌（绑定账号时必传）
///   - robot_check: 人机校验数据（连续发短信超过次数，弹出图形验证码）
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getSendCodeWithScene:(NSString *)scene account:(NSString *)account areaCode:(NSString *)areaCode token:(NSString *)token robot_check:(NSString *)robot_check successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 验证验证码
/// - Parameters:
///   - secne: 获取验证码场景，目前支持三种 ：第三方登录绑定账号(BIND)、注册账号(REGISTER)、忘记密码(FORGET)、门锁设置密码(door_lock_pwd)
///   - account: 账号或手机号
///   - code: 验证码
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_verificationCodeWithScene:(NSString *)scene account:(NSString *)account code:(NSString *)code successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;


/// 注册账户
/// - Parameters:
///   - account: 账号
///   - password: 密码
///   - verificationCode: 验证码
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_registerWithAccount:(NSString *)account password:(NSString *)password verificationCode:(NSString *)verificationCode area_code:(NSString *)areaCode countryCode:(NSString *)countryCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 登录
/// - Parameters:
///   - account: 账号
///   - password: 密码
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_loginWithAccount:(NSString *)account password:(NSString *)password area_code:(NSString *)area_code successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 重设密码
/// - Parameters:
///   - account: 账号
///   - password: 密码
///   - verificationCode: 验证码
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_resetPasswordWithAccount:(NSString *)account password:(NSString *)password verificationCode:(NSString *)verificationCode area_code:(NSString *)areaCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 获取用户信息
/// - Parameters:
///   - accessToken: token
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_getUserInforSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 修改登录密码
/// - Parameters:
///   - accessToken: token
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_changePasswordWithOldPassword:(NSString *)oldPassword newPassword:(NSString *)newPassword  successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 修改昵称
/// - Parameters:
///   - name: 名称
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_changeNameWithName:(NSString *)name successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 退出登录
/// - Parameters:
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_logoutSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 注销账号
/// - Parameters:
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_deleteAccountSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// apple登录
/// - Parameters:
///   - userIdToken: 用户标识id
///   - countryCode: 例如CN
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_loginWithAppleUserIdToken:(NSString *)userIdToken countryCode:(NSString *)countryCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// facebook登录
/// - Parameters:
///   - userIdToken: 用户标识id
///   - countryCode: 例如CN
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_loginWithFacebookUserIdToken:(NSString *)userIdToken countryCode:(NSString *)countryCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// google登录
/// - Parameters:
///   - accessToken:token
///   - userIdToken: 用户标识id
///   - countryCode: 例如CN
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_loginWithGoogleAccessToken:(NSString *)accessToken userIdToken:(NSString *)userIdToken countryCode:(NSString *)countryCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// line登录
/// - Parameters:
///   - accessToken:token
///   - userIdToken: 用户标识id
///   - countryCode: 例如CN
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_loginWithLineAccessToken:(NSString *)accessToken userIdToken:(NSString *)userIdToken countryCode:(NSString *)countryCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 微信登录
/// - Parameters:
///   - code: 微信登录返回的code 通过微信登陆后，获取到微信登陆返回的code，将该code传入该接口。1、如果该微信已经绑定过帐号，则返回该帐号对应的登陆令牌access_token。2、如果该微信尚未绑定过帐号，相当于新注册，则会返回用于 绑定新帐号 所需的bind_token
///   - countryCode: 例如CN
///   - successBlock: 成功返回
///   - failureBlock: 失败返回
- (void)tg_loginWithWeChatCode:(NSString *)code countryCode:(NSString *)countryCode successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 上报app日志
/// - Parameters:
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_uploadAppLogWithSuccessBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// 通用上报接口
/// - Parameters:
///   - time: 起始时间 时间戳1716810884 单位秒
///   - type: 类型 app_user_view
///   - logData: json字符串
///   - deviceId: 设备id
///   - successBlock: 成功
///   - failureBlock: 失败
- (void)tg_uploadCommonLogWithStartTime:(NSString *)time logType:(NSString *)type logData:(NSString *)logData deviceId:(NSString *)deviceId successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

/// app查询设备（日志，统计）上报开关
/// - Parameters:
///   - successBlock: 成功回调
///   - failureBlock: 失败回调
- (void)tg_getAppLogConfigWithSuccessBlock:(void(^)(TGBaseIOTReportEventConfigModel *result))successBlock failureBlock:(void(^)(id error))failureBlock;


@end

NS_ASSUME_NONNULL_END
