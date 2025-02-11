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
***     Description: Declaration of CAcUiSymbolEdit class
***
*****************************************************************************/
#pragma once

#include "CAcUiEdit.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiSymbolEdit : public CAcUiEdit
{
	DECLARE_DYNAMIC(CAcUiSymbolEdit)

public:
	CAcUiSymbolEdit();
	~CAcUiSymbolEdit();

public:
	void SetStyleMask(DWORD mask) override;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
