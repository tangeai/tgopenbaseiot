//
//  DASaveWavFileFormatTool.h
//  DAAudioVideo
//
//  Created by Darren on 2021/8/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DASaveWavFileFormatTool : NSObject

+ (BOOL)transformPCMFileToG711AFile:(NSString *)pcmPath g711aPath:(NSString *)g711aPath;

+ (BOOL)saveWavFormatWithAudioPath:(NSString *)audioPath filePath:(NSString *)filePath channels:(unsigned int)channels sampleRate:(unsigned int)sampleRate bitsPerSample:(unsigned int)bitsPerSample codeID:(DAMediaCodeID)codeID;

@end

NS_ASSUME_NONNULL_END
