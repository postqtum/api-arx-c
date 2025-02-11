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
***     Description: Declaration of AcGiRequestScanLines class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../gepnt2d.h"
#include "../gemat2d.h"
#include "../acgidefs.h"

#include "IcArxPackPush.h"

struct AcGiRequestScanLines
{
	enum IEDitherMethod
	{
		kIEAnyPalette,
		kCustomDithering,
		kCustomDitheringMethod
	};

	enum IEColorSystem
	{
		kBitonal,
		kCMY,
		kCMYK,
		kRGB
	};

	enum ImagePaletteType
	{
		kFromDevice,
		kFromIeWholeImage
	};

	uint32_t mPixelMinX = 0;
	uint32_t mPixelMinY = 0;
	uint32_t mPixelMaxX = 0;
	uint32_t mPixelMaxY = 0;
	AcGePoint2d mLowerLeft;
	AcGePoint2d mUpperRight;
	void* mpImageId = nullptr;
	AcGiImageOrg mImageOrg = kAcGiBitonal;
	AcGiImageOrient mImageOrient = kAcGiXLeftToRightTopFirst;
	int16_t mWindowId = 0;
	int16_t mColorDepth = 8;
	union
	{
		int16_t mBackgroundIndex;
		int8_t mBackgroundRGB[3];
	} mBackgroundColor;
	union
	{
		int16_t mTransparentIndex;
		int8_t mTransparentRGB[3];
	} mTransparentColor;
	union
	{
		int16_t mEntityIndex;
		int8_t mEntityRGB[3];
	} mEntityColor;
	int32_t mPaletteIncarnation = 0;
	int8_t* mpPalette = nullptr;
	int16_t mIsDisplay = 0;
	double mRasterRatio = 1.0;
	AcGeMatrix2d mPixelToDc;
	ImagePaletteType mPaletteType = kFromDevice;
	void* mpDataBuffer = nullptr;
	int32_t mRowWidth = 0;
	int32_t mNumRows = 0;
	int32_t const* mpBoundaryPoints = nullptr;
	uint32_t mnContours = 0;
	int32_t const* mpCounts = nullptr;
	AcGiScaleType mScalingType = kDefaultScale;
	AcGiScaleFilterType mScaleFilterType = kDefaultScaleFilter;
	AcGiRotationFilterType mRotationFilterType = kDefaultRotationFilter;
	short mnTotalChunks = 0;
	short mnThisChunk = 0;
};

#include "IcArxPackPop.h"
