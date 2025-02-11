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
***     Description: Declaration of AcDbAssocObjectAndIndexPersSubentId class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocIndexPersSubentId.h"

#include "IcArxPackPush.h"

class AcDbAssocObjectAndIndexPersSubentId : public AcDbAssocIndexPersSubentId
{
private:
	AcDbObjectId mObjectId;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocObjectAndIndexPersSubentId, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbAssocObjectAndIndexPersSubentId() = default;
	ACDBCORE2D_PORT AcDbAssocObjectAndIndexPersSubentId(const AcDbObjectId& objId,
														AcDb::SubentType subentType,
														unsigned int index);
	ACDBCORE2D_PORT bool operator==(const AcDbAssocObjectAndIndexPersSubentId& other) const;
	ACDBCORE2D_PORT bool operator<(const AcDbAssocObjectAndIndexPersSubentId& other) const;

	ACDBCORE2D_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFieldsData(AcDbDwgFiler*) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFieldsData(AcDbDxfFiler*) const override;
	ACDBCORE2D_PORT AcDbObjectId objectId() const { return this->mObjectId; }
	ACDBCORE2D_PORT void setObjectId(const AcDbObjectId& objId) { this->mObjectId = objId; }
};

#include "IcArxPackPop.h"
