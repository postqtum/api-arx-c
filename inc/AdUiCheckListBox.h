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
***     Description: Declaration of CAdUiCheckListBox class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"

class ADUI_PORT CAdUiCheckListBox : public CCheckListBox
{
	DECLARE_DYNAMIC(CAdUiCheckListBox)
public:
	enum HorizontalStyle
	{
		kHorizontalClip,
		kHorizontalEndEllipsis,
		kHorizontalPathEllipsis,
		kHorizontalWordEllipsis,
		kHorizontalScroll
	};

private:
	bool m_deleteItem;
	CAdUiCheckListBox::HorizontalStyle m_horizontalStyle;
	CToolTipCtrl* m_toolTipCtrl;

private:
	BOOL OnLButtonDown(int index, BOOL checkBox);
	bool ToolTip();

protected:
	virtual int CalcHorizontalExtent(int index, LPCTSTR text);
	virtual void CalcItemParts(int index, const CRect& item, CRect* checkBox, CRect* text);
	virtual int CalcMinimumItemHeight();
	int CheckFromPoint(CPoint point, BOOL& checkBox);
	LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void DrawCheckBox(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void DrawFocus(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void InvalidateCheck(int index);
	BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual bool OnItemToolTip(int index, const CRect& item, const CPoint& mouse,
							   CPoint& tipPosition, CString& tipText);
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	afx_msg void OnDestroy();
	afx_msg LRESULT OnLBAddString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBInsertString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBResetContent(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSetItemHeight(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetFont(CFont* pFont, BOOL bRedraw);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiCheckListBox();
	~CAdUiCheckListBox() noexcept;
	void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void EnableItemToolTip();
	CAdUiCheckListBox::HorizontalStyle GetHorizontalStyle() const { return m_horizontalStyle; }
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void PreSubclassWindow();
	void SetHorizontalStyle(CAdUiCheckListBox::HorizontalStyle style);
};
