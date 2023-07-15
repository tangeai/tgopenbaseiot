//
//  TGOSSCloudData.h
//  TGIOT
//
//  Created by Darren on 2020/5/15.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSCloudData : NSObject

@property (nonatomic, strong, nullable) NSData *streamData;
@property (nonatomic, assign) NSInteger timeInterval;
@property (nonatomic, assign) NSInteger utcTimeStamp;
@property (nonatomic, assign) BOOL isFirstData;
@property (nonatomic, assign) BOOL isLastData;
@property (nonatomic, assign) NSInteger sessionId;

@end

NS_ASSUME_NONNULL_END
