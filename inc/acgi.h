/***************************************************************************
***
***     Copyright (C) 2022-2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Common includes for AcGi subsystem
***
*****************************************************************************/
#pragma once

#include "icarx/AcGiSentScanLines.h"
#include "icarx/AcGiRequestScanLines.h"
#include "icarx/AcGiClipBoundary.h"
#include "icarx/AcGiColorRGB.h"
#include "icarx/AcGiColorRGBA.h"
#include "icarx/AcGiPixelBGRA32.h"
#include "icarx/AcGiImageBGRA32.h"
#include "icarx/AcGiVariant.h"
#include "icarx/AcGiKernelDescriptor.h"
#include "icarx/AcGiContext.h"
#include "icarx/AcGiCommonDraw.h"
#include "icarx/AcGiViewport.h"
#include "icarx/AcGiContextualColors.h"
#include "icarx/AcGiSubEntityTraits.h"
#include "icarx/AcGiDrawableTraits.h"
#include "icarx/AcGiNonEntityTraits.h"
#include "icarx/AcGiGdiDrawObject.h"
#include "icarx/AcGiPolyline.h"
#include "icarx/AcGiGeometry.h"
#include "icarx/AcGiWorldGeometry.h"
#include "icarx/AcGiViewportGeometry.h"
#include "icarx/AcGiEdgeData.h"
#include "icarx/AcGiFaceData.h"
#include "icarx/AcGiVertexData.h"
#include "icarx/AcGiTextStyle.h"
#include "icarx/AcGiFill.h"
#include "icarx/AcGiHatchPatternDefinition.h"
#include "icarx/AcGiHatchPattern.h"
#include "icarx/AcGiGradientFill.h"
#include "icarx/AcParallelTessPE.h"

#include "adesk.h"
#include "acgidefs.h"
#include "rxobject.h"
#include "AdAChar.h"
#include "dbpl.h"
#include "gemat3d.h"
#include "gemat2d.h"
#include "gepnt2d.h"
#include "dbcolor.h"
#include "acdb.h"
#include "AcGiStyleAttributes.h"
#include <cassert>
#include "AcGiParameter.h"
#include "PAL/api/charset.h"
#include "PAL/api/FontPitchAndFamily.h"
#include "rxboiler.h"

#define ACGI_SERVICES  ACRX_T(/*MSG0*/"AcGiServices")

bool acgiIsValidClipBoundary(const AcGePoint2dArray& pts);

Acad::ErrorStatus acgiGetRegenBlockRefStack(AcDbObjectIdArray& blkRefs);

constexpr int AcGiSelectionMarkerACADReserveStart = -2147483647 - 1;
constexpr int AcGiSelectionMarkerACADReserveEnd = AcGiSelectionMarkerACADReserveStart + 65535;

constexpr int AcGiSelectionMarkerACADSelectionPreviewOff = AcGiSelectionMarkerACADReserveStart + 1;
constexpr int AcGiSelectionMarkerACADSelectionPreviewOn = AcGiSelectionMarkerACADReserveStart + 2;
