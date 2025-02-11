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
***     Description: Declaration of CAcUiPlotStyleNamesComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"

#include "IcArxPackPush.h"

class CPrintStyleComboBox;

class ACUI_PORT CAcUiPlotStyleNamesComboBox : public CAcUiMRUComboBox
{
public:
	CAcUiPlotStyleNamesComboBox();
	~CAcUiPlotStyleNamesComboBox();
	int ImageWidth() override;
	void OtherRunsSelectPlotStyle() { m_whatOtherDoes = 0; }
	void OtherRunsCurrentPlotStyle() { m_whatOtherDoes = 1; }
	void OtherRunsDefault() { m_whatOtherDoes = -1; }
	void SetAllowByLayerByBlock(BOOL bAllow) { m_bAllowByLayerByBlock = bAllow; }
	void SetColorDependentMode();
	void SetNamedMode();

protected:
	void OnAddItems() override;
	BOOL OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;
	void OnComboBoxInit() override;

private:
	CPrintStyleComboBox* m_imp;
	int m_whatOtherDoes;

	BOOL m_bColorDependentMode;

	BOOL m_bAllowByLayerByBlock;

	BOOL m_bLastByBlock;
	BOOL m_bLastByLayer;
	BOOL m_bLastUseOther;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
