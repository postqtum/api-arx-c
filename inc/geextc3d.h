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

#include "gecurv3d.h"
#include "gearc3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"

class AcGeLine3d;
class AcGeLineSeg3d;
class AcGeRay3d;
class AcGeEllipArc3d;
class AcGeNurbCurve3d;
class AcGeExternalCurve2d;
class AcGeExternalCurve3d;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeExternalCurve3d : public AcGeCurve3d
{
public:
	AcGeExternalCurve3d();
	AcGeExternalCurve3d(void* curveDef, AcGe::ExternalEntityKind curveKind,
						bool makeCopy = true);
	AcGeExternalCurve3d(const AcGeExternalCurve3d&);
	AcGeExternalCurve3d& operator=(const AcGeExternalCurve3d&);

	AcGe::ExternalEntityKind externalCurveKind() const;
	void getExternalCurve(void*& curveDef) const;
	bool isCircArc() const;
	bool isDefined() const;
	bool isEllipArc() const;
	bool isLine() const;
	bool isLineSeg() const;
	bool isNativeCurve(AcGeCurve3d*& nativeCurve) const;
	bool isNurbCurve() const;
	bool isOwnerOfCurve() const;
	bool isRay() const;
	AcGeExternalCurve3d& set(void* curveDef, AcGe::ExternalEntityKind curveKind,
							 bool makeCopy = true);
	AcGeExternalCurve3d& setToOwnCurve();
};

#include "icarx/IcArxPackPop.h"
