//
//  HeziBanner.h
//  ActivityBox
//
//  Created by ljcoder on 16/9/6.
//  Copyright © 2016年 sunnsoft. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HeziBanner : UIView

/**
 *  初始化banner
 *
 *  @param positionKey  必须，位置key，后台获取
 
 *  @param properties 属性参数 （ username 必须，APP当前操作用户，sex 可选，用户性别信息，mobile 可选，用户手机号码，nickname 可选，用户昵称，province 可选，用户所在省份，city 可选，用户所在城市，points 可选，用户当前积分）
 */
- initWithPositionKey:(NSString *)positionKey properties:(NSDictionary *)properties;

/**
 *  设置自动滚动和滚动时间
 *
 *  @param autoScroll 是否滚动
 *  @param duration   滚动间隔时间
 */
- (void)autoScroll:(BOOL)autoScroll duration:(CGFloat)duration;


/**
 设置默认图和显示模式

 @param placeholder  默认图
 @param contentMode 显示模式
 */
- (void)setPlaceholder:(UIImage *)placeholder model:(UIViewContentMode)contentMode;

/**
 *  默认图
 */
@property (strong, nonatomic) UIImage *placeholderImage;

@property (strong, nonatomic, readonly) UIPageControl *pageControl;

@end
