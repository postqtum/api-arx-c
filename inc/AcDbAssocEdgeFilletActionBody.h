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
***     Description: Declaration of AcDbAssocEdgeFilletActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocEdgeFilletActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocEdgeFilletActionBody, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocEdgeFilletActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT static Acad::ErrorStatus createInstance(const AcDbFullSubentPathArray& filletEdges,
													  double radius, bool bEnabled,
													  AcDbObjectId& createdActionId);
	ACDB_PORT void evaluateOverride();
	ACDB_PORT double radius(AcString& expression = dummyString(),
							AcString& evaluatorId = dummyString()) const;
	ACDB_PORT Acad::ErrorStatus setInputEdges(const AcDbFullSubentPathArray& filletEdges);
	ACDB_PORT Acad::ErrorStatus setRadius(double radius, const AcString& expression = AcString(),
										  const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
