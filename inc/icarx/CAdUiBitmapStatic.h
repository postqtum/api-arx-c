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
***     Description: Declaration of CAdUiBitmapStatic class
***
*****************************************************************************/
#pragma once

#include "CAdUiBitmapButton.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiBitmapStatic : public CAdUiBitmapButton
{
	DECLARE_DYNAMIC(CAdUiBitmapStatic)

public:
	CAdUiBitmapStatic();
	~CAdUiBitmapStatic();

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
