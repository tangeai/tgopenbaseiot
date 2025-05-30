/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#import "OOSMTLModel.h"

void OOSmtl_loadMTLNSCoding(void);

// Defines how a MTLModel property key should be encoded into an archive.
//
// MTLModelEncodingBehaviorExcluded      - The property should never be encoded.
// MTLModelEncodingBehaviorUnconditional - The property should always be
//                                         encoded.
// MTLModelEncodingBehaviorConditional   - The object should be encoded only
//                                         if unconditionally encoded elsewhere.
//                                         This should only be used for object
//                                         properties.
typedef enum : NSUInteger {
    OOSMTLModelEncodingBehaviorExcluded = 0,
    OOSMTLModelEncodingBehaviorUnconditional,
    OOSMTLModelEncodingBehaviorConditional,
} OOSMTLModelEncodingBehavior;

// Implements default archiving and unarchiving behaviors for MTLModel.
@interface OOSMTLModel (NSCoding) <NSCoding>

// Initializes the receiver from an archive.
//
// This will decode the original +modelVersion of the archived object, then
// invoke -decodeValueForKey:withCoder:modelVersion: for each of the receiver's
// +propertyKeys.
//
// Returns an initialized model object, or nil if a decoding error occurred.
- (id)initWithCoder:(NSCoder *)coder;

// Archives the receiver using the given coder.
//
// This will encode the receiver's +modelVersion, then the receiver's properties
// according to the behaviors specified in +encodingBehaviorsByPropertyKey.
- (void)encodeWithCoder:(NSCoder *)coder;

// Determines how the +propertyKeys of the class are encoded into an archive.
// The values of this dictionary should be boxed MTLModelEncodingBehavior
// values.
//
// Any keys not present in the dictionary will be excluded from the archive.
//
// Subclasses overriding this method should combine their values with those of
// `super`.
//
// Returns a dictionary mapping the receiver's +propertyKeys to default encoding
// behaviors. If a property is an object with `weak` semantics, the default
// behavior is MTLModelEncodingBehaviorConditional; otherwise, the default is
// MTLModelEncodingBehaviorUnconditional.
+ (NSDictionary *)encodingBehaviorsByPropertyKey;

// Determines the classes that are allowed to be decoded for each of the
// receiver's properties when using <NSSecureCoding>. The values of this
// dictionary should be NSArrays of Class objects.
//
// If any encodable keys (as determined by +encodingBehaviorsByPropertyKey) are
// not present in the dictionary, an exception will be thrown during secure
// encoding or decoding.
//
// Subclasses overriding this method should combine their values with those of
// `super`.
//
// Returns a dictionary mapping the receiver's encodable keys (as determined by
// +encodingBehaviorsByPropertyKey) to default allowed classes, based on the
// type that each property is declared as. If type of an encodable property
// cannot be determined (e.g., it is declared as `id`), it will be omitted from
// the dictionary, and subclasses must provide a valid value to prevent an
// exception being thrown during encoding/decoding.
+ (NSDictionary *)allowedSecureCodingClassesByPropertyKey;

// Decodes the value of the given property key from an archive.
//
// By default, this method looks for a `-decode<Key>WithCoder:modelVersion:`
// method on the receiver, and invokes it if found.
//
// If the custom method is not implemented and `coder` does not require secure
// coding, `-[NSCoder decodeObjectForKey:]` will be invoked with the given
// `key`.
//
// If the custom method is not implemented and `coder` requires secure coding,
// `-[NSCoder decodeObjectOfClasses:forKey:]` will be invoked with the
// information from +allowedSecureCodingClassesByPropertyKey and the given `key`. The
// receiver must conform to <NSSecureCoding> for this to work correctly.
//
// key          - The property key to decode the value for. This argument cannot
//                be nil.
// coder        - The NSCoder representing the archive being decoded. This
//                argument cannot be nil.
// modelVersion - The version of the original model object that was encoded.
//
// Returns the decoded and boxed value, or nil if the key was not present.
- (id)decodeValueForKey:(NSString *)key withCoder:(NSCoder *)coder modelVersion:(NSUInteger)modelVersion;

// The version of this MTLModel subclass.
//
// This version number is saved in archives so that later model changes can be
// made backwards-compatible with old versions.
//
// Subclasses should override this method to return a higher version number
// whenever a breaking change is made to the model.
//
// Returns 0.
+ (NSUInteger)modelVersion;

@end
