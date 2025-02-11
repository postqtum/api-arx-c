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
***     Description: Declaration of AcDbTransformOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbTransformOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbTransformOverrule);

	ACDBCORE2D_PORT AcDbTransformOverrule();

	ACDBCORE2D_PORT virtual bool cloneMeForDragging(AcDbEntity* pSubject);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus explode(const AcDbEntity* pSubject,
													  AcDbVoidPtrArray& entitySet);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getTransformedCopy(const AcDbEntity* pSubject,
																 const AcGeMatrix3d& xform,
																 AcDbEntity*& pEnt);
	ACDBCORE2D_PORT virtual bool hideMeForDragging(const AcDbEntity* pSubject);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformBy(AcDbEntity* pSubject,
														  const AcGeMatrix3d& xform);
};

#include "IcArxPackPop.h"
