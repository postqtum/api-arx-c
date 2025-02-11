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
***     Description: Declaration of AcDbJoinEntityPE class
***
*****************************************************************************/
#pragma once

#include "geintarr.h"
#include "acdb.h"
#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class AcDbJoinEntityPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbJoinEntityPE);

	virtual Acad::ErrorStatus joinEntities(AcDbEntity* pPrimaryEntity,
										   const AcArray<AcDbEntity*>& otherEntities,
										   AcGeIntArray& joinedEntityIndices,
										   const AcGeTol& tol = AcGeContext::gTol) const = 0;
	virtual Acad::ErrorStatus joinEntity(AcDbEntity* pPrimaryEntity, AcDbEntity* pSecondaryEntity,
										 const AcGeTol& tol = AcGeContext::gTol) const = 0;
};

#include "icarx/IcArxPackPop.h"
