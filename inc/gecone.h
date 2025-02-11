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
***     Description: Declaration of AcGeCone class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "geintrvl.h"
#include "gevec3d.h"
#include "gesurf.h"
#include "gearc3d.h"

class AcGePoint3d;
class AcGeVector3d;
class AcGeCircArc3d;
class AcGeInterval;
class AcGeLinearEnt3d;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeCone : public AcGeSurface
{
public:
	AcGeCone();
	AcGeCone(double cosineAngle, double sineAngle, const AcGePoint3d& baseOrigin, double baseRadius,
			 const AcGeVector3d& axisOfSymmetry);
	AcGeCone(double cosineAngle, double sineAngle, const AcGePoint3d& baseOrigin, double baseRadius,
			 const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
			 const AcGeInterval& height, double startAngle, double endAngle);
	AcGeCone(const AcGeCone&);
	AcGeCone& operator=(const AcGeCone&);

	AcGePoint3d apex() const;
	AcGeVector3d axisOfSymmetry() const;
	AcGePoint3d baseCenter() const;
	double baseRadius() const;
	void getAngles(double& start, double& end) const;
	void getHalfAngle(double& cosineAngle, double& sineAngle) const;
	void getHeight(AcGeInterval& range) const;
	double halfAngle() const;
	double heightAt(double u) const;
	bool intersectWith(const AcGeLinearEnt3d& linEnt, int& intn, AcGePoint3d& p1, AcGePoint3d& p2,
					   const AcGeTol& tol = AcGeContext::gTol) const;
	bool isClosed(const AcGeTol& tol = AcGeContext::gTol) const;
	bool isOuterNormal() const;
	AcGeVector3d refAxis() const;
	AcGeCone& set(double cosineAngle, double sineAngle, const AcGePoint3d& baseCenter,
				  double baseRadius, const AcGeVector3d& axisOfSymmetry);
	AcGeCone& set(double cosineAngle, double sineAngle, const AcGePoint3d& baseCenter,
				  double baseRadius, const AcGeVector3d& axisOfSymmetry,
				  const AcGeVector3d& refAxis, const AcGeInterval& height, double startAngle,
				  double endAngle);
	AcGeCone& setAngles(double startAngle, double endAngle);
	AcGeCone& setBaseRadius(double radius);
	AcGeCone& setHeight(const AcGeInterval& height);
};

#include "icarx/IcArxPackPop.h"
