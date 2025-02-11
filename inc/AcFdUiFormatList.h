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
***     Description: Declaration of CAcFdUiFormatList class
***
*****************************************************************************/
#pragma once

#include "AcFdUi.h"

#include "aduiListBox.h"

class AcTcUiSystemInternals;

class ACFDUI_PORT CAcFdUiFormatList : public CAdUiListBox
{
	DECLARE_DYNAMIC(CAcFdUiFormatList)

protected:
	void* mpImpObj = nullptr;

private:
	friend class AcFdUiSystemInternals;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy(void);

	DECLARE_MESSAGE_MAP()

public:
	CAcFdUiFormatList();
	~CAcFdUiFormatList() noexcept;
	int GetCurrentFormat(CString& sDisplayName, CString& sFormatString) const;
	CString GetFormatType() const;
	BOOL Refresh();
	BOOL SetCurrentFormat(LPCTSTR pszDisplayName, LPCTSTR pszFormatString);
	BOOL SetFormatType(LPCTSTR pszFormatType);
	void SetPersistency(BOOL bPersist);
	void SetRootKey(LPCTSTR pszKey);
};
