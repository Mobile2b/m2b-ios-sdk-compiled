//
//  M2BLoginViewController.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 13.03.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "M2BLoginHandler.h"
#import "M2BSignUpDelegate.h"

extern NSString *const M2BSignUpSegueIdentifier;

@interface M2BLoginViewController : UIViewController <UITextFieldDelegate, M2BSignUpDelegate>

@property (weak, nonatomic) IBOutlet UITextField *usernameField;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
@property (weak, nonatomic) IBOutlet UILabel *wrongPasswordLabel;

/// should only be used for setting the username, not for getting it
@property (strong, nonatomic) NSString *username;
@property (assign) BOOL shouldShowIncorrectCredentialsErrorMessage;
@property (strong) M2BLoginCompletionBlock loginComplete;

- (IBAction)login:(id)sender;
- (IBAction)endEditing:(id)sender;

@end
