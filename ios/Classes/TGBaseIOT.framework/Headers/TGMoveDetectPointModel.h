//
//  TGMoveDetectPointModel.h
//  TGBaseIOT
//
//  Created by Darren on 2021/8/4.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGMoveDetectPointModel : NSObject

@property (nonatomic, assign) int x;
@property (nonatomic, assign) int y;
@property (nonatomic, assign) int index;

+ (instancetype)modelWithPointInfo:(NSDictionary *)pointInfo;

@end

NS_ASSUME_NONNULL_END
