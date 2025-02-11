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
***     Description: Declaration of AcDbRevolveOptions class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#include "icarx/IcArxPackPush.h"

class AcDbRevolveOptions
{
	friend class AcDbImpRevolveOptions;

private:
	void* mpImpRevolveOptions;

public:
	AcDbRevolveOptions();
	AcDbRevolveOptions(const AcDbRevolveOptions&);
	ACDBCORE2D_PORT ~AcDbRevolveOptions();
	AcDbRevolveOptions& operator=(const AcDbRevolveOptions&);

	Acad::ErrorStatus checkRevolveCurve(AcDbEntity* pRevEnt, const AcGePoint3d& axisPnt,
										const AcGeVector3d& axisDir, bool& closed,
										bool& endPointsOnAxis, bool& planar,
										bool displayErrorMessages = false);
	bool closeToAxis() const;
	double draftAngle() const;
	void setCloseToAxis(bool val);
	void setDraftAngle(double ang);
	void setTwistAngle(double ang);
	double twistAngle() const;
};

#include "icarx/IcArxPackPop.h"
