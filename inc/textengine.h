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
***     Description: Declaration of AcGiTextEngine class
***
*****************************************************************************/
#pragma once

#include "acgi.h"
#include "AdAChar.h"
#include "adesk.h"

using PolylineCallback = void (*)(int, int const*, AcGePoint3d const*, void*);
using UnicodeCallback = void (*)(AcFontHandle*, wchar_t const*, int, void*);

#include "icarx/IcArxPackPush.h"

class AcGiTextEngine
{
public:
	virtual ~AcGiTextEngine() = default;

	static AcGiTextEngine* create();
	virtual void getExtents(AcGiTextStyle& ts, const ACHAR* pStr, int nLength, bool bPenUp,
							bool bRaw, AcGePoint2d& extents) = 0;
	virtual void tessellate(AcGiTextStyle& ts, const ACHAR* pStr, int nLength, bool bRaw,
							double deviation, void* pVoid, PolylineCallback pPolylineCallback) = 0;
	virtual void tessellate(AcGiTextStyle& ts, const ACHAR* pString, int nLength, bool bRaw,
							void* pVoid, UnicodeCallback pUnicodeCallback,
							PolylineCallback pPolylineCallback) = 0;
};

#include "icarx/IcArxPackPop.h"
