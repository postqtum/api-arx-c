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
***     Description: Declaration of AcDbAssocNetworkSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"
#include "AcDbAssocLoftedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocNetworkSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocNetworkSurfaceActionBody);

	explicit AcDbAssocNetworkSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcArray<AcDbPathRef>& crossSections,
											const AcArray<AcDbPathRef>& guideCurves,
											const AcArray<int>& continuityArray,
											const AcArray<double>& bulgeArray, bool bEnabled,
											AcDbObjectId& createdActionId);
	Acad::ErrorStatus getBulge(AcDbAssocLoftedSurfaceActionBody::ProfileType type, double& bulge,
							   AcString& expression = dummyString(),
							   AcString& evaluatorId = dummyString()) const;
	Acad::ErrorStatus getContinuity(AcDbAssocLoftedSurfaceActionBody::ProfileType type,
									int& continuity, AcString& expression = dummyString(),
									AcString& evaluatorId = dummyString()) const;
	Acad::ErrorStatus setBulge(AcDbAssocLoftedSurfaceActionBody::ProfileType type, double bulge,
							   const AcString& expression = AcString(),
							   const AcString& evaluatorId = AcString());
	Acad::ErrorStatus setContinuity(AcDbAssocLoftedSurfaceActionBody::ProfileType type,
									int continuity, const AcString& expression = AcString(),
									const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
