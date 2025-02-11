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
***     Description: Declaration of AcColorSettingsEx2 struct
***
*****************************************************************************/
#pragma once

#include "AcColorSettingsEx.h"

#include "IcArxPackPush.h"

struct AcColorSettingsEx2
{
	DWORD dw2DModelGridMajorLines;
	DWORD dwLayoutGridMajorLines;
	DWORD dwBEditGridMajorLines;
	DWORD dw2DModelGridMinorLines;
	DWORD dwLayoutGridMinorLines;
	DWORD dwBEditGridMinorLines;
	DWORD dw2DModelGridAxisLines;
	DWORD dwLayoutGridAxisLines;
	DWORD dwBEditGridAxisLines;
	DWORD dwModelDynamicDimensionLineColor;
	DWORD dwLayoutDynamicDimensionLineColor;
	DWORD dwParallelDynamicDimensionLineColor;
	DWORD dwPerspectiveDynamicDimensionLineColor;
	DWORD dwBEditDynamicDimensionLineColor;
	DWORD dwModelRubberBandLineColor;
	DWORD dwLayoutRubberBandLineColor;
	DWORD dwParallelRubberBandLineColor;
	DWORD dwPerspectiveRubberBandLineColor;
	DWORD dwBEditRubberBandLineColor;
	DWORD dwModelDftingTooltipContourColor;
	DWORD dwLayoutDftingTooltipContourColor;
	DWORD dwParallelDftingTooltipContourColor;
	DWORD dwPerspectiveDftingTooltipContourColor;
	DWORD dwBEditDftingTooltipContourColor;
	int n2DModelGridMajorLineTintXYZ;
	int nLayoutGridMajorLineTintXYZ;
	int nBEditGridMajorLineTintXYZ;
	int n2DModelGridMinorLineTintXYZ;
	int nLayoutGridMinorLineTintXYZ;
	int nBEditGridMinorLineTintXYZ;
	int n2DModelGridAxisLineTintXYZ;
	int nLayoutGridAxisLineTintXYZ;
	int nBEditGridAxisLineTintXYZ;
	DWORD dwControlVerticesHullColor;
};

#include "IcArxPackPop.h"

ACCORE_PORT bool acedGetCurrentColorsEx2(AcColorSettings* pColorSettings,
										 AcColorSettingsEx* pColorSettingsEx,
										 AcColorSettingsEx2* pColorSettingsEx2);

ACCORE_PORT bool acedSetCurrentColorsEx2(AcColorSettings* pColorSettings,
										 AcColorSettingsEx* pColorSettingsEx,
										 AcColorSettingsEx2* pColorSettingsEx2);

ACCORE_PORT bool acedGetSystemColorsEx2(AcColorSettings* pColorSettings,
										AcColorSettingsEx* pColorSettingsEx,
										AcColorSettingsEx2* pColorSettingsEx2);
