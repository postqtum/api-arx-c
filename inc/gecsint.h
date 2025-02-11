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
***     Description: Declaration of AcGeCurveSurfInt class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "geent3d.h"
#include "geponc3d.h"
#include "geponsrf.h"
#include "geintrvl.h"
#include "gegbl.h"
#include "gegblabb.h"

class AcGeCurve3d;
class AcGeSurface;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeCurveSurfInt : public AcGeEntity3d
{
public:
	AcGeCurveSurfInt();
	AcGeCurveSurfInt(const AcGeCurve3d& crv, const AcGeSurface& srf,
					 const AcGeTol& tol = AcGeContext::gTol);
	AcGeCurveSurfInt(const AcGeCurveSurfInt&);
	AcGeCurveSurfInt& operator=(const AcGeCurveSurfInt&);

	const AcGeCurve3d* curve() const;
	void getIntConfigs(int intNum, AcGe::csiConfig& lower, AcGe::csiConfig& higher,
					   bool& smallAngle, AcGeIntersectError& err) const;
	void getIntParams(int intNum, double& param1, AcGePoint2d& param2,
					  AcGeIntersectError& err) const;
	void getPointOnCurve(int intNum, AcGePointOnCurve3d&, AcGeIntersectError& err) const;
	void getPointOnSurface(int intNum, AcGePointOnSurface&, AcGeIntersectError& err) const;
	AcGePoint3d intPoint(int intNum, AcGeIntersectError& err) const;
	int numIntPoints(AcGeIntersectError& err) const;
	AcGeCurveSurfInt& set(const AcGeCurve3d& cvr, const AcGeSurface& srf,
						  const AcGeTol& tol = AcGeContext::gTol);
	const AcGeSurface* surface() const;
	AcGeTol tolerance() const;
};

#include "icarx/IcArxPackPop.h"
