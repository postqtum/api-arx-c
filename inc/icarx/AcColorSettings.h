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
***     Description: Declaration of AcColorSettings struct
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"

#include "IcArxPackPush.h"

struct AcColorSettings
{
	DWORD dwGfxModelBkColor;
	DWORD dwGfxLayoutBkColor;
	DWORD dwPaperBkColor;
	DWORD dwParallelBkColor;
	DWORD dwBEditBkColor;
	DWORD dwCmdLineBkColor;
	DWORD dwPlotPrevBkColor;
	DWORD dwSkyGradientZenithColor;
	DWORD dwSkyGradientHorizonColor;
	DWORD dwGroundGradientOriginColor;
	DWORD dwGroundGradientHorizonColor;
	DWORD dwEarthGradientAzimuthColor;
	DWORD dwEarthGradientHorizonColor;
	DWORD dwModelCrossHairColor;
	DWORD dwLayoutCrossHairColor;
	DWORD dwParallelCrossHairColor;
	DWORD dwPerspectiveCrossHairColor;
	DWORD dwBEditCrossHairColor;
	DWORD dwParallelGridMajorLines;
	DWORD dwPerspectiveGridMajorLines;
	DWORD dwParallelGridMinorLines;
	DWORD dwPerspectiveGridMinorLines;
	DWORD dwParallelGridAxisLines;
	DWORD dwPerspectiveGridAxisLines;
	DWORD dwTextForeColor;
	DWORD dwTextBkColor;
	DWORD dwCmdLineForeColor;
	DWORD dwCmdLineTempPromptBkColor;
	DWORD dwCmdLineTempPromptTextColor;
	DWORD dwCmdLineCmdOptKeywordColor;
	DWORD dwCmdLineCmdOptBkColor;
	DWORD dwCmdLineCmdOptHighlightedColor;
	DWORD dwAutoTrackingVecColor;
	DWORD dwLayoutATrackVecColor;
	DWORD dwParallelATrackVecColor;
	DWORD dwPerspectiveATrackVecColor;
	DWORD dwBEditATrackVecColor;
	DWORD dwModelASnapMarkerColor;
	DWORD dwLayoutASnapMarkerColor;
	DWORD dwParallelASnapMarkerColor;
	DWORD dwPerspectiveASnapMarkerColor;
	DWORD dwBEditASnapMarkerColor;
	DWORD dwModelDftingTooltipColor;
	DWORD dwLayoutDftingTooltipColor;
	DWORD dwParallelDftingTooltipColor;
	DWORD dwPerspectiveDftingTooltipColor;
	DWORD dwBEditDftingTooltipColor;
	DWORD dwModelDftingTooltipBkColor;
	DWORD dwLayoutDftingTooltipBkColor;
	DWORD dwParallelDftingTooltipBkColor;
	DWORD dwPerspectiveDftingTooltipBkColor;
	DWORD dwBEditDftingTooltipBkColor;
	DWORD dwModelLightGlyphs;
	DWORD dwLayoutLightGlyphs;
	DWORD dwParallelLightGlyphs;
	DWORD dwPerspectiveLightGlyphs;
	DWORD dwBEditLightGlyphs;
	DWORD dwModelLightHotspot;
	DWORD dwLayoutLightHotspot;
	DWORD dwParallelLightHotspot;
	DWORD dwPerspectiveLightHotspot;
	DWORD dwBEditLightHotspot;
	DWORD dwModelLightFalloff;
	DWORD dwLayoutLightFalloff;
	DWORD dwParallelLightFalloff;
	DWORD dwPerspectiveLightFalloff;
	DWORD dwBEditLightFalloff;
	DWORD dwModelLightStartLimit;
	DWORD dwLayoutLightStartLimit;
	DWORD dwParallelLightStartLimit;
	DWORD dwPerspectiveLightStartLimit;
	DWORD dwBEditLightStartLimit;
	DWORD dwModelLightEndLimit;
	DWORD dwLayoutLightEndLimit;
	DWORD dwParallelLightEndLimit;
	DWORD dwPerspectiveLightEndLimit;
	DWORD dwBEditLightEndLimit;
	DWORD dwModelCameraGlyphs;
	DWORD dwLayoutCameraGlyphs;
	DWORD dwParallelCameraGlyphs;
	DWORD dwPerspectiveCameraGlyphs;
	DWORD dwModelCameraFrustrum;
	DWORD dwLayoutCameraFrustrum;
	DWORD dwParallelCameraFrustrum;
	DWORD dwPerspectiveCameraFrustrum;
	DWORD dwModelCameraClipping;
	DWORD dwLayoutCameraClipping;
	DWORD dwParallelCameraClipping;
	DWORD dwPerspectiveCameraClipping;
	int nModelCrosshairUseTintXYZ;
	int nLayoutCrosshairUseTintXYZ;
	int nParallelCrosshairUseTintXYZ;
	int nPerspectiveCrosshairUseTintXYZ;
	int nBEditCrossHairUseTintXYZ;
	int nModelATrackVecUseTintXYZ;
	int nLayoutATrackVecUseTintXYZ;
	int nParallelATrackVecUseTintXYZ;
	int nPerspectiveATrackVecUseTintXYZ;
	int nBEditATrackVecUseTintXYZ;
	int nModelDftingTooltipBkUseTintXYZ;
	int nLayoutDftingTooltipBkUseTintXYZ;
	int nParallelDftingTooltipBkUseTintXYZ;
	int nPerspectiveDftingTooltipBkUseTintXYZ;
	int nBEditDftingTooltipBkUseTintXYZ;
	int nParallelGridMajorLineTintXYZ;
	int nPerspectiveGridMajorLineTintXYZ;
	int nParallelGridMinorLineTintXYZ;
	int nPerspectiveGridMinorLineTintXYZ;
	int nParallelGridAxisLineTintXYZ;
	int nPerspectiveGridAxisLineTintXYZ;
};

#include "IcArxPackPop.h"

ACCORE_PORT bool acedGetCurrentColors(AcColorSettings* pColorSettings);
ACCORE_PORT bool acedSetCurrentColors(AcColorSettings* pColorSettings);
ACCORE_PORT bool acedGetSystemColors(AcColorSettings* pColorSettings);
