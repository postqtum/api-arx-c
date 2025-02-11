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
***     Description: Declaration of AcDbLoftedSurface class
***
*****************************************************************************/
#pragma once

#include "dbsurf.h"
#include "db3dProfile.h"

#include "icarx/IcArxPackPush.h"

class AcDbLoftedSurface : public AcDbSurface
{
public:
	enum LoftSurfaceType
	{
		kLoftSurf,
		kLoftBlendSurf,
		kLoftNetworkSurf
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbLoftedSurface();
	~AcDbLoftedSurface();

	ACDB_DECLARE_MEMBERS(AcDbLoftedSurface);

	virtual Acad::ErrorStatus createLoftedSurface(AcArray<AcDbEntity*>& crossSectionCurves,
												  AcArray<AcDbEntity*>& guideCurves,
												  AcDbEntity* pPathCurve,
												  AcDbLoftOptions& loftOptions);
	ACDB_PORT AcDbLoftProfile* crossSection(int idx) const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	ACDB_PORT int endContinuity(bool isCrossSection = true) const;
	ACDB_PORT double endMagnitude(bool isCrossSection = true) const;
	AcDbEntity* getCrossSection(int idx) const;
	ACDB_PORT void getCrossSections(AcArray<AcDbLoftProfile*>& crossSections) const;
	AcDbEntity* getGuideCurve(int idx) const;
	ACDB_PORT void getGuides(AcArray<AcDbLoftProfile*>& guides) const;
	void getLoftOptions(AcDbLoftOptions& loftOptions) const;
	AcDbEntity* getPathEntity() const;
	ACDB_PORT AcDbLoftProfile* guide(int idx) const;
	virtual bool isDependent() const;
	ACDB_PORT AcDbLoftedSurface::LoftSurfaceType loftSurfaceType() const;
	int numCrossSections() const;
	int numGuideCurves() const;
	ACDB_PORT AcDbLoftProfile* path() const;
	ACDB_PORT Acad::ErrorStatus setEndContinuity(int val, bool isCrossSection = true);
	ACDB_PORT Acad::ErrorStatus setEndMagnitude(double val, bool isCrossSection = true);
	ACDB_PORT Acad::ErrorStatus setLoftOptions(const AcDbLoftOptions& loftOptions);
	ACDB_PORT Acad::ErrorStatus setStartContinuity(int val, bool isCrossSection = true);
	ACDB_PORT Acad::ErrorStatus setStartMagnitude(double val, bool isCrossSection = true);
	ACDB_PORT int startContinuity(bool isCrossSection = true) const;
	ACDB_PORT double startMagnitude(bool isCrossSection = true) const;
};

#include "icarx/IcArxPackPop.h"
