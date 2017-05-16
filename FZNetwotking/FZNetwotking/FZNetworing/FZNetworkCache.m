//
//  FZNetworkCache.m
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/15.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import "FZNetworkCache.h"
#import "YYCache.h"


@implementation FZNetworkCache
static NSString *const NetworkCache = @"NetworkCache";
static YYCache *_dataCache;

+ (void)initialize {
    _dataCache = [YYCache cacheWithName:NetworkCache];
}
#pragma mark ------- 缓存网络数据 ----------
+(void)setHTTPCache:(id)data URL:(NSString *)URL parameters:(NSDictionary *)parameters{
    
    NSString *cacheKey = [self cacheKeyWithURL:URL parameters:parameters];
    //异步缓存,不会阻塞主线程
    [_dataCache setObject:data forKey:cacheKey withBlock:nil];
}
#pragma mark ------ 获取缓存数据 -----------
+ (id)getCacheForURL:(NSString *)URL parameters:(NSDictionary *)parameters {
    NSString *cacheKey = [self cacheKeyWithURL:URL parameters:parameters];
    return [_dataCache objectForKey:cacheKey];
}
+ (void)getCacheForURL:(NSString *)URL parameters:(NSDictionary *)parameters withBlock:(void(^)(id<NSCoding> object))block {
    NSString *cacheKey = [self cacheKeyWithURL:URL parameters:parameters];
    [_dataCache objectForKey:cacheKey withBlock:^(NSString * _Nonnull key, id<NSCoding>  _Nonnull object) {
        dispatch_async(dispatch_get_main_queue(), ^{
            block(object);
        });
    }];
}
#pragma mark ------ 获取所有缓存数据的大小 ---------
+ (NSInteger)getAllCacheSize{
    return [_dataCache.diskCache totalCost];
}
#pragma mark ------ 清空缓存 -------------
+ (void)removeAllCache{
    [_dataCache.diskCache removeAllObjects];
}
+ (NSString *)cacheKeyWithURL:(NSString *)URL parameters:(NSDictionary *)parameters {
    if(!parameters){return URL;};
    // 将参数字典转换成字符串
    NSData *stringData = [NSJSONSerialization dataWithJSONObject:parameters options:0 error:nil];
    NSString *paraString = [[NSString alloc] initWithData:stringData encoding:NSUTF8StringEncoding];
    
    // 将URL与转换好的参数字符串拼接在一起,成为最终存储的KEY值
    NSString *cacheKey = [NSString stringWithFormat:@"%@%@",URL,paraString];
    
    return cacheKey;
}


@end
