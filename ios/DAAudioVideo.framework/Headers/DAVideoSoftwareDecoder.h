//
//  DAVideoSoftwareDecoder.h
//  DAAudioVideo
//
//  Created by Darren on 2021/2/3.
//  Copyright © 2021 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DACameraP2PVideoData;

@interface DAVideoSoftwareDecoder : NSObject

- (BOOL)decodeVideoWithData:(DACameraP2PVideoData *)videoData;
- (void)cleanDecoder;

@end

NS_ASSUME_NONNULL_END
