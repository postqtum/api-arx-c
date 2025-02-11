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
***     Description: Decalration of AcDbSubentRef class
***
*****************************************************************************/
#pragma once

#include "AcDbSubentRef.h"

class BODY;

#include "IcArxPackPush.h"

class AcDbFaceRef : public AcDbSubentRef
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbFaceRef, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbFaceRef();
	ACDBCORE2D_PORT explicit AcDbFaceRef(const AcDbCompoundObjectId&,
										 const AcDbSubentId& = kNullSubentId,
										 BODY* = nullptr);
	ACDBCORE2D_PORT AcDbFaceRef(const AcDbFaceRef&);
	ACDBCORE2D_PORT ~AcDbFaceRef();
	ACDBCORE2D_PORT AcDbFaceRef& operator=(const AcDbFaceRef&);

	ACDBCORE2D_PORT BODY* asmBody() const;
	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT AcDbEntity* createEntity() const override;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override { return Acad::eOk; }
	ACDBCORE2D_PORT bool isEmpty() const override;
	ACDBCORE2D_PORT bool isValid() const override;
	ACDBCORE2D_PORT void reset() override;
};

#include "IcArxPackPop.h"
