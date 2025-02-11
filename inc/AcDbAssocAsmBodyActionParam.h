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
***     Description: Declaration of AcDbAssocAsmBodyActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocEdgeActionParam.h"
#include "AcDbAssocCompoundActionParam.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocAsmBodyActionParam : public AcDbAssocActionParam
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocAsmBodyActionParam, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocAsmBodyActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT virtual void* body(bool makeCopy) const;
	ACDB_PORT Acad::ErrorStatus getDependentOnCompoundObject(
			AcDbCompoundObjectId& compoundId) const;
	ACDB_PORT virtual Acad::ErrorStatus setBody(const AcDbEntity* pAsmEntity,
												bool isReadDependency = true,
												bool isWriteDependency = false,
												int dependencyOrder = 0);
	ACDB_PORT virtual Acad::ErrorStatus setBody(AcDbObjectId asmEntityId,
												bool isReadDependency = true,
												bool isWriteDependency = false,
												int dependencyOrder = 0);
	ACDB_PORT virtual Acad::ErrorStatus setBody(void* pAsmBody, bool makeCopy);
};

#include "icarx/IcArxPackPop.h"
