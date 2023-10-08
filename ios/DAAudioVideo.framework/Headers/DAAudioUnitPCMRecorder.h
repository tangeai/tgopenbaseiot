//
//  DAAudioUnitPCMRecorder.h
//  DAAudioVideo
//
//  Created by Darren on 2021/7/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DAAudioConfigModel;

@protocol DAAudioUnitPCMRecorderDelegate <NSObject>

@optional
- (void)audioUnitPCMRecorderDidRecordWithPCMData:(void *)data length:(unsigned int)length;
- (void)audioUnitPCMRecorderDidRecordWithG711AData:(void *)data length:(unsigned int)length;
- (void)audioUnitPCMRecorderDidStopRecordWithFilePath:(NSString *)filePath;

@end

@interface DAAudioUnitPCMRecorder : NSObject

@property (nonatomic, weak) id <DAAudioUnitPCMRecorderDelegate>delegate;
@property (nonatomic, assign) BOOL isRecording;
@property (nonatomic, strong) DAAudioConfigModel *config;

- (void)startRecord;
- (void)startReordWithFileName:(NSString * _Nullable)fileName;
- (void)startRecordWithConfig:(DAAudioConfigModel * _Nullable)config fileName:(NSString * _Nullable)fileName;
- (void)stopRecord;

@end

NS_ASSUME_NONNULL_END
