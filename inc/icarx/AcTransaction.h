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
***     Description: Declaration of AcTransaction class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcTransaction : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcTransaction);

	virtual Acad::ErrorStatus getAllObjects(AcArray<AcDbObject*>& objs) = 0;
	virtual Acad::ErrorStatus getObject(AcDbObject*& obj, AcDbObjectId objectId,
										AcDb::OpenMode mode = AcDb::kForRead,
										bool openErasedObject = false) = 0;
	virtual Acad::ErrorStatus markObjectPageable(AcDbObject* pObject) = 0;
	virtual int numOpenedObjects() = 0;
};

#include "IcArxPackPop.h"
