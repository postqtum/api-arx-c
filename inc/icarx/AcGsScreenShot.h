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
***     Description: Declaration of AcGsScreenShot class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"

#include "IcArxPackPush.h"

class AcGsScreenShot
{
public:
	AcGsScreenShot();
	virtual ~AcGsScreenShot() = 0;
	void* operator new(size_t size);
	void operator delete(void* p);
// TO DO
// maybe this is not necessary
#ifndef PRODUCTION
	void* operator new(size_t size, const char*, int) { return operator new(size); }
	void operator delete(void* p, const char*, int) { delete p; }
#endif

	virtual bool getColorMap(int index, uint8_t& red, uint8_t& green, uint8_t& blue) const = 0;
	virtual void const* getScanline(int offsetFromLeft, int offsetFromTop) const = 0;
	virtual bool getSize(int& width, int& height, int& depth) const = 0;
};

#include "IcArxPackPop.h"

#define ScreenShot AcGsScreenShot

AcGsScreenShot* acgsGetScreenShot(int viewportNumber);
