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
***     Description: Declaration of AcDbAssocPatchSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocPatchSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocPatchSurfaceActionBody);

	explicit AcDbAssocPatchSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	double bulge(AcString& expression = dummyString(), AcString& evaluatorId = dummyString()) const;
	int continuity(AcString& expression = dummyString(),
				   AcString& evaluatorId = dummyString()) const;
	static Acad::ErrorStatus createInstance(const AcDbObjectId& patchSurfaceId,
											const AcArray<AcDbEdgeRef>& profileCurves,
											const AcArray<AcDbEdgeRef>& constraintCurves,
											const AcArray<AcDbVertexRef>& constraintPoints,
											int nContinuity, double dBulge, bool bEnabled,
											AcDbObjectId& createdActionId);
	static Acad::ErrorStatus createInstance(const AcDbObjectId& patchSurfaceId,
											const AcArray<AcDbEdgeRef>& profileCurves,
											const AcArray<AcDbEdgeRef>& constraintCurves,
											const AcArray<AcDbVertexRef>& constraintPoints,
											bool bEnabled, AcDbObjectId& createdActionId);
	Acad::ErrorStatus getContinuityGripPoint(AcGePoint3d& gripPt) const;
	Acad::ErrorStatus setBulge(double bulge, const AcString& expression = AcString(),
							   const AcString& evaluatorId = AcString());
	Acad::ErrorStatus setConstraintCurves(const AcArray<AcDbEdgeRef>& constraintCurves);
	Acad::ErrorStatus setConstraintPoints(const AcArray<AcDbVertexRef>& constraintPoints);
	Acad::ErrorStatus setContinuity(int continuity, const AcString& expression = AcString(),
									const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
