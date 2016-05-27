//
//  LoginApi.h
//  Mostfabric
//
//  Created by 123456 on 16/5/27.
//  Copyright © 2016年 iuyoung. All rights reserved.
//


#import "YTKRequest.h"
@interface LoginApi : YTKRequest
-(id)initWithUserName:(NSString*)userName PassWord:(NSString*)password RandCode:(NSString*)randCode TenantId:(NSString*)tenantId;
@end
