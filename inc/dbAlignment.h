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
***     Description:
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbAlignment : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAlignment);

	virtual Acad::ErrorStatus getAlignment(
			AcDbEntity* pEnt,
			const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&
					nestedPickedEntities,
			const AcGePoint3d& pickPoint, const AcGeVector3d& normal, AcGePoint3d& closestPoint,
			AcGeVector3d& direction) = 0;
};

#include "icarx/IcArxPackPop.h"
