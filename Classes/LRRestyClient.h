//
//  LRRestyClient.h
//  LRResty
//
//  Created by Luke Redpath on 03/08/2010.
//  Copyright 2010 LJR Software Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRRestyClientResponseDelegate.h"
#import "LRRestyClientDelegate.h"

@class LRRestyResponse;
@class LRRestyRequest;
@class LRRestyStreamingClient;

typedef void (^LRRestyResponseBlock)(LRRestyResponse *response);
typedef void (^LRRestyRequestBlock)(LRRestyRequest *request);

@interface LRRestyClient : NSObject {
  NSOperationQueue *operationQueue;
  NSMutableArray *requestModifiers;
  id<LRRestyClientDelegate> clientDelegate;
}
@property (nonatomic, assign) id<LRRestyClientDelegate> delegate;

- (void)getURL:(NSURL *)url parameters:(NSDictionary *)parameters headers:(NSDictionary *)headers delegate:(id<LRRestyClientResponseDelegate>)delegate;
- (void)postURL:(NSURL *)url payload:(id)payload headers:(NSDictionary *)headers delegate:(id<LRRestyClientResponseDelegate>)delegate;
- (void)putURL:(NSURL *)url payload:(id)payload headers:(NSDictionary *)headers delegate:(id<LRRestyClientResponseDelegate>)delegate;
- (void)setHandlesCookiesAutomatically:(BOOL)shouldHandleCookies;
- (void)attachRequestModifier:(LRRestyRequestBlock)block;
- (void)setUsername:(NSString *)username password:(NSString *)password;
- (LRRestyStreamingClient *)streamingClient;
@end

@interface LRRestyClient (Blocks)
- (void)getURL:(NSURL *)url parameters:(NSDictionary *)parameters headers:(NSDictionary *)headers withBlock:(LRRestyResponseBlock)block;
- (void)postURL:(NSURL *)url payload:(id)payload headers:(NSDictionary *)headers withBlock:(LRRestyResponseBlock)block;
- (void)putURL:(NSURL *)url payload:(id)payload headers:(NSDictionary *)headers withBlock:(LRRestyResponseBlock)block;
@end

