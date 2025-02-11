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
***     Description: Declaration of AcDbAssocEdgeActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocActionParam.h"
#include "icarx/AcDbEdgeRef.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocEdgeActionParam : public AcDbAssocActionParam
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocEdgeActionParam, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbAssocEdgeActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDBCORE2D_PORT Acad::ErrorStatus getDependentOnCompoundObject(
			AcDbCompoundObjectId& compoundId) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getEdgeRef(AcArray<AcDbEdgeRef>& edgeRefs) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setEdgeRef(const AcDbEdgeRef& edgeRef,
														 bool isReadDependency = true,
														 bool isWriteDependency = false,
														 int dependencyOrder = 0);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setEdgeSubentityGeometry(
			const AcGeCurve3d* pNewEdgeCurve);
};

#include "icarx/IcArxPackPop.h"
