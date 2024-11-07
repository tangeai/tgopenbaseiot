//
//  TGDeviceVideoPlayView.h
//  AFNetworking
//
//  Created by liubin on 2024/11/6.
//

#import <UIKit/UIKit.h>
#import <DAAudioVideo/DAAudioVideo.h>
#import "TGCameraDefine.h"
NS_ASSUME_NONNULL_BEGIN

@interface TGDeviceVideoPlayView : UIView

@property (nonatomic, assign) int64_t iphoneTimeStamp;;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) CMSampleBufferRef sampleBuffer;
@property (nonatomic, assign) DAVideoPlayViewContentMode mode;
@property (nonatomic, assign) CGFloat rotateDegree;
@property (nonatomic, assign) float sharpness;  // 0.0 表示无锐化，1.0 表示完全锐化
@property (nonatomic, assign) float saturation; // 0.0 表示去饱和（灰度），1.0 保持原饱和度，>1.0 增加饱和度
@property (nonatomic, assign) float brightness; // -1.0 降低亮度，0.0 保持不变，1.0 增加亮度
@property (nonatomic, assign) float contrast;   // < 1.0 减少对比度，1.0 保持原对比度，>1.0 增加对比度

/// 自定义裁剪初始化
/// - Parameters:
///   - frame: frame
///   - cropLeft: 左侧百分百 0.0-1.0
///   - cropTop: 上部百分比 0.0-1.0
///   - cropRight: 右部百分比0.0-1.0 值要>cropLeft
///   - cropBottom: 下部百分比0.0-1.0 值要>cropTop
- (instancetype)initWithFrame:(CGRect)frame cropViewWithLeft:(float)cropLeft top:(float)cropTop right:(float)cropRight bottom:(float)cropBottom;

/// 自定义裁剪截屏
/// - Parameters:
///   - liveQuality: 清晰度
///   - featureInfo: 能力集（可从基础指令能力集中获取）
///   - extAttrs: 拓展属性（可从devieModel中的extAttrs属性获取）
- (UIImage *)snapShotImageLiveQuality:(ENUM_QUALITY_LEVEL)liveQuality featureInfo:(NSDictionary *)featureInfo extAttrs:(NSDictionary *)extAttrs;

/// 是否是假三目设备（特殊设备）
/// - Parameters:
///   - featureInfo: 能力集（可从基础指令能力集中获取）
///   - extAttrs: 拓展属性（可从devieModel中的extAttrs属性获取）
+ (BOOL)isTrinocularDeviceFeatureInfo:(NSDictionary *)featureInfo extAttrs:(NSDictionary *)extAttrs;

/// 假三目设备 分割的通道数 -1不分割
/// - Parameters:
///   - featureInfo: 能力集（可从基础指令能力集中获取）
///   - extAttrs: 拓展属性（可从devieModel中的extAttrs属性获取）
+ (NSInteger)isTrinocularSplitChannelsNumberFeatureInfo:(NSDictionary *)featureInfo extAttrs:(NSDictionary *)extAttrs;

@end

NS_ASSUME_NONNULL_END
