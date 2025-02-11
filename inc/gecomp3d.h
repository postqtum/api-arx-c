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
***     Description: Declaration of AcGeCompositeCurve3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gevptar.h"
#include "geintarr.h"

#include "icarx/IcArxPackPush.h"

class AcGeCompositeCurve3d : public AcGeCurve3d
{
public:
	GE_DLLEXPIMPORT AcGeCompositeCurve3d();
	GE_DLLEXPIMPORT AcGeCompositeCurve3d(const AcGeVoidPointerArray& curveList);
	GE_DLLEXPIMPORT AcGeCompositeCurve3d(const AcGeVoidPointerArray& curveList,
										 const AcGeIntArray& isOwnerOfCurves);
	GE_DLLEXPIMPORT AcGeCompositeCurve3d(const AcGeCompositeCurve3d&);
	~AcGeCompositeCurve3d() = default;
	GE_DLLEXPIMPORT AcGeCompositeCurve3d& operator=(const AcGeCompositeCurve3d&);

	GE_DLLEXPIMPORT void getCurveList(AcGeVoidPointerArray& curveList) const;
	GE_DLLEXPIMPORT double globalToLocalParam(double param, int& segNum) const;
	GE_DLLEXPIMPORT double localToGlobalParam(double param, int segNum) const;
	GE_DLLEXPIMPORT AcGeCompositeCurve3d& setCurveList(const AcGeVoidPointerArray& curveList);
	GE_DLLEXPIMPORT AcGeCompositeCurve3d& setCurveList(const AcGeVoidPointerArray& curveList,
													   const AcGeIntArray& isOwnerOfCurves);
};

#include "icarx/IcArxPackPop.h"
