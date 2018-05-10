//
//  AppDelegate.m
//  Mostfabric
//
//  Created by 123456 on 16/5/26.
//  Copyright © 2016年 iuyoung. All rights reserved.
//

#import "AppDelegate.h"
#import "LoginController.h"
#import "YTKNetworkConfig.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    LoginController *loginVC = [[LoginController alloc]initWithNibName:@"LoginController" bundle:nil];
    self.window.rootViewController = loginVC;
    [self suitScreen];
    YTKNetworkConfig *config = [YTKNetworkConfig sharedInstance];
    config.baseUrl = kBaseUrl;
    [self.window makeKeyAndVisible];
   
    return YES;
}
//适配屏幕
-(void)suitScreen{
    if ([UIScreen mainScreen].bounds.size.height>480) {
        self.autoSizeScaleX = [UIScreen mainScreen].bounds.size.width/320;
        
        self.autoSizeScaleY = [UIScreen mainScreen].bounds.size.height/568;
    }else{
        self.autoSizeScaleX = 1;
        
        self.autoSizeScaleY = 1;
    }
}
- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
