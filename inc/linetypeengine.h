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
***     Description: Declaration of AcGiLinetypeEngine class
***
*****************************************************************************/
#pragma once

#include "acgi.h"

class AcGiImpLinetypeEngine;

#include "icarx/IcArxPackPush.h"

class AcGiLinetypeEngine : public AcRxObject
{
private:
	AcGiImpLinetypeEngine* mpAcGiImpLinetypeEngine;

public:
	ACRX_DECLARE_MEMBERS(AcGiLinetypeEngine);

	AcGiLinetypeEngine();
	~AcGiLinetypeEngine();

	virtual Acad::ErrorStatus tessellate(bool bIsArc, bool bIsCircle, const uint32_t nPoints,
										 const AcGePoint3d* pVertexList, AcGiWorldDraw* pWorldDraw,
										 const AcDbObjectId linetypeId, double linetypeScale,
										 const AcGeVector3d* pNormal, bool plineGen = false);
	virtual Acad::ErrorStatus tessellate(bool bIsArc, bool bIsCircle, const uint32_t nPoints,
										 const AcGePoint3d* pVertexList,
										 AcGiViewportDraw* pViewportDraw,
										 const AcDbObjectId linetypeId, double linetypeScale,
										 const AcGeVector3d* pNormal, bool plineGen = false);

	virtual Acad::ErrorStatus tessellate(const AcGeCircArc3d& arcSeg, const AcGeMatrix3d& ecsMat,
										 double startWidth, double endWidth, AcGiCommonDraw* pDraw,
										 const AcDbObjectId linetypeId, double linetypeScale,
										 double thick);

	virtual Acad::ErrorStatus tessellate(const AcGeLineSeg3d& lineSeg, const AcGeMatrix3d& ecsMat,
										 double startWidth, double endWidth, AcGiCommonDraw* pDraw,
										 const AcDbObjectId linetypeId, double linetypeScale);

};

#include "icarx/IcArxPackPop.h"
