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
#include "brgbl.h"
#include "brent.h"

class AcDbEntity;
class AcDb3dSolid;
class AcDbSurface;
class AcGePoint3d;
class AcGeCurve3d;

#include "inc/icarx/IcArxPackPush.h"

class AcBrBrep : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrBrep);

	using AcBrEntity::get;
	using AcBrEntity::set;

	AcBrBrep();
	AcBrBrep(const AcBrBrep& src);
	~AcBrBrep();
	AcBrBrep& operator=(const AcBrBrep& src);
	AcBr::ErrorStatus get(AcDb3dSolid*& pSolid) const;
	AcBr::ErrorStatus get(AcDbSurface*& pSurface) const;
	AcBr::ErrorStatus getCurveRelationToBrep(const AcGeCurve3d& curve,
											 AcBr::Relation& relation) const;
	AcBr::ErrorStatus getPointRelationToBrep(const AcGePoint3d& point,
											 AcBr::Relation& relation) const;
	AcBr::ErrorStatus set(const AcDbEntity& entity);
};

#include "inc/icarx/IcArxPackPop.h"
