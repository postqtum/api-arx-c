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
***     Description: Declaration of AcGeSurfSurfInt class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "geent3d.h"
#include "gegbl.h"
#include "gegblabb.h"

class AcGeCurve3d;
class AcGeCurve2d;
class AcGeSurface;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeSurfSurfInt : public AcGeEntity3d
{
public:
	AcGeSurfSurfInt();
	AcGeSurfSurfInt(const AcGeSurface& srf1, const AcGeSurface& srf2,
					const AcGeTol& tol = AcGeContext::gTol);
	AcGeSurfSurfInt(const AcGeSurfSurfInt&);
	AcGeSurfSurfInt& operator=(const AcGeSurfSurfInt&);

	int getDimension(int intNum, AcGe::AcGeIntersectError& err) const;
	void getIntConfigs(int intNum, AcGe::ssiConfig& surf1Left, AcGe::ssiConfig& surf1Right,
					   AcGe::ssiConfig& surf2Left, AcGe::ssiConfig& surf2Right,
					   AcGe::ssiType& intType, int& dim, AcGe::AcGeIntersectError& err) const;
	void getIntPointParams(int intNum, AcGePoint2d& param1, AcGePoint2d& param2,
						   AcGe::AcGeIntersectError& err) const;
	AcGe::ssiType getType(int intNum, AcGe::AcGeIntersectError& err) const;
	AcGeCurve3d* intCurve(int intNum, bool isExternal, AcGe::AcGeIntersectError& err) const;
	AcGeCurve2d* intParamCurve(int num, bool isExternal, bool isFirst,
							   AcGe::AcGeIntersectError& err) const;
	AcGePoint3d intPoint(int intNum, AcGe::AcGeIntersectError& err) const;
	int numResults(AcGe::AcGeIntersectError& err) const;
	AcGeSurfSurfInt& set(const AcGeSurface& srf1, const AcGeSurface& srf2,
						 const AcGeTol& tol = AcGeContext::gTol);
	const AcGeSurface* surface1() const;
	const AcGeSurface* surface2() const;
	AcGeTol tolerance() const;
};

#include "icarx/IcArxPackPop.h"
