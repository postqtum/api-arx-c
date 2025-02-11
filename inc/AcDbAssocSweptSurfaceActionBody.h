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
***     Description: Declaration of AcDbAssocSweptSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "dbSweepOptions.h"
#include "AcDbAssocPathBasedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocSweptSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocSweptSurfaceActionBody);

	explicit AcDbAssocSweptSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	double alignAngle(AcString& expression = dummyString(),
					  AcString& evaluatorId = dummyString()) const;
	static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcDbPathRef& sweepProfile,
											const AcDbPathRef& sweepPathProfile,
											const AcDbSweepOptions& sweptOptions, bool bEnabled,
											AcDbObjectId& createdActionId);
	double scaleFactor(AcString& expression = dummyString(),
					   AcString& evaluatorId = dummyString()) const;
	Acad::ErrorStatus setAlignAngle(double angle, const AcString& expression = AcString(),
									const AcString& evaluatorId = AcString());
	Acad::ErrorStatus setScaleFactor(double scale, const AcString& expression = AcString(),
									 const AcString& evaluatorId = AcString());
	Acad::ErrorStatus setTwistAngle(double angle, const AcString& expression = AcString(),
									const AcString& evaluatorId = AcString());
	double twistAngle(AcString& expression = dummyString(),
					  AcString& evaluatorId = dummyString()) const;
};

#include "icarx/IcArxPackPop.h"
