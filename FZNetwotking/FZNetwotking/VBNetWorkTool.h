//
//  VBNetWorkTool.h
//  FZNetwotking
//
//  Created by Florence on 2017/5/16.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FZNetworking.h"
@interface VBNetWorkTool : NSObject



+(NSURLSessionTask *)VB_POST:(NSString *)URL
                  parameters:(id)parameters
                   SuccessFn:(NetworkSuccessFn)success
                       Error:(NetWorkErrorFn)error
                   FailureFn:(NetworkFailureFn)failure;


+(NSURLSessionTask *)VB_POST:(NSString *)URL
               parameters:(id)parameters
                  CacheFn:(FZRequestCache)cache
                SuccessFn:(NetworkSuccessFn)success
                    Error:(NetWorkErrorFn)error
                FailureFn:(NetworkFailureFn)failure;









@end
