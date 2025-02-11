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
***     Description: Declaration of CNavArray class
***
*****************************************************************************/
#pragma once

#include "afxtempl.h"

#include "icarx/IcArxPackPush.h"

template<class T>
class CNavArray : public CTypedPtrArray<CObArray, T*>
{
protected:
	virtual T* NewData() { return new T; }

public:
	CNavArray() = default;
	virtual ~CNavArray() { RemoveAllData(); }

	T* AddData()
	{
		auto result = NewData();
		this->Add(result);
		return result;
	}
	int GetCount() { return static_cast<int>(this->GetUpperBound() + 1); }
	T* GetData(INT_PTR index)
	{
		if (!IsIndexValid(index)) {return nullptr;}
		return this->GetAt(index);
	}
	BOOL IsIndexValid(INT_PTR index) { return ((index >= 0) && (index <= this->GetUpperBound())); }
	void RemoveData(INT_PTR index)
	{
		if (IsIndexValid(index))
		{
			auto d = this->GetAt(index);
			this->RemoveAt(index);
			delete d;
		}
	}
	void RemoveAllData()
	{
		const int n = GetCount();

		for (int i = 0; i < n; i++)
		{
			auto d = this->GetAt(i);
			delete d;
		}
		this->RemoveAll();
		this->FreeExtra();
	}
};

#include "icarx/IcArxPackPop.h"
