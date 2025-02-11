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

#include "IcArxPackPush.h"

namespace GS
{

enum DeviceType
{
	kScreenDevice = 0,
	kOffScreenDevice = 1,
	kSelectionDevice = 2
};

enum ErrorStatus
{
	kSuccess,
	kOutOfRange,
	kInvalidInput
};

enum HighlightStyle
{
	kHighlightDashed = 0,
	kHighlightThicken = 1,
	kHighlightDashedAndThicken = 2,
	kHighlightCustom = 3,
	kHighlightDim = 4,
	kHighlightThickDim = 5,
	kHighlightGlow = 6
};

enum ImageDataFormat
{
	kRGBA = 0,
	kBGRA = 1
};

enum ImageOrientation
{
	kTopDown = 0,
	kBottomUp = 1
};

enum SyncBehavior
{
	eSync = 0,
	eAsync = 1,
};

}  // namespace GS

#include "IcArxPackPop.h"
