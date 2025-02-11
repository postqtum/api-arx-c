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
***     Description: Declaration of CAdUiToolBarCtrl class
***
*****************************************************************************/
#pragma once

#include <afxcmn.h>

#ifndef ADUI_PORT
#	define ADUI_PORT
#endif

#define ADUI_TBSTYLE_AUTOSTRETCH 0x00080000

class ADUI_PORT CAdUiToolBarCtrl : public CToolBarCtrl
{
	DECLARE_DYNAMIC(CAdUiToolBarCtrl)
private:
	CBitmap* m_pBmp = nullptr;

private:
	void UpdateBitmap(const CBitmap& bmp);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiToolBarCtrl();
	~CAdUiToolBarCtrl() noexcept;
	int AddBitmap(int nNumButtons, UINT nBitmapID);
	int AddBitmap(int nNumButtons, CBitmap* pBitmap);
};
