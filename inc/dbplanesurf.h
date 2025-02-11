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
***     Description: Declaration of AcDbPlaneSurface class
***
*****************************************************************************/
#pragma once

#include "dbsurf.h"

class AcDbRegion;

#include "icarx/IcArxPackPush.h"

class AcDbPlaneSurface : public AcDbSurface
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbPlaneSurface();
	~AcDbPlaneSurface();

	ACDB_DECLARE_MEMBERS(AcDbPlaneSurface);

	virtual Acad::ErrorStatus createFromRegion(AcDbRegion* pRegion);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual bool isDependent() const;
};

#include "icarx/IcArxPackPop.h"
