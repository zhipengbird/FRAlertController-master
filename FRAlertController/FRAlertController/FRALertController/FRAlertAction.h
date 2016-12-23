//
//  FRAlertAction.h
//  FRAlertController
//
//  Created by 1860 on 2016/12/10.
//  Copyright © 2016年 FanrongQu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIView+AutoLayout.h"
#import "UIView+Layer.h"

typedef NS_ENUM(NSInteger, FRAlertActionStyle) {
    FRAlertActionStyleDefault = 0,//普通按钮
    FRAlertActionStyleColor,//背景色
    FRAlertActionStyleBorder//边框
};

@class FRAlertAction;
typedef void(^FRAlertActionBlock)(FRAlertAction *__nonnull action);

@interface FRAlertAction : NSObject

+ (nonnull FRAlertAction *)actionWithTitle:(nullable NSString *)title style:(FRAlertActionStyle)style color:(nullable UIColor *)color handler:(nullable FRAlertActionBlock)handler;

@property (nullable, nonatomic, readonly) NSString *title;
@property (nullable, nonatomic, readonly) UIColor *color;
@property (nonatomic, assign) FRAlertActionStyle style;
@property (nonatomic, getter=isEnabled) BOOL enabled;

/**  FRAlertAction回调  */
@property (nullable, nonatomic, copy) FRAlertActionBlock actionBlock;

@end
