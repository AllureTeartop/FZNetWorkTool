//
//  FZNetworking.h
//  FZNetWorkTool
//
//  Created by Florence on 2017/5/15.
//  Copyright © 2017年 AllureTeartop. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FZNetworkCache.h"
#import <UIKit/UIKit.h>
#import "AFNetworking.h"
#import "AFNetworkActivityIndicatorManager.h"

typedef NS_ENUM(NSUInteger, FZNetworkStatusType){
    /** 未知网络*/
    FZNetworkStatusUnknown,
    /** 无网络*/
    FZNetworkStatusNotReachable,
    /** 蜂窝网络*/
    FZNetworkStatusReachableViaWWAN,
    /** WIFI网络*/
    FZNetworkStatusReachableViaWiFi
};

typedef NS_ENUM(NSUInteger, FZRequestSerializer) {
    /** 设置请求数据为JSON格式*/
    FZRequestSerializerJSON,
    /** 设置请求数据为二进制格式*/
    FZRequestSerializerHTTP,
};
typedef NS_ENUM(NSUInteger, FZResponseSerializer) {
    /** 设置响应数据为JSON格式*/
    FZResponseSerializerJSON,
    /** 设置响应数据为二进制格式*/
    FZResponseSerializerHTTP,
};



/** 请求成功的Block */
typedef void (^NetworkSuccessFn)(id successValue);
/** 请求失败的Block */
typedef void (^NetworkFailureFn)(id failurValue);
/** 请求错误的Block */
typedef void (^NetWorkErrorFn)(id errorValue);
/** 网络请求进度的Block */
typedef void (^NetWorkProgressFn)(NSProgress *progress);
/** 网络请求进度的Block */
typedef void (^NetWorkStatus)(FZNetworkStatusType type);
/** 缓存的Block */
typedef void(^FZRequestCache)(id cacheValue);


@interface FZNetworking : NSObject


/**
 POST请求

 @param URL 请求地址
 @param parameters 请求参数
 @param success 成功的回调
 @param failure 失败的回调
 @return 返回的数据
 */
+(NSURLSessionTask *)POST:(NSString *)URL
               parameters:(id)parameters
                SuccessFn:(NetworkSuccessFn)success
                FailureFn:(NetworkFailureFn)failure;

/**
 POST请求(带缓存的)

 @param URL 请求地址
 @param parameters 请求参数
 @param cache 缓存数的回调
 @param success 成功的回调
 @param failure 失败的回调
 @return 返回的数据
 */
+(NSURLSessionTask *)POST:(NSString *)URL
               parameters:(id)parameters
                  CacheFn:(FZRequestCache)cache
                SuccessFn:(NetworkSuccessFn)success
                FailureFn:(NetworkFailureFn)failure;

/**
 GET请求

 @param URL 请求地址
 @param parameters 请求参数
 @param success 成功的回调
 @param failure 失败的回调
 @return 返回的数据
 */
+(NSURLSessionTask *)GET:(NSString *)URL
               parameters:(id)parameters
                SuccessFn:(NetworkSuccessFn)success
                FailureFn:(NetworkFailureFn)failure;

/**
 GET请求(带缓存的)

 @param URL 请求地址
 @param parameters 请求参数
 @param cache 缓存数的回调
 @param success 成功的回调
 @param failure 失败的回调
 @return 返回的数据
 */
+(NSURLSessionTask *)GET:(NSString *)URL
               parameters:(id)parameters
                  CacheFn:(FZRequestCache)cache
                SuccessFn:(NetworkSuccessFn)success
                FailureFn:(NetworkFailureFn)failure;

/**
 上传单/多张图片

 @param URL 请求地址
 @param parameters 请求参数
 @param name 图片对应服务器上的字段
 @param images 图片数组
 @param fileNames 图片文件名数组, 可以为nil, 数组内的文件名默认为当前日期时间"yyyyMMddHHmmss"
 @param imageScale 图片文件压缩比 范围 (0.f ~ 1.f)
 @param imageType 图片文件的类型,例:png、jpg(默认类型)....
 @param progress 上传进度信息
 @param success 请求成功的回调
 @param failure 请求失败的回调
 @return 返回的对象
 */
+ (NSURLSessionTask *)uploadImagesWithURL:(NSString *)URL
                               parameters:(id)parameters
                                     name:(NSString *)name
                                   images:(NSArray<UIImage *> *)images
                                fileNames:(NSArray<NSString *> *)fileNames
                               imageScale:(CGFloat)imageScale
                                imageType:(NSString *)imageType
                               ProgressFn:(NetWorkProgressFn)progress
                                SuccessFn:(NetworkSuccessFn)success
                                FailureFn:(NetworkFailureFn)failure;

