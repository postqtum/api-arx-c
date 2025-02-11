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
***     Description: Declaration of AcDbVertexRef class
***
*****************************************************************************/
#pragma once

#include "AcDbSubentRef.h"

#include "../gepnt3d.h"

class AcDbEdgeRef;

#include "IcArxPackPush.h"

class AcDbVertexRef : public AcDbSubentRef
{
public:
	enum ImpliedType
	{
		kExplicitVertex,
		kUnknownType,
		kEdgeStart,
		kEdgeEnd,
		kEdgeMid,
		kEdgeCenter,
		kEdgeSplineControlPoint,
		kEdgeSplineFitPoint
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbVertexRef, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbVertexRef();
	ACDBCORE2D_PORT AcDbVertexRef(const AcDbVertexRef&);
	ACDBCORE2D_PORT explicit AcDbVertexRef(const AcDbCompoundObjectId&,
										   const AcDbSubentId& = kNullSubentId,
										   const AcGePoint3d& = AcGePoint3d::kOrigin);
	ACDBCORE2D_PORT explicit AcDbVertexRef(const AcDbFullSubentPath&);
	ACDBCORE2D_PORT explicit AcDbVertexRef(const AcDbEntity*);
	ACDBCORE2D_PORT explicit AcDbVertexRef(const AcGePoint3d&);
	ACDBCORE2D_PORT explicit AcDbVertexRef(AcDbVertexRef::ImpliedType, const AcDbEdgeRef& edgeRef,
										   int controlOrFitPointIndex = 0,
										   const AcGePoint3d& = AcGePoint3d::kOrigin);
	ACDBCORE2D_PORT ~AcDbVertexRef();
	ACDBCORE2D_PORT AcDbVertexRef& operator=(const AcDbVertexRef&);

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT class AcDbEntity* createEntity() const override;
	ACDBCORE2D_PORT const AcDbCompoundObjectId& entity() const override;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus evaluatePoint(AcGePoint3d&) const;
	ACDBCORE2D_PORT AcDbVertexRef::ImpliedType impliedType() const;
	ACDBCORE2D_PORT int index() const;
	ACDBCORE2D_PORT bool isValid() const override;
	ACDBCORE2D_PORT AcGePoint3d point() const;
	ACDBCORE2D_PORT const AcDbGeomRef* referencedRef() const;
	ACDBCORE2D_PORT void reset() override;
	ACDBCORE2D_PORT AcDbSubentId subentId() const override;
};

#include "IcArxPackPop.h"
