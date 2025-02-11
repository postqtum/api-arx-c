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
***     Description: Declaration of AcDbPolyFaceMesh class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "AcDbPolyFaceMeshVertex.h"
#include "AcDbFaceRecord.h"
#include "AcDbObjectIterator.h"

class AcDbSequenceEnd;

#include "IcArxPackPush.h"

class AcDbPolyFaceMesh : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbPolyFaceMesh();
	~AcDbPolyFaceMesh();

	ACDB_DECLARE_MEMBERS(AcDbPolyFaceMesh);

	Acad::ErrorStatus appendFaceRecord(AcDbFaceRecord*);
	Acad::ErrorStatus appendFaceRecord(AcDbObjectId&, AcDbFaceRecord*);
	Acad::ErrorStatus appendVertex(AcDbPolyFaceMeshVertex*);
	Acad::ErrorStatus appendVertex(AcDbObjectId& objId, AcDbPolyFaceMeshVertex*);
	int16_t numFaces() const;
	int16_t numVertices() const;
	Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&, AcDb::OpenMode);
	Acad::ErrorStatus openVertex(AcDbVertex*&, AcDbObjectId subObjId, AcDb::OpenMode,
								 bool openErasedOne = false);
	AcDbObjectIterator* vertexIterator() const;
};

#include "IcArxPackPop.h"
