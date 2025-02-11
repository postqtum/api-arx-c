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
***     Description: Declaration of IAcadBaseDatabaseImpl class
***
*****************************************************************************/
#pragma once

#include "../axboiler.h"

#include "IcArxPackPush.h"

template<const CLSID* pclsid>
class ATL_NO_VTABLE IAcadBaseDatabaseImpl : public IAcadBaseDatabase
{
protected:
	AcDbDatabase* m_Database = nullptr;

public:
	IAcadBaseDatabaseImpl() = default;

	STDMETHOD(GetClassID)(CLSID& clsid)
	{
		clsid = *pclsid;
		return S_OK;
	}
	STDMETHOD(GetDatabase)(AcDbDatabase** pDb)
	{
		if (pDb == NULL)
			return E_POINTER;

		*pDb = m_Database;
		return S_OK;
	}
	STDMETHOD(SetDatabase)(AcDbDatabase*& pDb)
	{
		m_Database = pDb;
		return S_OK;
	}
};

#include "IcArxPackPop.h"
