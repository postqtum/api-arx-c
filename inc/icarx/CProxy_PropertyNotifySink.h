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
***     Description: Declaration of CProxy_PropertyNotifySink class
***
*****************************************************************************/
#pragma once

#include <atlbase.h>
#include <atlcom.h>

#include "IcArxPackPush.h"

template<class T>
class CProxy_PropertyNotifySink
		: public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CComDynamicUnkArray>
{
public:
	virtual ~CProxy_PropertyNotifySink() = default;

	void Fire_OnChanged() { Fire_OnChanged(DISPID_UNKNOWN); }
	void Fire_OnChanged(DISPID dispId)
	{
		T* pT = static_cast<T*>(this);
		pT->Lock();
		IUnknown** pp = this->m_vec.begin();
		while (pp < this->m_vec.end())
		{
			IPropertyNotifySink* pNotifySink = reinterpret_cast<IPropertyNotifySink*>(*pp);
			if (pNotifySink)
				pNotifySink->OnChanged(dispId);
			pp++;
		}
		pT->Unlock();
	}
};

#include "IcArxPackPop.h"
