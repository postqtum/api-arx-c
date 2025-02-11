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
***     Description: Declaration of IWebServicesLoader and AdApplicationFrame classes
***
*****************************************************************************/
#pragma once

#include "../AdExportDef.h"

class AdImpApplicationFrame;
class AdApplicationFrameReactor;
class AdMenuBar;

typedef LRESULT (*LPFNAPPFRAMECALLBACK)(UINT nIndex, void* pUserData, void* pContextData);

#include "IcArxPackPush.h"

class IWebServicesLoader
{
public:
	virtual bool LoadModule() = 0;

protected:
	virtual ~IWebServicesLoader() = default;
};

class ADAF_PORT AdApplicationFrame
{
public:
	enum Ad_AppFrame_Const
	{
		kAdApplicationStatusBarHeight_Min = 24,
		kAdDefaultDpi = 96
	};

	enum Ad_HostWindow_States
	{
		kAd_DocumentActivated = 1,
		kAd_MenuSelect = 2,
		kAd_MDIStateChanged = 3,
		kAd_WindowPosChanged = 4,
		kAd_SessionInit = 5,
		kAd_SessionDone = 6,
		kAd_SettingChanged = 7,
		kAd_MDIMetricsChanged = 8,
		kAd_SetWindowText = 9,
		kAd_VisibilityChanged = 10,
		kAd_GetWindowText = 11,
		kAd_GetWindowTextLen = 12,
		kAd_SysColorChanged = 13
	};

	enum Ad_AppFrame_Indexes
	{
		kAd_Index_ApplicationButton = 0,
		kAd_Index_QATBar = 1,
		kAd_Index_SysBtnGroup = 2,
		kAd_Index_InfoCenter = 3,
		kAd_Index_DocName = 4,
		kAd_Index_MenuBar = 5,
		kAd_Index_DocControl = 6
	};

	enum Ad_ApplicationButtonId
	{
		kAd_ApplicationButtonId_Big,
		kAd_ApplicationButtonId_Small,
		kAd_ApplicationButtonId_Window,
	};

	enum Ad_AppFrame_ToolTipId
	{
		kAd_ToolId_ApplicationButton = 1000,
	};

	enum Ad_Callback_Index
	{
		kAd_ApplicationButton_IsOpen,
		kAd_ApplicationButton_ShowSmallButton,
		kAd_ToolTip_Close,
		kAd_ToolTip_Show,
		kAd_MenuBar_Show,
		kAd_MenuBar_ExecuteMenuItem,
		kAd_WorkSpaceInfo,
		kAd_GetProductName,
		kAd_Ribbon_IsDockedTop,
		kAd_ACAD_InPlotPreview,
		kAd_ACAD_GetDataSource,
		kAd_RecalcLayout,
		kAd_StayActive,
		kAd_GetMDIClient,
		kAd_MDIGetActive,
		kAd_SkipStandardBackgroundDraw,
		kAd_SkipProductNameUpdate,
		kAd_CustomDraw,
	};

	enum Ad_Product_Character_Set
	{
		kAd_Unicode,
		kAd_MBCS
	};

	static void SetResourcesPath(LPCWSTR lpszName);
	static AdApplicationFrame* CreateInstance(HWND hWndMainFrame);

	virtual ~AdApplicationFrame();

	bool Initialize();

	void SessionInitialized();

	AdMenuBar* GetMenuBar();

	void SetDocumentName(LPCWSTR wszDocumentName);

	bool SetProductLogo(HBITMAP hBitmap);
	bool SetBrand(HBITMAP hBitmap);
	bool SetProductIcon(HICON hIcon);
	bool SetMainMenu(HMENU hMainMenu);
	bool SetMainFrame(HWND hWndMainFrame);
	bool SetMainFrameRect(RECT rectMainFrame);
	bool SetProductCharacterSet(Ad_Product_Character_Set charSet);
	bool SetProductName(LPCWSTR lpszName);
	void SetUseModernizedUI(bool bUse);
	void DisableVistaUI();
	bool SetApplicationWindowButton(HBITMAP hBitmap, HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);
	bool SetApplicationButton(HBITMAP hBitmap, HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);
	bool SetSmallApplicationButton(HBITMAP hBitmap, HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);

	bool IsMenuBarVisible();
	void ShowMenuBar(bool bShow = true);

	void UpdateApplicationButton();
	bool IsApplicationButtonEnabled() const;
	void EnableApplicationButton(bool bEnable = true);

	void ForceFrameRepaint(HWND hWnd);

	unsigned long GetFrameStates();
	unsigned long SetFrameStates(unsigned long dwFrameStates);

	bool AddFrameReactor(AdApplicationFrameReactor* pFrameReactor);
	bool RemoveFrameReactor(AdApplicationFrameReactor* pFrameReactor);

	LPFNAPPFRAMECALLBACK AddFrameCallback(LPFNAPPFRAMECALLBACK pfnCallback, void* pUserData);

	bool TranslateMainFrameMessage(MSG* pMessage);
	BOOL PreTranslateMessageHandler(MSG* pMsg);

	LRESULT ProcessMainFrameMessage(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
	bool HostWindowStateChanged(UINT nState, WPARAM wParam, LPARAM lParam);

	HWND GetAppFrameHwnd();

	HWND GetQuickAccessToolBarHwnd();
	bool IsQuickAccessToolBarVisible();
	void ShowQuickAccessToolBar(bool bShow);

	HWND GetInfoCenterControl();
	bool SetInfoCenterControl(HWND hControl);
	void EnableInfoCtrCtrl(BOOL bEnable);
	void UpdateInfoCenterControl();

	int GetDocumentControlHeight() const;

	void TrackPopupByMenuCmd(int nIndex);
	void EnableMenuBar(bool bEnable);
	void EnableSysBtnGroup(bool bEnable);
	void SetExitOnApplicationButtonDoubleClick(bool bExit);
	bool GetExitOnApplicationButtonDoubleClick();
	const wchar_t* GetApplicationButtonClassName();

	bool IsWebServicesEnabled() const;

	void EnableWebServices(bool isWebServicesEnabled);

	int GetCurrentLocale(wchar_t* locale, int size) const;

	void SetCurrentLocale(const wchar_t* locale);

	void SetSerialNumber(const wchar_t* snumber);

	void SetDecryptedConsumerKey(const wchar_t* skey);

	int GetCachePath(wchar_t* path, int size) const;

	void SetCachePath(const wchar_t* path);

	void SetWebServicesLoader(IWebServicesLoader* loader);

	IWebServicesLoader* GetWebServicesLoader() const;

	bool IsLoggedIn() const;

	int GetLoginUserName(wchar_t* name, int size) const;

	int GetLoginUserId(wchar_t* userId, int size) const;

	int GetServer() const;

	bool IsSyncServiceInstalled() const;

	HWND GetClicUI(int width, int height);

	void HideClicUI();

	void ShowClicUI();

protected:
	AdApplicationFrame(HWND hWndMainFrame);

	static AdApplicationFrame* spAppFrame;

	AdImpApplicationFrame* mpImpAppFrame;

	AdMenuBar* mpAdMenuBar;
};

#include "IcArxPackPop.h"
