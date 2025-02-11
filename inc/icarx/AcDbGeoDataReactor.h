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
***     Description: Declaration of AcDbGeoDataReactor class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"
#include "../acadstrc.h"

class AcDbDatabase;

#include "IcArxPackPush.h"

class AcDbGeoDataReactor
{
public:
	virtual ~AcDbGeoDataReactor() = default;

	virtual void geoCoordinateSystemChanged(AcDbDatabase* /*pDb*/, const AcString& /*oldId*/,
											const AcString& /*newId*/)
	{
	}
	virtual Acad::ErrorStatus geoCoordinateSystemWillChange(AcDbDatabase* /*pDb*/,
															const AcString& /*oldId*/,
															const AcString& /*newId*/)
	{
		return Acad::eOk;
	}
};

#include "IcArxPackPop.h"
