//
//  M2BManagedObjectWithJSONInitialization.h
//  Mobile2bSDK
//
//  Created by Joachim Kurz on 08.05.14.
//  Copyright (c) 2014 Mobile2b GmbH. All rights reserved.
//

#import <CoreData/CoreData.h>

extern NSString *const M2BJSONInitializationErrorDomain;

typedef NS_ENUM(NSUInteger, M2BJSONInitializationErrorCode) {
    M2BJSONInitializationErrorCodeUnknown,
    M2BJSONInitializationErrorCodeIncorrectCloudIDValue,
    M2BJSONInitializationErrorCodeUnhandledPropertyType,
    M2BJSONInitializationErrorCodeCouldNotFetchObjects,
    M2BJSONInitializationErrorCodeCouldNotParseValue,
    M2BJSONInitializationErrorCodeInvalidCollectionValue,
    M2BJSONInitializationErrorCodeDuplicateObjectForID,
    M2BJSONInitializationErrorCodeMissingCloudIDValue,
    M2BJSONInitializationErrorCodeInvalidJSONPropertyType,
    M2BJSONInitializationErrorCodeMissingValue
};

@interface M2BManagedObjectWithJSONInitialization : NSManagedObject

#pragma mark JSON serialization

// TODO: Comment
- (NSMutableDictionary*)jsonDictionaryRepresentation;
+ (BOOL)shouldSerializePropertyToJSON:(NSPropertyDescription *)propertyDescription;
- (id)jsonDictionaryContainingKeysAndValuesForProperty:(NSPropertyDescription *)propertyDescription;
- (id)convertAttributeValueIntoJSONValue:(id)attributeValue
                            forAttribute:(NSAttributeDescription *)attribute;
- (id)convertRelationshipValueIntoJSONValue:(id)relationShipValue
                            forRelationship:(NSRelationshipDescription *)relationship;

#pragma mark JSON parsing

+ (NSString *)cloudIDKey;
+ (NSString *)entityName;

/**
 *  Finds or (if not found) creates a managed object matching the given data (jsonValue).
 *  @discussion
 *  Tries to find a managed object fitting the data given in jsonvalue (this should usually be an id-value or a dictionar comntaining the id and other data). If none is found it will create the object, and use the given json value to initialize it.
 *  This method calls findObjectInManagedObjectContext:forJSONValue:error: to find the object. If you don't want any existing objects to be returned override that method to always return nil.
 *
 *  @param managedObjectContext the managed object context in which the object should be created.
 *  @param jsonValue            the json value to use to find the object and initialize/update the found/created object
 *  @param errorPtr             if an error occured, this will contain an error pointer on return
 *
 *  @return an already existing or newly created object which has already been initialized/updated with the given data
 */
+ (M2BManagedObjectWithJSONInitialization *)findOrCreateObjectInManagedObjectContext:(NSManagedObjectContext *)managedObjectContext
                                                                        forJSONValue:(id)jsonValue
                                                                               error:(NSError *__autoreleasing *)errorPtr;

/**
 *  Tries to find an object matching the given data. 
 *
 *  @discussion Tries to find a managed object fitting the data given in jsonvalue (this should usually be an id-value or a dictionar comntaining the id and other data). If you don't want to search for objects of this kind, simply return nil.
 *
 *  @param managedObjectContext the managed object context in which the object should be created.
 *  @param jsonValue            the json value to use to find the object and initialize/update the found/created object
 *  @param errorPtr             if an error occured, this will contain an error pointer on return
 *
 *  @return an already existing object matching the given data
 */
+ (M2BManagedObjectWithJSONInitialization *)findObjectInManagedObjectContext:(NSManagedObjectContext *)managedObjectContext
                                                                forJSONValue:(id)jsonValue
                                                                       error:(NSError *__autoreleasing *)errorPtr;

/**
 Takes a dictionary created from a JSON-string and uses it to set the values in the dictionary for the associated keys.
 
 @param jsonDictionary a dictionary containing key-value pairs to be set on this object.
 @param errorPtr   if an error occured, this will contain an error pointer on return
 @return YES if successfully parsed values from jsonDictionary, NO if not
 
 @discussion Only properties that are present in the NSEntityDescription retrieved by [self entity] of the NSManagedObject are set, values for other keys are ignored. Then
 1. for each property, jsonValueForProperty:fromJSONDictionary: is called to get the correct json value from the dictionary.
 2. If no value is present (i.e. the value returned is nil), no value will be set.
 3. If a value is is NSNull it will be interpreted as nil, but in this case nil will actually be set as the value for the property.
 4. For each property (except those in 2.) setJSONValue:forProperty:jsonKey:jsonDictionary:error: is called
 @see convertJSONValue:intoAttributeValueForAttribute:, convertJSONValue:intoRelationshipTargetForRelationship:, setJSONValue:forProperty:jsonKey:jsonDictionary:error:
 */
- (BOOL)setValuesForKeysFromJSONDictionary:(NSDictionary *)jsonDictionary
                                     error:(NSError **)errorPtr;

