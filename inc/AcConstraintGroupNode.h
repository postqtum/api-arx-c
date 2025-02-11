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

#include "AcGraphNode.h"
#include "icarx/AcDbObjectId.h"

class AcImpConstraintGroupNode;
class AcDbImpAssoc2dConstraintGroup;
class AcDbAssoc2dConstraintGroupUtil;

#include "icarx/IcArxPackPush.h"

class AcConstraintGroupNode : public AcGraphNode
{
	friend class AcDbImpAssoc2dConstraintGroup;
	friend class AcDbAssoc2dConstraintGroupEvalHelper;
	friend class AcDbAssoc2dConstaintGroupCloningHelper;

protected:
	ACDBCORE2D_PORT AcConstraintGroupNode();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstraintGroupNode, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual ~AcConstraintGroupNode();

	ACDBCORE2D_PORT AcDbObjectId owningConstraintGroupId() const;
};

#include "icarx/IcArxPackPop.h"
