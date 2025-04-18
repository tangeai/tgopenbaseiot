//
//  TGBaseIOTSocketManager.h
//  TGBaseIOT
//
//  Created by liubin on 2023/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TGBaseIOTSocketManagerDelegate <NSObject>

- (void)tgSocketDidReceiveMessage:(NSString *)message;
- (void)tgSocketDidReceiveKeyArrayMessage:(NSArray *)messageArray;

@end

@interface TGBaseIOTSocketManager : NSObject

@property (nonatomic, weak) id<TGBaseIOTSocketManagerDelegate>delegate;

+ (instancetype)shareManager;
- (void)connectWebSocket;
- (void)connectLocalWertcSocket;
- (void)closeWebSocket;
- (void)sendMessage:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
