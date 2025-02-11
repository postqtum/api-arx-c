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
***     Description: Declaration of AcDbEdgeRef class
***
*****************************************************************************/
#pragma once

#include "../gecurv3d.h"
#include "../AcDbCompoundObjectId.h"

#include "AcDbSubentRef.h"
#include "AcDbSubentId.h"

class AcDbEdgeRefImp;

#include "IcArxPackPush.h"

class AcDbEdgeRef : public AcDbSubentRef
{
private:
	mutable AcDbEdgeRefImp* m_pCurve = nullptr;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbEdgeRef, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbEdgeRef();
	ACDBCORE2D_PORT explicit AcDbEdgeRef(const AcDbCompoundObjectId&,
										 const AcDbSubentId& edgeSubentId = kNullSubentId,
										 const AcDbSubentId& faceSubentId = kNullSubentId,
										 const AcGeCurve3d* pCurve = nullptr);
	ACDBCORE2D_PORT explicit AcDbEdgeRef(const AcDbFullSubentPath&);
	ACDBCORE2D_PORT explicit AcDbEdgeRef(const AcDbEntity* pEntity);
	ACDBCORE2D_PORT explicit AcDbEdgeRef(const AcGeCurve3d* pGeCurve);
	ACDBCORE2D_PORT AcDbEdgeRef(const AcDbEdgeRef&);
	ACDBCORE2D_PORT ~AcDbEdgeRef();
	ACDBCORE2D_PORT AcDbEdgeRef& operator=(const AcDbEdgeRef&);
	ACDBCORE2D_PORT bool operator==(const AcDbEdgeRef&) const;

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT AcDbEntity* createEntity() const override;
	ACDBCORE2D_PORT const AcGeCurve3d* curve() const;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus evaluateCurve(AcGeCurve3d*&) const;
	ACDBCORE2D_PORT AcDbSubentId faceSubentId() const;
	ACDBCORE2D_PORT bool isEmpty() const override;
	ACDBCORE2D_PORT bool isValid() const override;
	ACDBCORE2D_PORT void reset() override;
	ACDBCORE2D_PORT void setFaceSubentity(const AcDbSubentId& faceSubentId);
};

#include "IcArxPackPop.h"
