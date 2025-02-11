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
***     Description: Declaration fo AcBrVertex class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class AcGePoint3d;
class AcGeCurve3d;

#include "inc/icarx/IcArxPackPush.h"

class AcBrVertex : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrVertex);

	AcBrVertex();
	AcBrVertex(const AcBrVertex& src);
	~AcBrVertex();
	AcBrVertex& operator=(const AcBrVertex& src);
	AcBr::ErrorStatus getCurveRelationToVertex(const AcGeCurve3d& curve,
											   AcBr::Relation& relation) const;
	AcBr::ErrorStatus getPoint(AcGePoint3d*& point) const;
	AcBr::ErrorStatus getPoint(AcGePoint3d& point) const;
	AcBr::ErrorStatus getPointRelationToVertex(const AcGePoint3d& point,
											   AcBr::Relation& relation) const;
};

#include "inc/icarx/IcArxPackPop.h"
