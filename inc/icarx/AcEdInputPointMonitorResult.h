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
***     Description: Declaration of AcEdInputPointMonitorResult class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"
#include "../AdAChar.h"

class AcEdImpInputPointMonitorResult;

#include "IcArxPackPush.h"

class AcEdInputPointMonitorResult
{
	friend class AcEdImpInputPointManager;

private:
	AcEdImpInputPointMonitorResult* m_pImp = nullptr;

private:
	AcEdInputPointMonitorResult();
	~AcEdInputPointMonitorResult();
	AcEdInputPointMonitorResult& operator=(const AcEdInputPointMonitorResult&);

public:
	ACAD_PORT const ACHAR* additionalTooltipString() const;
	ACAD_PORT bool appendToTooltipStr() const;
	ACAD_PORT void setAdditionalTooltipString(const ACHAR*);
};

#include "IcArxPackPop.h"
