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
***     Description: Declaration of AcDbAssocDimDependencyBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocDimDependencyBodyBase.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocDimDependencyBody : public AcDbAssocDimDependencyBodyBase
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocDimDependencyBody, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbAssocDimDependencyBody();
	ACDBCORE2D_PORT ~AcDbAssocDimDependencyBody();

	ACDBCORE2D_PORT static Acad::ErrorStatus createAndPostToDatabase(const AcDbObjectId& dimId,
													 AcDbObjectId& dimDepId,
													 AcDbObjectId& dimDepBodyId);
	ACDBCORE2D_PORT double getEntityMeasurementOverride() const;
	ACDBCORE2D_PORT AcString getEntityTextOverride() const;
	ACDBCORE2D_PORT bool isEntityAttachmentChangedOverride() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setEntityTextOverride(const AcString& newText);
	ACDBCORE2D_PORT Acad::ErrorStatus updateDependentOnObjectOverride();
};

#include "icarx/IcArxPackPop.h"
