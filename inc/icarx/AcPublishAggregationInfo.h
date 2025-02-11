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
***     Description: Declaration of AcPublishAggregationInfo class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "AcDMMEPlotProperty.h"
#include "AcDMMResourceInfo.h"

class AcPlPlotLogger;

#include "IcArxPackPush.h"

class AcPublishAggregationInfo
{
public:
	AcPublishAggregationInfo() = default;
	virtual ~AcPublishAggregationInfo() = default;

	virtual AcPlPlotLogger* GetPlotLogger() = 0;
	virtual void AddGlobalProperties(AcDMMEPlotPropertyVec props) = 0;
	virtual void AddGlobalResources(AcDMMResourceVec resources) = 0;
	virtual const ACHAR* dwfFileName() = 0;
	virtual const ACHAR* dwfPassword() = 0;
};

#include "IcArxPackPop.h"
