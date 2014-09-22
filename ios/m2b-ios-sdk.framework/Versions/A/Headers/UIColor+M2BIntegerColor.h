//
//  UIColor+M2BIntegerColor.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 05.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (M2BIntegerColor)

/**
 *  Creates a color from integer values between 0 and 255, avoiding the need to convert them to a range of 0.0 - 1.0 by hand.
 *
 *  @param red   The red component of the color object, specified as a value from 0 to 255.
 *  @param green The green component of the color object, specified as a value from 0 to 255.
 *  @param blue  The blue component of the color object, specified as a value from 0 to 255.
 *  @param alpha The opacity value of the color object, specified as a value from 0 to 255.
 *
 *  @return The color object. The color information represented by this object is in the device RGB colorspace.
 */
+ (UIColor *)colorUsingIntegerWithRed:(u_int8_t)red green:(u_int8_t)green blue:(u_int8_t)blue alpha:(u_int8_t)alpha;

/**
 *  This is simply a delegate call to colorUsingIntegerWithRed:green:blue:alpha which makes it more explicit that hex values can be used for it.
 *  Call this e.g. like this:
 */
+ (UIColor *)colorFromHexValueWithRed:(u_int8_t)red green:(u_int8_t)green blue:(u_int8_t)blue alpha:(u_int8_t)alpha;

@end
