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
***     Description: Declaration of AcGeCylinder class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gesurf.h"
#include "gevec3d.h"
#include "geintrvl.h"
#include "gearc3d.h"

class AcGeCircArc3d;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeCylinder : public AcGeSurface
{
public:
	AcGeCylinder();
	AcGeCylinder(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSymmetry);
	AcGeCylinder(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSymmetry,
				 const AcGeVector3d& refAxis, const AcGeInterval& height, double startAngle,
				 double endAngle);
	AcGeCylinder(const AcGeCylinder&);
	AcGeCylinder& operator=(const AcGeCylinder&);

	AcGeVector3d axisOfSymmetry() const;
	void getAngles(double& start, double& end) const;
	void getHeight(AcGeInterval& height) const;
	double heightAt(double u) const;
	bool intersectWith(const AcGeLinearEnt3d& linEnt, int& intn, AcGePoint3d& p1, AcGePoint3d& p2,
					   const AcGeTol& tol = AcGeContext::gTol) const;
	bool isClosed(const AcGeTol& tol = AcGeContext::gTol) const;
	bool isOuterNormal() const;
	AcGePoint3d origin() const;
	double radius() const;
	AcGeVector3d refAxis() const;
	AcGeCylinder& set(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym);
	AcGeCylinder& set(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym,
					  const AcGeVector3d& refAxis, const AcGeInterval& height, double startAngle,
					  double endAngle);
	AcGeCylinder& setRadius(double radius);
	AcGeCylinder& setAngles(double start, double end);
	AcGeCylinder& setHeight(const AcGeInterval& height);
};

#include "icarx/IcArxPackPop.h"
