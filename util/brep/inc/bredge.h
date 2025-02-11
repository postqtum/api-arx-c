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
***     Description:
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "inc/gegbl.h"
#include "brgbl.h"
#include "brent.h"

class AcGePoint3d;
class AcGeCurve3d;
class AcGeNurbCurve3d;
class AcBrVertex;

#include "inc/icarx/IcArxPackPush.h"

class AcBrEdge : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrEdge);

	AcBrEdge();
	AcBrEdge(const AcBrEdge& src);
	~AcBrEdge();
	AcBrEdge& operator=(const AcBrEdge& src);
	AcBr::ErrorStatus getCurve(AcGeCurve3d*& curve) const;
	AcBr::ErrorStatus getCurveAsNurb(AcGeNurbCurve3d& nurb, const double* fitTolRequired = nullptr,
									 double* fitTolAchieved = nullptr) const;
	AcBr::ErrorStatus getCurveRelationToEdge(const AcGeCurve3d& curve,
											 AcBr::Relation& relation) const;
	AcBr::ErrorStatus getCurveType(AcGe::EntityId& type) const;
	AcBr::ErrorStatus getOrientToCurve(bool& bOrientToCurve) const;
	AcBr::ErrorStatus getPointRelationToEdge(const AcGePoint3d& point,
											 AcBr::Relation& relation) const;
	AcBr::ErrorStatus getVertex1(AcBrVertex& vertex) const;
	AcBr::ErrorStatus getVertex2(AcBrVertex& vertex) const;
};

#include "inc/icarx/IcArxPackPop.h"
