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
***     Description: Declaration of AcGeCompositeCurve2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gevptar.h"
#include "geintarr.h"

#include "icarx/IcArxPackPush.h"

class AcGeCompositeCurve2d : public AcGeCurve2d
{
public:
	GE_DLLEXPIMPORT AcGeCompositeCurve2d();
	GE_DLLEXPIMPORT AcGeCompositeCurve2d(const AcGeVoidPointerArray& curveList);
	GE_DLLEXPIMPORT AcGeCompositeCurve2d(const AcGeVoidPointerArray& curveList,
										 const AcGeIntArray& isOwnerOfCurves);
	GE_DLLEXPIMPORT AcGeCompositeCurve2d(const AcGeCompositeCurve2d&);
	~AcGeCompositeCurve2d() = default;
	GE_DLLEXPIMPORT AcGeCompositeCurve2d& operator=(const AcGeCompositeCurve2d&);

	GE_DLLEXPIMPORT void getCurveList(AcGeVoidPointerArray& curveList) const;
	GE_DLLEXPIMPORT double globalToLocalParam(double param, int& crvNum) const;
	GE_DLLEXPIMPORT double localToGlobalParam(double param, int crvNum) const;
	GE_DLLEXPIMPORT AcGeCompositeCurve2d& setCurveList(const AcGeVoidPointerArray& curveList);
	GE_DLLEXPIMPORT AcGeCompositeCurve2d& setCurveList(const AcGeVoidPointerArray& curveList,
													   const AcGeIntArray& isOwnerOfCurves);
};

#include "icarx/IcArxPackPop.h"
