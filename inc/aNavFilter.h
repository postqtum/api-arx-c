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
***     Description: Declaration of CNavFilter class
***
*****************************************************************************/
#pragma once

#ifndef ANAV_PORT
#	define ANAV_PORT
#endif

#include <afxcoll.h>

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class ANAV_PORT CNavFilter : public CStringArray
{
private:
	BOOL m_bFullDescription;
	BOOL m_bMultiSelectAllowed;

protected:
	CString m_description;
	INT_PTR m_tagIndex;

public:
	CNavFilter();
	virtual ~CNavFilter();

	int Find(LPCTSTR str);
	int GetCount();
	LPCTSTR GetDescription();
	void GetFullDescription(CString& desc);
	BOOL GetMultiSelectAllowed();
	INT_PTR GetTagIndex();
	BOOL IsAllowed(LPCTSTR fileName);
	void SetDescription(LPCTSTR desc);
	LPTSTR SetFrom(LPTSTR str, BOOL bUseFullDescrition = 0);
	void SetFullDescription(LPCTSTR desc);
	void SetMultiSelectAllowed(BOOL bMultiSelection);
	void SetTagIndex(INT_PTR tagIndex);
};


#include "icarx/IcArxPackPop.h"
