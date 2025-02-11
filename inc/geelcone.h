/***************************************************************************
***
***     Copyright (C) 2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Declaration of AcGeEllipCone class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "geintrvl.h"
#include "gevec3d.h"
#include "gesurf.h"

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeEllipCone : public AcGeSurface
{
public:
	AcGeEllipCone();
	AcGeEllipCone(
	        double baseRadius, const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry);
	AcGeEllipCone(double baseRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
	        const AcGeInterval& height, double startAngle, double endAngle);
	AcGeEllipCone(double baseMajorRadius, double baseMinorRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis);
	AcGeEllipCone(double baseMajorRadius, double baseMinorRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
	        const AcGeInterval& height, double startAngle, double endAngle);
	AcGeEllipCone(double cosineAngle, double sineAngle, double baseRadius,
	        const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry);
	AcGeEllipCone(double cosineAngle, double sineAngle, double baseRadius,
	        const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry,
	        const AcGeVector3d& refAxis, const AcGeInterval& height, double startAngle,
	        double endAngle);
	AcGeEllipCone(double cosineAngle, double sineAngle, double baseMajorRadius,
	        double baseMinorRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis);
	AcGeEllipCone(double cosineAngle, double sineAngle, double baseMajorRadius,
	        double baseMinorRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
	        const AcGeInterval& height, double startAngle, double endAngle);
	AcGeEllipCone(const AcGeEllipCone&);
	AcGeEllipCone& operator=(const AcGeEllipCone&);

	AcGePoint3d apex() const;
	AcGeVector3d axisOfSymmetry() const;
	double baseMajorRadius() const;
	double baseMinorRadius() const;
	AcGePoint3d baseOrigin() const;
	void getAngles(double& start, double& end) const;
	void getHalfAngle(double& cosineAngle, double& sineAngle) const;
	void getHeight(AcGeInterval& height) const;
	double halfAngle() const;
	double heightAt(double u) const;
	bool intersectWith(const AcGeLinearEnt3d& linEnt, int& intn, AcGePoint3d& p1, AcGePoint3d& p2,
	        const AcGeTol& tol = AcGeContext::gTol) const;
	bool isClosed(const AcGeTol& tol = AcGeContext::gTol) const;
	bool isOuterNormal() const;
	AcGeVector3d refAxis() const;
	AcGeEllipCone& set(
	        double baseRadius, const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry);
	AcGeEllipCone& set(double baseRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
	        const AcGeInterval& height, double startAngle, double endAngle);
	AcGeEllipCone& set(double baseMajorRadius, double baseMinorRadius,
	        const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry,
	        const AcGeVector3d& refAxis);
	AcGeEllipCone& set(double baseMajorRadius, double baseMinorRadius,
	        const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry,
	        const AcGeVector3d& refAxis, const AcGeInterval& height, double startAngle,
	        double endAngle);
	AcGeEllipCone& set(double cosineAngle, double sineAngle, double baseRadius,
	        const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry);
	AcGeEllipCone& set(double cosineAngle, double sineAngle, double baseRadius,
	        const AcGePoint3d& baseOrigin, const AcGeVector3d& axisOfSymmetry,
	        const AcGeVector3d& refAxis, const AcGeInterval& height, double startAngle,
	        double endAngle);
	AcGeEllipCone& set(double cosineAngle, double sineAngle, double baseMajorRadius,
	        double baseMinorRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis);
	AcGeEllipCone& set(double cosineAngle, double sineAngle, double baseMajorRadius,
	        double baseMinorRadius, const AcGePoint3d& baseOrigin,
	        const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis,
	        const AcGeInterval& height, double startAngle, double endAngle);
	AcGeEllipCone& setAngles(double startAngle, double endAngle);
	AcGeEllipCone& setBaseRadius(double radius);
	AcGeEllipCone& setHeight(const AcGeInterval& height);
};

#include "icarx/IcArxPackPop.h"
