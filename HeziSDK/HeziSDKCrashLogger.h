//
//  HeziSDKCrashLogger.h
//  ActivityBox
//
//  Created by ljcoder on 16/9/20.
//  Copyright © 2016年 sunnsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HeziSDKCrashLogger : NSObject

// 注册崩溃收集处理
+ (void)registerUncaughtExceptionHandler;

// 上传崩溃日志
+ (void)uploadCrashLog;

@end
