//
//  M2BActionSheet.h
//  Mobile2bSDK
//
//  Created by Robert Vennemann on 19.04.13.
//  Copyright (c) 2013 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^M2BActionSheetOnClickBlock)(NSInteger buttonIndex);

@interface M2BActionSheet : UIActionSheet

@property (nonatomic, copy) M2BActionSheetOnClickBlock onClickBlock;

- (id)initWithTitle:(NSString *)title
  cancelButtonTitle:(NSString *)cancelButtonTitle
destructiveButtonTitle:(NSString *)destructiveButtonTitle
  otherButtonTitles:(NSArray *)otherButtonTitles
            onClick:(M2BActionSheetOnClickBlock)onClick;

@end
