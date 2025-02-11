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
***     Description: Declaration of IAcadAcCmColorAccess interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

class AcCmColor;

DEFINE_GUID(IID_IAcadAcCmColorAccess, 0x6fad24dc, 0xf0bc, 0x4ac4, 0xa3, 0x20, 0x39, 0x94, 0xd1,
			0x59, 0x77, 0x6f);

#undef INTERFACE
#define INTERFACE IAcadAcCmColorAccess

interface DECLSPEC_UUID("6FAD24DC-F0BC-4AC4-A320-3994D159776F") IAcadAcCmColorAccess
		: public IUnknown
{
	STDMETHOD(GetAcCmColor)(THIS_ AcCmColor* clr) PURE;
	STDMETHOD(SetAcCmColor)(THIS_ AcCmColor* clr) PURE;
};

typedef IAcadAcCmColorAccess* LPACADACCMCOLORACCESS;
