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
***     Description: Declaration of AcDbImage class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "acgi.h"

#include "icarx/IcArxPackPush.h"

class AcDbImage : public AcDbEntity
{
protected:
	AcDbImage(AcDbSystemInternals* pSys) : AcDbEntity(pSys) {}

public:
	ACRX_DECLARE_MEMBERS(AcDbImage);

	virtual AcGiSentScanLines* getScanLines(const AcGiRequestScanLines&) const = 0;
	virtual bool freeScanLines(AcGiSentScanLines*) const = 0;
};

#include "icarx/IcArxPackPop.h"
