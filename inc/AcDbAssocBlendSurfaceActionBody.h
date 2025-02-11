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
***     Description: Declaration of AcDbAssocBlendSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "dbgrip.h"
#include "AcDbAssocPathBasedSurfaceActionBody.h"

class AcDbLoftProfile;
class AcDbBlendOptions;

#include "icarx/IcArxPackPush.h"

class AcDbAssocBlendSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocBlendSurfaceActionBody, ACDB_PORT);

public:
	ACDB_PORT explicit AcDbAssocBlendSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDB_PORT static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcDbLoftProfile* startProfile,
											const AcDbLoftProfile* endProfile,
											const AcDbBlendOptions& blendOptions, bool bEnabled,
											AcDbObjectId& createdActionId);
	ACDB_PORT double endEdgeBulge(AcString& expression = dummyString(),
						AcString& evaluatorId = dummyString()) const;
	ACDB_PORT int16_t endEdgeContinuity(AcString& expression = dummyString(),
							  AcString& evaluatorId = dummyString()) const;
	ACDB_PORT Acad::ErrorStatus getBlendOptions(AcDbBlendOptions& blendOptions) const;
	ACDB_PORT Acad::ErrorStatus getContinuityGripPoints(AcGePoint3d& startEdgePt,
											  AcGePoint3d& endEdgePt) const;
	ACDB_PORT Acad::ErrorStatus getProfiles(AcDbLoftProfile*& pStartProfile,
								  AcDbLoftProfile*& pEndProfile) const;
	ACDB_PORT Acad::ErrorStatus setBlendOptions(const AcDbBlendOptions& blendOptions);
	ACDB_PORT Acad::ErrorStatus setEndEdgeBulge(double value, const AcString& expression = AcString(),
									  const AcString& evaluatorId = AcString());
	ACDB_PORT Acad::ErrorStatus setEndEdgeContinuity(int16_t value, const AcString& expression = AcString(),
										   const AcString& evaluatorId = AcString());
	ACDB_PORT Acad::ErrorStatus setStartEdgeBulge(double value, const AcString& expression = AcString(),
										const AcString& evaluatorId = AcString());
	ACDB_PORT Acad::ErrorStatus setStartEdgeContinuity(int16_t value, const AcString& expression = AcString(),
											 const AcString& evaluatorId = AcString());
	ACDB_PORT double startEdgeBulge(AcString& expression = dummyString(),
						  AcString& evaluatorId = dummyString()) const;
	ACDB_PORT int16_t startEdgeContinuity(AcString& expression = dummyString(),
								AcString& evaluatorId = dummyString()) const;
};

#include "icarx/IcArxPackPop.h"
