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
***     Description: Declaration of AcDbAssocTrimSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbSurfaceTrimInfo.h"
#include "AcDbAssocPathBasedSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocTrimSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocTrimSurfaceActionBody);

	explicit AcDbAssocTrimSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static Acad::ErrorStatus createInstance(const AcDbObjectId& resultingSurfaceId,
											const AcArray<AcDbSurfaceTrimInfo>& trimInfo,
											bool bAutoExtend, bool bEnabled,
											AcDbObjectIdArray& createdActionIds);
	double getTrimmedArea() const;
	Acad::ErrorStatus makeTrimPermanent();
	Acad::ErrorStatus setTrimInfo(const AcArray<AcDbSurfaceTrimInfo> trimInfoArray,
								  bool bAutoExtend);
	Acad::ErrorStatus untrim();
};

#include "icarx/IcArxPackPop.h"
