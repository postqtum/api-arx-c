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
***     Description: Declaration of AcGeLinearEnt3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"

class AcGeLine3d;
class AcGeCircArc3d;
class AcGePlanarEnt;

#include "icarx/IcArxPackPush.h"

class AcGeLinearEnt3d : public AcGeCurve3d
{
protected:
	GE_DLLEXPIMPORT AcGeLinearEnt3d();
	GE_DLLEXPIMPORT AcGeLinearEnt3d(const AcGeLinearEnt3d&);

public:
	~AcGeLinearEnt3d() = default;
	GE_DLLEXPIMPORT AcGeLinearEnt3d& operator=(const AcGeLinearEnt3d&);

	GE_DLLEXPIMPORT AcGeVector3d direction() const;
	GE_DLLEXPIMPORT void getLine(AcGeLine3d&) const;
	GE_DLLEXPIMPORT void getPerpPlane(const AcGePoint3d& pnt, AcGePlane& plane) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt3d& line, AcGePoint3d& intPt,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGePlanarEnt& plane, AcGePoint3d& intPnt,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isColinearTo(const AcGeLinearEnt3d& line,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, double& param,
							  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(double param, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePlane& plane, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGeLinearEnt3d& line,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGePlanarEnt& plane,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGeLinearEnt3d& line,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGePlanarEnt& plane,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool overlap(const AcGeLinearEnt3d& line, AcGeLinearEnt3d*& overlap,
								 const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d pointOnLine() const;
	GE_DLLEXPIMPORT bool projIntersectWith(const AcGeLinearEnt3d& line,
													 const AcGeVector3d& projDir,
													 AcGePoint3d& pntOnThisLine,
													 AcGePoint3d& pntOnOtherLine,
													 const AcGeTol& tol = AcGeContext::gTol) const;
};

#include "icarx/IcArxPackPop.h"
