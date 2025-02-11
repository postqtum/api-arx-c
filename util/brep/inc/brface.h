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
***     Description: Declaration of AcBrFace class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "inc/gegbl.h"
#include "brgbl.h"
#include "brent.h"

class AcGeSurface;
class AcGeNurbSurface;
class AcGeExternalBoundedSurface;
class AcGeCurve3d;
class AcGePoint3d;
class AcBrShell;

#include "inc/icarx/IcArxPackPush.h"

class AcBrFace : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrFace);

	AcBrFace();
	AcBrFace(const AcBrFace& src);
	~AcBrFace();
	AcBrFace& operator=(const AcBrFace& src);
	AcBr::ErrorStatus getArea(double& area, const double* tolRequired = nullptr,
							  double* tolAchieved = nullptr) const;
	AcBr::ErrorStatus getCurveRelationToFace(const AcGeCurve3d& curve,
											 AcBr::Relation& relation) const;
	AcBr::ErrorStatus getOrientToSurface(bool& bOrientToSurface) const;
	AcBr::ErrorStatus getPointRelationToFace(const AcGePoint3d& point,
											 AcBr::Relation& relation) const;
	AcBr::ErrorStatus getShell(AcBrShell& shell) const;
	AcBr::ErrorStatus getSurfaceType(AcGe::EntityId& type) const;
	AcBr::ErrorStatus getSurface(AcGeSurface*& surface) const;
	AcBr::ErrorStatus getSurfaceAsNurb(AcGeNurbSurface& nurb,
									   const double* fitTolRequired = nullptr,
									   double* fitTolAchieved = nullptr) const;
	AcBr::ErrorStatus getSurfaceAsTrimmedNurbs(uint32_t& numNurbs,
											   AcGeExternalBoundedSurface**& ppNurbs) const;
};

#include "inc/icarx/IcArxPackPop.h"
