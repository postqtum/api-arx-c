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
***     Description: Declaration of AcDbAnnotativeObjectPE class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

class AcDbObject;

#include "IcArxPackPush.h"

class AcDbAnnotativeObjectPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAnnotativeObjectPE);

	virtual bool annotative(AcDbObject* pObject) const = 0;
	virtual bool forceAnnoAllVisible(AcDbObject* pObj) const
	{
		(void)(pObj);
		return false;
	}
	virtual Acad::ErrorStatus resetScaleDependentProperties(AcDbObject* pObject)
	{
		(void)(pObject);
		return Acad::eNotImplemented;
	}
	virtual Acad::ErrorStatus setAnnotative(AcDbObject* pObject, const bool bAnnotative) = 0;
	virtual Acad::ErrorStatus setForceAnnoAllVisible(AcDbObject* pObj, bool bForce) const
	{
		(void)(pObj);
		(void)(bForce);
		return Acad::eNotImplemented;
	}
	virtual Acad::ErrorStatus setFromStyle(AcDbObject* pObject, bool& bUpdated) = 0;
};

#include "IcArxPackPop.h"
