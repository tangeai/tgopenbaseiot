//
//  TGIOTCommandModel.h
//  TGIOT
//
//  Created by Darren on 2021/8/13.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGIOTCommandModel : NSObject

@property (nonatomic, assign) int cmdType;
@property (nonatomic, assign, nullable) char *buffer;
@property (nonatomic, assign) int bufferSize;

@end

NS_ASSUME_NONNULL_END
