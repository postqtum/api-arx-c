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
***     Description: Declaration of AcDbAssocPathBasedSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbEdgeRef.h"
#include "icarx/AcDbPathRef.h"
#include "icarx/AcDbVertexRef.h"

#include "AcDbAssocSurfaceActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocPathBasedSurfaceActionBody : public AcDbAssocSurfaceActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocPathBasedSurfaceActionBody);

	explicit AcDbAssocPathBasedSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	Acad::ErrorStatus getInputPathParams(AcDbObjectIdArray& pathParamIds) const;
	Acad::ErrorStatus getInputPaths(AcArray<AcArray<AcArray<AcDbEdgeRef>>>&) const;
	Acad::ErrorStatus getInputPoints(AcArray<AcDbVertexRef>&) const;
	Acad::ErrorStatus getInputVertexParams(AcDbObjectIdArray& vertexParamIds) const;
	Acad::ErrorStatus makeInputPathsDrawOnTopOfResultingSurface() const;
	Acad::ErrorStatus removeAllPathParams();
	Acad::ErrorStatus removeAllVertexParams();
	Acad::ErrorStatus setInputPaths(const AcArray<AcArray<AcDbEdgeRef>>&);
	Acad::ErrorStatus setInputPaths(const AcArray<AcDbPathRef>&);
	Acad::ErrorStatus setInputPoints(const AcArray<AcDbVertexRef>&);
	Acad::ErrorStatus updateInputPath(int pathIndex, const AcDbPathRef&);
};

#include "icarx/IcArxPackPop.h"
