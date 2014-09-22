//
//  M2BSignUpDelegate.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 28.04.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
@class M2BSignUpViewController;

@protocol M2BSignUpDelegate <NSObject>

- (void)signUpViewController:(M2BSignUpViewController *)signUpViewController
       didSignUpWithUsername:(NSString *)username
                    password:(NSString *)password;

@end
