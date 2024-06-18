//
//  TGMoveDetectPolygonModel.h
//  TGBaseIOT
//
//  Created by Darren on 2022/11/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TGMoveDetectPointModel;

@interface TGMoveDetectPolygonModel : NSObject

@property (nonatomic, assign) int index;
@property (nonatomic, assign) int nPoints;
@property (nonatomic, strong) NSMutableArray <TGMoveDetectPointModel *>*pointsArray;

+ (instancetype)modelWithPolygonInfo:(NSDictionary *)polygonInfo;

@end

NS_ASSUME_NONNULL_END
