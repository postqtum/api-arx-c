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
***     Description: Declaration of AcDbNonSubEntDynamicUCSPE class
***
*****************************************************************************/
#pragma once

#include "../geplane.h"
#include "../rxobject.h"

class AcDbEntity;
class AcDbSubentId;
class CPoint;

#include "IcArxPackPush.h"

class AcDbNonSubEntDynamicUCSPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbNonSubEntDynamicUCSPE, ACDBCORE2D_PORT);

	virtual Acad::ErrorStatus dehighlightPlane(AcDbEntity* Ent, void* context) = 0;
	virtual Acad::ErrorStatus getCandidatePlane(AcDbEntity* Ent, const CPoint& pt,
												AcGePlane& result, double& distToEdge,
												double& objWidth, double& objHeight,
												void*& context) = 0;
	virtual Acad::ErrorStatus highlightPlane(AcDbEntity* Ent, void* context) = 0;
};

#include "IcArxPackPop.h"
