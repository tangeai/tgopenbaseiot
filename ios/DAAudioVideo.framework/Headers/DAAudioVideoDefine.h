//
//  DAAudioVideoDefine.h
//  DAAudioVideo
//
//  Created by Darren on 2021/3/2.
//  Copyright © 2021 Darren. All rights reserved.
//

#ifndef DAAudioVideoDefine_h
#define DAAudioVideoDefine_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DAMediaCodeID) {
    DAMediaCodeID_Unknow,
    DAMediaCodeID_Video_H264,
    DAMediaCodeID_Video_H265,
    DAMediaCodeID_Video_JPEG,
    DAMediaCodeID_Video_IJPG,
    DAMediaCodeID_Audio_PCM,
    DAMediaCodeID_Audio_G711A,
    DAMediaCodeID_Audio_G711U,
    DAMediaCodeID_Audio_AAC_RAW
};

typedef NS_ENUM(NSInteger, DAVideoFrameType) {
    DAVideoFrameType_UnKnown,
    DAVideoFrameType_IFrame,
    DAVideoFrameType_BPFrame,
    DAVideoFrameType_SPS,
    DAVideoFrameType_PPS,
    DAVideoFrameType_SEI,
    DAVideoFrameType_VPS,
    DAVideoFrameType_Other
};

extern NSString * const DAMp4DidStartRecordNotification;
extern NSString * const DAMp4DidStopRecordNotification;

#endif /* DAAudioVideoDefine_h */
