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
***     Description: Declaration of AcDbAssocArrayItem class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../rxobject.h"

#include "AcDbObjectId.h"

class AcDbItemLocator;
class AcGeMatrix3d;
class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbImpAssocArrayItem;

#include "IcArxPackPush.h"

class AcDbAssocArrayItem : public AcRxObject
{
	friend class AcDbImpAssocArrayItem;

private:
	AcDbImpAssocArrayItem* mpSelf;

private:
	AcDbAssocArrayItem(const AcDbAssocArrayItem&) = delete;
	AcDbAssocArrayItem& operator=(const AcDbAssocArrayItem&) = delete;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayItem, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbAssocArrayItem();
	ACDBCORE2D_PORT AcDbAssocArrayItem(AcDbItemLocator& locator, const AcGeMatrix3d& transform);
	ACDBCORE2D_PORT ~AcDbAssocArrayItem();

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	ACDBCORE2D_PORT const AcDbObjectId& entityProvider() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getTransform(AcGeMatrix3d& transform,
												   bool bCompounded = true) const;
	ACDBCORE2D_PORT bool hasRelativeTransform() const;
	ACDBCORE2D_PORT bool isErased() const;
	ACDBCORE2D_PORT const AcDbItemLocator& locator() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setDefaultTransform(const AcGeMatrix3d& transform);
	ACDBCORE2D_PORT void setEntityProvider(AcDbObjectId provider);
	ACDBCORE2D_PORT Acad::ErrorStatus setErased(bool bErased);
	ACDBCORE2D_PORT Acad::ErrorStatus transformBy(const AcGeMatrix3d& transform);
};

#include "IcArxPackPop.h"
