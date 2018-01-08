//
//  LoginController.m
//  Mostfabric
//
//  Created by 123456 on 16/5/26.
//  Copyright © 2016年 iuyoung. All rights reserved.
//

#import "LoginController.h"
#import "LoginApi.h"
#import "EncryptMd5.h"
@interface LoginController ()
@property(nonatomic,strong)UITextField *tenantTF;
@property(nonatomic,strong)UITextField *adminTF;
@property(nonatomic,strong)UITextField *passWordTF;
@property(nonatomic,strong)UITextField *randCodeTF;
@end
static NSString * const TenantTFPlaceholder = @"请输入企业租户ID,默认system";
static NSString * const AdminTFPlaceholder = @"admin";
static NSString * const PassWordTFPlaceholder = @"密码";
static NSString * const RandCodeTFPlaceholder = @"请输入验证码";


@implementation LoginController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"status");
    [self initUI];
    
    
    
}
//登录
-(void)login{
    /*
    密码加密方式  :
    
    md5( md5(密码明文) + md5(固定特征码) ) 
    固定 特征码:
     */
    if (_adminTF.text.length==0) {
        ALERT(@"请输入账户");
        return;
    }else if(_passWordTF.text.length==0){
        ALERT(@"请输入密码");
        return;
    }else if(_randCodeTF.text.length==0){
        ALERT(@"请输入验证码");
        return;
    }
//    [MBProgressHUD showMessage:@"登录中..." toView:self.view];
    NSString *Pwd = [NSString stringWithFormat:@"%@%@",[EncryptMd5 md5:_passWordTF.text],[EncryptMd5 md5:@"u30*!/xr^15vy$s+h6@"]];
   NSString *encryptPwd = [EncryptMd5 md5:Pwd];
    LoginApi *api = [[LoginApi alloc]initWithUserName:_adminTF.text PassWord:encryptPwd RandCode:_randCodeTF.text TenantId:_tenantTF.text];
    
    [api startWithCompletionBlockWithSuccess:^(__kindof YTKBaseRequest *request) {
        NSLog(@"responseJSONObject%@",request.responseJSONObject);
        
       
    } failure:^(__kindof YTKBaseRequest *request) {
        
    }];

}
-(void)initUI{
    
    _tenantTF = [[UITextField alloc]init];
    _tenantTF.placeholder = TenantTFPlaceholder;
    _tenantTF.font = [UIFont systemFontOfSize:15];
    [_tenantTF setBorderStyle:UITextBorderStyleRoundedRect];
    [self.view addSubview:_tenantTF];
    [_tenantTF mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.top.mas_offset(64);
        make.left.mas_offset(30);
        make.right.mas_offset(-30);
        make.height.mas_offset(30);
        
    }];
    
    _adminTF = [[UITextField alloc]init];
    _adminTF.placeholder = AdminTFPlaceholder;
    _adminTF.text = @"dev";
    _adminTF.font = [UIFont systemFontOfSize:15];
    [_adminTF setBorderStyle:UITextBorderStyleRoundedRect];
    [self.view addSubview:_adminTF];
    [_adminTF mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_tenantTF.mas_bottom).mas_offset(20);
        make.left.mas_offset(30);
        make.right.mas_offset(-30);
        make.height.mas_offset(30);
    }];
    
    _passWordTF = [[UITextField alloc]init];
    _passWordTF.placeholder = PassWordTFPlaceholder;
    _passWordTF.text = @"111111";
    _passWordTF.font = [UIFont systemFontOfSize:15];
    [_passWordTF setBorderStyle:UITextBorderStyleRoundedRect];
    [self.view addSubview:_passWordTF];
    [_passWordTF mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_adminTF.mas_bottom).mas_offset(20);
        make.left.mas_offset(30);
        make.right.mas_offset(-30);
        make.height.mas_offset(30);
    }];
    
    UIImageView *randCodeIV = [[UIImageView alloc]init];
    NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:[NSString stringWithFormat:@"%@%@",kBaseUrl,kRandCodeUrl]]];
    randCodeIV.image = [UIImage imageWithData:data];
    [self.view addSubview:randCodeIV];
    [randCodeIV mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_passWordTF.mas_bottom).mas_offset(20);
        make.right.equalTo(self.view.mas_right).mas_offset(-30);
        make.size.mas_offset(CGSizeMake(100, 30));
    }];

    _randCodeTF = [[UITextField alloc]init];
    _randCodeTF.placeholder = RandCodeTFPlaceholder;
    _randCodeTF.font = [UIFont systemFontOfSize:15];
    [_randCodeTF setBorderStyle:UITextBorderStyleRoundedRect];
    [self.view addSubview:_randCodeTF];
    [_randCodeTF mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_passWordTF.mas_bottom).mas_offset(20);
        make.left.mas_offset(30);
        make.height.mas_offset(30);
        make.right.equalTo(randCodeIV.mas_left).mas_offset(-30);
    }];
    
    UIButton *loginBtn = [[UIButton alloc]init];
    [loginBtn setTitle:@"登录" forState:UIControlStateNormal];
    [loginBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [loginBtn setBackgroundColor:[UIColor blackColor]];
    [loginBtn addTarget:self action:@selector(login) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:loginBtn];
    [loginBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_randCodeTF.mas_bottom).mas_offset(20);
        make.height.mas_offset(30);
        make.left.mas_offset(100);
        make.right.mas_offset(-100);
        
    }];
    
    
}
-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [self.view endEditing:YES];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
