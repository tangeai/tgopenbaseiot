//
//  DADeviceVideoPlayView.h
//  DAAudioVideo
//
//  Created by Darren on 2020/10/9.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,DAVideoPlayViewContentMode) {
    DAVideoPlayViewContentMode_ScaleToFill,
    DAVideoPlayViewContentMode_ScaleAspectFit,
    DAVideoPlayViewContentMode_ScaleAspectFill
};

@interface DADeviceVideoPlayView : UIView

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) CMSampleBufferRef sampleBuffer;
@property (nonatomic, assign) DAVideoPlayViewContentMode mode;
@property (nonatomic, assign) CGFloat rotateDegree;

- (UIImage *)snapShotImage;

@end

NS_ASSUME_NONNULL_END
