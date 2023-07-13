//
//  TGMagicLogManager.h
//  TGIOT
//
//  Created by Darren on 2021/8/23.
//
#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>

#ifdef LOG_LEVEL_DEF
#   undef LOG_LEVEL_DEF
#endif
#define LOG_LEVEL_DEF ([TGMagicLogManager shareManager].logLevel)

NS_ASSUME_NONNULL_BEGIN

@interface TGMagicLogManager : NSObject

+ (instancetype)shareManager;
@property (nonatomic, assign) DDLogLevel logLevel;

- (void)startLog;
- (NSString *)currentLogFilePath;

@end

NS_ASSUME_NONNULL_END
