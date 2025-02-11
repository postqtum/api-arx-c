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
***     Description: Declaration of CAcUiLineWeightComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiLineWeightComboBox : public CAcUiMRUComboBox
{
public:
	CAcUiLineWeightComboBox();
	~CAcUiLineWeightComboBox();

protected:
	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	void OnAddItems() override;

protected:
	double m_lineWeightScale;

public:
	int FindItemByLineWeight(int lw);
	int GetCurrentItemLineWeight();
	int GetCurrentLayerLineWeight();
	int GetItemLineWeight(int item);
	double GetLineWeightScale();
	void SetLineWeightScale(double scale);
	void SetUseDefault(BOOL b);
	int ImageWidth() override;

private:
	BOOL m_bUseDefault = FALSE;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
