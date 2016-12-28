//
//  FRAlertController.h
//  FRAlertController
//
//  Created by 1860 on 2016/12/10.
//  Copyright © 2016年 FanrongQu. All rights reserved.
//

/** 颜色 */
#define FRUIColor_RGB(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)/1.0]

#import <UIKit/UIKit.h>
#import "FRAlertAction.h"


typedef NS_ENUM(NSInteger, FRAlertControllerStyle) {
    FRAlertControllerStyleActionSheet = 0,
    FRAlertControllerStyleAlert
};

typedef void (^ FRAlertDatePickerBlock)(UIDatePicker *__nonnull datePicker);
typedef void(^ FRAlertTextFieldBlock)(UITextField *__nonnull textField);
typedef void (^ FRAlertArrayBlock)(NSInteger row);
typedef void(^FRAlertPassWardBlock)(NSString *__nonnull passWord);

@interface FRAlertController : UIViewController

/**
 类方法展示日期选择器
 
 @param title 标题
 @param message 描述
 @param preferredStyle alertController类型
 
 @return alertController
 */
+ (nonnull FRAlertController *)alertControllerWithTitle:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(FRAlertControllerStyle)preferredStyle;

@property (nullable, nonatomic, copy) NSString *message;

@property (nonatomic, readonly) FRAlertControllerStyle preferredStyle;

#pragma mark - 按钮
- (void)addAction:(nonnull FRAlertAction *)action;

@property (nonatomic, readonly, nullable) NSArray<FRAlertAction *> *actions;

#pragma mark - TextField
- (void)addTextFieldConfigurationHandler:(nonnull FRAlertTextFieldBlock)configurationHandler;

@property (nullable, nonatomic, readonly) NSArray<UITextField *> *textFields;

#pragma mark - DatePicker
/**
 类方法展示日期选择器

 @param controller 当前控制器
 @param title 标题
 @param message 描述
 @param preferredStyle alertController类型
 @param color 确定按钮颜色
 @param style 确定按钮类型
 @param configurationHandler 日期选择器回调
 
 @return alertController
 */
+ (nonnull FRAlertController *)showAlertDatePickerController:(nonnull UIViewController *)controller title:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(FRAlertControllerStyle)preferredStyle datePickerColor:(nullable UIColor *)color datePickerStyle:(FRAlertActionStyle)style configurationHandler:(nonnull FRAlertDatePickerBlock)configurationHandler;
/**
 添加日期选择器(默认选中日期为今天  最小日期默认为1900/01/01  最大日期默认为当前日期)
 
 @param color 确定按钮颜色
 @param style 确定按钮类型
 @param configurationHandler 日期选择器回调
 */
- (void)addDatePickerWithColor:(nullable UIColor *)color style:(FRAlertActionStyle)style configurationHandler:(nonnull FRAlertDatePickerBlock)configurationHandler;

/**  日期选择器  */
@property (nonatomic, strong, nullable) UIDatePicker *datePicker;

#pragma mark - SelectArray

/**
 类方法展示数组选择器
 
 @param controller 当前控制器
 @param title 标题
 @param message 描述
 @param preferredStyle alertController类型
 @param array 待选数组
 @param configurationHandler 选中数组的序号
 
 @return AlertController
 */
+ (nonnull FRAlertController *)showAlertSelectArrayController:(nonnull UIViewController *)controller title:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(FRAlertControllerStyle)preferredStyle selectArray:(nonnull NSArray *)array configurationHandler:(nonnull FRAlertArrayBlock)configurationHandler;

/**
 数组选择
 
 @param array 待选数组
 @param configurationHandler 选中数组的序号
 */
- (void)addSelectArray:(nonnull NSArray *)array configurationHandler:(nonnull FRAlertArrayBlock)configurationHandler;

#pragma mark - PassWard
/**
 类方法展示密码输入框
 
 @param controller 当前控制器
 @param title 标题
 @param message 描述
 @param preferredStyle alertController类型
 @param payMoney 付款金额
 @param configurationHandler 支付密码回调
 
 @return AlertController
 */
+ (nonnull FRAlertController *)showAlertPassWardController:(nonnull UIViewController *)controller title:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(FRAlertControllerStyle)preferredStyle payMoney:(nonnull NSString *)payMoney configurationHandler:(nonnull FRAlertPassWardBlock)configurationHandler;

/**
 支付密码

 @param payMoney 付款金额
 @param configurationHandler 支付密码回调
 */
- (void)addPassWardWithPayMoney:(nonnull NSString *)payMoney configurationHandler:(nonnull FRAlertPassWardBlock)configurationHandler;


@end
