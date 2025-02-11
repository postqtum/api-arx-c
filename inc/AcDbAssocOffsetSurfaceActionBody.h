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
***     Description: Declaration of AcDbAssocOffsetSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocOffsetSurfaceActionBody : public AcDbAssocSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocOffsetSurfaceActionBody);

	explicit AcDbAssocOffsetSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcDbObjectId& inputSurfaceId, double distance,
											bool bEnabled, AcDbObjectId& createdActionId);
	double distance(AcString& expression = dummyString(),
					AcString& evaluatorId = dummyString()) const;
	Acad::ErrorStatus setDistance(double distance, const AcString& expression = AcString(),
								  const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
