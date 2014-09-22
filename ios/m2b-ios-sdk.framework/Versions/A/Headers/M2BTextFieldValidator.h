//
//  M2BFieldValidator.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 28.04.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol M2BTextFieldValidator <NSObject>

- (BOOL)providesCustomValidationForTextField:(UITextField *)textField;
- (BOOL)validateTextField:(UITextField *)textField error:(NSError **)error;

@end
