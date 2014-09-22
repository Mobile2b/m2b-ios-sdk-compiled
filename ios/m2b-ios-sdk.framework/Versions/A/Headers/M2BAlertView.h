//
//  M2BAlertView.h
//  Mobile2bSDK
//
//  Created by Robert Vennemann on 18.04.13.
//  Copyright (c) 2013 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^M2BAlertViewOnClickBlock)(NSInteger buttonIndex);

/**
 @deprecated Use https://github.com/ryanmaxwell/UIAlertView-Blocks instead
 */
__attribute__ ((deprecated))
@interface M2BAlertView : UIAlertView

@property (nonatomic, copy) M2BAlertViewOnClickBlock onClickBlock;

- (id)initWithTitle:(NSString *)title
            message:(NSString *)message
  cancelButtonTitle:(NSString *)cancelButtonTitle
  otherButtonTitles:(NSArray *)otherButtonTitles
            onClick:(M2BAlertViewOnClickBlock)onClick;

@end