/**
 上传文件

 @param URL 请求地址
 @param parameters 请求参数
 @param name 文件对应服务器上的字段
 @param filePath 文件本地的沙盒路径
 @param progress 上传进度信息
 @param success 请求成功的回调
 @param failure 请求失败的回调
 @return 返回的对象
 */
+ (NSURLSessionTask *)uploadFileWithURL:(NSString *)URL
                                      parameters:(id)parameters
                                            name:(NSString *)name
                                        filePath:(NSString *)filePath
                             ProgressFn:(NetWorkProgressFn)progress
                              SuccessFn:(NetworkSuccessFn)success
                              FailureFn:(NetworkFailureFn)failure;

/**
 上传视频

 @param URL 请求地址
 @param parameters 请求参数
 @param name 文件对应服务器上的字段
 @param filePath 文件本地的沙盒路径
 @param progress 上传进度信息
 @param success 请求成功的回调
 @param failure 请求失败的回调
 @return 返回的对象
 */
+ (NSURLSessionTask *)uploadVideoWithURL:(NSString *)URL
                             parameters:(id)parameters
                                   name:(NSString *)name
                               filePath:(NSString *)filePath
                             ProgressFn:(NetWorkProgressFn)progress
                              SuccessFn:(NetworkSuccessFn)success
                              FailureFn:(NetworkFailureFn)failure;
/**
 下载文件

 @param URL 请求地址
 @param fileDir 文件存储目录(默认存储目录为Download)
 @param progress 文件下载进度
 @param success 下载成功的回调
 @param failure 下载失败的回调
 @return 返回NSURLSessionDownloadTask实例
 */
+ (NSURLSessionTask *)downloadFileWithURL:(NSString *)URL
                              fileDir:(NSString *)fileDir
                             progress:(NetWorkProgressFn)progress
                              success:(NetworkSuccessFn)success
                                  failure:(NetworkFailureFn)failure;

/**
 有无网络

 @return 有网YES, 无网:NO
 */
+ (BOOL)isNetwork;
/**
 蜂窝网络

 @return YES, 反之:NO
 */
+ (BOOL)isWWANNetwork;
/**
 WiFi网络

 @return YES, 反之:NO
 */
+ (BOOL)isWiFiNetwork;
/**
 实时获取网络状态，通过block回调

 @param networkStatus 网络状态
 */
+ (void)networkStatusWithBlock:(NetWorkStatus)networkStatus;



#pragma mark - 设置AFHTTPSessionManager相关属性
/**
 在开发中,如果以下的设置方式不满足项目的需求,就调用此方法获取AFHTTPSessionManager实例进行自定义设置

 @param sessionManager AFHTTPSessionManager的实例
 */
+ (void)setAFHTTPSessionManagerProperty:(void(^)(AFHTTPSessionManager *sessionManager))sessionManager;

/**
 *  设置网络请求参数的格式:默认为二进制格式
 *
 *  @param requestSerializer PPRequestSerializerJSON(JSON格式),PPRequestSerializerHTTP(二进制格式),
 */


/**
 设置网络请求参数的格式:默认为二进制格式

 @param requestSerializer FZRequestSerializerJSON(JSON格式),FZRequestSerializerHTTP(二进制格式),
 */
+ (void)setRequestSerializer:(FZRequestSerializer)requestSerializer;
/**
 设置服务器响应数据格式:默认为JSON格式

 @param responseSerializer FZRequestSerializerJSON(JSON格式),FZRequestSerializerHTTP(二进制格式),
 */
+ (void)setResponseSerializer:(FZResponseSerializer)responseSerializer;
/**
 设置请求超时时间:默认为15S

 @param time 时长
 */
+ (void)setRequestTimeoutInterval:(NSTimeInterval)time;
/**
 设置请求头

 @param value 1
 @param field 2
 */
+ (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
/**
 是否打开网络状态转圈菊花:默认打开

 @param open YES(打开), NO(关闭)
 */
+ (void)openNetworkActivityIndicator:(BOOL)open;
/**
 配置自建证书的Https请求

 @param cerPath 自建Https证书的路径
 @param validatesDomainName 是否需要验证域名，默认为YES. 如果证书的域名与请求的域名不一致，需设置为NO; 即服务器使用其他可信任机构颁发
 的证书，也可以建立连接，这个非常危险, 建议打开.validatesDomainName=NO, 主要用于这种情况:客户端请求的是子域名, 而证书上的是另外
 一个域名。因为SSL证书上的域名是独立的,假如证书上注册的域名是www.google.com, 那么mail.google.com是无法验证通过的.
 */
+ (void)setSecurityPolicyWithCerPath:(NSString *)cerPath validatesDomainName:(BOOL)validatesDomainName;



























@end
