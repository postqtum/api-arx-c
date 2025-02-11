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
***     Description: Declaration of AcDbAssocFaceActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocActionParam.h"
#include "icarx/AcDbFaceRef.h"

class AcGeSurface;

#include "icarx/IcArxPackPush.h"

class AcDbAssocFaceActionParam : public AcDbAssocActionParam
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocFaceActionParam, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocFaceActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT Acad::ErrorStatus getDependentOnCompoundObject(
			AcDbCompoundObjectId& compoundId) const;
	ACDB_PORT virtual Acad::ErrorStatus getFaceRef(AcArray<AcDbFaceRef>& faceRefs) const;
	ACDB_PORT virtual Acad::ErrorStatus setFaceRef(const AcDbFaceRef& faceRef,
												   bool isReadDependency = true,
												   bool isWriteDependency = false,
												   int dependencyOrder = 0);
	ACDB_PORT virtual Acad::ErrorStatus setFaceSubentityGeometry(
			const AcGeSurface* pNewFaceSurface);
};

#include "icarx/IcArxPackPop.h"
