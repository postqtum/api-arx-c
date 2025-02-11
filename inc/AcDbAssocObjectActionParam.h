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
***     Description: Declaration of AcDbAssocObjectActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocActionParam.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocObjectActionParam : public AcDbAssocActionParam
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocObjectActionParam);

	explicit AcDbAssocObjectActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	Acad::ErrorStatus getObject(AcDbCompoundObjectId& object) const;
	Acad::ErrorStatus setObject(const AcDbCompoundObjectId& object, bool isReadDependency = true,
								bool isWriteDependency = false, int dependencyOrder = 0);
};

#include "icarx/IcArxPackPop.h"
