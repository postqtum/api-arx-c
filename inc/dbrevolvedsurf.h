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
***     Description: Declaration of AcDbRevolvedSurface class
***
*****************************************************************************/
#pragma once

#include "dbsurf.h"

#include "icarx/IcArxPackPush.h"

class AcDbRevolvedSurface : public AcDbSurface
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbRevolvedSurface);

	AcDbRevolvedSurface();
	~AcDbRevolvedSurface();

	virtual Acad::ErrorStatus createRevolvedSurface(AcDbEntity* pRevEnt, const AcGePoint3d& axisPnt,
													const AcGeVector3d& axisDir, double revAngle,
													double startAngle,
													AcDbRevolveOptions& revolveOptions);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	AcGePoint3d getAxisPnt() const;
	AcGeVector3d getAxisVec() const;
	double getRevolveAngle() const;
	AcDbEntity* getRevolveEntity() const;
	void getRevolveOptions(AcDbRevolveOptions& revolveOptions) const;
	double getStartAngle() const;
	virtual bool isDependent() const;
	ACDB_PORT AcDb3dProfile* revolveProfile() const;
	Acad::ErrorStatus setAxisPnt(const AcGePoint3d& pnt);
	Acad::ErrorStatus setAxisVec(const AcGeVector3d& vec);
	Acad::ErrorStatus setRevolve(const AcGePoint3d& axisPnt, const AcGeVector3d& axisVec,
								 double revAngle, const AcDbRevolveOptions& revolveOptions);
	Acad::ErrorStatus setRevolveAngle(double ang);
	Acad::ErrorStatus setRevolveOptions(const AcDbRevolveOptions& revolveOptions);
};

#include "icarx/IcArxPackPop.h"
