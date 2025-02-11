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
***     Description: Declaration of AcApStatusBar class
***
*****************************************************************************/
#pragma once

enum AcDefaultPane
{
	ACSBPANE_APP_MODEMACRO,
	ACSBPANE_APP_CURSORCOORD,
	ACSBPANE_APP_SNAP,
	ACSBPANE_APP_GRID,
	ACSBPANE_APP_ORTHO,
	ACSBPANE_APP_POLAR,
	ACSBPANE_APP_OTRACK,
	ACSBPANE_APP_LINEWEIGHT,
	ACSBPANE_APP_PAPERMODEL,
	ACSBPANE_APP_PAPER,
	ACSBPANE_APP_MODEL,
	ACSBPANE_APP_OSNAP,
	ACSBPANE_APP_FLOAT,
	ACSBPANE_APP_TABLET,
	ACSBPANE_APP_SPACER,
	ACSBPANE_APP_VPMAX_PREV,
	ACSBPANE_APP_VPMAX,
	ACSBPANE_APP_VPMAX_NEXT,
	ACSBPANE_APP_DYNINPUT,
	ACSBPANE_APP_DYNAMICUCS,
	ACSBPANE_APP_LAYOUTMODELICONS,
	ACSBPANE_APP_MODEL_ICON,
	ACSBPANE_APP_LAYOUT_ICON,
	ACSBPANE_APP_LAYOUTMORE_ICON,
	ACSBPANE_APP_ALL,
	ACSBPANE_ANNO_STRETCH,
	ACSBPANE_ANNO_AUTOSCALE,
	ACSBPANE_ANNO_VIEWPORT_SCALE_LABEL,
	ACSBPANE_ANNO_VIEWPORT_SCALE,
	ACSBPANE_ANNO_VIEWPORT_LOCK_STATE,
	ACSBPANE_ANNO_ANNOTATION_SCALE_LABEL,
	ACSBPANE_ANNO_ANNOTATION_SCALE,
	ACSBPANE_ANNO_ANNO_ALL_VISIBLE,
	ACSBPANE_ANNO_EMPTY,
	ACSBPANE_APP_STRETCH,
	ACSBPANE_APP_WORKSPACE,
	ACSBPANE_APP_WORKSPACE_LOCK,
	ACSBPANE_APP_QPROPERTIES,
	ACSBPANE_ANNO_SYNCHSCALES,
	ACSBPANE_APP_QV_LAYOUTS,
	ACSBPANE_APP_QV_DRAWINGS,
	ACSBPANE_APP_QV_SPACER,
	ACSBPANE_APP_QV_PAN,
	ACSBPANE_APP_QV_ZOOM,
	ACSBPANE_APP_QV_STEERINGWHEEL,
	ACSBPANE_APP_QV_SHOWMOTION,
	ACSBPANE_APP_QV_ANNO_SPACER,
	ACSBPANE_APP_3DOSNAP,
	ACSBPANE_APP_WORKSPACE_PERFORMANCE,
	ACSBPANE_APP_SELECTIONCYCLING,
	ACSBPANE_APP_TRANSPARENCY,
	ACSBPANE_APP_INFER,
	ACSBPANE_APP_ANNOMONITOR,
	ACSBPANE_APP_SELECTION_FILTER,
	ACSBPANE_APP_GIZMO,
	ACSBPANE_APP_UNITS,
	ACSBPANE_APP_GEO_SPACER,
	ACSBPANE_APP_GEO_MARKERVISIBILITY,
	ACSBPANE_APP_GEO_COORDSYS,
	ACSBPANE_APP_ISODRAFT,
	ACSBPANE_APP_HARDWAREACCELERATION,
	ACSBPANE_APP_ADD_CLEANSCREEN,
	ACSBPANE_APP_ADD_CUSTOMIZATION
};

class AcPane;
class AcTrayItem;

#include "IcArxPackPush.h"

class AcApStatusBar
{
public:
	virtual int Add(AcPane* pPane, BOOL bUpdate = TRUE) = 0;
	virtual int Add(AcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;
	virtual BOOL ClientToScreen(LPPOINT lpPoint) = 0;
	virtual BOOL ClientToScreen(LPRECT lpRect) = 0;
	virtual BOOL CloseAllBubbleWindows(AcTrayItem* pTrayItem) = 0;
	virtual UINT DisplayContextMenu(CMenu& menu, CPoint point) = 0;
	virtual UINT DisplayPopupPaneMenu(AcPane* pPane, CMenu& menu) = 0;
	virtual AcPane* GetDefaultPane(AcDefaultPane nPane) = 0;
	virtual int GetID(int nIndex, BOOL bTrayItem = FALSE) const = 0;
	virtual int GetID(AcPane* pPane) const = 0;
	virtual int GetID(AcTrayItem* pTrayItem) const = 0;
	virtual int GetIndex(int nID, BOOL bTrayItem = FALSE) const = 0;
	virtual int GetIndex(AcPane* pPane) const = 0;
	virtual int GetIndex(AcTrayItem* pTrayItem) const = 0;
	virtual AcPane* GetPane(int nIndex) = 0;
	virtual int GetPaneCount() const = 0;
	virtual int GetTextWidth(const CString& strText) const = 0;
	virtual AcTrayItem* GetTrayItem(int nIndex) = 0;
	virtual int GetTrayItemCount() const = 0;
	virtual BOOL GetTraySettingsShowIcons() const = 0;
	virtual BOOL GetTraySettingsShowNotifications() const = 0;
	virtual BOOL Insert(int nIndex, AcPane* pPane, BOOL bUpdate = TRUE) = 0;
	virtual BOOL Insert(int nIndex, AcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;
	virtual BOOL Remove(int nIndex, BOOL bTrayItem = FALSE, BOOL bUpdate = TRUE) = 0;
	virtual BOOL Remove(AcPane* pPane, BOOL bUpdate = TRUE) = 0;
	virtual BOOL Remove(AcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;
	virtual BOOL RemoveAllPanes(BOOL bUpdate = TRUE) = 0;
	virtual BOOL RemoveAllTrayIcons(BOOL bUpdate = TRUE) = 0;
	virtual BOOL RemoveCleanScreenIcon() = 0;
	virtual BOOL RemoveDefaultPane(AcDefaultPane nPane, BOOL bUpdate = TRUE) = 0;
	virtual BOOL ScreenToClient(LPPOINT lpPoint) = 0;
	virtual BOOL ScreenToClient(LPRECT lpRect) = 0;
	virtual BOOL SetStatusBarMenuItem(AcPane* pPane) = 0;
	virtual void ShowCleanScreenIcon(BOOL bShow) = 0;
	virtual void ShowStatusBarMenuIcon(BOOL bShow) = 0;
	virtual BOOL ShowTraySettingsDialog() = 0;
	virtual void Update() = 0;
};

#include "IcArxPackPop.h"
