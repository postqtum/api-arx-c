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
***     Description: Declaration of CAdUiThemedStatic class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"

class ADUI_PORT CAdUiThemedStatic : public CStatic
{
	DECLARE_DYNAMIC(CAdUiThemedStatic)
private:
	CString mThemeName;
	CBrush mBackgroundBrush;

protected:
	void Initialize();

	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiThemedStatic();
	CAdUiThemedStatic(const CString& themeName);
	~CAdUiThemedStatic();
	CString GetThemeName() const;
	void PreSubclassWindow();
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HICON SetIcon(HICON hIcon);
	bool SetThemeName(const CString& themeName);
};
