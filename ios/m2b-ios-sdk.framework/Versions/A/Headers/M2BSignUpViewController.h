//
//  M2BSignUpViewController.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 04.04.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "M2BSignUpDelegate.h"
#import "M2BTextFieldValidator.h"

@interface M2BSignUpViewController : UITableViewController

@property (weak) id<M2BSignUpDelegate> delegate;
@property (weak) id<M2BTextFieldValidator> textFieldValidator;

@property (weak, nonatomic) IBOutlet UITextField *userNameField;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
@property (weak, nonatomic) IBOutlet UITextField *passwordRepeatField;
@property (strong) IBOutlet UIView *errorMessageView;
@property (weak, nonatomic) IBOutlet UILabel *errorLabel;
@property (weak, nonatomic) IBOutlet UITableViewCell *signUpCell;

/**
 *  This property is used to determine the next responder if "return" is tapped in any of the text fields
 *  To make this work, you need to set the signup controller as the delegate of the text fields.
 */
@property (strong, nonatomic) IBOutletCollection(UITextField) NSArray *inputTextFieldsInOrder;

/**
 *  The required text fields. Any of the required text fields need to have some text entered to be valid. This is independent of any further validation.
 */
@property (strong, nonatomic) IBOutletCollection(UITextField) NSArray *requiredTextFields;

/**
 *  The text fields in which emails should be entered. All text fields entered here are required to contain a valid email adress (if they contain any). They could still be empty if they are not contained in -requiredTextFields in order.
 */
@property (strong, nonatomic) IBOutletCollection(UITextField) NSArray *emailFields;

/**
  * Will check the input and if it's valid, send a signup request via sendSignUpRequestWithSuccess:failure:. If that succeeds it tells the delegate about a successfult signup.
  */
- (IBAction)signup:(id)sender;


/** Gathers data from the view of the receiver and sends it to a remote service, trying to register the user with the server.
  Often, this is the only method subclasses have to override. */
- (void)sendSignUpRequestWithSuccess:(void (^)())success
                             failure:(void (^)(NSError *error))failure;

/**
 * Scrolls to the given text field. This could be called to e.g. highlight an erroneous input field.
 */
- (void)scrollToTextFieldIfNecessary:(UITextField *)textField;

/**
 * @return the color used to mark fields and labels as erroneous
 */
- (UIColor *)errorMarkingColor;

/**
 *  This method checks the current input, highlights all erroneous fields and displays an error message if necessary.
 *
 *  @return YES if the input is valid, NO if an error was found
 */
- (BOOL)checkInputAndHighlightErrors;

/**
 *  Shows the given error message in the specified -errorMarkingColor in the common error message view.
 *
 *  @param errorMessage the error message to display.
 */
- (void)showErrorMessage:(NSString *)errorMessage;

/**
 *  Clears any displayed error message from the display.
 */
- (void)clearErrorMessage;

/**
 *  Changes the text color of the given label to the -errorMarkingColor
 *
 *  @param label the label to mark
 */
- (void)markLabelAsErroneous:(UILabel *)label;

@end
