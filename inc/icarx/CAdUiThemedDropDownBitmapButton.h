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
***     Description: Declaration of CAdUiThemedDropDownBitmapButton class
***
*****************************************************************************/
#pragma once

#include "CAdUiBitmapButton.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiThemedDropDownBitmapButton : public CAdUiBitmapButton
{
	DECLARE_DYNAMIC(CAdUiThemedDropDownBitmapButton)
public:
	enum
	{
		BitmapButtonSize = 24,
		MenuButtonWidth = 15
	};

protected:
	BOOL m_bMainButtonSelected = FALSE;
	BOOL m_bMenuButtonSelected = FALSE;
	int m_menuButtonWidth = 0;

protected:
	void DrawButton(CDC& dc, int w, int h, BOOL isDefault, BOOL isDisabled, BOOL isSelected,
					BOOL isFocused);

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiThemedDropDownBitmapButton();
	~CAdUiThemedDropDownBitmapButton();
	void ClearClick();
	BOOL GetMainButtonSelected();
	BOOL GetMenuButtonSelected();
	virtual int GetMenuButtonWidth();
	void SetMainButtonSelected(BOOL selected);
	void SetMenuButtonSelected(BOOL selected);
	virtual bool SetMenuButtonWidth(int width);
};

#include "IcArxPackPop.h"
