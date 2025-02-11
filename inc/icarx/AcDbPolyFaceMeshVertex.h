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
***     Description: Declaration of AcDbPolyFaceMeshVertex class
***
*****************************************************************************/
#pragma once

#include "AcDbVertex.h"
#include "../gepnt3d.h"

#include "IcArxPackPush.h"

class AcDbPolyFaceMeshVertex : public AcDbVertex
{
public:
	AcDbPolyFaceMeshVertex();
	AcDbPolyFaceMeshVertex(const AcGePoint3d& position);
	~AcDbPolyFaceMeshVertex();

	ACDB_DECLARE_MEMBERS(AcDbPolyFaceMeshVertex);

	AcGePoint3d position() const;
	Acad::ErrorStatus setPosition(const AcGePoint3d&);
};

#include "IcArxPackPop.h"
