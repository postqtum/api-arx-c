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
***     Description: Declaration of CAdUiDropSite class
***
*****************************************************************************/
#pragma once

#include "CAdUiBitmapStatic.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiDropSite : public CAdUiBitmapStatic
{
	DECLARE_DYNAMIC(CAdUiDropSite)

public:
	CAdUiDropSite();
	~CAdUiDropSite();

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
