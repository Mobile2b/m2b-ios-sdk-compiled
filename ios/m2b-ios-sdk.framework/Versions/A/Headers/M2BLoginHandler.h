//
//  M2BLoginHandler.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 24.03.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^M2BLoginCompletionBlock)(NSString *username, NSString *password);

// TODO: Find a better name than "LoginHandler"
@protocol M2BLoginHandler <NSObject>

- (void)askUserForLoginCredentialsWithUsername:(NSString *)username
                    afterUsingWrongCredentials:(BOOL)usedWrongCredentials
                               completionBlock:(M2BLoginCompletionBlock)loginComplete;

@end
