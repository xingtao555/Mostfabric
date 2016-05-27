//
//  LoginApi.m
//  Mostfabric
//
//  Created by 123456 on 16/5/27.
//  Copyright © 2016年 iuyoung. All rights reserved.
//

#import "LoginApi.h"

@implementation LoginApi{
    NSString *_userName;
    NSString *_password;
    NSString *_randCode;
    NSString *_tenantId;
}

-(id)initWithUserName:(NSString *)userName PassWord:(NSString *)password RandCode:(NSString *)randCode TenantId:(NSString *)tenantId{
    self = [super init];
    if (self) {
        _userName = userName;
        _password = password;
        _randCode = randCode;
        _tenantId = tenantId;
        
    }
    return self;
}
-(NSString *)requestUrl{
    return kLoginUrl;
}
- (YTKRequestMethod)requestMethod {
    return YTKRequestMethodPost;
}
-(id)requestArgument{
    return @{@"userName":_userName,@"password":_password,@"randCode":_randCode,@"tenantId":_tenantId};
}



@end
