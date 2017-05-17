//
//  VBNetWorkTool.m
//  FZNetwotking
//
//  Created by Florence on 2017/5/16.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import "VBNetWorkTool.h"

@implementation VBNetWorkTool

+(NSURLSessionTask *)VB_POST:(NSString *)URL
                  parameters:(id)parameters
                   SuccessFn:(NetworkSuccessFn)success
                       Error:(NetWorkErrorFn)error
                   FailureFn:(NetworkFailureFn)failure{

    NSURLSessionTask *sessionTask = [FZNetworking POST:URL parameters:parameters SuccessFn:^(id successValue) {
    NSDictionary * dic = [NSJSONSerialization JSONObjectWithData:successValue options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil];
        if (dic) {
            if (![dic[@"errorNum"] isEqualToString:@"1"]) {
                error ? error(dic[@"data"]) : nil;
            }else{
                success ? success(dic[@"data"]):nil;
            }
        }else{
            failure ? failure(@"请求失败") : nil;
        }
    } FailureFn:^(id failurValue) {
        failure ? failure(failurValue) : nil;
    }];
    return sessionTask;
}
+(NSURLSessionTask *)VB_POST:(NSString *)URL
                  parameters:(id)parameters
                     CacheFn:(FZRequestCache)cache
                   SuccessFn:(NetworkSuccessFn)success
                       Error:(NetWorkErrorFn)error
                   FailureFn:(NetworkFailureFn)failure{

    NSURLSessionTask *sessionTask = [FZNetworking POST:URL parameters:parameters CacheFn:^(id cacheValue) {
        NSDictionary * dic = [NSJSONSerialization JSONObjectWithData:cacheValue options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil];
        if (dic) {
            cache ? cache(dic[@"data"]): nil;
        }
    } SuccessFn:^(id successValue) {
        NSDictionary * dic = [NSJSONSerialization JSONObjectWithData:successValue options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil];
        if (dic) {
            if (![dic[@"errorNum"] isEqualToString:@"1"]) {
                error ? error(dic[@"data"]) : nil;
            }else{
                success ? success(dic[@"data"]):nil;
            }
        }
    } FailureFn:^(id failurValue) {
        failure ? failure(failurValue) : nil;
    }];
    return sessionTask;
}
















@end
