//
//  SDwatchOSVersion.h
//  SDVersion
//
//  Created by Jeff Kelley on 6/29/16.
//  Copyright © 2016 Sebastian Dobrincu. All rights reserved.
//

#import <WatchKit/WatchKit.h>

typedef NS_ENUM(NSInteger, DeviceVersion) {
    
    AppleWatch        NS_ENUM_AVAILABLE_IOS(8.2)  = 1,
    AppleWatchSeries1 NS_ENUM_AVAILABLE_IOS(10.0) = 4,
    AppleWatchSeries2 NS_ENUM_AVAILABLE_IOS(10.0) = 6,
    
    Simulator                                     = 0,
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
static NSString *DeviceVersionNames[] = {
    [AppleWatch]        = @"Apple Watch",
    [AppleWatchSeries1] = @"Apple Watch Series 1",
    [AppleWatchSeries2] = @"Apple Watch Series 2",
    
    [Simulator]         = @"Simulator",
};
#pragma clang diagnostic pop

typedef NS_ENUM(NSInteger, DeviceSize) {
    UnknownSize = 0,
    
    Screen38mm NS_ENUM_AVAILABLE_IOS(8.2) = 1,
    Screen42mm NS_ENUM_AVAILABLE_IOS(8.2) = 2,
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
static NSString *DeviceSizeNames[] = {
    [UnknownSize] = @"Unknown Size",
    [Screen38mm]  = @"38mm",
    [Screen42mm]  = @"42mm",
};
#pragma clang diagnostic pop

@interface SDwatchOSVersion : NSObject

#define watchOSVersionEqualTo(v)                  ([[[WKInterfaceDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define watchOSVersionGreaterThan(v)              ([[[WKInterfaceDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define watchOSVersionGreaterThanOrEqualTo(v)     ([[[WKInterfaceDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define watchOSVersionLessThan(v)                 ([[[WKInterfaceDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define watchOSVersionLessThanOrEqualTo(v)        ([[[WKInterfaceDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

+ (DeviceVersion)deviceVersion;
+ (DeviceSize)deviceSize;
+ (NSString*)deviceName;

@end
