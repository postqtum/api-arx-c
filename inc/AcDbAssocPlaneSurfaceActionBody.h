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
***     Description: Declaration of AcDbAssocPlaneSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocPlaneSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocPlaneSurfaceActionBody);

	explicit AcDbAssocPlaneSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcDbPathRef& inputPath, bool bEnabled,
											AcDbObjectId& createdActionId);
};

#include "icarx/IcArxPackPop.h"
