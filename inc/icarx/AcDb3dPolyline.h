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
***     Description: Declaration of AcDb3dPolyline classes
***
*****************************************************************************/
#pragma once

#include "../dbcurve.h"
#include "AcDb3dPolylineVertex.h"

class AcDbSequenceEnd;

#include "IcArxPackPush.h"

class AcDb3dPolyline : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDb3dPolyline();
	~AcDb3dPolyline();
	AcDb3dPolyline(AcDb::Poly3dType, AcGePoint3dArray& vertices,
				   bool closed = false);

	ACDBCORE2D_DECLARE_MEMBERS(AcDb3dPolyline);

	DBCURVE_METHODS

	Acad::ErrorStatus appendVertex(AcDb3dPolylineVertex*);
	Acad::ErrorStatus appendVertex(AcDbObjectId& objId, AcDb3dPolylineVertex*);
	Acad::ErrorStatus convertToPolyType(AcDb::Poly3dType newVal);
	Acad::ErrorStatus insertVertexAt(const AcDb3dPolylineVertex* pIndexVert,
									 AcDb3dPolylineVertex* pNewVertex);
	Acad::ErrorStatus insertVertexAt(AcDbObjectId& newVertId, const AcDbObjectId& indexVertId,
									 AcDb3dPolylineVertex* pNewVertex);
	ACDBCORE2D_PORT Acad::ErrorStatus length(double&) const;
	Acad::ErrorStatus makeClosed();
	Acad::ErrorStatus makeOpen();
	Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&, AcDb::OpenMode);
	Acad::ErrorStatus openVertex(AcDb3dPolylineVertex*&, AcDbObjectId vertId, AcDb::OpenMode,
								 bool openErasedOne = false);
	ACDBCORE2D_PORT AcDb::Poly3dType polyType() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setClosed(bool);
	Acad::ErrorStatus setPolyType(AcDb::Poly3dType);
	Acad::ErrorStatus splineFit();
	Acad::ErrorStatus splineFit(AcDb::Poly3dType splineType, int16_t splineSegs);
	Acad::ErrorStatus straighten();
	ACDBCORE2D_PORT AcDbObjectIterator* vertexIterator() const;
};

#include "IcArxPackPop.h"
