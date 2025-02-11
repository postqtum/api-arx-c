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
***     Description: Declaration of AcDbAssocCompoundActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocActionParam.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocCompoundActionParam : public AcDbAssocActionParam
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocCompoundActionParam, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbAssocCompoundActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDBCORE2D_PORT Acad::ErrorStatus addParam(const AcDbObjectId& paramId, int& paramIndex);
	ACDBCORE2D_PORT const AcDbObjectIdArray& ownedParams() const;
	ACDBCORE2D_PORT AcDbObjectId paramAtIndex(int paramIndex) const;
	ACDBCORE2D_PORT AcDbObjectId paramAtName(const AcString& paramName, int index = 0) const;
	ACDBCORE2D_PORT int paramCount() const;
	ACDBCORE2D_PORT const AcDbObjectIdArray& paramsAtName(const AcString& paramName) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus removeAllParams(bool alsoEraseThem);
	ACDBCORE2D_PORT Acad::ErrorStatus removeParam(const AcDbObjectId& paramId, bool alsoEraseIt);
};

#include "icarx/IcArxPackPop.h"
