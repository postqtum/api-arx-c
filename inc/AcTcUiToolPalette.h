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
***     Description:
***
*****************************************************************************/
#pragma once

#include "AcTcUi.h"
#include "aduiPalette.h"
#include "AcTcUiPaletteView.h"

class CAcTcUiImpToolPalette;
class AcTcUiSystemInternals;
class CAcTcUiScheme;

class ACTCUI_PORT CAcTcUiToolPalette : public CAdUiPalette
{
	friend CAcTcUiImpToolPalette;

	DECLARE_DYNCREATE(CAcTcUiToolPalette);

public:
	CAcTcUiToolPalette();
	~CAcTcUiToolPalette();

	CAcTcUiPaletteView* GetView(void);

public:
	// Base class overrides
	BOOL Create(CAdUiPaletteSet* pParent) override;
	BOOL Create(DWORD dwStyle, LPCTSTR pszName, CAdUiPaletteSet* pParent, DWORD dwPaletteStyle = 0);
	BOOL Load(IUnknown* pUnk) override;
	bool CanFrameworkTakeFocus() override;
	BOOL Save(IUnknown* pUnk) override;
	virtual BOOL Import(IUnknown* pUnk, LPCTSTR pszRefPath);
	virtual BOOL Export(IUnknown* pUnk, LPCTSTR pszRefPath);
	BOOL OnKillActive(void) override;
	BOOL GetMinimumSize(CSize& size) override;
	void OnSetActive(void) override;
	BOOL NameEditValidation(CEdit* pEdit) override;
	virtual BOOL Paste(IDataObject* pDataObject, int iIndex = -1,
					   AcTcCatalogItemArray* pNewTools = nullptr);
	virtual BOOL CanPaste(IDataObject* pDataObject);
	BOOL SetView(CAcTcUiPaletteView* pView);
	CAcTcUiScheme* GetScheme(void) const;

protected:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

protected:
	void* mpImpObj;

private:
	friend class AcTcUiSystemInternals;
};
