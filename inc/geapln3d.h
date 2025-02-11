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
***     Description: Declaration of AcGeAugPolyline3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "geplin3d.h"

#include "icarx/IcArxPackPush.h"

class AcGeAugPolyline3d : public AcGePolyline3d
{
public:
	GE_DLLEXPIMPORT AcGeAugPolyline3d();
	GE_DLLEXPIMPORT AcGeAugPolyline3d(const AcGeKnotVector& knots,
									  const AcGePoint3dArray& cntrlPnts,
									  const AcGeVector3dArray& vecBundle);
	GE_DLLEXPIMPORT AcGeAugPolyline3d(const AcGePoint3dArray& cntrlPnts,
									  const AcGeVector3dArray& vecBundle);
	GE_DLLEXPIMPORT AcGeAugPolyline3d(const AcGeCurve3d& curve, double fromParam, double toParam,
									  double apprEps);
	GE_DLLEXPIMPORT AcGeAugPolyline3d(const AcGeAugPolyline3d&);
	~AcGeAugPolyline3d() = default;
	GE_DLLEXPIMPORT AcGeAugPolyline3d& operator=(const AcGeAugPolyline3d&);

	GE_DLLEXPIMPORT double approxTol() const;
	GE_DLLEXPIMPORT void getD1Vectors(AcGeVector3dArray& tangents) const;
	GE_DLLEXPIMPORT AcGeVector3d getD2Vector(int idx) const;
	GE_DLLEXPIMPORT void getD2Vectors(AcGeVector3dArray& d2Vectors) const;
	GE_DLLEXPIMPORT AcGePoint3d getPoint(int idx) const;
	GE_DLLEXPIMPORT void getPoints(AcGePoint3dArray& pnts) const;
	GE_DLLEXPIMPORT AcGeVector3d getVector(int idx) const;
	GE_DLLEXPIMPORT AcGeAugPolyline3d& setApproxTol(double approxTol);
	GE_DLLEXPIMPORT AcGeAugPolyline3d& setD2Vector(int idx, AcGeVector3d pnt);
	GE_DLLEXPIMPORT AcGeAugPolyline3d& setPoint(int idx, AcGePoint3d pnt);
	GE_DLLEXPIMPORT AcGeAugPolyline3d& setVector(int idx, AcGeVector3d pnt);
};

#include "icarx/IcArxPackPop.h"
