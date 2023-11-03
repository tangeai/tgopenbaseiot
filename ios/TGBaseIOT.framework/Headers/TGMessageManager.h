//
//  TGMessageManager.h
//  TGIOT
//
//  Created by liubin on 2022/7/21.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TGMessageUrlDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TGMessageManager : NSObject

@property (nonatomic, strong) NSMutableDictionary *messageDic;

+ (instancetype)sharedMessageManager;

// 根据uuid查询未读状态
- (NSInteger)unreadMessageWithUuid:(NSString *)uuid;

// 根据uuid查询URL
- (NSString *)urlWithUuid:(NSString *)uuid;

// 根据uuid查询是否有客服入口
- (BOOL)hasServiceAgentWithUuid:(NSString *)uuid;

// 根据uuid清除红点
- (BOOL)clearUnreadMessageWithUuid:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
