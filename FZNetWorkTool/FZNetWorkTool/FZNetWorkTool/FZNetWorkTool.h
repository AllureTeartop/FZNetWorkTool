//
//  FZNetWorkTool.h
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/12.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^NetworkSuccessFn)(id successValue);
typedef void (^NetworkFailureFn)(id failurValue);
typedef void (^NetWorkErrorFn)(id error);
typedef void (^NetWorkProgressFn)(float progress);

@interface FZNetWorkTool : NSObject
/**
    例如一个请求地址为 http://47.98.112.32/api/getMsg
    其中http://47.98.112.32/api这些是固定的可以被认为是请求url
    然后getMsg可以被认为urlaction，根据个人项目的不同做一些调整

 **/
@property (nonatomic, strong) NSString *url;    //请求url
@property (nonatomic, strong) NSMutableDictionary * parameters; //请求体
@property (nonatomic, strong) NSString * urlaction;//urlaction

/**
 网络请求

 @param success 成功
 @param failure 失败
 @param errorr 错误
 */
- (void)startRequestWithSuccessFn:(NetworkSuccessFn)success
                        FailureFn:(NetworkFailureFn)failure
                        ErrorFn:(NetWorkErrorFn)errorr;








@end
