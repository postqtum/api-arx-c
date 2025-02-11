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
***     Description: Decalration of AcDbSubentRef class
***
*****************************************************************************/
#pragma once

#include "AcDbGeomRef.h"

#include "../dbsubeid.h"

class AcDbCompoundObjectId;

#include "IcArxPackPush.h"

class AcDbSubentRef : public AcDbGeomRef
{
protected:
	ACDBCORE2D_PORT void setEntity(const AcDbCompoundObjectId& entityId);
	ACDBCORE2D_PORT void setFromSubentPath(const AcDbFullSubentPath&);
	ACDBCORE2D_PORT void setSubent(const AcDbSubentId& subentId);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbSubentRef, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbSubentRef() = default;
	ACDBCORE2D_PORT explicit AcDbSubentRef(const AcDbCompoundObjectId&,
										   const AcDbSubentId& = kNullSubentId);
	AcDbSubentRef(const AcDbSubentRef&) = delete;
	~AcDbSubentRef() = default;
	ACDBCORE2D_PORT AcDbSubentRef& operator=(const AcDbSubentRef&);
	ACDBCORE2D_PORT bool operator==(const AcDbSubentRef&) const;

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT AcDbEntity* createEntity() const override;
	ACDBCORE2D_PORT virtual const AcDbCompoundObjectId& entity() const;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateAndCacheGeometry() override { return Acad::eOk; }
	ACDBCORE2D_PORT bool isEmpty() const override;
	ACDBCORE2D_PORT void reset() override;
	ACDBCORE2D_PORT virtual AcDbSubentId subentId() const;
};

#include "IcArxPackPop.h"
