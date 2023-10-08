//
//  DAAudioSessionManager.h
//  DAAudioVideo
//
//  Created by Darren on 2022/3/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DACameraP2PAudioData,DAAudioConfigModel;

@protocol DAAudioSessionManagerDelegate <NSObject>

- (void)audioSessionManagerDidRecordWithData:(void *)data length:(unsigned int)length config:(DAAudioConfigModel *)config;

@end

@interface DAAudioSessionManager : NSObject

@property (nonatomic, assign, readonly) BOOL playing;
@property (nonatomic, assign, readonly) BOOL speaking;
@property (nonatomic, assign, readonly) BOOL hasAudioPlaying;

@property (nonatomic, assign) CGFloat voiceRaiseRate;
@property (nonatomic, weak) id <DAAudioSessionManagerDelegate>delegate;

- (void)playAudiohData:(DACameraP2PAudioData *)audio;
- (void)startPlay;
- (void)stopPlay;

- (void)startSpeakWithConfig:(DAAudioConfigModel *)config;
- (void)stopSpeak;

@end

NS_ASSUME_NONNULL_END
