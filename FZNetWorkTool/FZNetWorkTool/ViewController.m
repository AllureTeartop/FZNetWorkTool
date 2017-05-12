//
//  ViewController.m
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/12.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import "ViewController.h"
#import "TestAPI.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //使用举例
    TestAPI *api = [[TestAPI alloc] initWithUserName:@"" PassWord:@""];
    [api startRequestWithSuccessFn:^(id successValue) {
        
    } FailureFn:^(id failurValue) {
        
    } ErrorFn:^(id error) {
        
    }];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
