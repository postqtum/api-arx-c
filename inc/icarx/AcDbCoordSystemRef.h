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
***     Description: Declaration of AcDbCoordSystemRef class
***
*****************************************************************************/
#pragma once

#include "AcDbSubentRef.h"

#include "../gemat3d.h"

class AcDbCompoundObjectId;

#include "IcArxPackPush.h"

class AcDbCoordSystemRef : public AcDbGeomRef
{
private:
	AcGeMatrix3d mCoordSystem;
	AcArray<AcDbSubentRef*> mSubentRefs;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbCoordSystemRef, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbCoordSystemRef();
	ACDBCORE2D_PORT explicit AcDbCoordSystemRef(const AcDbCoordSystemRef&);
	ACDBCORE2D_PORT explicit AcDbCoordSystemRef(const AcGeMatrix3d&);
	ACDBCORE2D_PORT explicit AcDbCoordSystemRef(const AcDbCompoundObjectId&, const AcGeMatrix3d&);
	ACDBCORE2D_PORT explicit AcDbCoordSystemRef(const AcArray<AcDbSubentRef*>&);
	ACDBCORE2D_PORT ~AcDbCoordSystemRef();
	ACDBCORE2D_PORT AcDbCoordSystemRef& operator=(const AcDbCoordSystemRef&);

	ACDBCORE2D_PORT const AcGeMatrix3d& coordSystem() const;
	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT AcDbEntity* createEntity() const override { return 0; }
	ACDBCORE2D_PORT const AcDbCompoundObjectId& entityId() const;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override;
	ACDBCORE2D_PORT bool isEmpty() const override;
	ACDBCORE2D_PORT bool isValid() const override;
	ACDBCORE2D_PORT void reset() override;
	ACDBCORE2D_PORT void set(const AcGeMatrix3d&);
	ACDBCORE2D_PORT void set(const AcDbCompoundObjectId&);
	ACDBCORE2D_PORT void set(const AcArray<AcDbSubentRef*>&);
	ACDBCORE2D_PORT const AcArray<AcDbSubentRef*>& subentRefs() const;
};

#include "IcArxPackPop.h"
