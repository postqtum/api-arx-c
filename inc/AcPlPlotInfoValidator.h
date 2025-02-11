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
#include "AcPlPlotInfo.h"

#define DEFAULT_MEDIA_GROUP_WEIGHT 50
#define DEFAULT_SHEET_MEDIA_GROUP_WEIGHT 10
#define DEFAULT_MEDIA_BOUNDS_WEIGHT 100
#define DEFAULT_PRINTABLE_BOUNDS_WEIGHT 10
#define DEFAULT_DIMENSIONAL_WEIGHT 50
#define DEFAULT_SHEET_DIMENSIONAL_WEIGHT 10
#define DEFAULT_THRESHOLD 500

class AcPlPlotInfo;

#include "icarx/IcArxPackPush.h"

class AcPlPlotInfoValidator : public AcPlObject
{
public:
	enum MatchingPolicy
	{
		kMatchDisabled = 1,
		kMatchEnabled,
		kMatchEnabledCustom,
		kMatchEnabledTmpCustom
	};

	enum eCustomSizeResult
	{
		ePossible = 0x0000,
		eMustCreatePC3 = 0x0001,
		eRotationRequired = 0x0002,
		ePC3DirReadOnly = 0x0004,
		ePMPDirReadOnly = 0x0008,
		ePMPDirMissing = 0x0010,
		eUnknownErrPMPDir = 0x0020,
		ePC3FileReadOnly = 0x0040,
		eSizeTooBig = 0x0080,
		eException = 0x0100,
		eUnknownErrPC3File = 0x0200,
		eUnknownErrPMPFile = 0x0400,
		ePMPFileReadOnly = 0x0800,
		eWidthAndHeightMustBePositive = 0x1000,
		eDeviceLoadFailed = 0x2000
	};

protected:
	unsigned int m_mediaBoundsWeight = DEFAULT_MEDIA_BOUNDS_WEIGHT;
	unsigned int m_dimensionalWeight = DEFAULT_DIMENSIONAL_WEIGHT;
	unsigned int m_mediaGroupWeight = DEFAULT_MEDIA_GROUP_WEIGHT;
	unsigned int m_printableBoundsWeight = DEFAULT_PRINTABLE_BOUNDS_WEIGHT;
	unsigned int m_sheetDimensionalWeight = DEFAULT_SHEET_DIMENSIONAL_WEIGHT;
	unsigned int m_sheetMediaGroupWeight = DEFAULT_SHEET_MEDIA_GROUP_WEIGHT;
	unsigned int m_matchingThreshold = DEFAULT_THRESHOLD;
	MatchingPolicy m_matchingPolicy = kMatchEnabled;

public:
	ACPL_DECLARE_MEMBERS(AcPlPlotInfoValidator);

public:
	ACPL_PORT AcPlPlotInfoValidator();
	ACPL_PORT ~AcPlPlotInfoValidator() = default;

	ACPL_PORT unsigned int dimensionalWeight() const;
	ACPL_PORT virtual unsigned long isCustomPossible(AcPlPlotInfo& info) const;
	ACPL_PORT MatchingPolicy matchingPolicy() const;
	ACPL_PORT unsigned int mediaBoundsWeight() const;
	ACPL_PORT unsigned int mediaGroupWeight() const;
	ACPL_PORT unsigned int mediaMatchingThreshold() const;
	ACPL_PORT unsigned int printableBoundsWeight() const;
	ACPL_PORT void setDimensionalWeight(unsigned int weight = DEFAULT_DIMENSIONAL_WEIGHT);
	ACPL_PORT void setMediaBoundsWeight(unsigned int weight = DEFAULT_MEDIA_BOUNDS_WEIGHT);
	ACPL_PORT void setMediaGroupWeight(unsigned int weight = DEFAULT_MEDIA_GROUP_WEIGHT);
	ACPL_PORT void setMediaMatchingPolicy(MatchingPolicy policy);
	ACPL_PORT void setMediaMatchingThreshold(unsigned int threshold = DEFAULT_THRESHOLD);
	ACPL_PORT void setPrintableBoundsWeight(unsigned int weight = DEFAULT_PRINTABLE_BOUNDS_WEIGHT);
	ACPL_PORT void setSheetDimensionalWeight(
			unsigned int weight = DEFAULT_SHEET_DIMENSIONAL_WEIGHT);
	ACPL_PORT void setSheetMediaGroupWeight(unsigned int weight = DEFAULT_SHEET_MEDIA_GROUP_WEIGHT);
	ACPL_PORT unsigned int sheetDimensionalWeight() const;
	ACPL_PORT unsigned int sheetMediaGroupWeight() const;
	ACPL_PORT virtual Acad::ErrorStatus validate(AcPlPlotInfo& info);
};

#include "icarx/IcArxPackPop.h"
