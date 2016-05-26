//
//  Macros.h


#ifndef Macros_h
#define Macros_h
//-------------------获取设备大小-------------------------

#define kStatusBarHeight        (20.f)

#define kTopBarHeight           (44.f)
#define kBottomBarHeight        (49.f)

#define kCellDefaultHeight      (44.f)

#define kEnglishKeyboardHeight  (216.f)
#define kChineseKeyboardHeight  (252.f)
//获取屏幕 宽度、高度
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

// 除去信号区的屏幕的frame
#define APP_FRAME  [[UIScreen mainScreen] applicationFrame]
// 应用程序的屏幕高度
#define APP_FRAME_H   [[UIScreen mainScreen] applicationFrame].size.height
// 应用程序的屏幕宽度
#define APP_FRAME_W    [[UIScreen mainScreen] applicationFrame].size.width

//----------------------系统----------------------------

//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion [[UIDevice currentDevice] systemVersion]

//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//当前国家
#define LOCAL_COUNTRY [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode]

//判断是否 Retina屏、设备是否iphone 5
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

// 设备判断 是iphone还是ipad
#define IS_IPHONE [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone
#define IS_PAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// iPhone的型号
#define IS_IPHONE4 ([[UIScreen mainScreen] bounds].size.height == 480)
#define IS_IPHONE5 ([[UIScreen mainScreen] bounds].size.height == 568)
#define IS_IPHONE6 ([[UIScreen mainScreen] bounds].size.height == 667)//6或者6s
#define IS_IPHONE6_PLUS ([[UIScreen mainScreen] bounds].size.height == 736)//6p或者6sp

//系统版本
#define IS_IOS6 (SYSTEM_VERSION >= 6.0 && SYSTEM_VERSION < 7)
#define IS_IOS7 (SYSTEM_VERSION >= 7.0 && SYSTEM_VERSION < 8.0)
#define IS_IOS8 (SYSTEM_VERSION >= 8.0 && SYSTEM_VERSION < 9.0)
#define IS_IOS9 (SYSTEM_VERSION >= 9.0 && SYSTEM_VERSION < 10.0)

// APP版本号
#define APP_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//APP BUILD 版本号
#define APP_BUILD_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

//APP名字
#define APP_DISPLAY_NAME  [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]

/*都是系统的宏定义*/
////判断是真机还是模拟器
//#if TARGET_OS_IPHONE
////iPhone Device
//#endif
//
//#if TARGET_IPHONE_SIMULATOR
////iPhone Simulator
//#endif
//
////当前使用Xcode iPhone OS SDK 的版本
//#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_8_0
//
//#else
//
//#endif
////判断系统为64位还是32位
//#if __LP64__
//
//#else
//
//#endif

//大于等于7.0的ios版本
#define iOS7_OR_LATER SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")

//大于等于8.0的ios版本
#define iOS8_OR_LATER SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")

//获取系统时间戳
#define GetCurentTime [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]]

//检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

//----------------------图片----------------------------

//定义UIImage对象  可以加载Assets中资源
#define ImageNamed(NAME) [UIImage imageNamed:(NAME)]

//读取本地图片 只能加载到拖入项目资源（带文件夹也可）
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]
//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]
//png图片
#define PNGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
//jpg图片
#define JPGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]

//----------------------颜色类---------------------------

// rgb颜色转换（16进制->10进制）rgbValue 0x4bb9a0（rgb16进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//带有RGBA的颜色设置
#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]


//----------------------其他----------------------------

//自定义一个API
#define APIURL                @"http://xxxxx/"
//登陆API
#define APILogin              [APIURL stringByAppendingString:@"Login"]

//appdelegate
#define ShareDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)

//沙盒路径
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

//方正黑体简体字体定义
#define FONTBLACK(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]
// 字体加粗 italicSystemFontOfSize//斜体字
#define BOLDSYSTEMFONT(FONTSIZE) [UIFont boldSystemFontOfSize:FONTSIZE]
//字体大小
#define SYSTEMFONT(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
//设置字体
#define FONT(NAME, FONTSIZE)    [UIFont fontWithName:(NAME) size:(FONTSIZE)]

//设置View的tag属性
#define VIEWWITHTAG(_OBJECT, _TAG)    [_OBJECT viewWithTag : _TAG]

// View 坐标(x,y)和宽高(width,height)
#define X(v)                    (v).frame.origin.x
#define Y(v)                    (v).frame.origin.y
#define WIDTH(v)                (v).frame.size.width
#define HEIGHT(v)               (v).frame.size.height
//view最大坐标 中点坐标 最小坐标
#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)

//程序的本地化,引用国际化的文件
#define MyLocal(x, ...) NSLocalizedString(x, nil)

