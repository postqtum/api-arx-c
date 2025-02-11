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
***     Description: Declaration of CProxy_AcadObjectEvents class
***
*****************************************************************************/
#pragma once

#include <atlbase.h>
#include <atlcom.h>
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

template<class T>
class CProxy_AcadObjectEvents
		: public IConnectionPointImpl<T, &IID_IAcadObjectEvents, CComDynamicUnkArray>
{
public:
	virtual ~CProxy_AcadObjectEvents() = default;

	void Fire_Modified()
	{
		T* pT = static_cast<T*>(this);
		CComPtr<IAcadObject> pAcadObject;
		pT->QueryInterface(__uuidof(IAcadObject), (void**)&pAcadObject);
		pT->Lock();
		IUnknown** pp = this->m_vec.begin();
		while (pp < this->m_vec.end())
		{
			if (*pp != NULL)
			{
				IAcadObjectEvents* pAcadObjectEvents = reinterpret_cast<IAcadObjectEvents*>(*pp);
				ICARX_ASSERT(pAcadObjectEvents != NULL);

				pAcadObjectEvents->Modified(pAcadObject);
			}
			pp++;
		}
		pT->Unlock();
	}
};

#include "IcArxPackPop.h"
