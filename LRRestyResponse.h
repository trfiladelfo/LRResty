//
//  LRRestyResponse.h
//  LRResty
//
//  Created by Luke Redpath on 03/08/2010.
//  Copyright 2010 LJR Software Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LRRestyResponse : NSObject {
  NSUInteger status;
  NSData *responseData;
}
- (id)initWithStatus:(NSInteger)statusCode responseData:(NSData *)data;
- (NSUInteger)status;
- (NSString *)asString;
@end
