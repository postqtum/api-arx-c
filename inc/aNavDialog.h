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
***     Description: Declaration of CNavDialog class
***
*****************************************************************************/
#pragma once

#ifndef ANAV_PORT
#	define ANAV_PORT
#endif

#include "aduiDialog.h"

#include "aNavDataArray.h"
#include "aNavFilterArray.h"
#include "aNavListCtrl.h"

#define WM_FILEDLG_FINDFILEHELP (WM_USER + 37)

enum OkHandlerErr
{
	NAV_OKHANDLER_SUCCESS = 0,
	NAV_OKHANDLER_NONFILESYSTEM,
	NAV_OKHANDLER_FAILURE,
	NAV_OKHANDLER_TOOLONG
};

enum NavToolsMenuItem
{
	NAV_TOOLS_ITEM_FIND = 0x1,
	NAV_TOOLS_ITEM_LOCATE = 0x2,
	NAV_TOOLS_ITEM_FTPMODIFY = 0x4,
	NAV_TOOLS_ITEM_SIMPLESTORAGE = 0x8,
	NAV_TOOLS_ITEM_ADDCURRENT = 0x10,
	NAV_TOOLS_ITEM_ADDFAVORITES = 0x20
};

enum NavInetTransferActions
{
	NAV_INET_IGNORE_CACHE = 0x1,
	NAV_INET_STOP_ON_ERROR = 0x2,
	NAV_INET_KEEP_CACHE = 0x4
};

class ANAV_PORT CNavDialog : public CAdUiDialog
{
	friend class CNavDialogImp;
	DECLARE_DYNAMIC(CNavDialog)

public:
	enum
	{
		IDD = 0
	};

	DECLARE_MESSAGE_MAP()
private:
	void* m_navImp = nullptr;

