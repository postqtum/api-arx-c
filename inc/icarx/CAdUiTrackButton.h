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
***     Description: Declaration of CAdUiTrackButton class
***
*****************************************************************************/
#pragma once

#include "CAdUiOwnerDrawButton.h"

class CAdUiTrackButtonDraw;

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiTrackButton : public CAdUiOwnerDrawButton
{
	DECLARE_DYNAMIC(CAdUiTrackButton)

private:
	static CAdUiTrackButtonDraw* s_pDefaultDraw;
	CAdUiTrackButtonDraw* m_pDraw = nullptr;

protected:
	void DrawBorder(CDC* pDC, CRect& r, COLORREF cr);
	void DrawButton(CDC& dc, int w, int h, BOOL isDefault, BOOL isDisabled, BOOL isSelected,
					BOOL isFocused);
	void DrawHotBorder();
	void DrawPushButtonBorder(CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected);
	void DrawToolButtonBorder(CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused);
	ADUI_REPLY OnGetTipSupport(CPoint& p);
	virtual void releaseDraw();

	afx_msg void OnNcPaint();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	CAdUiTrackButton();
	CAdUiTrackButton(const CAdUiTrackButtonDraw& pDraw);
	~CAdUiTrackButton() noexcept;
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual CAdUiTheme* GetTheme() const;
	static CAdUiTrackButtonDraw* SetDefaultDraw(CAdUiTrackButtonDraw* pDraw);
	CAdUiTrackButtonDraw* SetDraw(CAdUiTrackButtonDraw* pDraw);
	CAdUiTheme* SetTheme(CAdUiTheme* pTheme);
	void SetTracking(BOOL b);
};

#include "IcArxPackPop.h"
