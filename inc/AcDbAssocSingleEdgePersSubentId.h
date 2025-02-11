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
***     Description:
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPersSubentId.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocSingleEdgePersSubentId : public AcDbAssocPersSubentId
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocSingleEdgePersSubentId);

	bool isEqualTo(const AcDbEntity* pEntity, AcDbDatabase* pDatabase,
				   const AcDbAssocPersSubentId* pOther) const override;
	bool isNull() const override { return false; }
	AcDb::SubentType subentType(const AcDbEntity* pEntity, AcDbDatabase* pDatabase) const override
	{
		(void)(pEntity);
		(void)(pDatabase);
		return AcDb::kEdgeSubentType;
	}
	int transientSubentCount(const AcDbEntity* pEntity, AcDbDatabase* pDatabase) const override
	{
		(void)(pEntity);
		(void)(pDatabase);
		return 1;
	}
};

#include "icarx/IcArxPackPop.h"
