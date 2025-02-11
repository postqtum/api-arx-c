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
***     Description: Declaration of AcDb3dPolylineVertex classes
***
*****************************************************************************/
#pragma once

#include "AcDbVertex.h"
#include "../gepnt3d.h"

#include "IcArxPackPush.h"

class AcDb3dPolylineVertex : public AcDbVertex
{
public:
	AcDb3dPolylineVertex();
	AcDb3dPolylineVertex(const AcGePoint3d&);
	~AcDb3dPolylineVertex();

	ACDBCORE2D_DECLARE_MEMBERS(AcDb3dPolylineVertex);
	ACDBCORE2D_PORT AcGePoint3d position() const;

	Acad::ErrorStatus setPosition(const AcGePoint3d&);
	AcDb::Vertex3dType vertexType() const;
};

#include "IcArxPackPop.h"
