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
***     Description: Declaration of AcDbAssocPathActionParam class
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbEdgeRef.h"
#include "AcDbAssocCompoundActionParam.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocPathActionParam : public AcDbAssocCompoundActionParam
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocPathActionParam);

	explicit AcDbAssocPathActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	virtual Acad::ErrorStatus getEdgeRefArray(AcArray<AcArray<AcDbEdgeRef>>& edgeRefs) const;
	virtual Acad::ErrorStatus setEdgeRefArray(const AcArray<AcDbEdgeRef>& edgeRefs,
											  int dependencyOrder = 0);
	virtual Acad::ErrorStatus updateEdgeRef(int edgeRefIndex, const AcDbEdgeRef& edgeRef);
};

#include "icarx/IcArxPackPop.h"
