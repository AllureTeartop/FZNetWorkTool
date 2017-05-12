//
//  BaseRequestAPI.m
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/12.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import "BaseRequestAPI.h"

@implementation BaseRequestAPI

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.parameters[@"AccountID"] = @"";
        self.parameters[@"cva_token"] = @"";
    }
    return self;
}




@end
