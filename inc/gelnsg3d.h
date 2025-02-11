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
***     Description: Declaration of AcGeLineSeg3d class
***
*****************************************************************************/
#pragma once

#include "geline3d.h"
#include "geplane.h"

class AcGeLineSeg2d;

#include "icarx/IcArxPackPush.h"

class AcGeLineSeg3d : public AcGeLinearEnt3d
{
public:
	GE_DLLEXPIMPORT AcGeLineSeg3d();
	GE_DLLEXPIMPORT AcGeLineSeg3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeLineSeg3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
	GE_DLLEXPIMPORT AcGeLineSeg3d(const AcGeLineSeg3d&);
	~AcGeLineSeg3d() = default;
	GE_DLLEXPIMPORT AcGeLineSeg3d& operator=(const AcGeLineSeg3d&);

	GE_DLLEXPIMPORT AcGePoint3d baryComb(double blendCoeff) const;
	GE_DLLEXPIMPORT AcGePoint3d endPoint() const;
	GE_DLLEXPIMPORT void getBisector(AcGePlane& plane) const;
	GE_DLLEXPIMPORT double length() const;
	GE_DLLEXPIMPORT double length(double fromParam, double toParam,
								  double tol = AcGeContext::gTol.equalPoint()) const;
	GE_DLLEXPIMPORT AcGePoint3d midPoint() const;
	GE_DLLEXPIMPORT AcGeLineSeg3d& set(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeLineSeg3d& set(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
	GE_DLLEXPIMPORT AcGeLineSeg3d& set(const AcGeCurve3d& curve1, const AcGeCurve3d& curve2,
									   double& param1, double& param2, bool& success);
	GE_DLLEXPIMPORT AcGeLineSeg3d& set(const AcGeCurve3d& curve, const AcGePoint3d& point,
									   double& param, bool& success);
	GE_DLLEXPIMPORT AcGePoint3d startPoint() const;
};

#include "icarx/IcArxPackPop.h"
