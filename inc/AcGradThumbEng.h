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

#include "dbcolor.h"
#include "accoredefs.h"

#include "icarx/IcArxPackPush.h"

class CAcGradientThumbnailEngine
{
public:
	virtual ~CAcGradientThumbnailEngine() = default;

	virtual Acad::ErrorStatus gradientThumbnailsDrawBitmap(int gradientNumber, HDC hDC, int xPos,
														   int yPos) = 0;
	virtual Acad::ErrorStatus gradientThumbnailsRender() = 0;
	virtual Acad::ErrorStatus gradientThumbnailsSetRotation(double angle) = 0;
	virtual Acad::ErrorStatus gradientThumbnailsSetShift(bool bShifted) = 0;
	virtual Acad::ErrorStatus gradientThumbnailsSetStartColor(AcCmEntityColor startColor) = 0;
	virtual Acad::ErrorStatus gradientThumbnailsSetStopColor(AcCmEntityColor stopColor) = 0;
};

#include "icarx/IcArxPackPop.h"

ACCORE_PORT CAcGradientThumbnailEngine* createGradientThumbnailEngine();
