//
//  TGIOTCameraManagerDelegate.h
//  TGBaseIOT
//
//  Created by Darren on 2023/2/27.
//

#import <Foundation/Foundation.h>
#import <TGBaseIOT/TGBaseIOTDefine.h>
#import <Foundation/Foundation.h>
#import "TGCameraDeviceModel.h"
#import "TGCameraDefine.h"
#import "TGBaseIOTDefine.h"
#import <DAAudioVideo/DAAudioVideo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TGDataChannelType) {
    TGDataChannelType_Command                 = 0x00, //设备命令通道
    TGDataChannelType_LiveVideoChannelZero    = 0x01, //实时视频通道
    TGDataChannelType_LiveVideoChannelOne     = 0x02, //实时画中画通道
    TGDataChannelType_LiveAudio               = 0x03, //实时音频通道
    TGDataChannelType_LiveSpeak               = 0x04, //实时对讲通道
    TGDataChannelType_SDCardVideo             = 0x05, //回放视频通道
    TGDataChannelType_SDCardAudio             = 0x06, //回放音频通道
};

typedef void(^SDCardRecordListBlock)(const char * __nullable data,int ctrolType,int errorCode);

@class TGIOTCameraManager,TGCameraDeviceModel,TGResolutionModel,TGIOTCommandModel;

@protocol TGIOTCameraManagerDelegate <NSObject>

@optional
- (void)manager:(TGIOTCameraManager *)manager didConnectSessionStatusChanged:(TGConnectSessionStatus)sessionStatus;
- (void)manager:(TGIOTCameraManager *)manager didReceiveIOCtrlWithType:(NSInteger)type Data:(const char *)data DataSize:(NSInteger)size;

- (void)manager:(TGIOTCameraManager *)manager didPlayCameraLiveVideo:(DACameraP2PVideoData *)videoData;
- (void)manager:(TGIOTCameraManager *)manager didPlayCameraSDCardVideo:(DACameraP2PVideoData *)videoData;

- (void)manager:(TGIOTCameraManager *)manager didLiveVideoBpsUpdateWithBitRate:(unsigned int)bitRate frameRate:(unsigned int)frameRate;

- (void)manager:(TGIOTCameraManager *)manager didRecordWithRecordType:(TGVideoRecordType)type second:(NSInteger)second;
- (void)manager:(TGIOTCameraManager *)manager didStopRecordWithRecordType:(TGVideoRecordType)type filePath:(NSString * _Nonnull)filePath;

@end

@interface TGIOTCameraManager : NSObject

@property (nonatomic, weak) id<TGIOTCameraManagerDelegate> delegate;
@property (nonatomic, copy) void (^receiveCtrolCallBack) (int ctrolType, int errorCode);
@property (nonatomic, copy) void (^sendCtrolCallBack) (int ctrolType, int errorCode);
@property (nonatomic, strong) TGCameraDeviceModel *device;
@property (nonatomic, copy, nullable) void(^connectCallback)(TGConnectSessionStatus sessionStatus);
@property (nonatomic, copy) SDCardRecordListBlock recordListCallBlock;
@property (nonatomic, assign) TGConnectSessionStatus sessionStatus;
@property (nonatomic, assign) TGDeviceConnectMode connectMode;
@property (nonatomic, assign) BOOL isNeedReconnect;
@property (nonatomic, assign) NSInteger maxReconnectCount;
@property (nonatomic, strong) dispatch_source_t connectTimer;

@property (nonatomic, assign) BOOL isDeviceConnected;
@property (nonatomic, assign) BOOL isDeviceConnecting;
@property (nonatomic, assign) BOOL isDeviceReConnecting;
@property (nonatomic, assign) NSInteger reconnectedCount;
@property (nonatomic, assign) NSInteger maxPwdCheckCount;
@property (nonatomic, assign) NSInteger passwordCheckCount;

@property (nonatomic, assign) BOOL isChannelZeroSwitchingCamera;
@property (nonatomic, assign) BOOL isChannelOneSwitchingCamera;
@property (nonatomic, assign) BOOL isChannelZeroReceiveFlagFrame;
@property (nonatomic, assign) BOOL isChannelOneReceiveFlagFrame;
@property (nonatomic, assign) BOOL isChannelZeroStepOneComplete;
@property (nonatomic, assign) BOOL isChannelOneStepOneComplete;

@property (nonatomic, assign) BOOL isRecordVideo;
@property (nonatomic, assign) TGVideoRecordType recordType;
@property (nonatomic, assign) NSInteger firstVideoTimeStamp;
@property (nonatomic, assign) NSInteger firstAudioTimeStamp;
@property (nonatomic, assign) NSInteger lastVideoTimeStamp;
@property (nonatomic, assign) NSInteger lastAudioTimeStamp;
@property (nonatomic, strong, nullable) DAMP4RecordManager *mp4Recorder;
@property (nonatomic, strong) DAAudioSessionManager *liveAudioManager;
@property (nonatomic, strong) DAAudioUnitPCMPlayer *sdcardAudioPlayer;

@property (nonatomic, assign) BOOL isSendingAudioToDevice;

@property (nonatomic, assign) BOOL isPlayLiveChannelZeroVideo;
@property (nonatomic, assign) BOOL isLiveChannelZeroFindIFrame;
@property (nonatomic, strong) NSLock *liveChannelZeroVideoLock;
@property (nonatomic, strong) NSThread *playLiveChannelZeroVideoThread;
@property (nonatomic, strong) DACustomQueue *liveChannelZeroVideoQueue;

