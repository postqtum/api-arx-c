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
***     Description: Declaration of AcGeSphere class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "geintrvl.h"
#include "gesurf.h"

class AcGeCircArc3d;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeSphere : public AcGeSurface
{
public:
	AcGeSphere();
	AcGeSphere(double radius, const AcGePoint3d& center);
	AcGeSphere(double radius, const AcGePoint3d& center, const AcGeVector3d& northAxis,
			   const AcGeVector3d& refAxis, double startAngleU, double endAngleU,
			   double startAngleV, double endAngleV);
	AcGeSphere(const AcGeSphere&);
	AcGeSphere& operator=(const AcGeSphere&);

	AcGePoint3d center() const;
	void getAnglesInU(double& start, double& end) const;
	void getAnglesInV(double& start, double& end) const;
	bool intersectWith(const AcGeLinearEnt3d&, int& intn, AcGePoint3d& p1, AcGePoint3d& p2,
					   const AcGeTol& tol = AcGeContext::gTol) const;
	bool isClosed(const AcGeTol& tol = AcGeContext::gTol) const;
	bool isOuterNormal() const;
	AcGeVector3d northAxis() const;
	AcGePoint3d northPole() const;
	double radius() const;
	AcGeVector3d refAxis() const;
	AcGeSphere& set(double radius, const AcGePoint3d& center);
	AcGeSphere& set(double radius, const AcGePoint3d& center, const AcGeVector3d& northAxis,
					const AcGeVector3d& refAxis, double startAngleU, double endAngleU,
					double startAngleV, double endAngleV);
	AcGeSphere& setAnglesInU(double start, double end);
	AcGeSphere& setAnglesInV(double start, double end);
	AcGeSphere& setRadius(double);
	AcGePoint3d southPole() const;
};

#include "icarx/IcArxPackPop.h"
