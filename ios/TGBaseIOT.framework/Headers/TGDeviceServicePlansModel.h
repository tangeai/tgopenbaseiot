//
//  TGDeviceServicePlansModel.h
//  TGBaseIOT
//
//  Created by liubin on 2023/6/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TGDeviceCloudStorageModel;
@class TGDeviceAIAbilityModel;
@class TGDeviceMobileDataAbilityModel;
@class TGDeviceSmartBoxAbilityModel;
@class TGDeviceAbilityModel;

// 套餐
@interface TGDeviceServicePlansModel : NSObject

@property (nonatomic, copy) NSString *service_id;                   // 套餐ID
@property (nonatomic, copy) NSString *product_id;                   // 套餐产品ID
@property (nonatomic, copy) NSString *name;                         // 套餐名称
@property (nonatomic, copy) NSNumber *price;                        // 套餐价格
@property (nonatomic, copy) NSString *currency_code;                // 货币单位
@property (nonatomic, copy) NSString *country_code;                 // 国家代码
@property (nonatomic, strong) TGDeviceAbilityModel *ability;        // 套餐能力
@property (nonatomic, copy) NSString *level;                        // 套餐级别
@property (nonatomic, copy) NSString *version_name;                 // 套餐版本名称
@property (nonatomic, copy) NSString *period;                       // 套餐时长

@end

// 服务
@interface TGDeviceServiceModel : NSObject

@property (nonatomic, assign) NSInteger id;                         // 服务ID
@property (nonatomic, copy) NSString *device_id;                    // 设备ID
@property (nonatomic, copy) NSString *iccid;                        // 物联网卡号
@property (nonatomic, assign) NSInteger product_id;                 // 套餐产品id
@property (nonatomic, assign) NSInteger service_id;                 // 套餐id
@property (nonatomic, strong) TGDeviceAbilityModel *ability;        // 服务能力
@property (nonatomic, assign) NSInteger level;                      // 服务级别
@property (nonatomic, assign) BOOL is_free;                         // 是否是免费服务 0否、1是
@property (nonatomic, assign) NSInteger status;                     // 套餐状态 0正常、1已冻结
@property (nonatomic, assign) NSInteger frozen_time;                // 冻结时间戳
@property (nonatomic, assign) NSInteger start_time;                 // 服务开始时间戳
@property (nonatomic, assign) NSInteger end_time;                   // 服务结束时间戳
@property (nonatomic, assign) NSInteger create_at;                  // 数据插入时间戳

@end

// 套餐能力
@interface TGDeviceAbilityModel : NSObject

@property (nonatomic, strong) TGDeviceCloudStorageModel *storage;           //云录像存储
@property (nonatomic, strong) TGDeviceAIAbilityModel *ai;                   //ai能力
@property (nonatomic, strong) TGDeviceMobileDataAbilityModel *mobile_data;      //移动数据
@property (nonatomic, strong) TGDeviceSmartBoxAbilityModel *smart_box;       //智能音箱

@end

// 套餐-云录像
@interface TGDeviceCloudStorageModel : NSObject

@property (nonatomic, copy) NSString *recording_mode;               // 录制模式 INCIDENT（全时）、CONTINUOUS（事件）
@property (nonatomic, copy) NSArray *recording_content;             // 录制内容 "IMAGE","VIDEO"
@property (nonatomic, assign) NSInteger recording_ahead;            // 预录时长 5
@property (nonatomic, assign) NSInteger recording_duration;        // 录制时长 30
@property (nonatomic, assign) NSInteger recording_image_max;       // 最多录制图片数量
@property (nonatomic, assign) NSInteger recording_image_span;      // 两张图片至少间隔
@property (nonatomic, assign) NSInteger keep_days;                 // 保存时长

@end

// 套餐-智能识别
@interface TGDeviceAIAbilityModel : NSObject

@property (nonatomic, copy) NSArray * algorithm;                    // 支持的算法 "body","pet","livestocks","car","bird"

@end

// 套餐-移动数据
@interface TGDeviceMobileDataAbilityModel : NSObject

@property (nonatomic, copy) NSString *traffic_limit;                // 流量限制 -1(无限流量)、0(无流量)、20(20M)、10240(1G)
@property (nonatomic, copy) NSString *limit_mode;                   // 限制模式 month(分月)、entirety(整包)

@end

// 套餐-智能音箱
@interface TGDeviceSmartBoxAbilityModel : NSObject

@property (nonatomic, copy) NSArray *supported_smart_box;           //支持的智能音箱  "echo-show","google-home"

@end

// 订单
@interface TGDeviceOrderModel : NSObject

@property (nonatomic, copy) NSString *merchant_number;              // 平台订单号
@property (nonatomic, copy) NSString *payment_method;               // 支付方式
@property (nonatomic, copy) NSString *status;                       // 订单状态 0待支付、1支付处理中、2支付完成、3支付失败、4退款中、5退款失败、6已退款
@property (nonatomic, assign) NSInteger create_at;                 // 下单时间 unix时间戳，如1675785868
@property (nonatomic, copy) NSString *device_id;                    // 设备id
@property (nonatomic, copy) NSString *iccid;                        // 物联网卡号
@property (nonatomic, assign) NSInteger user_id;                   // 用户账号
@property (nonatomic, copy) NSNumber *fee_amount;                   // 服务金额
@property (nonatomic, copy) NSString *currency_code;                // 货币单位
@property (nonatomic, copy) NSString *amount;                       // 订单金额

@end

NS_ASSUME_NONNULL_END
