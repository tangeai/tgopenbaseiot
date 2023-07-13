//
//  DACustomQueue.h
//  DAAudioVideo
//
//  Created by Darren on 2020/6/2.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DACustomQueue <__covariant ObjectType> : NSObject

- (void)clear;
- (NSInteger)size;
- (BOOL)isEmpty;
- (void)enQueueWithObject:(ObjectType)object;
- (ObjectType)dequeue;
- (ObjectType)front;

@end

NS_ASSUME_NONNULL_END
