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
***     Description: Declaration of CAdToolTipCtrl class
***
*****************************************************************************/
#pragma once

#include "../adui_port.h"

#include <afxcmn.h>

class AdToolTip;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdToolTipCtrl : public CToolTipCtrl
{
protected:
	AdToolTip* m_pToolTip = nullptr;
	BOOL m_bActivate = true;
	UINT m_nDelayTime = 0;

private:
	static BOOL m_bToolTipHasCreated;
	static BOOL m_bToolTipsFlag;
	static UINT m_nDefaultDealyTime;

protected:
	virtual AdToolTip* CreateAdToolTipInstance();

public:
	CAdToolTipCtrl();
	~CAdToolTipCtrl();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	static void SetDeaultDelayTime(int nDelay);
	static void SetToolTipsFlag(BOOL bToolTipsFlag);

	DECLARE_MESSAGE_MAP()
};


#include "IcArxPackPop.h"
