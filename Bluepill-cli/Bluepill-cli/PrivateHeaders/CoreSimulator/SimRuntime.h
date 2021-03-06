//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import Foundation;

@class NSArray, NSBundle, NSDictionary, NSString, SimRuntimePairingReuirements;

@interface SimRuntime : NSObject
{
    unsigned int _version;
    unsigned int _equivalentIOSVersion;
    unsigned int _minHostVersion;
    unsigned int _maxHostVersion;
    unsigned int _minCoreSimulatorFrameworkVersion;
    unsigned int _maxCoreSimulatorFrameworkVersion;
    NSString *_name;
    NSString *_identifier;
    NSBundle *_bundle;
    NSString *_root;
    NSString *_versionString;
    NSString *_buildVersionString;
    NSString *_platformIdentifier;
    NSDictionary *_supportedFeatures;
    NSDictionary *_supportedFeaturesConditionalOnDeviceType;
    NSDictionary *_requiredHostServices;
    NSDictionary *_forwardHostNotifications;
    NSDictionary *_forwardHostNotificationsWithState;
    NSString *_platformName;
    NSString *_platformPath;
    NSArray *_supportedProductFamilyIDs;
    SimRuntimePairingReuirements *_pairingRequirements;
    NSArray *_preferredPairingDeviceTypes;
    NSDictionary *_environment_extra;
    void *_libLaunchHostHandle;
    NSDictionary *_aliases;
}

+ (unsigned int)equivalentIOSVersionForVersion:(unsigned int)arg1 profile:(id)arg2 platformIdentifier:(id)arg3;
+ (id)updatedMaxCoreSimulatorVersions;
+ (id)updatedMaxHostVersions;
@property(nonatomic) unsigned int maxCoreSimulatorFrameworkVersion; // @synthesize maxCoreSimulatorFrameworkVersion=_maxCoreSimulatorFrameworkVersion;
@property(nonatomic) unsigned int minCoreSimulatorFrameworkVersion; // @synthesize minCoreSimulatorFrameworkVersion=_minCoreSimulatorFrameworkVersion;
@property(nonatomic) unsigned int maxHostVersion; // @synthesize maxHostVersion=_maxHostVersion;
@property(nonatomic) unsigned int minHostVersion; // @synthesize minHostVersion=_minHostVersion;
@property(copy, nonatomic) NSDictionary *aliases; // @synthesize aliases=_aliases;
@property(nonatomic) void *libLaunchHostHandle; // @synthesize libLaunchHostHandle=_libLaunchHostHandle;
@property(copy, nonatomic) NSDictionary *environment_extra; // @synthesize environment_extra=_environment_extra;
@property(copy, nonatomic) NSArray *preferredPairingDeviceTypes; // @synthesize preferredPairingDeviceTypes=_preferredPairingDeviceTypes;
@property(retain, nonatomic) SimRuntimePairingReuirements *pairingRequirements; // @synthesize pairingRequirements=_pairingRequirements;
@property(copy, nonatomic) NSArray *supportedProductFamilyIDs; // @synthesize supportedProductFamilyIDs=_supportedProductFamilyIDs;
@property(copy, nonatomic) NSString *platformPath; // @synthesize platformPath=_platformPath;
@property(copy, nonatomic) NSString *platformName; // @synthesize platformName=_platformName;
@property(copy, nonatomic) NSDictionary *forwardHostNotificationsWithState; // @synthesize forwardHostNotificationsWithState=_forwardHostNotificationsWithState;
@property(copy, nonatomic) NSDictionary *forwardHostNotifications; // @synthesize forwardHostNotifications=_forwardHostNotifications;
@property(copy, nonatomic) NSDictionary *requiredHostServices; // @synthesize requiredHostServices=_requiredHostServices;
@property(copy, nonatomic) NSDictionary *supportedFeaturesConditionalOnDeviceType; // @synthesize supportedFeaturesConditionalOnDeviceType=_supportedFeaturesConditionalOnDeviceType;
@property(copy, nonatomic) NSDictionary *supportedFeatures; // @synthesize supportedFeatures=_supportedFeatures;
@property(nonatomic) unsigned int equivalentIOSVersion; // @synthesize equivalentIOSVersion=_equivalentIOSVersion;
@property(nonatomic) unsigned int version; // @synthesize version=_version;
@property(copy, nonatomic) NSString *platformIdentifier; // @synthesize platformIdentifier=_platformIdentifier;
@property(copy, nonatomic) NSString *buildVersionString; // @synthesize buildVersionString=_buildVersionString;
@property(copy, nonatomic) NSString *versionString; // @synthesize versionString=_versionString;
@property(copy, nonatomic) NSString *root; // @synthesize root=_root;
@property(retain, nonatomic) NSBundle *bundle; // @synthesize bundle=_bundle;
@property(copy, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
//- (void).cxx_destruct;
- (id)platformRuntimeOverlay;
- (CDUnknownFunctionPointerType)launch_sim_set_death_handler;
- (CDUnknownFunctionPointerType)launch_sim_waitpid;
- (CDUnknownFunctionPointerType)launch_sim_spawn;
- (CDUnknownFunctionPointerType)launch_sim_getenv;
- (CDUnknownFunctionPointerType)launch_sim_bind_session_to_port;
- (CDUnknownFunctionPointerType)launch_sim_find_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_unregister_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_register_endpoint;
- (BOOL)isAvailableWithError:(id *)arg1;
@property(readonly, nonatomic) BOOL available;
- (id)dyld_simPath;
- (BOOL)createInitialContentPath:(id)arg1 error:(id *)arg2;
- (id)sampleContentPath;
- (long long)compare:(id)arg1;
- (BOOL)supportsFeatureConditionally:(id)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (BOOL)supportsDeviceType:(id)arg1;
- (id)environment;
- (id)description;
- (id)initWithBundle:(id)arg1;
- (id)initWithPath:(id)arg1;

@end

