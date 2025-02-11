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
***     Description: Declaration of AcGeLineSeg2d class
***
*****************************************************************************/
#pragma once

#include "geline2d.h"

#include "icarx/IcArxPackPush.h"

class AcGeLineSeg2d : public AcGeLinearEnt2d
{
public:
	GE_DLLEXPIMPORT AcGeLineSeg2d();
	GE_DLLEXPIMPORT AcGeLineSeg2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
	GE_DLLEXPIMPORT AcGeLineSeg2d(const AcGePoint2d& pnt, const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeLineSeg2d(const AcGeLineSeg2d&);
	~AcGeLineSeg2d() = default;
	GE_DLLEXPIMPORT AcGeLineSeg2d& operator=(const AcGeLineSeg2d&);

	GE_DLLEXPIMPORT AcGePoint2d baryComb(double blendCoeff) const;
	GE_DLLEXPIMPORT AcGePoint2d endPoint() const;
	GE_DLLEXPIMPORT void getBisector(AcGeLine2d& line) const;
	GE_DLLEXPIMPORT double length() const;
	GE_DLLEXPIMPORT double length(double fromParam, double toParam,
								  double tol = AcGeContext::gTol.equalPoint()) const;
	GE_DLLEXPIMPORT AcGePoint2d midPoint() const;
	GE_DLLEXPIMPORT AcGeLineSeg2d& set(const AcGePoint2d& pnt, const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeLineSeg2d& set(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
	GE_DLLEXPIMPORT AcGeLineSeg2d& set(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
									   double& param1, double& param2, bool& success);
	GE_DLLEXPIMPORT AcGeLineSeg2d& set(const AcGeCurve2d& curve, const AcGePoint2d& point,
									   double& param, bool& success);
	GE_DLLEXPIMPORT AcGePoint2d startPoint() const;
};

#include "icarx/IcArxPackPop.h"
