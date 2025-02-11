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
***     Description: Declaration of AcDbPdfDefinition class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayDefinition.h"

#include "IcArxPackPush.h"

class AcDbPdfDefinition : public AcDbUnderlayDefinition
{
private:
	const AcDbUnderlayHost* getUnderlayHost() const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbPdfDefinition);
	ACDBCORE2D_PORT AcDbPdfDefinition();
	ACDBCORE2D_PORT virtual ~AcDbPdfDefinition();
};

#include "IcArxPackPop.h"
