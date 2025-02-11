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
***     Description: Declaration of AcDbAssocFilletSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocFilletSurfaceActionBody : public AcDbAssocSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocFilletSurfaceActionBody, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocFilletSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT static Acad::ErrorStatus createInstance(
			const AcDbObjectId& resultingSurfaceId, const AcDbObjectId& inputSurfaceId1,
			const AcGePoint3d& pickPt1, const AcDbObjectId& inputSurfaceId2,
			const AcGePoint3d& pickPt2, double radius, AcDb::FilletTrimMode trimMode,
			const AcGeVector3d& viewDir, bool bEnabled, AcDbObjectId& createdActionId);
	ACDB_PORT Acad::ErrorStatus getFilletHandleData(AcGePoint3d& pt, AcGeVector3d& dir,
													AcGePoint3d& filletCenPt,
													AcGeVector3d& filletNormal) const;
	ACDB_PORT Acad::ErrorStatus getHintPoints(AcGePoint3d hintPoints[2]) const;
	ACDB_PORT double radius(AcString& expression = dummyString(),
							AcString& evaluatorId = dummyString()) const;
	ACDB_PORT Acad::ErrorStatus setHintPoints(const AcGePoint3d hintPoints[2],
											  const AcGeVector3d& viewDir);
	ACDB_PORT Acad::ErrorStatus setRadius(double dRadius, const AcString& expression = AcString(),
										  const AcString& evaluatorId = AcString());
	ACDB_PORT Acad::ErrorStatus setTrimMode(AcDb::FilletTrimMode trimMode);
	ACDB_PORT AcDb::FilletTrimMode trimMode() const;
};

#include "icarx/IcArxPackPop.h"
