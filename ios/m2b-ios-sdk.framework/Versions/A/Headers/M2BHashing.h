//
//  M2BHashing.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 05.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface M2BHashing : NSObject

+ (NSString *)sha256StringFromString:(NSString *)string;
+ (NSString *)md5StringFromString:(NSString *)string;

@end
