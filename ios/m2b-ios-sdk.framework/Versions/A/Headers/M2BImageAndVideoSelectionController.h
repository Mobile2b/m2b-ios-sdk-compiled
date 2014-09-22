//
//  M2BPhotoVideoSelectionController.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 12.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

@import UIKit;
@class M2BImageAndVideoSelectionController;

@protocol M2BImageAndVideoSelectionDelegate <NSObject>

@optional

- (void)imageAndVideoSelectionController:(M2BImageAndVideoSelectionController *)selectionController didSelectImage:(UIImage *)image fromLibrary:(BOOL)wasPickedFromLibrary;
- (void)imageAndVideoSelectionController:(M2BImageAndVideoSelectionController *)selectionController didSelectVideoAtURL:(NSURL *)videoURL fromLibrary:(BOOL)wasPickedFromLibrary;
- (void)imageAndVideoSelectionControllerDidCancelSelection:(M2BImageAndVideoSelectionController *)selectionController;

@end

@interface M2BImageAndVideoSelectionController : NSObject

- (instancetype)initWithViewControllerToPresentPickerViewControllerOn:(UIViewController *)viewControllerToPresentOn;

@property (assign) BOOL allowedToChooseVideo;
@property (assign) BOOL allowedToChooseImage;
@property (assign) BOOL allowedToTakeNewPictureOrVideo;
@property (assign) BOOL allowedToChooseFromLibrary;
@property (assign) BOOL allowsEditing;
@property (assign) UIImagePickerControllerCameraDevice initialCameraDevice;

/// According to the HIG, an action sheet can have a title, but it should be avoided. Use this to decide whether a title should be displayed (if an action sheet is displayed at all). Default is NO (as the HIG recommends).
@property (assign) BOOL shouldShowActionSheetTitle;

@property (readonly) BOOL canChooseVideo;
@property (readonly) BOOL canChooseImage;
@property (readonly) BOOL canTakeNewPictureOrVideo;
@property (readonly) BOOL canChooseFromLibrary;

@property (strong) NSString *actionSheetTitle;
@property (strong) NSString *takePictureOrVideoButtonTitle;
@property (strong) NSString *choosePictureOrVideoFromLibraryButtonTitle;

@property (weak) id<M2BImageAndVideoSelectionDelegate> delegate;

- (IBAction)presentSelectionController:(id)sender;
- (UIActionSheet *)actionSheetWithOptionsForSelectionController;

@end
