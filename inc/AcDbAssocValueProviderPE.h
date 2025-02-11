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
***     Description: Declaration of AcDbAssocValueProviderPE class
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbObject.h"
#include "icarx/AcDbEvalVariant.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocValueProviderPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocValueProviderPE);

	virtual bool canGetValue(const AcDbObject* pObject, const AcString& valueName)
	{
		(void)(pObject);
		(void)(valueName);
		return true;
	}
	virtual bool canSetValue(const AcDbObject* pObject, const AcString& valueName)
	{
		(void)(pObject);
		(void)(valueName);
		return false;
	}
	static Acad::ErrorStatus getObjectValue(const AcDbObjectId&, const AcString& valueName,
											AcDbEvalVariant& value);
	virtual Acad::ErrorStatus getValue(const AcDbObject* pObject, const AcString& valueName,
									   AcDbEvalVariant& value) = 0;
	static Acad::ErrorStatus setObjectValue(const AcDbObjectId&, const AcString& valueName,
											const AcDbEvalVariant& value);
	virtual Acad::ErrorStatus setValue(AcDbObject* pObject, const AcString& valueName,
									   const AcDbEvalVariant& newValue)
	{
		(void)(pObject);
		(void)(valueName);
		(void)(newValue);
		return Acad::eNotHandled;
	}
};

#include "icarx/IcArxPackPop.h"
