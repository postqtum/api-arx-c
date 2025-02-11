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
***     Description: Declaration of AcDbFace class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "../gepnt3d.h"
#include "AcDbEnumGeom.h"

#include "IcArxPackPush.h"

class AcDbFace : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbFace();
	AcDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2,
			 const AcGePoint3d& pt3, bool e0vis = true,
			 bool e1vis = true, bool e2vis = true,
			 bool e3vis = true);
	AcDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2,
			 bool e0vis = true, bool e1vis = true,
			 bool e2vis = true, bool e3vis = true);
	~AcDbFace();

	ACDBCORE2D_DECLARE_MEMBERS(AcDbFace);

	ACDBCORE2D_PORT Acad::ErrorStatus getPlane(AcGePlane& plane,
											   AcDb::Planarity& planarity) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus getVertexAt(uint16_t, AcGePoint3d&) const;
	Acad::ErrorStatus isEdgeVisibleAt(uint16_t, bool&) const;
	ACDBCORE2D_PORT bool isPlanar() const override;
	Acad::ErrorStatus makeEdgeInvisibleAt(uint16_t);
	Acad::ErrorStatus makeEdgeVisibleAt(uint16_t);
	Acad::ErrorStatus setVertexAt(uint16_t, const AcGePoint3d&);
};

#include "IcArxPackPop.h"
