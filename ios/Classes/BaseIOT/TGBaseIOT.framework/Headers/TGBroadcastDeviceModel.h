//
//  TGBroadcastDeviceModel.h
//  TGBaseIOT
//
//  Created by Darren on 2019/7/2.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGBroadcastDeviceModel : NSObject

@property (nonatomic, copy) NSString *model;
@property (nonatomic, copy) NSString *snString;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, copy) NSString *ipAddress;
@property (nonatomic, copy) NSString *netmark;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *sdkver;
@property (nonatomic, copy) NSString *deviceType;
@property (nonatomic, copy) NSString *p2pId;
@property (nonatomic, copy) NSString *fwId;
@property (nonatomic, copy) NSString *mac;
@property (nonatomic, copy) NSString *uptime;
@property (nonatomic, copy) NSString *setWifi;

@property (nonatomic, assign) BOOL isSelected;

+ (instancetype)modelWithString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
