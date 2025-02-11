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
***     Description: Declaration of CAcUiStringComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiComboBox.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiSymbolComboBox : public CAcUiComboBox
{
	DECLARE_DYNAMIC(CAcUiSymbolComboBox);

public:
	CAcUiSymbolComboBox();
	~CAcUiSymbolComboBox();

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
