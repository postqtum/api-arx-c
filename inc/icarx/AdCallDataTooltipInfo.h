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
***     Description: Declaration of AdCallDataTooltipInfo class
***
*****************************************************************************/
#pragma once

#include "../AdExportDef.h"

#include "IcArxPackPush.h"

class ADAF_PORT AdCallDataTooltipInfo
{
public:
	AdCallDataTooltipInfo(int nToolType, wchar_t* pBtnStr);

	int GetToolType();
	void SetToolType(int nToolType);
	wchar_t* GetButtonText();
	void SetButtonText(wchar_t* pBtnStr);

private:
	AdCallDataTooltipInfo() = delete;
	AdCallDataTooltipInfo(const AdCallDataTooltipInfo& callDataTooltipInfo) = delete;
	AdCallDataTooltipInfo& operator=(const AdCallDataTooltipInfo& callDataTooltipInfo) = delete;

private:
	int m_nToolType;

	wchar_t* m_pBtnStr;
};

#include "IcArxPackPop.h"
