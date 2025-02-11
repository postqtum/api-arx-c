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
***     Description:
***
*****************************************************************************/
#pragma once

#include "dbdict.h"

class AcDbImpDictionaryWithDefault;

#include "icarx/IcArxPackPush.h"

class AcDbDictionaryWithDefault : public AcDbDictionary
{
public:
	ACDB_DECLARE_MEMBERS(AcDbDictionaryWithDefault);

	AcDbDictionaryWithDefault();
	~AcDbDictionaryWithDefault();

	AcDbObjectId defaultId() const;
	virtual Acad::ErrorStatus getObjectBirthVersion(AcDb::AcDbDwgVersion& ver,
													AcDb::MaintenanceReleaseVersion& maintVer);
	Acad::ErrorStatus setDefaultId(const AcDbObjectId& newId);
};

#include "icarx/IcArxPackPop.h"
