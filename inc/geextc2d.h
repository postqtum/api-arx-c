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
***     Description: Declaration of AcGeExternalCurve3d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gearc2d.h"
#include "gevec2d.h"
#include "gepnt2d.h"

class AcGeNurbCurve2d;
class AcGeExternalCurve2d;
class AcGeExternalCurve2d;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeExternalCurve2d : public AcGeCurve2d
{
public:
	AcGeExternalCurve2d();
	AcGeExternalCurve2d(void* curveDef, AcGe::ExternalEntityKind curveKind,
						bool makeCopy = true);
	AcGeExternalCurve2d(const AcGeExternalCurve2d&);
	AcGeExternalCurve2d& operator=(const AcGeExternalCurve2d&);

	AcGe::ExternalEntityKind externalCurveKind() const;
	void getExternalCurve(void*& curveDef) const;
	bool isDefined() const;
	bool isNurbCurve() const;
	bool isNurbCurve(AcGeNurbCurve2d& nurbCurve) const;
	bool isOwnerOfCurve() const;
	AcGeExternalCurve2d& set(void* curveDef, AcGe::ExternalEntityKind curveKind,
							 bool makeCopy = true);
	AcGeExternalCurve2d& setToOwnCurve();
};

#include "icarx/IcArxPackPop.h"
