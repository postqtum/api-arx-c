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
***     Description: Declaration of AcDbAssocExtendSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocPathBasedSurfaceActionBody.h"
#include "dbsurf.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocExtendSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocExtendSurfaceActionBody, ACDB_PORT);

	ACDB_PORT explicit AcDbAssocExtendSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcArray<AcDbEdgeRef>& extendEdges,
											double distance, AcDbSurface::EdgeExtensionType option,
											bool bEnabled, AcDbObjectId& createdActionId);
	ACDB_PORT double distance(AcString& expression = dummyString(),
					AcString& evaluatorId = dummyString()) const;
	ACDB_PORT Acad::ErrorStatus setDistance(double distance, const AcString& expression = AcString(),
								  const AcString& evaluatorId = AcString());
};

#include "icarx/IcArxPackPop.h"
