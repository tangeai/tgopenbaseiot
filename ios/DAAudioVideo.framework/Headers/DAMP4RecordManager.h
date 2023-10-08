//
//  DAMP4RecordManager.h
//  DAAudioVideo
//
//  Created by Darren on 2021/6/3.
//  Copyright © 2021 Darren. All rights reserved.
//

#import <UIKit/UIkit.h>

NS_ASSUME_NONNULL_BEGIN

@class DACameraP2PVideoData,DACameraP2PAudioData;

@interface DAMP4RecordManager : NSObject

@property (nonatomic, assign, readonly) BOOL isRecording;
@property (nonatomic, assign) NSInteger minRecordTime;//默认最短录像时长1s
@property (nonatomic, copy) void(^stopRecordCallback)(NSString *filePath);

- (void)startRecordWithFileName:(NSString *)fileName;
- (void)stopRecordWithVideoPath:(nullable void(^)(NSString *filePath))callBack;

- (BOOL)writeVideoData:(DACameraP2PVideoData *)videoData;
- (BOOL)writeAudioData:(DACameraP2PAudioData *)audioData;

@end

NS_ASSUME_NONNULL_END
