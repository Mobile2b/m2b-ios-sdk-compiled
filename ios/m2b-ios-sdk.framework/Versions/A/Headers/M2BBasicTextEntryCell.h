//
//  M2BBasicTextEntryCell.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 14.07.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface M2BBasicTextEntryCell : UITableViewCell

/// If you just want to set the text of the input control use -setText: instead
@property (strong, nonatomic) IBOutlet UIControl *inputControl;
@property (strong) IBOutlet UILabel *labelForInputControl;

@property (strong, nonatomic) NSString *text;

@end
