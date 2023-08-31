//
//  DAVideoHardwareDecoder.h
//  DAAudioVideo
//
//  Created by Darren on 2020/11/13.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DACameraP2PVideoData;

@interface DAVideoHardwareDecoder : NSObject

- (BOOL)decodeVideoWithData:(DACameraP2PVideoData *)videoData;
- (void)cleanDecoder;

@end

NS_ASSUME_NONNULL_END
