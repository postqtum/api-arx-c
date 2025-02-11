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
***     Description: Declaration of AcDbFaceRecord class
***
*****************************************************************************/
#pragma once

#include "AcDbVertex.h"

#include "IcArxPackPush.h"

class AcDbFaceRecord : public AcDbVertex
{
public:
	AcDbFaceRecord();
	AcDbFaceRecord(int16_t vtx0, int16_t vtx1, int16_t vtx2, int16_t vtx3);
	~AcDbFaceRecord();

	ACDB_DECLARE_MEMBERS(AcDbFaceRecord);

	Acad::ErrorStatus getVertexAt(uint16_t faceIdx, int16_t& vtxIdx) const;
	Acad::ErrorStatus isEdgeVisibleAt(uint16_t faceIndex, bool& visible) const;
	Acad::ErrorStatus makeEdgeInvisibleAt(uint16_t faceIndex);
	Acad::ErrorStatus makeEdgeVisibleAt(uint16_t faceIndex);
	Acad::ErrorStatus setVertexAt(uint16_t faceIdx, int16_t vtxIdx);
};

#include "IcArxPackPop.h"
