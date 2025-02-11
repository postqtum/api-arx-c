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
***     Description: Declaration of IAcadShadowDisplayImpl class
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

#include "IcArxPackPush.h"

template<class C>
class ATL_NO_VTABLE IAcadShadowDisplayImpl : public IAcadShadowDisplay
{
public:
	STDMETHODIMP get_EnableShadowDisplay(BOOL* bEnabled)
	{
		*bEnabled = TRUE;

		return S_OK;
	}
	STDMETHODIMP get_ShadowDisplay(AcShadowDisplayType* pShadowDisplay)
	{
		CComPtr<IAcadBaseObject> pAcadBaseObject;
		HRESULT hr = QueryInterface(IID_IAcadBaseObject, (LPVOID*)&pAcadBaseObject);
		if (FAILED(hr))
			return S_FALSE;

		AcDbObjectId objId;
		pAcadBaseObject->GetObjectId(&objId);
		return AcAxGetShadowDisplay(objId, pShadowDisplay);
	}
	STDMETHODIMP put_ShadowDisplay(AcShadowDisplayType shadowDisplay)
	{
		CComPtr<IAcadBaseObject> pAcadBaseObject;
		HRESULT hr = QueryInterface(IID_IAcadBaseObject, (LPVOID*)&pAcadBaseObject);
		if (FAILED(hr))
			return S_FALSE;

		AcDbObjectId objId;
		pAcadBaseObject->GetObjectId(&objId);
		return AcAxPutShadowDisplay(objId, shadowDisplay);
	}
};

#include "IcArxPackPop.h"
