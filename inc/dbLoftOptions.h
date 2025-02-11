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
***     Description: Declaration of AcDbLoftOptions class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#include "icarx/IcArxPackPush.h"

class AcDbLoftOptions
{
	friend class AcDbImpLoftOptions;

public:
	enum NormalOption
	{
		kNoNormal,
		kFirstNormal,
		kLastNormal,
		kEndsNormal,
		kAllNormal,
		kUseDraftAngles
	};

private:
	void* mpImpLoftOptions;

public:
	AcDbLoftOptions();
	AcDbLoftOptions(const AcDbLoftOptions& src);
	ACDB_PORT ~AcDbLoftOptions();
	AcDbLoftOptions& operator=(const AcDbLoftOptions& src);
	bool operator==(const AcDbLoftOptions&) const;

	bool alignDirection() const;
	bool arcLengthParam() const;
	Acad::ErrorStatus checkCrossSectionCurves(AcArray<AcDbEntity*>& crossSectionCurves,
											  bool& allOpen, bool& allClosed, bool& allPlanar,
											  bool displayErrorMessages = false);
	Acad::ErrorStatus checkGuideCurves(AcArray<AcDbEntity*>& guideCurves,
									   bool displayErrorMessages = false);
	Acad::ErrorStatus checkLoftCurves(AcArray<AcDbEntity*>& crossSectionCurves,
									  AcArray<AcDbEntity*>& guideCurves, AcDbEntity* pPathCurve,
									  bool& allOpen, bool& allClosed, bool& allPlanar,
									  bool displayErrorMessages = false);
	Acad::ErrorStatus checkOptions(bool displayErrorMessages = false);
	Acad::ErrorStatus checkPathCurve(AcDbEntity* pPathCurve, bool displayErrorMessages = false);
	ACDB_PORT bool closed() const;
	ACDB_PORT double draftEnd() const;
	ACDB_PORT double draftEndMag() const;
	ACDB_PORT double draftStart() const;
	ACDB_PORT double draftStartMag() const;
	bool noTwist() const;
	ACDB_PORT AcDbLoftOptions::NormalOption normal() const;
	ACDB_PORT bool periodic() const;
	ACDB_PORT bool ruled() const;
	void setAlignDirection(bool val);
	void setArcLengthParam(bool val);
	void setClosed(bool val);
	void setDraftEnd(double ang);
	void setDraftEndMag(double val);
	void setDraftStart(double ang);
	void setDraftStartMag(double val);
	void setNoTwist(bool val);
	void setNormal(AcDbLoftOptions::NormalOption val);
	Acad::ErrorStatus setOptionsFromSysvars();
	void setPeriodic(bool val);
	void setRuled(bool val);
	void setSimplify(bool val);
	Acad::ErrorStatus setSysvarsFromOptions();
	void setVirtualGuide(bool val);
	ACDB_PORT bool simplify() const;
	bool virtualGuide() const;
};

#include "icarx/IcArxPackPop.h"
