//
//  M2BCoreDataManager.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 13.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface M2BCoreDataManager : NSObject

/**
 *  Returns the a managed object context bound to a the persistent store coordinator of the receiver. 
 *  The context is lazily initialized so it is only created, once this method is called the first time.
 *  The context is created with NSMainQueueConcurrencyType so it is suitable for usage on the main queue without using blocks and suitable as parent context for any background contexts.
 */
@property (readonly, strong, nonatomic) NSManagedObjectContext *mainManagedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
/**
 *  This check whether the core data stack, i.e. the managed object model, persistent stores, persistent store coordinator and managed object context have all been sucessfully setup without causing it to be initialized if it hasn't been setup, yet.
 */
@property (readonly, getter=isCoreDataStackFullyInitialized) BOOL coreDataStackFullyInitialized;

/**
 *  Initializes the receiver with the given modelName and storeURL which will make it creates the corresponding managedObjectModel, persistentStoreCoordinator and managed object context on request (see properties).
 *
 *  @param modelName The name of a CoreData model file that can be loaded from the main bundle.
 *  @param storeURL  the URL where an old store can be found or a new one should be created
 *
 *  @return a new M2BCoreDataManager that manages the corresponding managed object context, managed object model and persistentStoreCoordinator.
 */
- (instancetype)initWithModelURL:(NSURL *)modelURL storeURL:(NSURL *)storeURL;

/**
 *  Saves the main context, ignoring any errors that may occur. If you are interested in the errors use the -mainManagedObjectContext's save: method.
 *
 *  @return YES if the save operation was successful, no if not.
 */
- (BOOL)saveMainContext;

/**
 *  Deletes the store of this manager and resets the complete Core data stack (managed object context, persistent store coordinator, etc.) if it has already been setup. Should be like a fresh start afterwards.
 *
 *  @return whether or not the operation was successful
 */
- (BOOL)deleteStoreAndResetCoreDataStack:(NSError **)error;

@end
