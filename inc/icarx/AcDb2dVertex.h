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
***     Description: Declaration of AcDb2dVertex classes
***
*****************************************************************************/
#pragma once

#include "AcDbBlockReference.h"
#include "AcDbVertex.h"

#include "IcArxPackPush.h"

class AcDb2dVertex : public AcDbVertex
{
public:
	AcDb2dVertex();
	~AcDb2dVertex();

	ACDB_DECLARE_MEMBERS(AcDb2dVertex);

	AcDb2dVertex(const AcGePoint3d& position, double bulge = 0, double startWidth = 0,
				 double endWidth = 0, double tangent = 0, int32_t vertexIdentifier = 0);
	double bulge() const;
	double endWidth() const;
	Acad::ErrorStatus ignoreTangent();
	bool isTangentUsed() const;
	AcGePoint3d position() const;
	Acad::ErrorStatus setBulge(double newVal);
	Acad::ErrorStatus setEndWidth(double newVal);
	Acad::ErrorStatus setPosition(const AcGePoint3d&);
	Acad::ErrorStatus setStartWidth(double newVal);
	Acad::ErrorStatus setTangent(double newVal);
	ACDBCORE2D_PORT Acad::ErrorStatus setTangentUsed(bool);
	Acad::ErrorStatus setVertexIdentifier(int32_t suggestedValue);
	double startWidth() const;
	double tangent() const;
	Acad::ErrorStatus useTangent();
	int vertexIdentifier() const;
	AcDb::Vertex2dType vertexType() const;
};

#include "IcArxPackPop.h"
