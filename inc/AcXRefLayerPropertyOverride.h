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
***     Description:
***
*****************************************************************************/
#pragma once

#include "AcDbCore2dDefs.h"

class AcDbDatabase;
class AcDbObjectId;
class AcDbBlockReference;

#include "icarx/IcArxPackPush.h"

class AcXRefLayerPropertyOverride
{
public:
	enum XRefLayerPropertyOverrideType
	{
		On = 0,
		Freeze = 1,
		Lock = 2,
		Plot = 3,
		Color = 4,
		Linetype = 5,
		Lineweight = 6,
		Transparency = 7,
		PlotStyle = 8,
		NewVPFreeze = 9,
		Description = 10
	};

public:
	ACDBCORE2D_PORT static Acad::ErrorStatus addXRefLayerOverride(
			const AcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);
	ACDBCORE2D_PORT static void disableXRefLayerPropertyOverrideRecording();
	ACDBCORE2D_PORT static void enableXRefLayerPropertyOverrideRecording();
	ACDBCORE2D_PORT static bool hasAnyXRefLayerOverrides(const AcDbObjectId& hostLayerId);
	ACDBCORE2D_PORT static bool hasAnyXRefLayerOverrides(AcDbDatabase* pHostDb);
	ACDBCORE2D_PORT static bool hasXRefLayerOverride(const AcDbObjectId& hostLayerId,
													 XRefLayerPropertyOverrideType property);
	ACDBCORE2D_PORT static bool hasXRefLayerOverride(AcDbBlockReference* pRef);
	ACDBCORE2D_PORT static bool isXRefLayerPropertyOverrideRecordingEnabled();
	ACDBCORE2D_PORT static Acad::ErrorStatus removeXRefLayerOverride(
			const AcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);
	ACDBCORE2D_PORT static Acad::ErrorStatus removeXRefLayerOverride(
			AcDbDatabase* pHostDb, XRefLayerPropertyOverrideType property);
	ACDBCORE2D_PORT static Acad::ErrorStatus removeXRefLayerOverrides(AcDbDatabase* pHostDb);
	ACDBCORE2D_PORT static Acad::ErrorStatus removeXRefLayerOverrides(
			const AcDbObjectId& hostLayerId);
};

#include "icarx/IcArxPackPop.h"
