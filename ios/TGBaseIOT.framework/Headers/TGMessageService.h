//
//  TGMessageService.h
//  TGIOT
//
//  Created by liubin on 2022/7/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGMessageService : NSObject

+ (void)getMessage:(NSArray *)uuidArray successBlock:(void(^)(id result))successBlock failureBlock:(void(^)(id error))failureBlock;

@end

NS_ASSUME_NONNULL_END
