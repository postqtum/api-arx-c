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

#include "adesk.h"
#include "AdAChar.h"
#include "AcStatusBar.h"
#include "core_rxmfcapi.h"

class AcDbDatabase;
class CDialogBar;
class AdApplicationFrame;
class CMDIFrameWnd;
class CMDIChildWnd;

using AcedPreTranslateMsgFn = BOOL (*)(MSG*);

#include "icarx/IcArxPackPush.h"

typedef struct tagChildFrmSettings
{
	AcColorSettings m_ColorSettings;
	bool m_bShowLayoutBar;
	bool m_bShowScrollBar;
	CDialogBar* m_pDialogBar;
	bool m_bIsBedit;
} AcChildFrmSettings;

#include "icarx/IcArxPackPop.h"

AcDbDatabase* AcApGetDatabase(CView* pView);
HINSTANCE acedGetAcadBrandingResourceInstance();
CDocument* acedGetAcadDoc();
CWnd* acedGetAcadDockCmdLine();
CView* acedGetAcadDwgView();
CMDIFrameWnd* acedGetAcadFrame();
CWnd* acedGetAcadTextCmdLine();
CWinApp* acedGetAcadWinApp();
AdApplicationFrame* acedGetApplicationFrame();
BOOL acedGetChildFrameSettings(AcChildFrmSettings* pChildFrmSettings, CMDIChildWnd* pWnd);
BOOL acedGetIUnknownForCurrentCommand(LPUNKNOWN& pUnk);
HMENU acedGetMenu(const wchar_t* pszAlias);
const CString& acedGetRegistryCompany();
BOOL acedRegisterExtendedTab(const wchar_t* szAppName, const wchar_t* szDialogName);
BOOL acedRegisterMainFramePreTranslateObserver(const AcedPreTranslateMsgFn pfn);
BOOL acedRegisterStatusBarMenuItem(AcStatusBarMenuItem* pItem,
								   AcStatusBarMenuItem::AcStatusBarType nType);
BOOL acedRemoveMainFramePreTranslateObserver(const AcedPreTranslateMsgFn pfn);
BOOL acedSetChildFrameSettings(AcChildFrmSettings* pChildFrmSettings, CMDIChildWnd* pWnd);
BOOL acedSetIUnknownForCurrentCommand(const LPUNKNOWN);
BOOL acedSetStatusBarPaneID(AcPane* pPane, AcStatusBarMenuItem::AcStatusBarType nType, int nID);
BOOL acedShowDrawingStatusBars(BOOL bShow = TRUE);
void acedSuppressFileMRU(bool bSuppress);
BOOL acedUnregisterStatusBarMenuItem(AcStatusBarMenuItem* pItem,
									 AcStatusBarMenuItem::AcStatusBarType nType);

#ifdef _ARX_CUSTOM_DRAG_N_DROP_
BOOL acedAddDropTarget(COleDropTarget* pTarget);
BOOL acedEndOverrideDropTarget(COleDropTarget* pTarget);
BOOL acedRegisterCustomDropTarget(IDropTarget* pItarget);
BOOL acedRemoveDropTarget(COleDropTarget* pTarget);
BOOL acedRevokeCustomDropTarget();
BOOL acedStartOverrideDropTarget(COleDropTarget* pTarget);
#endif	// _ARX_CUSTOM_DRAG_N_DROP_

#ifndef WM_ACAD_KEEPFOCUS
#	define WM_ACAD_KEEPFOCUS (WM_USER + 0x6D01)
#endif	// WM_ACAD_KEEPFOCUS
