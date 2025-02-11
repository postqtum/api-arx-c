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
***     Description: Declaration of AcDbAssocExternalIndexPersSubentId class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocIndexPersSubentId.h"

#include "IcArxPackPush.h"

class AcDbAssocExternalIndexPersSubentId : public AcDbAssocIndexPersSubentId
{
private:
	static const int kRoundTripOffset = 2000000;

private:
	int roundTripOffset() const override { return kRoundTripOffset; }

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocExternalIndexPersSubentId, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbAssocExternalIndexPersSubentId(
			AcDb::SubentType subentType = AcDb::kNullSubentType, unsigned int index = 0)
			: AcDbAssocIndexPersSubentId(subentType, index)
	{
	}
};

#include "IcArxPackPop.h"
