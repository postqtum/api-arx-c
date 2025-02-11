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
***     Description: Declaration of IRetrieveApplicationImpl class
***
*****************************************************************************/
#pragma once

#include "../axboiler.h"

#include "IcArxPackPush.h"

class ATL_NO_VTABLE IRetrieveApplicationImpl : public IRetrieveApplication
{
protected:
	LPDISPATCH m_App = nullptr;

public:
	IRetrieveApplicationImpl() = default;
	virtual ~IRetrieveApplicationImpl()
	{
		if (m_App != NULL)
			m_App->Release();
	}

	STDMETHOD(GetApplicationObject)(LPDISPATCH* pApp)
	{
		*pApp = m_App;
		if (m_App == NULL)
			return E_FAIL;

		m_App->AddRef();
		return S_OK;
	}
	STDMETHOD(SetApplicationObject)(LPDISPATCH pApp)
	{
		if (m_App != NULL)
			return E_FAIL;
		m_App = pApp;

		if (m_App != NULL)
			m_App->AddRef();

		return S_OK;
	}
};

#include "IcArxPackPop.h"
