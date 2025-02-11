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
***     Description: Declaration of AcPublishBeginJobInfo class
***
*****************************************************************************/
#pragma once

#include "AcNameValuePair.h"

class AcPlDSDData;
class AcPlPlotLogger;

#include "IcArxPackPush.h"

class AcPublishBeginJobInfo
{
public:
	AcPublishBeginJobInfo() = default;
	virtual ~AcPublishBeginJobInfo() = default;

	virtual const AcPlDSDData* GetDSDData() = 0;
	virtual AcPlPlotLogger* GetPlotLogger() = 0;
	virtual const AcNameValuePairVec GetPrivateData(const ACHAR* sectionName) = 0;
	virtual bool JobWillPublishInBackground() = 0;
	virtual bool WritePrivateSection(const ACHAR* sectionName,
									 const AcNameValuePairVec nameValuePairVec) = 0;
};

#include "IcArxPackPop.h"
