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
***     Description: Declaration of AcDb2dPolyline class
***
*****************************************************************************/
#pragma once

#include "../dbcurve.h"
#include "AcDb2dVertex.h"

#include "IcArxPackPush.h"

class AcDb2dPolyline : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDb2dPolyline);

	AcDb2dPolyline();
	~AcDb2dPolyline();
	AcDb2dPolyline(AcDb::Poly2dType type, AcGePoint3dArray& vertices, double elevation = 0,
				   bool closed = false, double defStartWidth = 0,
				   double defEndWidth = 0, AcGeDoubleArray* bulges = nullptr,
				   AcArray<int32_t>* vertexIdentifiers = nullptr);

	DBCURVE_METHODS

	Acad::ErrorStatus appendVertex(AcDb2dVertex*);
	Acad::ErrorStatus appendVertex(AcDbObjectId& objId, AcDb2dVertex*);
	ACDBCORE2D_PORT Acad::ErrorStatus constantWidth(double&) const;
	Acad::ErrorStatus convertToPolyType(AcDb::Poly2dType newVal);
	Acad::ErrorStatus curveFit();
	double defaultEndWidth() const;
	double defaultStartWidth() const;
	double elevation() const;
	Acad::ErrorStatus insertVertexAt(const AcDb2dVertex* pIndexVert, AcDb2dVertex* pNewVertex);
	Acad::ErrorStatus insertVertexAt(AcDbObjectId& newVertId, const AcDbObjectId& indexVertId,
									 AcDb2dVertex* pNewVertex);
	bool isLinetypeGenerationOn() const;
	ACDBCORE2D_PORT Acad::ErrorStatus length(double&) const;
	Acad::ErrorStatus makeClosed();
	ACDBCORE2D_PORT Acad::ErrorStatus makeClosedIfStartAndEndVertexCoincide(double distTol);
	Acad::ErrorStatus makeOpen();
	AcGeVector3d normal() const;
	Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&, AcDb::OpenMode);
	Acad::ErrorStatus openVertex(AcDb2dVertex*&, AcDbObjectId vertId, AcDb::OpenMode,
								 bool openErasedOne = false) const;
	ACDBCORE2D_PORT AcDb::Poly2dType polyType() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setClosed(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setConstantWidth(double);
	Acad::ErrorStatus setDefaultEndWidth(double);
	Acad::ErrorStatus setDefaultStartWidth(double);
	Acad::ErrorStatus setElevation(double);
	Acad::ErrorStatus setLinetypeGenerationOff();
	Acad::ErrorStatus setLinetypeGenerationOn();
	Acad::ErrorStatus ACDBCORE2D_PORT setLinetypeGenerationOn(bool bOn);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setPolyType(AcDb::Poly2dType);
	Acad::ErrorStatus setThickness(double);
	Acad::ErrorStatus splineFit();
	Acad::ErrorStatus splineFit(AcDb::Poly2dType splineType, int16_t splineSegs);
	Acad::ErrorStatus straighten();
	double thickness() const;
	AcDbObjectIterator* vertexIterator() const;
	AcGePoint3d vertexPosition(const AcDb2dVertex& vert) const;
};

#include "IcArxPackPop.h"
