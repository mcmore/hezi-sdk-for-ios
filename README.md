# hezi-SDK-for-ios
### 1.导入SDK

 下载[HeziSDK.zip文件](http://help.huodonghezi.com/hc/kb/article/195000/)，将zip文件解压，得到HeziSDK文件夹，将HeziSDK文件夹拖入工程即可。
 
### 2.SDK使用
- 设置KEY和活动页导航样式
打开AppDelegate.m文件，导入HeziSDKManager.h，在didFinishLaunchingWithOptions方法里面执行下面方法：
```objectivec
// 设置KEY
[[HeziSDKManager sharedInstance] configureKey:@"2363bea83d660828ae9a6be2c9e50048"];
// 设置导航栏样式
[[HeziSDKManager sharedInstance] setNavigationBarBackgroundImage:[UIImage imageNamed:@"anniu01"]];
```

- 埋点示例，登录埋点
假如你的app登录后跳转到mainVC页面可以在登录成功后调用下面方法
```objectivec
// 初始化
HeziSDK *heziSDK = [[HeziSDK alloc] init];
// 添加到视图上
[heziSDK showInView:mainVC.view];
// 触发
[heziSDK trigger:@"logged" properties:@{@"username":@"18688885454"}];
```
- 参数说明：
	- trigger 必填，可填下列字段
		
		1. logged 登录埋点
		2. registered 注册埋点 
		3. purchase_succes 支付成功埋点
	
	- properties
		1.  username     --用户名（必须）接入方自己用户体系中的用户名
        2.  mobile        --手机（必须）接入方自己用户体系中的手机号码
		3.  nickname      --昵   称 (可选)
        4.  sex           --性   别 (可选) 
        5. province      --省   份 (可选)
        6. city         --城   市 (可选)
        7. points       --积   分 (可选)
        
	    *提醒：* 可选属性和后台活动规则相对应，如果设置了相应的活动规则，而没有传相应的字段，则埋点无法正确触发。例如后台设置了在广州的用户触发，而在埋点的时候没有传入用户所在城市这个参数，我们则无法知道哪些用户是属于广州的，则会出现埋点无法正确触发。

- 可以调用下面的方法使悬浮图标消失.
```objectivec
[heziSDK dismiss];
```

### 3.HeziBanner控件的使用
- 去后台新增活动投放，得到活动位key(也就是position_key)。在需要投放的页面导入HeziBanner.h
```objectivec
#import "HeziBanner.h"
```

- 创建控件，并放置在需要的地方
```objectivec
// 初始化，positionKey就是上面的位置key，properties和第4步的properties一样的要求
HeziBanner *banner = [[HeziBanner alloc] initWithPositionKey:@"bfb706d6b8" properties:@{@"username":@"18688885454",@"mobile":@"18688885454"}];
// 设置默认图和拉伸模式，图片未加载时显示的图片
[banner setPlaceholder:[UIImage imageNamed:@"banner"] model:UIViewContentModeScaleAspectFill];
//banner.placeholderImage = [UIImage imageNamed:@"banner"];(不建议使用这种方式)
// 设置frame
banner.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_WIDTH/2+5);
// 添加到父视图
[self.view addSubview:banner];
```

- 在多张图的情况下，可以添加自动滚动功能，调用以下方法实现
```objectivec
// 第一个参数为是否开启自动滚动，第二个参数为滚动的时间间隔
[banner autoScroll:YES duration:3];
```

### 4.崩溃日志收集
1. 收集和上传策略
	程序启动时检查是否有崩溃记录，如果有则上传崩溃日志，上传成功删除本地的崩溃日志。

2. 使用方法

- 在```AppDelegate.m```导入```HeziSDKCrashLogger.h```

	``` objectivec
		#import "HeziSDKCrashLogger.h"
	```
- 在 ```- (void)applicationDidBecomeActive:(UIApplication *)application```方法中添加日志上传方法。

	```objectivec
	- (void)applicationDidBecomeActive:(UIApplication *)application {
		 [HeziSDKCrashLogger uploadCrashLog];
	}
	```

### 5.debug模式的使用
在```AppDelegate.m```的```- (void)applicationDidBecomeActive:(UIApplication *)application```方法中添加如下方法
```
[[HeziSDKManager sharedInstance] openDebug:YES];
```

debug模式下可以查看请求信息和规则的匹配。

### 常见BUG
![Alt text](./1476435427156.png)
这个bug是只有刮刮卡活动才会出现，只会引起断点，不影响正常使用，直接跳过即可，在Xcode里面点击下图的这个按钮就行了。
![Alt text](./1476435498773.png)


##### 更新记录
1.2.0  新增banner控件

1.2.1  新增崩溃日志上传功能，debug模式
