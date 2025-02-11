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
***     Description: Declaration of AcDbObjectOverrule class
***
*****************************************************************************/
#pragma once

#include "rxoverrule.h"

#include "icarx/AcDbIdMapping.h"
#include "icarx/AcDbEnumMode.h"

class AcDbObject;

#include "icarx/IcArxPackPush.h"

class AcDbObjectOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbObjectOverrule);

	ACDBCORE2D_PORT AcDbObjectOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus cancel(AcDbObject* pSubject);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus close(AcDbObject* pSubject);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus deepClone(const AcDbObject* pSubject,
														AcDbObject* pOwnerObject,
														AcDbObject*& pClonedObject,
														AcDbIdMapping& idMap,
														bool isPrimary = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus erase(AcDbObject* pSubject, bool erasing);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus open(AcDbObject* pSubject, AcDb::OpenMode mode);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus wblockClone(const AcDbObject* pSubject,
														  AcRxObject* pOwnerObject,
														  AcDbObject*& pClonedObject,
														  AcDbIdMapping& idMap,
														  bool isPrimary = true);
};

#include "icarx/IcArxPackPop.h"
