//
//  TGOSSVideoRecordModel.h
//  TGIOT
//
//  Created by Darren Xia on 2025/3/20.
//

#import <Foundation/Foundation.h>
#import <TGBaseIOT/TGBaseIOTDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGOSSVideoRecordModel : NSObject

@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) BOOL writeWhenDataLose;
@property (nonatomic, assign) BOOL writeAudioWhenMute;
@property (nonatomic, assign) BOOL writeAudioWhenSpeed;
@property (nonatomic, assign) TGVideoRecordType recordType;

@end

NS_ASSUME_NONNULL_END
