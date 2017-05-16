//
//  FZNetworkCache.h
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/15.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FZNetworkCache : NSObject

/**
 异步缓存网络数据,根据请求的 URL与parameters
 做KEY存储数据, 这样就能缓存多级页面的数据

 @param data 服务器返回的数据
 @param URL 请求的地址
 @param parameters 请求的参数
 */
+(void)setHTTPCache:(id)data URL:(NSString *)URL parameters:(NSDictionary *)parameters;
/**
 获取缓存数据

 @param URL 请求地址
 @param parameters 请求的参数
 @return 返回的数据
 */
+ (id)getCacheForURL:(NSString *)URL parameters:(NSDictionary *)parameters;
/**
 获取缓存数据（异步获取）
 
 @param URL 请求的地址
 @param parameters 请求的参数
 @param block 异步回调缓存的数据
 */
+ (void)getCacheForURL:(NSString *)URL parameters:(NSDictionary *)parameters withBlock:(void(^)(id<NSCoding> object))block;
/**
 获取网络缓存的总大小 bytes(字节)

 @return 缓存数据的大小
 */
+ (NSInteger)getAllCacheSize;
/**
 删除所有网络缓存
 */
+ (void)removeAllCache;






@end
