//
//  HeziSDK.h
//  FloatIconSDK
//
//  Created by 雷军 on 16/7/2.
//  Copyright © 2016年 ljcoder. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HeziSDK : UIView

/**
 *  要显示在哪个父视图上
 *
 *  @param view 父视图
 */
- (void)showInView:(UIView *)view;

/**移除*/
- (void)dismiss;

/**
 *  根据事件触发显示
 *
 *  @param event  必须，当前事件（logged  登录成功，registered 注册成功，purchase_success  付款成功）
 
 *  @param properties 属性参数 （ username 必须，APP当前操作用户，sex 可选，用户性别信息，mobile 可选，用户手机号码，nickname 可选，用户昵称，province 可选，用户所在省份，city 可选，用户所在城市，points 可选，用户当前积分）
 */
- (void)trigger:(NSString *)event properties:(NSDictionary *)properties;

@property (strong, nonatomic) NSString *event;


@end
