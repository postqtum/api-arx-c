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
***     Description: Declaration of AcDbPaperOrientationPE class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

class AcDbViewport;
class AcDbObject;

#include "IcArxPackPush.h"

class AcDbPaperOrientationPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbPaperOrientationPE);

	virtual Acad::ErrorStatus applyPaperOrientationTransform(AcDbObject* pObject,
															 const AcDbViewport* pVport) const
	{
		(void)(pObject);
		(void)(pVport);
		return Acad::eNotImplemented;
	}
	virtual bool paperOrientation(AcDbObject* pObject) const = 0;
	virtual Acad::ErrorStatus setPaperOrientation(AcDbObject* pObject,
												  const bool bPaperOrientation) = 0;
};

#include "IcArxPackPop.h"
