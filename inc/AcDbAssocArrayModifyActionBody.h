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
***     Description: Declaration of AcDbAssocArrayModifyActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocArrayActionBody.h"

class AcDbVertexRef;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayModifyActionBody : public AcDbAssocArrayActionBody
{
public:
	ACDB_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayModifyActionBody, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbAssocArrayModifyActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);
	ACDBCORE2D_PORT ~AcDbAssocArrayModifyActionBody();

	ACDBCORE2D_PORT bool controlsItem(const AcDbAssocArrayItem& item) const;
	ACDBCORE2D_PORT static Acad::ErrorStatus createInstance(AcDbObjectId arrayId,
															const AcArray<AcDbItemLocator>& indices,
															const AcDbObjectIdArray& substEntities,
															AcDbVertexRef& basePoint,
															AcDbObjectId& actionBodyId);
	ACDBCORE2D_PORT Acad::ErrorStatus getOverridenItems(AcArray<AcDbItemLocator>& indices) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setOverridenItems(const AcArray<AcDbItemLocator>& indices);
};

#include "icarx/IcArxPackPop.h"
