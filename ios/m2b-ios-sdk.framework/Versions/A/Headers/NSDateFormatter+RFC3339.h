//
//  NSDateFormatter+RFC3339.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 30.04.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDateFormatter (RFC3339)

+ (NSDateFormatter *)dateFormatterForRFC3339;

+ (NSDateFormatter *)dateFormatterForRFC3339WithMilliseconds;
+ (NSDateFormatter *)dateFormatterForRFC3339WithoutMilliseconds;

@end
