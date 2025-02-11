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
***     Description: Declaration of CAdUiPaletteSetDockSite class
***
*****************************************************************************/
#pragma once

#include <afxpriv.h>
#include "../AdAChar.h"
#include "../aduiButton.h"
#include "../aduiTheme.h"

class CAdUiDockBar;

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiPaletteSetDockSite
{
private:
	DWORD m_dwDockStyle = 0;
	CControlBar* m_pBar = nullptr;
	CAdUiDockBar* m_pTargetDockBar = nullptr;
	CFrameWnd* m_pDockSite = nullptr;
	CRect m_rectDragDock;
	CRect m_rectDragHorz;
	CRect m_rectDragHorzAlone;

public:
	CRect* CanDock(const CPoint& pMousePos);
	bool DockControlBar(CControlBar* pBar);
	void Initialize(CControlBar* pBar, CSize* pDesiredSize, DWORD dwDockStyle);
};


#include "IcArxPackPop.h"
