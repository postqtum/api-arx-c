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
***     Description: Common includes for dock support classes
***
*****************************************************************************/
#pragma once

#include "icarx/CAdUiDockControlBarThemeModReactor.h"
#include "icarx/CAdUiDockControlBar.h"
#include "icarx/CAdUiDockFrame.h"
#include "icarx/CAdUiPaletteSetDockFrame.h"
#include "icarx/CAdUiPaletteSetDockSite.h"

#include <afxpriv.h>
#include "AdAChar.h"
#include "aduiButton.h"
#include "aduiTheme.h"

#define ADUI_DOCK_POSITION_TOOL_KEY ADUI_XML_DOCK_TOOL_INFO
#define ADUI_DOCK_STARTUP_TOOL_KEY ADUI_XML_DOCK_STARTUP_INFO
#define ADUI_XML_ROOT ACRX_T("AdUiTools")
#define ADUI_XML_DOCK_TOOL_INFO ACRX_T("ToolsInfo")
#define ADUI_XML_DOCK_TOOL ACRX_T("Tool")
#define ADUI_XML_DOCK_TOOL_CLSID ACRX_T("CLSID")
#define ADUI_XML_DOCK_STARTUP_INFO ACRX_T("StartupInfo")
#define ADUI_XML_DOCK_STARTUP_TOOL_NAME ACRX_T("ToolName")
#define ADUI_XML_DOCK_STARTUP_CMD_NAME ACRX_T("Command")

#define ID_ADUI_ALLOWDOCK 0x1001
#define ID_ADUI_HIDEBAR 0x1002

#define ADUI_DOCK_NF_SIZECHANGED 0x01
#define ADUI_DOCK_NF_STATECHANGED 0x02
#define ADUI_DOCK_NF_FRAMECHANGED 0x02

#define WM_ACAD_DOCKBAR_ROLLED_UP (WM_USER + 37)
#define WM_ACAD_DOCKBAR_ROLLED_OUT (WM_USER + 38)

void ADUI_PORT AdUiSaveDockingToolPositions();
void ADUI_PORT AdUiShowDockControlBars(bool bShow);
bool ADUI_PORT AdUiRegisterDockingTool(LPCTSTR lpszToolName, LPCTSTR lpszCommand, UINT nToolbarID);
bool ADUI_PORT AdUiRegisterTool(LPCTSTR lpszToolName, LPCTSTR lpszCommand, LPCGUID pID);

ADUI_PORT CRuntimeClass* AdUiSetFloatingFrameClass(CRuntimeClass* pNewClass);

ADUI_PORT void AdUiRegisterFloatingFrameClassAddress(CRuntimeClass** pClass);
ADUI_PORT void AdUiRegisterPaletteSetFloatingFrameClass(CRuntimeClass* pClass);
ADUI_PORT CRuntimeClass* AdUiGetRegisteredPaletteSetFloatingFrameClass(void);

typedef HRESULT ADUI_LOADFN(IUnknown** ppAdUiRootNode);
typedef HRESULT ADUI_SAVEFN(IUnknown* pAdUiRootNode);

void ADUI_PORT AdUiEnableDocking(CFrameWnd* pFrame, DWORD dwDockStyle, ADUI_LOADFN* pLoadFcn,
								 ADUI_SAVEFN* pSaveFcn);

bool ADUI_PORT CanStealFocusFromDockedWindow();
void ADUI_PORT GetSystemVirtualScreen(RECT& rect);

void ADUI_PORT AdUiEnableDockControlBars(BOOL bEnable, CStringArray* pToolIds = nullptr);
