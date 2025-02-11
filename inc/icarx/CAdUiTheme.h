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
***     Description: Declaration of CAdUiTheme class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>
#include <afxtempl.h>

#include "CAdUiThemeModifiedReactor.h"
#include "../adui_port.h"
#include "../AdAChar.h"
#include "../AcColorThemeEnum.h"

#define PROPERTY_PALETTE_THEME ACRX_T(/*MSG0*/ "PropertyPalette")
#define TOOL_PALETTE_THEME ACRX_T(/*MSG0*/ "ToolPalette")
#define OWNDERDRAW_BUTTON_THEME ACRX_T(/*MSG0*/ "OwnerDrawButton")
#define DIALOG_WORKSHEET_THEME ACRX_T(/*MSG0*/ "DialogWorksheet")
#define PALETTE_SET_THEME ACRX_T(/*MSG0*/ "PaletteSet")
#define DESIGN_CENTER_THEME ACRX_T(/*MSG0*/ "DesignCenter")
#define TOOL_PANEL_THEME ACRX_T(/*MSG0*/ "ToolPanel")
#define DOCKBAR_THEME ACRX_T(/*MSG0*/ "DockBar")
#define DOCKCONTROLBAR_THEME ACRX_T(/*MSG0*/ "DockControlBar")
#define ANCHORBAR_THEME ACRX_T(/*MSG0*/ "AnchorBar")
#define ACTIVE_THEME ACRX_T(/*MSG0*/ "ACTIVETHEME")
#define DIALOG_THEME ACRX_T(/*MSG0*/ "DIALOGTHEME")

class CAcColorTheme;

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiTheme
{
	friend class CAdUiThemeManager;

private:
	int m_nRefCount = 1;
	CTypedPtrArray<CPtrArray, CAdUiThemeModifiedReactor*> m_arrayModReactors;
	int m_nModNotificationsSuspended = 0;
	CMap<int, int, DWORD, DWORD> m_mapDwordValues;
	CMap<int, int, CString, CString> m_mapStringValues;
	CMap<int, int, void*, void*> m_mapPointerValues;
	LOGFONT m_lfWorksheet;
	LOGFONT m_lfWorksheetCaption;
	LOGFONT m_lfPaletteCaption;
	LOGFONT m_lfInspectorItem;
	LOGFONT m_lfInspectorRoot;
	LOGFONT m_lfPaletteTab;
	LOGFONT m_lfPalette;
	LOGFONT m_lfPaletteToolTip;
	CAcColorTheme* m_pColorTheme = nullptr;
	AcColorThemeEnum m_themeType = AcColorThemeEnum::eAcadDarkTheme;
	BOOL m_bUsesXPThemes = false;

private:
	CAdUiTheme();
	CAdUiTheme(const CAcColorTheme& colorTheme, AcColorThemeEnum themeType);
	virtual ~CAdUiTheme();
	void CheckXP();
	void DecrementRefCount() { m_nRefCount--; }
	void InitializeFont(LOGFONT& sourceLF, LOGFONT& destLF, int fontType = 0);
	void InitializeFontsForDialog();
	int RefCount() { return m_nRefCount; }
	void SendThemeModifiedNotifications(AdUiThemeElement nElement) const;
	void SetColorTheme(const CAcColorTheme& colorTheme, AcColorThemeEnum themeType);
	BOOL UsesXP() { return m_bUsesXPThemes; }
	void commonInitialize();

public:
	DWORD GetARGBColor(AdUiThemeElement nDisplayElement) const;
	COLORREF GetColor(AdUiThemeElement nDisplayElement) const;
	BOOL GetData(int nElement, DWORD& dwData) const;
	BOOL GetData(int nElement, CString& sData) const;
	void* GetDataPtr(int nElement) const;
	BOOL GetFont(AdUiThemeElement nDisplayElement, LOGFONT* plf) const;
	BOOL GetFont(AdUiThemeElement nDisplayElement, CFont*& pFont) const;
	static COLORREF GetRGBForeColor(DWORD fgColor, COLORREF bgColor);
	void IncrementRefCount() { m_nRefCount++; }
	bool IsDark() const;
	BOOL RegisterReactor(CAdUiThemeModifiedReactor* pReactor);
	void ResumeModifiedNotifications();
	void SendModifiedNotification() const;
	BOOL SetARGBColor(AdUiThemeElement nDisplayElement, DWORD dColor);
	BOOL SetColor(AdUiThemeElement nDisplayElement, COLORREF crColor);
	void SetData(int nElement, const DWORD& dwData);
	void SetData(int nElement, const CString& sData);
	void SetDataPtr(int nElement, void* pData);
	BOOL SetFont(AdUiThemeElement nDisplayElement, LOGFONT* plf = nullptr);
	void SuspendModifiedNotifications() { m_nModNotificationsSuspended++; }
	BOOL UnregisterReactor(CAdUiThemeModifiedReactor* pReactor);
	bool UsesActiveThemeColors() const { return !m_pColorTheme; }
	CAdUiTheme& operator=(const CAdUiTheme& Theme);
};


#include "IcArxPackPop.h"
