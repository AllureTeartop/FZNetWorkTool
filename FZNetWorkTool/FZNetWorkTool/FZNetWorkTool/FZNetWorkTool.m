//
//  FZNetWorkTool.m
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/12.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import "FZNetWorkTool.h"
#import "AFNetworking.h"
static NSString *HTTPURL = @"http://47.93.78.8:8091/";

@interface FZNetWorkTool ()

@property (nonatomic,strong)NetWorkProgressFn progroessBlock;
@property (nonatomic,strong)NetworkSuccessFn successBlock;
@property (nonatomic,strong)NetworkFailureFn failureBlock;
@property (nonatomic,strong)NetWorkErrorFn errorBlock;
@property (nonatomic,strong)AFHTTPSessionManager * session;
/**
 *  post请求
 */
@property (nonatomic, strong) NSURLSessionDataTask *posttask;

@end


@implementation FZNetWorkTool

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.parameters = [[NSMutableDictionary alloc] init];
        
    }
    return self;
}
-(void)setUrlaction:(NSString *)urlaction{
    _urlaction = urlaction;
    self.url = [NSString stringWithFormat:@"%@%@",HTTPURL,_urlaction];
}
- (void)startRequestWithSuccessFn:(NetworkSuccessFn)success
                        FailureFn:(NetworkFailureFn)failure
                          ErrorFn:(NetWorkErrorFn)errorr{
    
    [self.session POST:self.url parameters:self.parameters progress:^(NSProgress * _Nonnull uploadProgress) {
        NSLog(@"====%@",self.url);
        NSLog(@"====%@",self.parameters);
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        NSDictionary * dic = [NSJSONSerialization JSONObjectWithData:responseObject options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil];
        
        NSLog(@"====%@",dic);
        
        /**
         
         {
         errorNum : 1,
         msg : 获取成功,
         data : [
         {
         UserName : Florence
         }]
         }
         **/
    
        if (dic) {
            if (![dic[@"errorNum"]isEqualToString:@"1"]) {
                if (failure) {
                    failure(dic[@"msg"]);
                }
            }else{
                if (success) {
                    success(dic[@"data"]);
                }
            }

        }else{
        
            if (failure) {
                failure(dic[@"msg"]);
            }
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        
        if (errorr) {
            errorr(@"请求超时");
        }
    }];
}



















-(AFHTTPSessionManager*)session{
    if (!_session) {
        _session = [AFHTTPSessionManager manager];
        //设置超时时间
        [_session.requestSerializer willChangeValueForKey:@"timeoutInterval"];
        _session.requestSerializer.timeoutInterval = 10.f;
        [_session.requestSerializer didChangeValueForKey:@"timeoutInterval"];
        
        _session.responseSerializer = [AFHTTPResponseSerializer serializer];
        _session.responseSerializer.acceptableContentTypes = [NSSet setWithObject:@"text/html"];
    }
    return _session;
}



@end
