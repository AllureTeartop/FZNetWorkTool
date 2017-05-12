//
//  TestAPI.m
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/12.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import "TestAPI.h"

@implementation TestAPI


-(instancetype)initWithUserName:(NSString *)userName PassWord:(NSString *)passWord{
    self = [super init];
    if (self) {
        self.parameters[@"userName"] = userName;
        self.parameters[@"passWord"] = passWord;
        self.urlaction = @"getMsg";
    }
    return self;
}



@end
