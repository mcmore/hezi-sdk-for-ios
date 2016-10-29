//
//  HeziSDKManager.h
//  FloatIconSDK
//
//  Created by 雷军 on 16/7/2.
//  Copyright © 2016年 ljcoder. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface HeziSDKManager : NSObject
/**单例*/
+ (instancetype)sharedInstance;

/**
 *  设置key
 *
 *  @param key 必须，由用户在活动盒子后台申请
 */
- (void)configureKey:(NSString *)key;

- (void)openDebug:(BOOL)open;

@property (assign, nonatomic, readonly) BOOL isDebug;

@property (strong, nonatomic, readonly) NSString *key;

//设置导航栏
- (void)setNavigationBarBackgroundImage:(UIImage  *)backgroundImage;
@property (strong, nonatomic, readonly) UIImage * navigationImage;


- (void)setNavigationBarBackgroundColor:(UIColor  *)backgroundColor;
@property (strong, nonatomic, readonly) UIColor * navigationColor;

@end
