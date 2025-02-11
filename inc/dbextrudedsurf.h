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
***     Description: Declaration of AcDbExtrudedSurface class
***
*****************************************************************************/
#pragma once

#include "dbsurf.h"

#include "icarx/IcArxPackPush.h"

class AcDbExtrudedSurface : public AcDbSurface
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbExtrudedSurface();
	~AcDbExtrudedSurface();

	ACDB_DECLARE_MEMBERS(AcDbExtrudedSurface);

	virtual Acad::ErrorStatus createExtrudedSurface(AcDbEntity* pSweepEnt,
													const AcGeVector3d& directionVec,
													AcDbSweepOptions& sweepOptions);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	double getHeight() const;
	AcDbEntity* getSweepEntity() const;
	void getSweepOptions(AcDbSweepOptions& sweepOptions) const;
	AcGeVector3d getSweepVec() const;
	virtual bool isDependent() const;
	Acad::ErrorStatus setExtrude(const AcGeVector3d& sweepVec,
								 const AcDbSweepOptions& sweepOptions);
	Acad::ErrorStatus setHeight(double height);
	Acad::ErrorStatus setSweepOptions(const AcDbSweepOptions& sweepOptions);
	Acad::ErrorStatus setSweepVec(const AcGeVector3d& sweepVec);
	ACDB_PORT AcDb3dProfile* sweepProfile() const;
};

#include "icarx/IcArxPackPop.h"
