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
***     Description: Declaration of AcGePlanarEnt class
***
*****************************************************************************/
#pragma once

#include "gesurf.h"
#include "gevec3d.h"

class AcGeLineSeg3d;
class AcGeLinearEnt3d;
class AcGeCircArc3d;

#include "icarx/IcArxPackPush.h"

class AcGePlanarEnt : public AcGeSurface
{
protected:
	GE_DLLEXPIMPORT AcGePlanarEnt();
	GE_DLLEXPIMPORT AcGePlanarEnt(const AcGePlanarEnt&);

public:
	~AcGePlanarEnt() = default;
	GE_DLLEXPIMPORT AcGePlanarEnt& operator=(const AcGePlanarEnt&);

	GE_DLLEXPIMPORT AcGePoint3d
	closestPointToLinearEnt(const AcGeLinearEnt3d& line, AcGePoint3d& pointOnLine,
							const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d
	closestPointToPlanarEnt(const AcGePlanarEnt& otherPln, AcGePoint3d& pointOnOtherPln,
							const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void get(AcGePoint3d&, AcGeVector3d& uVec, AcGeVector3d& vVec) const;
	GE_DLLEXPIMPORT void get(AcGePoint3d&, AcGePoint3d& origin, AcGePoint3d&) const;
	GE_DLLEXPIMPORT void getCoefficients(double& a, double& b, double& c, double& d) const;
	GE_DLLEXPIMPORT void getCoordSystem(AcGePoint3d& origin, AcGeVector3d& axis1,
										AcGeVector3d& axis2) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt3d& linEnt, AcGePoint3d& pnt,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isCoplanarTo(const AcGePlanarEnt& otherPlnEnt,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGeLinearEnt3d& linEnt,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGePlanarEnt& otherPlnEnt,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGeLinearEnt3d& linEnt,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGePlanarEnt& linEnt,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeVector3d normal() const;
	GE_DLLEXPIMPORT AcGePoint3d pointOnPlane() const;
};

#include "icarx/IcArxPackPop.h"
