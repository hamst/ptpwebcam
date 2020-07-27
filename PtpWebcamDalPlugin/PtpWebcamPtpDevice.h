//
//  PtpWebcamPtpDevice.h
//  PtpWebcamDalPlugin
//
//  Created by Dömötör Gulyás on 06.06.2020.
//  Copyright © 2020 Doemoetoer Gulyas. All rights reserved.
//

#import "PtpWebcamDevice.h"

#import "PtpWebcamPlugin.h"

#import <CoreMediaIo/CMIOHardwarePlugIn.h>
#import <ImageCaptureCore/ImageCaptureCore.h>


NS_ASSUME_NONNULL_BEGIN

@interface PtpWebcamPtpDevice : PtpWebcamDevice <ICCameraDeviceDelegate>

@property ICCameraDevice* cameraDevice;
@property NSDictionary* ptpDeviceInfo;
@property NSDictionary* ptpPropertyInfos;

@property size_t liveViewHeaderLength;

- (uint32_t) nextTransactionId;

- (instancetype) initWithIcDevice: (ICCameraDevice*) device pluginInterface: (_Nonnull CMIOHardwarePlugInRef) pluginInterface;

- (NSData*) ptpCommandWithType: (uint16_t) type code: (uint16_t) code transactionId: (uint32_t) transId;
- (void) ptpQueryKnownDeviceProperties;

+ (nullable NSDictionary*) supportsCamera: (ICDevice*) camera;

- (BOOL) isPtpOperationSupported: (uint16_t) opId;

@end

NS_ASSUME_NONNULL_END
