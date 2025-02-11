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
***     Description: Declaration of CAdUiDialog class
***
*****************************************************************************/
#pragma once

#include <afxcmn.h>

#include "aduiBaseDialog.h"

#include "icarx/IcArxPackPush.h"

struct _dlgControlTag;
typedef _dlgControlTag* PDLGCTLINFO;

class ADUI_PORT CAdUiDialog : public CAdUiBaseDialog
{
	DECLARE_DYNAMIC(CAdUiDialog);

private:
	LPVOID m_pElastic = nullptr;
	CString m_dlgHelpTag;

protected:
	BOOL m_bEnableElasticMessageMap = false;
	UINT m_templateid = -1;

public:
	enum
	{
		IDD = 0
	};

private:
	void* mHighlightWnd = nullptr;
	bool m_bNewItemsHighlighted = false;

protected:
	void DoDataExchange(CDataExchange* pDX) override;

	void OnInitDialogBegin() override;
	void OnInitDialogFinish() override;
	void OnOK() override;

	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiDialog(UINT idd, CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	~CAdUiDialog();
	BOOL AddControl(CWnd* pControl);
	BOOL AutoLoadControl(CWnd* pControl);
	bool BeginHighlight(CString dialogName);
	BOOL DelDialogData(LPCTSTR valueName);
	BOOL DoDialogHelp() override;
	void EndHighlight();
	BOOL ForceControlRepaint(CWnd* pControl, BOOL bForce);
	BOOL ForceControlResize(CWnd* pControl, LPRECT prect);
	BOOL GetColumnSizes(CListCtrl* pList);
	CSize* GetCurrentDelta();
	BOOL GetDialogData(LPCTSTR valueName, CString& data);
	BOOL GetDialogData(LPCTSTR valueName, DWORD& data);
	void GetDialogHelpTag(CString& tag);
	BOOL GetDialogKey(CString& key);
	BOOL GetDialogName(CString& name);
	void GetElasticMinMaxInfo(MINMAXINFO& mmi);
	LPVOID GetElasticPointer();
	BOOL GetPixelData(CRect& r);
	void LockDialogHeight();
	void LockDialogWidth();
	BOOL MoveControlX(UINT id, LONG lMovePct);
	BOOL MoveControlXY(UINT id, LONG lMoveXPct, LONG lMoveYPct);
	BOOL MoveControlY(UINT id, LONG lMovePct);
	virtual void OnDialogHelp();
	BOOL ReloadControl(CWnd* pControl, LPCTSTR lpResString);
	BOOL RemoveControl(CWnd* pControl);
	BOOL SaveColumnSizes(CListCtrl* pList);
	BOOL SetControlProperty(PDLGCTLINFO lp, DWORD numElements);
	BOOL SetDialogData(LPCTSTR valueName, LPCTSTR data);
	BOOL SetDialogData(LPCTSTR valueName, DWORD data);
	void SetDialogHelpTag(LPCTSTR tag);
	void SetDialogMaxExtents(int width, int height);
	void SetDialogMinExtents(int width, int height);
	void SetDialogName(LPCTSTR name);
	void SetElasticSize(CSize& size, BOOL bRefreshDialog);
	void SetPersistency(BOOL bFlag);
	void SetRootKey(LPCTSTR key);
	void SetTabSize(LPARAM lParam, BOOL bRefreshDialog);
	BOOL StorePixelData();
	BOOL StretchControlX(UINT id, LONG lStretchPct);
	BOOL StretchControlXY(UINT id, LONG lStretchXPct, LONG lStretchYPct);
	BOOL StretchControlY(UINT id, LONG lStretchPct);
};


#include "icarx/IcArxPackPop.h"
