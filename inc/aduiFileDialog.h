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
***     Description: Declaration of CAdUiFileDialog class
***
*****************************************************************************/
#pragma once

#include <afxdlgs.h>

#include "aduiMessage.h"

#include "icarx/IcArxPackPush.h"

#ifndef kDialogOptionNone
#	define kDialogOptionNone 0
#endif

#ifndef kDialogOptionUseTips
#	define kDialogOptionUseTips 1
#endif

#ifndef kDialogOptionUseTipsForContextHelp
#	define kDialogOptionUseTipsForContextHelp 2
#endif

class CAdUiTextTip;

#pragma warning(disable : 4275)

class ADUI_PORT CAdUiFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CAdUiFileDialog);

private:
	HINSTANCE m_commandResourceInstance = nullptr;
	BOOL m_commandWindowWasEnabled = FALSE;
	HWND m_commandWindowWithFocus = nullptr;

protected:
	ADUI_COMMAND_STATE m_commandState = ADUI_COMMAND_STATE::kAdUiCommand_Cancelled;

protected:
	CString m_contextHelpFileName;
	CString m_contextHelpFullPathName;
	CString m_contextHelpPrefix;

private:
	HINSTANCE m_hDialogResourceSaved = nullptr;
	CString m_dlgHelpTag;
	CString m_dlgName;
	CImageList* m_pNavButtonImageList = nullptr;

protected:
	int m_bUseTips = 0;
	HINSTANCE m_hDialogResource = nullptr;
	HICON m_hIcon = nullptr;
	CAdUiTextTip* m_pTextTip = nullptr;
	CToolTipCtrl* m_pToolTip = nullptr;
	CString m_rootKey;
	CWnd* m_pParent = nullptr;

public:
	enum
	{
		IDD = 0
	};

protected:
	void BeginEditorCommand();
	void CancelEditorCommand();
	void CompleteEditorCommand(BOOL restoreDialogs = 1);
	virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);
	void DoDataExchange(CDataExchange* pDX);
	virtual BOOL FindContextHelpFullPath(LPCTSTR fileName, CString& fullPath);
	void MakeDialogsVisible(BOOL visible);
	BOOL OnInitDialog();
	virtual void OnInitDialogBegin();
	virtual void OnInitDialogFinish();
	virtual ADUI_REPLY OnNotifyControlChange(UINT controlId, LPARAM lParam);
	virtual ADUI_REPLY OnNotifyControlValid(UINT controlId, BOOL isValid);
	virtual ADUI_REPLY OnNotifyGeneric(UINT controlId, LPARAM lParam);
	virtual ADUI_REPLY OnNotifyUpdateTip(CWnd* control);
	void PostNcDestroy();
	BOOL PreCreateWindow(CREATESTRUCT& cs);

	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
	afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
	public:
	CAdUiFileDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt = nullptr,
					LPCTSTR lpszFileName = nullptr,
					DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
					LPCTSTR lpszFilter = nullptr, CWnd* pParentWnd = nullptr,
					HINSTANCE hDialogResource = nullptr);
	~CAdUiFileDialog();
	virtual CWnd* AppMainWindow();
	virtual HINSTANCE AppResourceInstance();
	virtual LPCTSTR AppRootKey();
	void AutoHiDPIScaleNavButtons();
	virtual BOOL DoDialogHelp();
	INT_PTR DoModal();
	BOOL EditorCommandCancelled();
	virtual void EnableFloatingWindows(BOOL allow);
	LPCTSTR GetContextHelpFileName();
	LPCTSTR GetContextHelpFullPathName();
	LPCTSTR GetContextHelpPrefix();
	void GetDialogHelpTag(CString& tag) { tag = this->m_dlgHelpTag; }
	HICON GetDialogIcon();
	void GetDialogName(CString& name) { name = this->m_dlgName; }
	int GetUseTips();
	virtual void OnDialogHelp();
	BOOL PreTranslateMessage(MSG* pMsg);
	void SetContextHelpFileName(LPCTSTR pFileName);
	void SetContextHelpFullPathName(LPCTSTR pFullPathName);
	void SetContextHelpPrefix(LPCTSTR pPrefix);
	void SetDialogHelpTag(LPCTSTR tag) { this->m_dlgHelpTag = tag; }
	void SetDialogIcon(HICON hIcon);
	void SetDialogName(LPCTSTR name);
	void SetUseTips(int useTips);
};

#include "icarx/IcArxPackPop.h"
