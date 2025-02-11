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
***     Description: Declaration of AcDbSweepOptions class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#include "icarx/IcArxPackPush.h"

class AcDbSweepOptions
{
	friend class AcDbImpSweepOptions;

public:
	enum AlignOption
	{
		kNoAlignment,
		kAlignSweepEntityToPath,
		kTranslateSweepEntityToPath,
		kTranslatePathToSweepEntity
	};

	enum MiterOption
	{
		kDefaultMiter,
		kOldMiter,
		kNewMiter,
		kCrimpMiter,
		kBendMiter
	};

private:
	void* mpImpSweepOptions;

public:
	ACDB_PORT AcDbSweepOptions();
	AcDbSweepOptions(const AcDbSweepOptions& src);
	ACDB_PORT ~AcDbSweepOptions();
	AcDbSweepOptions& operator=(const AcDbSweepOptions& src);
	bool operator==(const AcDbSweepOptions&) const;

	AcDbSweepOptions::AlignOption align() const;
	double alignAngle() const;
	bool alignStart() const;
	ACDB_PORT bool bank() const;
	AcGePoint3d basePoint() const;
	ACDB_PORT bool checkIntersections() const;
	Acad::ErrorStatus checkPathCurve(AcDbEntity* pPathEnt, bool displayErrorMessages = false);
	Acad::ErrorStatus checkSweepCurve(AcDbEntity* pSweepEnt, AcDb::Planarity& planarity,
									  AcGePoint3d& pnt, AcGeVector3d& vec, bool& closed,
									  double& approxArcLen, bool displayErrorMessages = false);
	ACDB_PORT double draftAngle() const;
	ACDB_PORT double endDraftDist() const;
	bool getPathEntityTransform(AcGeMatrix3d& mat);
	bool getSweepEntityTransform(AcGeMatrix3d& mat);
	AcDbSweepOptions::MiterOption miterOption() const;
	ACDB_PORT double scaleFactor() const;
	void setAlign(AcDbSweepOptions::AlignOption val);
	void setAlignAngle(double ang);
	void setAlignStart(bool val);
	void setBank(bool val);
	void setBasePoint(AcGePoint3d& pnt);
	void setCheckIntersections(bool val);
	void setDraftAngle(double ang);
	void setEndDraftDist(double val);
	void setMiterOption(AcDbSweepOptions::MiterOption val);
	void setPathEntityTransform(AcGeMatrix3d& mat);
	Acad::ErrorStatus setPathEntityTransform(AcDbEntity* pPathEnt,
											 bool displayErrorMessages = false);
	void setScaleFactor(double val);
	void setStartDraftDist(double val);
	void setSweepEntityTransform(AcGeMatrix3d& mat);
	Acad::ErrorStatus setSweepEntityTransform(AcArray<AcDbEntity*>& sweepEntities,
											  bool displayErrorMessages = false);
	void setTwistAngle(double ang);
	void setTwistRefVec(const AcGeVector3d& vec);
	double startDraftDist() const;
	ACDB_PORT double twistAngle() const;
	AcGeVector3d twistRefVec() const;
};

#include "icarx/IcArxPackPop.h"
