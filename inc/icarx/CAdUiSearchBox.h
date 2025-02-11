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
***     Description: Declaration of CAdUiSearchBox class
***
*****************************************************************************/
#pragma once

#include "CAdUiEdit.h"

class CAdUiSearchBoxEditor;
class CAdUiSearchBoxSearchButton;
class CAdUiSearchBoxClearButton;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiSearchBox : public CAdUiEdit
{
	DECLARE_DYNAMIC(CAdUiSearchBox)

private:
	bool m_bIsControlsCreated = false;
	CAdUiSearchBoxEditor* m_pEditor = nullptr;
	CAdUiSearchBoxSearchButton* m_pBtnSearch = nullptr;
	CAdUiSearchBoxClearButton* m_pBtnClear = nullptr;
	CString m_strNotification;
	CString m_strDefaultText;

private:
	BOOL CreateControls();
	BOOL DestroyControls();
	void GetControlRect(CRect& editRect, CRect& buttonRect);
	void UpdateButton();
	void UpdateSearchBox();

protected:
	BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	afx_msg void KillEditFocus();
	afx_msg void OnClearButton();
	afx_msg void OnEditChange();
	afx_msg void OnSearchButton();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void SetEditFocus();

	DECLARE_MESSAGE_MAP()

public:
	CAdUiSearchBox();
	~CAdUiSearchBox();
	virtual void ClearButtonClicked();
	void ClearEditor();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual void EditChanged();
	bool IsEditEmpty();
	void PreSubclassWindow();
	virtual void SearchButtonClicked();
	void SetButtonBackgroundColorForThemeChange(COLORREF color, bool bThemeIsDark);
	void SetDefaultText(LPCTSTR pszText);
	void SetNotification(LPCTSTR pszText);
};


#include "IcArxPackPop.h"
