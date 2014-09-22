//
//  M2BDeviceInformation.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 05.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface M2BDeviceInformation : NSObject


/**
 Generates a custom user agent including app name, app version, platform version, device and locale;
 Example: CityHero/2.0 (iOS 7.0; iPhone5,1; de_DE)
 @return The user agent as a formatted string
 */
+ (NSString *)userAgentString;

@end
