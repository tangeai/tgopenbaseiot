//
//  TGSocketIOManager.h
//  TGIOT
//
//  Created by Darren on 2019/5/28.
//  Copyright © 2019 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGSocketIOManager : NSObject

+ (instancetype)shareManager;
- (void)startSocketIO;
- (void)disconnectSocketIO;
- (void)sendMsgWithFuncName:(NSString *)funcName message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
