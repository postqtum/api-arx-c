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

#include "AcPlObject.h"
#include "dbid.h"

class AcPlPlotConfig;
class AcRxObject;
class AcDbPlotSettings;
class AcString;

#include "icarx/IcArxPackPush.h"

class AcPlPlotInfo : public AcPlObject
{
public:
	enum MergeStatus
	{
		kNoChanges = 0x00000000,
		kPlotCfgName = 0x00000001,
		kPlotPaperMargins = 0x00000002,
		kPlotPaperSize = 0x00000004,
		kCanonicalMediaName = 0x00000008,
		kPlotOrigin = 0x00000010,
		kPlotPaperUnits = 0x00000020,
		kPlotViewportBorders = 0x00000040,
		kPlotPlotStyles = 0x00000080,
		kShowPlotStyles = 0x00000100,
		kPlotRotation = 0x00000200,
		kPlotCentered = 0x00000400,
		kPlotHidden = 0x00000800,
		kShadePlot = 0x00001000,
		kShadePlotResLevel = 0x00002000,
		kShadePlotCustomDPI = 0x00004000,
		kPlotType = 0x00008000,
		kPlotWindowArea = 0x00010000,
		kPlotViewName = 0x00020000,
		kScale = 0x00040000,
		kCurrentStlyeSheet = 0x00080000,
		kScaleLineWeights = 0x00100000,
		kPrintLineWeights = 0x00200000,
		kDrawViewportsFirst = 0x00400000,
		kPlotTransparency = 0x00800000
	};

public:
	ACPL_DECLARE_MEMBERS(AcPlPlotInfo);

public:
	ACPL_PORT AcPlPlotInfo();
	ACPL_PORT ~AcPlPlotInfo();

	ACPL_PORT AcString& OrgFilePath();
	ACPL_PORT Acad::ErrorStatus copyFrom(const AcRxObject* pOther);
	ACPL_PORT const AcPlPlotConfig* deviceOverride() const;
	ACPL_PORT bool isCompatibleDocument(const AcPlPlotInfo* pOtherInfo) const;
	ACPL_PORT bool isValidated() const;
	ACPL_PORT AcDbObjectId layout() const;
	ACPL_PORT unsigned long mergeStatus() const;
	ACPL_PORT const AcDbPlotSettings* overrideSettings() const;
	ACPL_PORT void setDeviceOverride(const AcPlPlotConfig* pconf);
	ACPL_PORT void setLayout(AcDbObjectId& layoutId);
	ACPL_PORT void setOverrideSettings(const AcDbPlotSettings* pOverrides);
	ACPL_PORT void setValidatedConfig(const AcPlPlotConfig* pConfig);
	ACPL_PORT Acad::ErrorStatus setValidatedSettings(const AcDbPlotSettings* pValidatedSettings);
	ACPL_PORT const AcPlPlotConfig* validatedConfig() const;
	ACPL_PORT const AcDbPlotSettings* validatedSettings() const;
};

#include "icarx/IcArxPackPop.h"
