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
***     Description: Declaration of AcDbAssocRevolvedSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"

class AcDbRevolveOptions;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocRevolvedSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocRevolvedSurfaceActionBody);

	explicit AcDbAssocRevolvedSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcDbPathRef& revolvePath,
											const AcDbPathRef& axisPath, double dAngle,
											double dStartAngle,
											const AcDbRevolveOptions& revolveOptions,
											bool bFlipAxisDirection, bool bEnabled,
											AcDbObjectId& createdActionId);
	double revolveAngle(AcString& expression = dummyString(),
						AcString& evaluatorId = dummyString()) const;
	Acad::ErrorStatus setRevolveAngle(double angle, const AcString& expression = AcString(),
									  const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
