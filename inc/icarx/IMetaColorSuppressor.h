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
***     Description: Declaration of IMetaColorSuppressor interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

DEFINE_GUID(IID_IIMetaColorSuppressor, 0x2346f231, 0x6dbf, 0x429a, 0xa2, 0xfe, 0xce, 0x1e, 0xe7,
			0xee, 0x37, 0xd6);

interface DECLSPEC_UUID("2346F231-6DBF-429A-A2FE-CE1EE7EE37D6") IMetaColorSuppressor
		: public IUnknown
{
	STDMETHOD(GetSuppressor)(THIS_ bool* val) PURE;
	STDMETHOD(SetSuppressor)(THIS_ bool val) PURE;
};

typedef IMetaColorSuppressor* LPMETACOLORSUPPRESSOR;
