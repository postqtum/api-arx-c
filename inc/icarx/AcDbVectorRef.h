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
***     Description: Declaration of AcDbVectorRef class
***
*****************************************************************************/
#pragma once

#include "AcDbGeomRef.h"

class AcGeVector3d;

#include "IcArxPackPush.h"

class AcDbVectorRef : public AcDbGeomRef
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbVectorRef, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbVectorRef();
	ACDBCORE2D_PORT explicit AcDbVectorRef(const AcDbVectorRef&);
	ACDBCORE2D_PORT explicit AcDbVectorRef(const AcGeVector3d&);
	ACDBCORE2D_PORT ~AcDbVectorRef();
	ACDBCORE2D_PORT AcDbVectorRef& operator=(const AcDbVectorRef&);

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT AcDbEntity* createEntity() const override;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override;
	ACDBCORE2D_PORT bool isEmpty() const override;
	ACDBCORE2D_PORT bool isValid() const override;
	ACDBCORE2D_PORT void reset() override;
	ACDBCORE2D_PORT void set(const AcGeVector3d&);
	ACDBCORE2D_PORT const AcGeVector3d vector() const;
};

#include "IcArxPackPop.h"
