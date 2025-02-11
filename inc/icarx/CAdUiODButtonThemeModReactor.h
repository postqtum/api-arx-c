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
***     Description: Declaration of CAdUiODButtonThemeModReactor class
***
*****************************************************************************/
#pragma once

#include "CAdUiThemeModifiedReactor.h"

class CAdUiOwnerDrawButton;
class CAdUiTheme;

#include "IcArxPackPush.h"

class CAdUiODButtonThemeModReactor : public CAdUiThemeModifiedReactor
{
private:
	CAdUiOwnerDrawButton* m_pBtn = nullptr;

public:
	CAdUiODButtonThemeModReactor(CAdUiOwnerDrawButton* pBtn);
	void ThemeModified(const CAdUiTheme* pTheme, AdUiThemeElement element) override;
};

#include "IcArxPackPop.h"