//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefault 存取数据
#define UNSaveObject(obj,key) \
if(obj && key){ \
[[NSUserDefaults standardUserDefaults] setObject:obj forKey:key]; \
[[NSUserDefaults standardUserDefaults] synchronize]; \
}

#define UNSaveInteger(Integer,key) \
if(obj && key){ \
[[NSUserDefaults standardUserDefaults] setInteger:Integer forKey:key]; \
[[NSUserDefaults standardUserDefaults] synchronize]; \
}

#define UNGetInteger(key)    key ? [[NSUserDefaults standardUserDefaults] integerForKey:key] : 0

#define UNGetObject(key)    key ? [[NSUserDefaults standardUserDefaults] objectForKey:key] : nil

//NSUserDefault 序列化存取数据
#define UNSaveSerializedObject(obj,key) \
NSData *serialized = [NSKeyedArchiver archivedDataWithRootObject:obj];\
if(serialized){ \
[[NSUserDefaults standardUserDefaults] setObject:serialized forKey:key]; \
[[NSUserDefaults standardUserDefaults] synchronize]; \
}

#define UNGetSerializedObject(key)  key ? ([[NSUserDefaults standardUserDefaults] objectForKey:key] ? [NSKeyedUnarchiver unarchiveObjectWithData:[[NSUserDefaults standardUserDefaults] objectForKey:key]] : nil) : nil

//NSUserDefault 删除数据
#define UNDeletedSerializedObject(key) { [[NSUserDefaults standardUserDefaults] removeObjectForKey:key];\
[[NSUserDefaults standardUserDefaults] synchronize]; \
}


//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]


//alertView
#define ALERT(msg) [[[UIAlertView alloc] initWithTitle:nil message:msg delegate:nil cancelButtonTitle:@"好的" otherButtonTitles:nil] show]

#define ALERT_WITH_DELEGATE(msg) [[[UIAlertView alloc] initWithTitle:nil message:msg delegate:self cancelButtonTitle:@"好的" otherButtonTitles:nil] show]

//验证正则表达式 expression表达式  content验证内容
#define isMatch(regex,content) [[NSPredicate predicateWithFormat:@"SELF MATCHES %@",regex] evaluateWithObject:content]

//-------------------打印日志-------------------------


//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif


//#define ITTDEBUG
//#define ITTLOGLEVEL_INFO     10
//#define ITTLOGLEVEL_WARNING  3
//#define ITTLOGLEVEL_ERROR    1
//
//#ifndef ITTMAXLOGLEVEL
//
//#ifdef DEBUG
//#define ITTMAXLOGLEVEL ITTLOGLEVEL_INFO
//#else
//#define ITTMAXLOGLEVEL ITTLOGLEVEL_ERROR
//#endif
//
//#endif
//
//// The general purpose logger. This ignores logging levels.
//#ifdef ITTDEBUG
//#define ITTDPRINT(xx, ...)  NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
//#else
//#define ITTDPRINT(xx, ...)  ((void)0)
//#endif
//
//// Prints the current method's name.
//#define ITTDPRINTMETHODNAME() ITTDPRINT(@"%s", __PRETTY_FUNCTION__)
//
//// Log-level based logging macros.
//#if ITTLOGLEVEL_ERROR <= ITTMAXLOGLEVEL
//#define ITTDERROR(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
//#else
//#define ITTDERROR(xx, ...)  ((void)0)
//#endif
//
//#if ITTLOGLEVEL_WARNING <= ITTMAXLOGLEVEL
//#define ITTDWARNING(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
//#else
//#define ITTDWARNING(xx, ...)  ((void)0)
//#endif
//
//#if ITTLOGLEVEL_INFO <= ITTMAXLOGLEVEL
//#define ITTDINFO(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
//#else
//#define ITTDINFO(xx, ...)  ((void)0)
//#endif
//
//#ifdef ITTDEBUG
//#define ITTDCONDITIONLOG(condition, xx, ...) { if ((condition)) { \
//ITTDPRINT(xx, ##__VA_ARGS__); \
//} \
//} ((void)0)
//#else
//#define ITTDCONDITIONLOG(condition, xx, ...) ((void)0)
//#endif
//
//#define ITTAssert(condition, ...)                                       \
//do {                                                                      \
//if (!(condition)) {                                                     \
//[[NSAssertionHandler currentHandler]                                  \
//handleFailureInFunction:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
//file:[NSString stringWithUTF8String:__FILE__]  \
//lineNumber:__LINE__                                  \
//description:__VA_ARGS__];                             \
//}                                                                       \
//} while(0)








#endif /* Macros_h */
