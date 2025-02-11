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
***     Description: Declaration of AcDbAssocValueDependency class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocDependency.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocValueDependency : public AcDbAssocDependency
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocValueDependency);

	explicit AcDbAssocValueDependency(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	Acad::ErrorStatus getDependentOnObjectValue(AcDbEvalVariant& objectValue) const;
	Acad::ErrorStatus setDependentOnObjectValue(const AcDbEvalVariant& newObjectValue);
	Acad::ErrorStatus setValueName(const AcString& newValueName);
	const AcString& valueName() const;
};

#include "icarx/IcArxPackPop.h"
