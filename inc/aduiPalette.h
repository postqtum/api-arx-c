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
***     Description: Declaration of CAdUiPalette class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>
#include "adui_port.h"

class CAdUiPaletteSet;

#define PS_EDIT_NAME 0x00000001

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiPalette : public CWnd
{
	DECLARE_DYNAMIC(CAdUiPalette)

private:
	CString m_sName;
	CAdUiPaletteSet* m_pPaletteSet = nullptr;
	CObArray m_arrayColors;
	DWORD m_dwStyle = 0;
	static UINT m_nNextPaletteId;
	CEdit* m_pLabelEdit = nullptr;
	static bool m_bPaletteNameEditInProgress;

protected:
	afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);
	afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);
	afx_msg BOOL OnEraseBkgnd(CDC* pdc);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint pt);
	afx_msg BOOL OnSetCursor(CWnd* pwnd, UINT nHitTest, UINT msg);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiPalette();
	~CAdUiPalette();
	virtual bool CanFrameworkTakeFocus();
	BOOL Create(DWORD dwStyle, LPCTSTR pszName, CAdUiPaletteSet* pParent, DWORD dwPaletteStyle = 0);
	virtual BOOL Create(CAdUiPaletteSet* pParent);
	virtual void EditName(CPoint& ptLoc);
	virtual void EditName();
	BOOL EditNameStyle() { return m_dwStyle & PS_EDIT_NAME; }
	virtual CString GetClassNameW();
	virtual BOOL GetMaximumSize(CSize& size);
	virtual BOOL GetMinimumSize(CSize& size);
	CString GetName();
	CAdUiPaletteSet* GetPaletteSet() { return m_pPaletteSet; }
	DWORD GetPaletteStyle();
	virtual void InitPaletteTheme() {}
	virtual BOOL Load(IUnknown* pUnk);
	virtual BOOL NameEditValidation(CEdit* pEdit);
	virtual BOOL OnKillActive();
	virtual void OnSetActive();
	static bool PaletteNameEditInProgress();
	virtual BOOL Save(IUnknown* pUnk);
	void SetName(CString strName);
	void SetPaletteSet(CAdUiPaletteSet* pSet);
	void SetPaletteStyle(DWORD dwStyle);
};


#include "icarx/IcArxPackPop.h"
