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
***     Description: Declaration of AcDbAssocDependencyPE class
***
*****************************************************************************/
#pragma once

#include "AcDbCompoundObjectId.h"
#include "AcDbAssocGlobal.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocDependencyPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocDependencyPE, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual bool allowsDependencies(const AcDbObject* pObject,
													bool isWriteDependency,
													const AcRxClass* pActionBodyOrActionClass,
													const AcDbAssocDependency* pDependency,
													const AcRxObject* pContext) const = 0;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus redirectDependencyAttachment(
			AcDbObject* pObject, const AcDbCompoundObjectId& compoundObjectId,
			AcDbAssocDependency* pDependency, AcDbCompoundObjectId& redirectedCompoundObjectId)
	{
		(void)(pDependency);
		(void)(pObject);
		redirectedCompoundObjectId = compoundObjectId;
		return Acad::eOk;
	}
};

#include "icarx/IcArxPackPop.h"
