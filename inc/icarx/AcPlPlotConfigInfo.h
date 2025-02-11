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
***     Description: Declaration of AcPlPlotConfigInfo class
***
*****************************************************************************/
#pragma once

#include "../AcPlObject.h"

enum DeviceType
{
	kSystemPrinter = 0,
	kPC3File = 1,
	kOneOffConfig = 2,
	kUninitialized = -1
};

#include "IcArxPackPush.h"

class AcPlPlotConfigInfo : public AcPlObject
{
public:
	ACPL_DECLARE_MEMBERS(AcPlPlotConfigInfo);

public:
	ACPL_PORT AcPlPlotConfigInfo();
	ACPL_PORT AcPlPlotConfigInfo(const ACHAR* pDevName, const ACHAR* pFullPath, DeviceType devType);
	ACPL_PORT AcPlPlotConfigInfo(const AcPlPlotConfigInfo& copy);
	ACPL_PORT ~AcPlPlotConfigInfo();
	ACPL_PORT const AcPlPlotConfigInfo& operator=(const AcPlPlotConfigInfo& src);

	ACPL_PORT Acad::ErrorStatus copyFrom(const AcRxObject* pSrc);
	ACPL_PORT const ACHAR* deviceId() const;
	ACPL_PORT const ACHAR* deviceName() const;
	ACPL_PORT DeviceType deviceType() const;
	ACPL_PORT const ACHAR* fullPath() const;
	ACPL_PORT void setDeviceId(const ACHAR* pDevId);
	ACPL_PORT void setDeviceName(const ACHAR* pDevName);
	ACPL_PORT void setDeviceType(DeviceType devType);
	ACPL_PORT void setFullPath(const ACHAR* pPath);
};

#include "IcArxPackPop.h"