	afx_msg LRESULT OnWmDeviceChange(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnWmGetIShellBrowser(WPARAM wp, LPARAM lp);

protected:
	afx_msg void OnContextMenu(CWnd*, CPoint);
	afx_msg void OnDestroy();
	afx_msg BOOL OnHelpInfo(HELPINFO * pHelpInfo);
	afx_msg void OnKickIdle();
	afx_msg void OnSysColorChange();

protected:
	virtual OkHandlerErr CombineDataTextWithFolderName(CNavData * data, CString & strResult);
	virtual void DisplaySearchError(LPCTSTR sBase);
	void DoDataExchange(CDataExchange * pDX);
	virtual BOOL FindInSearchPath(LPCTSTR sBase, CString * pFullPath);
	virtual void GetDefaultBrowserStartURL(CString & strStartPage);
	virtual BOOL GetRecentDirectory(CString & strRecent);
	virtual BOOL LaunchBrowserDialog(CString & strSelectedURL, LPCTSTR strDialogCaption,
										LPCTSTR strOk, LPCTSTR strStartPage);
	void OnCancel();
	BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void OnDoAddToFavorites(BOOL bOneItem);
	virtual void OnDoFind();
	virtual void OnDoLocate();
	virtual void OnFileNameChange();
	virtual BOOL OnFileNameOK();
	virtual void OnFileNameSelectionChange();
	virtual void OnFilterChange();
	virtual void OnFolderChange();
	virtual void OnFolderItemChange();
	BOOL OnInitDialog();
	ADUI_REPLY OnNotifyControlChange(UINT controlId, LPARAM lParam);
	ADUI_REPLY OnNotifyGeneric(UINT controlId, LPARAM lParam);
	void OnOK();
	virtual void OnPlacesChanged();
	virtual void OnURLDownloadSuccess(CString & strURL);
	virtual BOOL OnUrlOK();
	BOOL PreTranslateMessage(MSG * pMsg);
	virtual void PrepareOkMenu(CMenu * pMenu);
	virtual void PrepareToolsMenu(CMenu * pMenu);
	virtual void PrepareViewsMenu(CMenu * pMenu);
	virtual OkHandlerErr PreprocessData(CNavDataArray & array);
	virtual void Refresh();
	virtual BOOL ReportURLTransferStatus(CDWordArray & dwErrorArray, CStringArray & strURLs,
											CStringArray & strLocals);
	virtual BOOL UpdateFileExtension(CString & strName, BOOL bCanUseCurrentExtension);
	virtual void UpdateUIState();
	virtual BOOL VerifyURLSave();

public:
	CNavDialog(CNavDataArray & dataArray, CNavFilterArray & filterArray, UINT idd = 0,
				CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	~CNavDialog() throw();
	void AddDataToHistory();
	virtual BOOL BeginDownloadFiles(CStringArray & strURLs, CDWordArray & dwActionCodes);
	void BrowseCurrentObject();
	INT_PTR DoModal();
	BOOL GetAcceptAnyFileExtension();
	virtual BOOL GetAllDialogsData(const CString& cValueName, DWORD& data);
	virtual BOOL GetAllDialogsData(const CString& cValueName, CString& cValue);
	BOOL GetConfirmReplace();
	BOOL GetCreatingFile();
	CNavFilter* GetCurrentFileExtension(CString & strExt);
	void GetCurrentFolderForPersistence(CString & strFolder);
	CNavDataArray& GetDataArray();
	LPCTSTR GetDefaultFileExtension();
	int GetDefaultFilterIndex();
	LPCTSTR GetDefaultInitialFolder();
	LPCTSTR GetDialogCaption();
	virtual DWORD GetDownloadActionCodes(CString & strURL);
	CNavFilterArray& GetFilterArray();
	int GetFilterIndex();
	CNavListCtrl* GetFolderListCtrl();
	BOOL GetFoldersOnly();
	int GetForceFilterIndex();
	LPCTSTR GetForceInitialFolder();
	UINT GetIDD();
	void* GetImpObject() const;
	LPCTSTR GetInitialFileName();
	DWORD GetInitialFilterIndex();
	BOOL GetMultiSelectAllowed();
	BOOL GetNoExtraExtensions();
	BOOL GetNoExtraExtensionsInPlaces();
	BOOL GetNoFTP();
	BOOL GetNoFTPInPlaces();
	BOOL GetNoFavoritesInPlaces();
	BOOL GetNoPlacesList();
	BOOL GetNoURLFileTransfer();
	BOOL GetNoURLsAllowed();
	void GetOkButtonText(CString & strOk, BOOL bIncludeAccel = 1);
	BOOL GetPersonalFolderPath(CString & strPersonal);
	virtual BOOL GetProductName(CString & strProduct);
	BOOL GetReadOnlyAllowed();
	BOOL GetReadOnlyHidden();
	BOOL GetReadOnlySpecified();
	void GetSingleDataFullPath(CString & strFullPath);
	int GetToolsMenuItemPosition(NavToolsMenuItem itemFlag);
	UINT GetToolsMenuItemsPresent();
	BOOL GetUseRegExtensionFlags();
	UINT GetViewMode();
	int InsertUserItemInPlaces(int index, LPCTSTR sFullPath, LPCTSTR sText);
	BOOL IsPlacesListCustomized();
	virtual void LocateFile();
	int MovePlacesItem(int fromLocation, int toLocation);
	BOOL NavigateToFolder(LPCTSTR sFolder);
	void OnDialogHelp();
	virtual void OnDialogHelp(LPCTSTR pHelpTag);
	void SetAcceptAnyFileExtension(BOOL any);
	virtual BOOL SetAllDialogsData(const CString& cValueName, DWORD dwValue);
	virtual BOOL SetAllDialogsData(const CString& cValueName, CString& cValue);
	void SetConfirmReplace(BOOL confirm);
	void SetCreatingFile(BOOL create);
	void SetDefaultFileExtension(LPCTSTR ext);
	void SetDefaultFilterIndex(int index);
	void SetDefaultInitialFolder(LPCTSTR folder);
	void SetDialogCaption(LPCTSTR caption);
	void SetFilterIndex(int index);
	void SetFolderComboCurSel(int i);
	void SetFolderListCtrl(CNavListCtrl * folderListCtrl);
	void SetFoldersOnly(BOOL foldersOnly);
	void SetForceFilterIndex(int index);
	void SetForceInitialFolder(LPCTSTR folder);
	void SetInitialFileName(LPCTSTR name);
	void SetMultiSelectAllowed(BOOL allow);
	void SetNoExtraExtensions(BOOL noExtraExtensions);
	void SetNoExtraExtensionsInPlaces(BOOL noExtraExtensions);
	void SetNoFTP(BOOL noFTP);
	void SetNoFTPInPlaces(BOOL noFTPInPlaces);
	void SetNoFavoritesInPlaces(BOOL noFavorites);
	void SetNoURLFileTransfer(BOOL noTransfer);
	void SetNoURLsAllowed(BOOL noURLs);
	void SetOkButtonMenuExists(BOOL bExists);
	void SetOkButtonText(LPCTSTR text);
	void SetReadOnlyAllowed(BOOL allow);
	void SetReadOnlyHidden(BOOL hidden);
	void SetReadOnlySpecified(BOOL readOnly);
	void SetToolsMenuItemsPresent(UINT flag);
	void SetUseRegExtensionFlags(BOOL bUse);
	void SetViewMode(UINT viewMode);
	void TrimWhiteSpace(CString & strName, BOOL bAll);
};
