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
***     Description: Declaration of AcDbPathRef class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"

#include "AcDbEdgeRef.h"
#include "AcDbFullSubentPathArray.h"

#include "IcArxPackPush.h"

class AcDbPathRef : public AcDbGeomRef
{
private:
	AcArray<AcDbEdgeRef> mEdgeRefs;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbPathRef, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbPathRef();
	ACDBCORE2D_PORT AcDbPathRef(const AcDbPathRef&);
	ACDBCORE2D_PORT explicit AcDbPathRef(const AcArray<AcDbEdgeRef>&);
	ACDBCORE2D_PORT AcDbPathRef(const AcDbFullSubentPathArray& edgeSubentPathArr,
								const AcDbFullSubentPathArray& faceSubentPathArr);
	ACDBCORE2D_PORT ~AcDbPathRef();

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT AcDbEntity* createEntity() const override;
	ACDBCORE2D_PORT const AcArray<AcDbEdgeRef>& edgeRefs() const;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override;
	ACDBCORE2D_PORT Acad::ErrorStatus getEntityArray(AcArray<AcDbEntity*>& entities,
													 bool concatenate) const;
	ACDBCORE2D_PORT bool isEmpty() const override;
	ACDBCORE2D_PORT bool isEqualTo(const AcGeCurve3d*);
	ACDBCORE2D_PORT bool isReferencePath();
	ACDBCORE2D_PORT bool isValid() const override;
	ACDBCORE2D_PORT void reset() override;
	ACDBCORE2D_PORT void setEdgeRefs(const AcArray<AcDbEdgeRef>& edges);
};

#include "IcArxPackPop.h"
