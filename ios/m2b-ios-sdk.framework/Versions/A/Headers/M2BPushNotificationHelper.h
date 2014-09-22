//
//  M2BPushNotificationHelper.h
//  Mobile2bSDK
//
//  Created by Robert Vennemann on 12.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface M2BPushNotificationHelper : NSObject

+ (NSString *)stringFromDeviceToken:(NSData *)deviceToken;

@end
