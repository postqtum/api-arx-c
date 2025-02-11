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

#include "AcDbAssocPathBasedSurfaceActionBody.h"

class AcDbPathRef;
class AcDbLoftOptions;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocLoftedSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	enum ProfileType
	{
		kStartCrossSection = 1,
		kEndCrossSection = 2,
		kStartGuide = 4,
		kEndGuide = 8
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbAssocLoftedSurfaceActionBody);

	explicit AcDbAssocLoftedSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static Acad::ErrorStatus createInstance(
			const AcDbObjectId& resultingSurfaceId, const AcArray<AcDbGeomRef*>& crossSections,
			const AcArray<AcDbPathRef>& guideCurves, const AcDbPathRef& pathCurve,
			const AcDbLoftOptions& loftOptions, const AcArray<int>& continuityArray,
			const AcArray<double>& bulgeArray, bool bEnabled, AcDbObjectId& createdActionId);
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
