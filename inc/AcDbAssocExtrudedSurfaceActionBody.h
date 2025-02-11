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
***     Description: Declaration of AcDbAssocExtrudedSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"

class AcDbSweepOptions;

#include "icarx/IcArxPackPush.h"

class AcDbAssocExtrudedSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocExtrudedSurfaceActionBody, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocExtrudedSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
													  const AcDbPathRef& inputPath,
													  const AcGeVector3d& directionVec,
													  const AcDbSweepOptions& sweptOptions,
													  bool bEnabled, AcDbObjectId& createdActionId);
	ACDB_PORT double height(AcString& expression = dummyString(),
							AcString& evaluatorId = dummyString()) const;
	ACDB_PORT Acad::ErrorStatus setHeight(double dHeight, const AcString& expression = AcString(),
										  const AcString& evaluatorId = AcString());
	ACDB_PORT Acad::ErrorStatus setTaperAngle(double dTaperAngle,
											  const AcString& expression = AcString(),
											  const AcString& evaluatorId = AcString());
	ACDB_PORT double taperAngle(AcString& expression = dummyString(),
								AcString& evaluatorId = dummyString()) const;
};

#include "icarx/IcArxPackPop.h"