/**
 *  Convenience method for easy overriding in subclasses if values for a property can't be retrieved from a single field in the json dictionary but must be combined from several fields.
 *
 *  @param propertyDescription the property description for which a json value should be retrieved
 *  @param jsonDictionary      the json dictionary from which to retrieve the value
 *  @param errorPtr            if an error occured, this will contain an error pointer on return
 *
 *  @return the value to use as json value when trying to set the given property of the receiver. [NSNull null] is used if the value should be nil. nil is returned if no entry was found for this property. This value may still be converted to a fitting CoreData value afterwards. This method is just meant to make it easy to combine several values from the dictionary into one, which can then be easily converted using one of the default conversions.
 *
 * @discussion The default implementation uses the dictionary returned by dictionaryMappingPropertyNamesToJSONDictionaryKeys to map property names to keys in the given dictionary. If there is no entry in the mapping dict, the name of the property will be used to extract a value from the json dictionary.
 */
+ (id)jsonValueForProperty:(NSPropertyDescription *)propertyDescription
        fromJSONDictionary:(NSDictionary *)jsonDictionary
                     error:(NSError *__autoreleasing *)errorPtr;

/**
 *  Convenience method for easy overriding in subclasses. This method is called for each property of the managed object.
 *
 *  @param jsonValue           the json value which might have to be converted before being set
 *  @param propertyDescription the target property of the receiver for which the value should be set
 *  @param errorPtr            if an error occured, this will contain an error pointer on return
 *
 *  @return YES if the json value was successfully converted and set for the target property, NO if not
 *
 *  @discussion
 *     The default implementation just checks whether the property is an attribute or a relationship, uses the appropriate conversion method to convert the json value in the correct target value and sets it using setValue:forKey:. Properties which are neither attributes nor relationships are ignored in the default implementation.
 *
 *  @see convertJSONValue:intoAttributeValueForAttribute:, convertJSONValue:intoRelationshipTargetForRelationship:
 */
- (BOOL)setJSONValue:(id)jsonValue
         forProperty:(NSPropertyDescription *)propertyDescription
               error:(NSError *__autoreleasing *)errorPtr;

/**
 Converts a value retrieved from a dictionary built from a JSON string into the kind of value used by the object for the attribute with the given attributeName
 @param jsonValue the jsonValue that should be converted into an appropriate value to be used for the attribute of this object
 @param attribute the attribute the jsonValue should be used for
 @param errorPtr if an error occured, this will contain an error pointer on return. Use this to test whether an error occured, since a nil-return value could also be a valid conversion and is not reliable to detect an error.
 @return the converted value that could be used as a value for the specified attribute
 
 @discussion The default implementation does some basic conversion of string to numbers and the other way round. It does so by checking the expected type of the attribute for the given attributeName. If the expected type is a string but the given value is a number the number will be converted to a string. If the expected type is an integer (16, 32 or 64bit) or float or boolean, but the given value is an NSString it will try to parse the string into a number appropriately.
 
 It also converts some values for special attributes in the BaseObject class, e.g. for the updated key a timestamp retrieved from the jsonDictionary will be converted to an appropriate NSDate object.
 */
- (id)convertJSONValue:(id)jsonValue intoAttributeValueForAttribute:(NSAttributeDescription *)attribute error:(NSError **)errorPtr;;

/**
 Converts a given jsonValue into an appropriate NSManagedObject that should be the target object for the given relationship.
 @param jsonValue the jsonValue that should be converted into an appropriate object to be used for the target of the specified relationship of this object. This is often just some kind of id of another object.
 @param relationship the name of the relationship the jsonValue should be used for
 @param errorPtr  if an error occured, this will contain an error pointer on return. Use this to test whether an error occured, since a nil-return value could also be a valid conversion and is not reliable to detect an error.
 @return an NSManagedObject of the entity specified in the relationship which has the cloudId given by jsonValue. If no entity was found for the given id and no new object could be created or a fetch error occurs, it will return nil. But nil could also be returned as the result of a valid conversion, so it should not be used to detect errors.
 
 @discussion This method could create a new object from the data in the json value or retrieve an existing object or do anything else that results in an NSManagedObject or a set (possibly ordered) of NSManagedObjects being returned.
 The default implementation expects the jsonValue to be a value that can be used as value of the cloudID property to search for another object (e.g. NSNumber of NSString) or an NSArray of such id objects and interprets this as the cloudId (list of cloudIds) of the wanted target object. It then uses the entity specified in the given relationship to fetch an entity of that type that has the cloudId specified by jsonValue. If no such entity is found or the jsonValue is not a suitable id value/NSArray of id values it will return nil.
 */
- (id)convertJSONValue:(id)jsonValue intoRelationshipTargetForRelationship:(NSRelationshipDescription *)relationship error:(NSError **)errorPtr;

/**
 This method is used to define mappings from attribute and relationship names to json dictionary keys. It is used in setValuesForKeysFromJSONDictionary:.
 @return A dictionary containing a key for each attribute name for which an expected JSON dictionary uses a different key than the attribute name. The keys of the dictionary are the attribute names and the values are the keys that are used instead of this attribute name in the json dictionary.
 @discussion If you override this method, make sure to call [super dictionaryMappingPropertyNamesToJSONDictionaryKeys] and add the key-value mappings of that dictionary to yours before returning the combined dictionary.
  @see setValuesForKeysFromJSONDictionary:
 */
+ (NSDictionary *)dictionaryMappingPropertyNamesToJSONDictionaryKeys;

+ (Class)destinationEntityClassForJSONValue:(id)jsonValue
                            forRelationship:(NSRelationshipDescription *)relationship
                                      error:(NSError *__autoreleasing *)errorPtr;

@end
