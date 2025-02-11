//
//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2017 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
//
// icon.cpp
//
//  This example demonstrates the main use of polylineDc(),
//  polygonDc() and getViewportDcCorners() -- graphics
//  that depend on the physical layout of the viewport,
//  such as icons, markers, or borders that vary with the
//  size of the viewport.
//
//  For the demonstration, this example draws a box in
//  the upper right corner of the viewport.  The box's
//  width and height are always a tenth of the viewport's
//  shortest dimension and are centered a tenth of the
//  viewport's shortest dimension down and to the left of
//  the upper righthand corner of the viewport.

#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
#error _DEBUG should not be defined except in internal Adesk debug builds
#endif

#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rxdlinkr.h"

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* appId) 
{
    switch (msg) {
    case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(appId);
		acrxDynamicLinker->registerAppMDIAware(appId);
        break;
    case AcRx::kUnloadAppMsg:
		break;
    }
    return AcRx::kRetOK;
}
