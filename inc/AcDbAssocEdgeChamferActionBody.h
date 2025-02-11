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
***     Description: Declaration of AcDbAssocEdgeChamferActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocEdgeChamferActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocEdgeChamferActionBody, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocEdgeChamferActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT double baseDistance(AcString& expression = dummyString(),
								  AcString& evaluatorId = dummyString()) const;
	ACDB_PORT static Acad::ErrorStatus createInstance(const AcDbFullSubentPathArray& chamferEdges,
													  const AcDbSubentId& baseFace,
													  double baseDistance, double otherDistance,
													  bool bEnabled, AcDbObjectId& createdActionId);
	ACDB_PORT void evaluateOverride() override;
	ACDB_PORT double otherDistance(AcString& expression = dummyString(),
								   AcString& evaluatorId = dummyString()) const;
	ACDB_PORT Acad::ErrorStatus setBaseDistance(double baseDistance,
												const AcString& expression = AcString(),
												const AcString& evaluatorId = AcString());
	ACDB_PORT Acad::ErrorStatus setInput(const AcDbFullSubentPathArray& chamferEdges,
										 const AcDbSubentId& baseFace);
	ACDB_PORT Acad::ErrorStatus setOtherDistance(double otherDistance,
												 const AcString& expression = AcString(),
												 const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
