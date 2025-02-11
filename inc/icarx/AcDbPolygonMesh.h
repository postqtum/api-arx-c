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
***     Description: Declaration of AcDbPolygonMesh class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "../gept3dar.h"

class AcDbSequenceEnd;
class AcDbPolygonMeshVertex;
class AcDbObjectIterator;

#include "IcArxPackPush.h"

class AcDbPolygonMesh : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbPolygonMesh();
	AcDbPolygonMesh(AcDb::PolyMeshType pType, int16_t mSize, int16_t nSize,
					const AcGePoint3dArray& vertices, bool mClosed = true,
					bool nClosed = true);
	~AcDbPolygonMesh();

	ACDB_DECLARE_MEMBERS(AcDbPolygonMesh);

	Acad::ErrorStatus appendVertex(AcDbPolygonMeshVertex*);
	Acad::ErrorStatus appendVertex(AcDbObjectId& objId, AcDbPolygonMeshVertex*);
	Acad::ErrorStatus convertToPolyMeshType(AcDb::PolyMeshType newVal);
	bool isMClosed() const;
	bool isNClosed() const;
	int16_t mSize() const;
	int16_t mSurfaceDensity() const;
	Acad::ErrorStatus makeMClosed();
	Acad::ErrorStatus makeMOpen();
	Acad::ErrorStatus makeNClosed();
	Acad::ErrorStatus makeNOpen();
	int16_t nSize() const;
	int16_t nSurfaceDensity() const;
	Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&, AcDb::OpenMode);
	Acad::ErrorStatus openVertex(AcDbPolygonMeshVertex*&, AcDbObjectId vertId, AcDb::OpenMode,
								 bool openErasedOne = false);
	AcDb::PolyMeshType polyMeshType() const;
	Acad::ErrorStatus setMSize(int16_t);
	Acad::ErrorStatus setMSurfaceDensity(int16_t);
	Acad::ErrorStatus setNSize(int16_t);
	Acad::ErrorStatus setNSurfaceDensity(int16_t);
	Acad::ErrorStatus setPolyMeshType(AcDb::PolyMeshType);
	Acad::ErrorStatus straighten();
	Acad::ErrorStatus surfaceFit();
	Acad::ErrorStatus surfaceFit(AcDb::PolyMeshType surfType, int16_t surfu, int16_t surfv);
	AcDbObjectIterator* vertexIterator() const;
};

#include "IcArxPackPop.h"
