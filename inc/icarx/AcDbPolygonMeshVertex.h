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
***     Description: Declaration of AcDbPolygonMeshVertex class
***
*****************************************************************************/
#pragma once

#include "AcDbVertex.h"
#include "../gepnt3d.h"

#include "IcArxPackPush.h"

class AcDbPolygonMeshVertex : public AcDbVertex
{
public:
	AcDbPolygonMeshVertex();
	AcDbPolygonMeshVertex(const AcGePoint3d& position);
	~AcDbPolygonMeshVertex();

	ACDB_DECLARE_MEMBERS(AcDbPolygonMeshVertex);

	AcGePoint3d position() const;
	Acad::ErrorStatus setPosition(const AcGePoint3d&);
	AcDb::Vertex3dType vertexType() const;
};

#include "IcArxPackPop.h"
