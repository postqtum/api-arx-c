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
***     Description: Declaration of AcDbAssocGeomDependency class
***
*****************************************************************************/
#pragma once

#include "gept3dar.h"

#include "AcDbAssocDependency.h"
#include "AcDbAssocPersSubentId.h"

class AcGeSurface;

#include "icarx/IcArxPackPush.h"

class AcDbAssocGeomDependency : public AcDbAssocDependency
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocGeomDependency, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbAssocGeomDependency(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDBCORE2D_PORT Acad::ErrorStatus dependentOnObjectMirrored();
	ACDBCORE2D_PORT Acad::ErrorStatus getEdgeSubentityGeometry(
			AcArray<AcGeCurve3d*>& edgeCurves) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getFaceSubentityGeometry(
			AcArray<AcGeSurface*>& faceSurfaces) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getTransientSubentIds(
			AcArray<AcDbSubentId>& transientSubentIds) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getVertexSubentityGeometry(
			AcGePoint3dArray& vertexPositions) const;
	ACDBCORE2D_PORT bool isCachingSubentityGeometry() const;
	ACDBCORE2D_PORT const AcDbAssocPersSubentId* persistentSubentId() const;
	ACDBCORE2D_PORT static Acad::ErrorStatus redirectToAnotherSubentity(
			const AcDbObjectId& oldObjectId, const AcDbSubentId& oldSubentId,
			const AcDbObjectId& newObjectId, const AcDbSubentId& newSubentId);
	ACDBCORE2D_PORT void setCachingSubentityGeometry(bool yesNo);
	ACDBCORE2D_PORT Acad::ErrorStatus setEdgeSubentityGeometry(
			const AcArray<const AcGeCurve3d*>& newEdgeCurves);
	ACDBCORE2D_PORT Acad::ErrorStatus setFaceSubentityGeometry(
			const AcArray<const AcGeSurface*>& newFaceSurfaces);
	ACDBCORE2D_PORT Acad::ErrorStatus setSubentity(const AcDbSubentId& transientSubentId);
	ACDBCORE2D_PORT Acad::ErrorStatus setVertexSubentityGeometry(
			const AcGePoint3dArray& newVertexPositions);
	ACDBCORE2D_PORT AcDb::SubentType subentType() const;
	ACDBCORE2D_PORT int transientSubentCount() const;
};

#include "icarx/IcArxPackPop.h"
