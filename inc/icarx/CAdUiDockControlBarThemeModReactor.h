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
***     Description: Declaration of CAdUiDockControlBarThemeModReactor class
***
*****************************************************************************/
#pragma once

#include "CAdUiThemeModifiedReactor.h"

class CAdUiDockControlBar;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class CAdUiDockControlBarThemeModReactor : public CAdUiThemeModifiedReactor
{
private:
	CAdUiDockControlBar* m_pDockControlBar = nullptr;

public:
	CAdUiDockControlBarThemeModReactor(CAdUiDockControlBar* pDockControlBar);
	void ThemeModified(const CAdUiTheme* pTheme, AdUiThemeElement element) override;
	void SetDockControlBar(CAdUiDockControlBar* pDockControlBar);
};

#include "IcArxPackPop.h"
