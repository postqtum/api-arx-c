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
***     Description: Declaration of AcGeLinearEnt2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gepnt2d.h"
#include "gevec2d.h"

class AcGeCircArc2d;

#include "icarx/IcArxPackPush.h"

class AcGeLinearEnt2d : public AcGeCurve2d
{
protected:
	GE_DLLEXPIMPORT AcGeLinearEnt2d();
	GE_DLLEXPIMPORT AcGeLinearEnt2d(const AcGeLinearEnt2d&);

public:
	~AcGeLinearEnt2d() = default;
	GE_DLLEXPIMPORT AcGeLinearEnt2d& operator=(const AcGeLinearEnt2d&);

	GE_DLLEXPIMPORT AcGeVector2d direction() const;
	GE_DLLEXPIMPORT void getLine(AcGeLine2d& line) const;
	GE_DLLEXPIMPORT void getPerpLine(const AcGePoint2d& pnt, AcGeLine2d& perpLine) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt2d& line, AcGePoint2d& intPnt,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isColinearTo(const AcGeLinearEnt2d& line,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGeLinearEnt2d& line,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGeLinearEnt2d& line,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool overlap(const AcGeLinearEnt2d& line, AcGeLinearEnt2d*& overlap,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint2d pointOnLine() const;
};

#include "icarx/IcArxPackPop.h"
