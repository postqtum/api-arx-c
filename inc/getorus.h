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
***     Description: Declaration of AcGeTorus class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gesurf.h"
#include "geintrvl.h"
#include "gevec3d.h"

class AcGeCircArc3d;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeTorus : public AcGeSurface
{
public:
	AcGeTorus();
	AcGeTorus(double majorRadius, double minorRadius, const AcGePoint3d& origin,
			  const AcGeVector3d& axisOfSymmetry);
	AcGeTorus(double majorRadius, double minorRadius, const AcGePoint3d& origin,
			  const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis, double startAngleU,
			  double endAngleU, double startAngleV, double endAngleV);
	AcGeTorus(const AcGeTorus&);
	AcGeTorus& operator=(const AcGeTorus&);

	AcGeVector3d axisOfSymmetry() const;
	AcGePoint3d center() const;
	void getAnglesInU(double& start, double& end) const;
	void getAnglesInV(double& start, double& end) const;
	bool intersectWith(const AcGeLinearEnt3d& linEnt, int& intn, AcGePoint3d& p1, AcGePoint3d& p2,
					   AcGePoint3d& p3, AcGePoint3d& p4,
					   const AcGeTol& tol = AcGeContext::gTol) const;
	bool isApple() const;
	bool isDegenerate() const;
	bool isDoughnut() const;
	bool isHollow() const;
	bool isLemon() const;
	bool isOuterNormal() const;
	bool isVortex() const;
	double majorRadius() const;
	double minorRadius() const;
	AcGeVector3d refAxis() const;
	AcGeTorus& set(double majorRadius, double minorRadius, const AcGePoint3d& origin,
				   const AcGeVector3d& axisOfSymmetry);
	AcGeTorus& set(double majorRadius, double minorRadius, const AcGePoint3d& origin,
				   const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
				   double startAngleU, double endAngleU, double startAngleV, double endAngleV);
	AcGeTorus& setAnglesInU(double start, double end);
	AcGeTorus& setAnglesInV(double start, double end);
	AcGeTorus& setMajorRadius(double radius);
	AcGeTorus& setMinorRadius(double radius);
};

#include "icarx/IcArxPackPop.h"
