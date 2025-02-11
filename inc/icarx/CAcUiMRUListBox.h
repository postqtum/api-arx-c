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
***     Description: Declaration of CAcUiMRUListBox class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "../acuiListBox.h"

class CAcUiMRUComboBox;

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiMRUListBox : public CAcUiListBox
{
public:
	CAcUiMRUListBox();
	~CAcUiMRUListBox();

public:
	void GetContentExtent(int item, LPCTSTR text, int& width, int& height) override;

protected:
	BOOL OnGetTipRect(CRect& r) override;

protected:
	int ExtraWidth();
	CAcUiMRUComboBox* MRUComboBox();

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
