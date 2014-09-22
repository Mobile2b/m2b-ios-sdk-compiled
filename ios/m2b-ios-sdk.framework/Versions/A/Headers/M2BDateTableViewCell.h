//
//  M2BDateTableViewCell.h
//  GiraLib
//
//  Created by Joachim Kurz on 24.06.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface M2BDateTableViewCell : UITableViewCell

@property (readonly) UIDatePicker *datePicker;
@property (nonatomic, strong) NSDate *date;
@property (strong) NSDateFormatter *dateFormatter;

@end
