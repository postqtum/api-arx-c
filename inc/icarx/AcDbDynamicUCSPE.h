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
***     Description: Declaration of AcDbDynamicUCSPE class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acarray.h"
#include "../geplane.h"

class AcDbEntity;
class AcDbSubentId;

#include "IcArxPackPush.h"

class AcDbDynamicUCSPE : public AcRxObject
{
public:
	enum Flags
	{
		kDefault = 0x00,
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbDynamicUCSPE);

	virtual Acad::ErrorStatus getCandidatePlanes(
			AcArray<AcGePlane>& results, double& distToEdge, double& objWidth, double& objHeight,
			AcDbEntity* pEnt, const AcDbSubentId& subentId, const AcGePlane& viewplane,
			Flags flags = kDefault) const = 0;
};

#include "IcArxPackPop.h"
