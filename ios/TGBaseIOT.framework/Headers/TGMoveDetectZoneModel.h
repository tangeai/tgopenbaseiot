//
//  TGMoveDetectZoneModel.h
//  TGIOT
//
//  Created by Darren on 2020/3/2.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGMoveDetectZoneModel : NSObject

@property (nonatomic, assign) int left;
@property (nonatomic, assign) int top;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int centerX;
@property (nonatomic, assign) int centerY;
@property (nonatomic, assign) BOOL isSelect;

@end

NS_ASSUME_NONNULL_END
