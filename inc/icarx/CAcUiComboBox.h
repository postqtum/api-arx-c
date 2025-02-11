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
***     Description: Declaration of CAcUiComboBox class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "../aduiComboBox.h"

#include "CAcUiEdit.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiComboBox : public CAdUiComboBox
{
	DECLARE_DYNAMIC(CAcUiComboBox);

protected:
	DECLARE_MESSAGE_MAP()

public:
	CAcUiComboBox();
	~CAcUiComboBox();

	CAcUiEdit* AcUiEditBox();
	void Convert();
	BOOL ConvertData(CString& x);
	void SetRange(double vMin, double vMax);
	BOOL Validate();
	ACUI_ERROR_CODE ValidateData(CString& x);
};


#include "IcArxPackPop.h"
