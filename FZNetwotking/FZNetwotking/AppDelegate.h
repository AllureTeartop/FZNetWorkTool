//
//  AppDelegate.h
//  FZNetwotking
//
//  Created by Florence on 2017/5/15.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

