//
//  DAAudioUnitPCMPlayer.h
//  DAAudioVideo
//
//  Created by Darren on 2021/2/25.
//  Copyright © 2021 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DACameraP2PAudioData;

@interface DAAudioUnitPCMPlayer : NSObject

@property (nonatomic, assign, readonly) BOOL playing;
@property (nonatomic, assign, readonly) BOOL hasAudioPlaying;

- (void)playAudiohData:(DACameraP2PAudioData *)audio;
- (void)startPlay;
- (void)stopPlay;
- (void)voiceMute;
- (void)cancleMute;

@end

NS_ASSUME_NONNULL_END
