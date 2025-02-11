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
***     Description:
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "acdbport.h"

class AcGeVector3d;
class AcGePoint3d;

#include "icarx/IcArxPackPush.h"

class AcDbBlendOptions
{
	friend class AcDbImpBlendOptions;

private:
	void* mpImpBlendOptions;

public:
	enum DriveModeType
	{
		kDriveModeFirst = 0,
		kDriveModeSecond = 1,
		kDriveModeBoth = 2
	};

public:
	ACDB_PORT AcDbBlendOptions();
	ACDB_PORT ~AcDbBlendOptions();
	ACDB_PORT AcDbBlendOptions(const AcDbBlendOptions&);
	ACDB_PORT AcDbBlendOptions& operator=(const AcDbBlendOptions&);

	ACDB_PORT AcGeVector3d* coplanarDirection() const;
	ACDB_PORT AcGePoint3d* coplanarPoint() const;
	ACDB_PORT AcDbBlendOptions::DriveModeType driveMode() const;
	ACDB_PORT unsigned int quality() const;
	ACDB_PORT Acad::ErrorStatus setDriveMode(AcDbBlendOptions::DriveModeType val);
	ACDB_PORT Acad::ErrorStatus setCoplanarDirection(const AcGeVector3d* pDir);
	ACDB_PORT Acad::ErrorStatus setCoplanarPoint(const AcGePoint3d* pPt);
	ACDB_PORT Acad::ErrorStatus setQuality(unsigned int val);
	ACDB_PORT Acad::ErrorStatus setSimplify(bool val);
	ACDB_PORT Acad::ErrorStatus setSolid(bool val);
	ACDB_PORT bool simplify() const;
	ACDB_PORT bool solid() const;
};

#include "icarx/IcArxPackPop.h"
