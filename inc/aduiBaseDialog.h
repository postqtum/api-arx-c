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
***     Description: Declaration of CAdUiBaseDialog class
***
*****************************************************************************/
#pragma once

#include <afxdlgs.h>

#include "adui_port.h"
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

#pragma warning(push)
#pragma warning(disable : 4275)

class CAdUiTextTip;

class ADUI_PORT CAdUiBaseDialog : public CDialog
{
	DECLARE_DYNAMIC(CAdUiBaseDialog);

private:
	HINSTANCE m_commandResourceInstance;
	BOOL m_commandWindowWasEnabled;
	HWND m_commandWindowWithFocus;

protected:
	ADUI_COMMAND_STATE m_commandState;

protected:
	CString m_contextHelpFileName;
	CString m_contextHelpFullPathName;
	CString m_contextHelpPrefix;
	CString m_contextHelpMapFileName;

private:
	BOOL m_bRunningModal;
	HINSTANCE m_hDialogResourceSaved;
	CFont m_substFont;

protected:
	int m_bUseTips;
	HINSTANCE m_hDialogResource;
	HICON m_hIcon;
	CAdUiTextTip* m_pTextTip;
	CToolTipCtrl* m_pToolTip;
	CString m_rootKey;
	friend class CAdUiAssist;
	static CAdUiAssist* m_pUIAssist;

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

	DECLARE_MESSAGE_MAP()

	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnAdUiTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
	afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR * pNMHDR, LRESULT * pResult);

public:
	CAdUiBaseDialog(UINT idd, CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	~CAdUiBaseDialog();
	virtual CWnd* AppMainWindow();
	virtual HINSTANCE AppResourceInstance();
	virtual LPCTSTR AppRootKey();
	BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = nullptr);
	BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = nullptr);
	BOOL DisplayData();
	virtual BOOL DoDialogHelp();
	INT_PTR DoModal();
	BOOL EditorCommandCancelled();
	virtual void EnableFloatingWindows(BOOL allow);
	virtual int EnableMultiDocumentActivation(BOOL bEnable);
	virtual BOOL ExchangeData(BOOL bSaveAndValidate);
	LPCTSTR GetContextHelpFileName();
	LPCTSTR GetContextHelpFullPathName();
	LPCTSTR GetContextHelpMapFileName();
	LPCTSTR GetContextHelpPrefix();
	HICON GetDialogIcon();
	CToolTipCtrl* GetToolTipCtrl();
	int GetUseTips();
	virtual int IsMultiDocumentActivationEnabled();
	BOOL PreTranslateMessage(MSG* pMsg);
	void SetAppRootKey(LPCTSTR key);
	void SetContextHelpFileName(LPCTSTR pFileName);
	void SetContextHelpFullPathName(LPCTSTR pFullPathName);
	void SetContextHelpMapFileName(LPCTSTR pFileName);
	void SetContextHelpPrefix(LPCTSTR pPrefix);
	void SetDialogIcon(HICON hIcon);
	void SetUseTips(int useTips);
	BOOL ValidateData();
};

#include "icarx/IcArxPackPop.h"
