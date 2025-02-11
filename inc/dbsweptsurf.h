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
***     Description: Declaration of AcDbSweptSurface class
***
*****************************************************************************/
#pragma once

#include "dbsurf.h"

#include "icarx/IcArxPackPush.h"

class AcDbSweptSurface : public AcDbSurface
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbSweptSurface);

	AcDbSweptSurface();
	~AcDbSweptSurface();

	virtual Acad::ErrorStatus createSweptSurface(AcDbEntity* pSweepEnt, AcDbEntity* pPathEnt,
												 AcDbSweepOptions& sweepOptions);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	AcDbEntity* getPathEntity() const;
	Acad::ErrorStatus getPathLength(double& len) const;
	AcDbEntity* getSweepEntity() const;
	void getSweepOptions(AcDbSweepOptions& sweepOptions) const;
	virtual bool isDependent() const;
	ACDB_PORT AcDb3dProfile* pathProfile() const;
	Acad::ErrorStatus setSweepOptions(const AcDbSweepOptions& sweepOptions);
	ACDB_PORT AcDb3dProfile* sweepProfile() const;
};

#include "icarx/IcArxPackPop.h"
