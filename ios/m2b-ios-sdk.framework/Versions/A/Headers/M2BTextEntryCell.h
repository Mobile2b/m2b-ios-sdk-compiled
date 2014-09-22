//
//  M2BTextEntryCell.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 30.01.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import "M2BBasicTextEntryCell.h"
@class M2BTextEntryCell;

@protocol M2BTextEntryCellDelegate <NSObject>

@optional
- (void)textEntryCellDidEndEditing:(M2BTextEntryCell *)textEntryCell;
- (void)textEntryCellDidChangeText:(M2BTextEntryCell *)textEntryCell;

@end

@interface M2BTextEntryCell : M2BBasicTextEntryCell




@property (assign) UITextBorderStyle editingBorderStyle;
@property (assign) UITextBorderStyle displayBorderStyle;

@property (weak) id<M2BTextEntryCellDelegate> delegate;

@end
