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
***     Description: Declaration of AcDbAssocVertexActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocEdgeActionParam.h"
#include "AcDbGeomRef.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocVertexActionParam : public AcDbAssocActionParam
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocVertexActionParam);

	explicit AcDbAssocVertexActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	Acad::ErrorStatus getDependentOnCompoundObject(AcDbCompoundObjectId& compoundId) const;
	virtual Acad::ErrorStatus getVertexRef(AcArray<AcDbVertexRef>& vertexRefs) const;
	Acad::ErrorStatus getVertexRef(AcDbVertexRef& vertexRef) const;
	virtual Acad::ErrorStatus setVertexRef(const AcDbVertexRef& vertexRef,
										   bool isReadDependency = true,
										   bool isWriteDependency = false, int dependencyOrder = 0);
	virtual Acad::ErrorStatus setVertexSubentityGeometry(const AcGePoint3d& newPosition);
};

#include "icarx/IcArxPackPop.h"
