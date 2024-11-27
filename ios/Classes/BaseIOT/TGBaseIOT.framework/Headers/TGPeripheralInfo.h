//
//  TGPeripheralInfo.h
//  HKBabyBluetooth
//
//  Created by 刘华坤 on 2019/3/15.
//  Copyright © 2018年 liuhuakun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BabyBluetooth/BabyBluetooth.h>

@interface TGPeripheralInfo : NSObject

@property (nonatomic, copy) NSString *name;                     // 设备的名称
@property (nonatomic, strong) NSNumber *RSSI;                   // 设备的信号强度
@property (nonatomic, strong) CBPeripheral *peripheral;         // 远程的 BLE 设备
@property (nonatomic, strong) NSDictionary *advertisementData;  // BLE 广播包中的附加数据

@end