@property (nonatomic, assign) BOOL isPlayLiveChannelOneVideo;
@property (nonatomic, assign) BOOL isLiveChannelOneFindIFrame;
@property (nonatomic, strong) NSLock *liveChannelOneVideoLock;
@property (nonatomic, strong) NSThread *playLiveChannelOneVideoThread;
@property (nonatomic, strong) DACustomQueue *liveChannelOneVideoQueue;

@property (nonatomic, assign) BOOL isPlayCameraLiveAudio;
@property (nonatomic, strong) NSLock *liveAudioLock;
@property (nonatomic, strong) NSThread *playLiveAudioThread;
@property (nonatomic, strong) DACustomQueue *liveAudioQueue;

@property (nonatomic, strong) NSLock *sdcardSelectTimeLock;
@property (nonatomic, strong) NSMutableArray *sdcardSelectTimeArray;

@property (nonatomic, assign) BOOL isPlaySDCardChannelZeroVideo;
@property (nonatomic, assign) BOOL isSDCardChannelZeroFindIFrame;
@property (nonatomic, strong) NSLock *sdcardChannelZeroVideoLock;
@property (nonatomic, strong) NSThread *playSDCardChannelZeroVideoThread;
@property (nonatomic, strong) DACustomQueue *sdcardChannelZeroVideoQueue;

@property (nonatomic, assign) BOOL isPlaySDCardChannelOneVideo;
@property (nonatomic, assign) BOOL isSDCardChannelOneFindIFrame;
@property (nonatomic, strong) NSLock *sdcardChannelOneVideoLock;
@property (nonatomic, strong) NSThread *playSDCardChannelOneVideoThread;
@property (nonatomic, strong) DACustomQueue *sdcardChannelOneVideoQueue;

@property (nonatomic, assign) BOOL isPlayCameraSDCardAudio;
@property (nonatomic, strong) NSLock *sdcardAudioLock;
@property (nonatomic, strong) NSThread *playSDCardAudioThread;
@property (nonatomic, strong) DACustomQueue *sdcardAudioQueue;
@property (nonatomic, assign) TGCameraPlaySpeedLevel speedLevel;

@property (nonatomic, strong) NSDate *startConnectDate;
@property (nonatomic, strong) NSDate *connectSuccessDate;
@property (nonatomic, strong) NSDate *connectFailedDate;
@property (nonatomic, strong) NSDate *sendPasswordDate;
@property (nonatomic, strong) NSDate *receivePasswordDate;
@property (nonatomic, strong) NSDate *sendStartLiveDate;
@property (nonatomic, strong) NSDate *receiveFirstFrameDate;

@property (nonatomic, assign) NSTimeInterval liveStartTs;
@property (nonatomic, assign) NSTimeInterval liveLastReadTs;
@property (nonatomic, assign) NSTimeInterval liveStickTime;
@property (nonatomic, assign) unsigned int liveStickCount;


- (instancetype)initWithDevice:(TGCameraDeviceModel *)device;
- (void)connectDevice;
- (void)connectFailed;
- (void)connectFailedWithResult:(int)result;
- (void)checkCameraPassword;
- (void)startLiveChannelZeroVideoWithResolution:(TGResolutionModel *)resolution;
- (void)setLiveVideoQuality:(ENUM_QUALITY_LEVEL)level;
- (void)stopLiveChannelZeroVideo;
- (void)startCameraLiveAudio;
- (void)stopCameraLiveAudio;
- (void)startLiveChannelOneVideoWithResolution:(TGResolutionModel *)resolution;
- (void)setLivePIPVideoQuality:(ENUM_QUALITY_LEVEL)level;
- (void)stopLiveChannelOneVideo;
- (void)startDeviceLiveSpeak;
- (void)stopDeviceLiveSpeak;
- (void)startCameraLiveRecordWithFileName:(NSString *)fileName;
- (void)stopCameraLiveRecord;
- (void)getCameraSDCardRecordListWithDate:(NSString *)dateString callBack:(nullable SDCardRecordListBlock)callBack;
- (void)playDeviceSDCardRecordWithTimePoint:(NSString *)timePoint;
- (void)startCameraSDCardPlay;
- (void)stopCameraSDCardPlay;
- (void)startCameraSDCardRecordWithFileName:(NSString *)fileName;
- (void)stopCameraSDCardRecord;
- (void)cameraSDCardMute;
- (void)cancleCameraSDCardMute;
- (void)setSDCardPlaySpeedLevel:(TGCameraPlaySpeedLevel)level;
- (unsigned int)getMilliSecondTime;
- (NSInteger)calculateRecordDuration;
- (void)sendIOCtrl:(int)controlCMD Data:(char *)buffer DataSize:(int)size;
- (void)exitConnectedSession;

- (void)doPlayLiveChannelZeroVideo;
- (void)doPlayLiveChannelOneVideo;
- (void)doPlayLiveAudio;
- (void)doPlaySDCardChannelZeroVideo;
- (void)doPlaySDCardChannelOneVideo;
- (void)doPlaySDCardAudio;

- (void)receiveDeviceCommandWithModel:(TGIOTCommandModel *)commandModel result:(int)result;

- (void)reportConnectFailed;
- (void)reportConnectFailedWithResult:(int)result;
- (void)reportConnectSuccess;
- (void)reportSendPassword;
- (void)reportReceivePassword;
- (void)reportStartCameraLive;
- (void)reportReceiveFirstFrame;
- (void)reportDeviceP2PVideo;

@end

NS_ASSUME_NONNULL_END
