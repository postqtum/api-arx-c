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
***     Description: Declaration of AcGeClipBoundary2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include <cassert>
#include "geent2d.h"
#include "gepnt2d.h"
#include "gept2dar.h"
#include "gegbl.h"
#include "geintarr.h"

class AcGeImpClipBoundary2d;

#include "icarx/IcArxPackPush.h"

class AcGeClipBoundary2d : public AcGeEntity2d
{
public:
	GE_DLLEXPIMPORT AcGeClipBoundary2d();
	GE_DLLEXPIMPORT AcGeClipBoundary2d(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB);
	GE_DLLEXPIMPORT AcGeClipBoundary2d(const AcGePoint2dArray& clipBoundary);
	GE_DLLEXPIMPORT AcGeClipBoundary2d(const AcGeClipBoundary2d&);
	~AcGeClipBoundary2d() = default;
	GE_DLLEXPIMPORT AcGeClipBoundary2d& operator=(const AcGeClipBoundary2d&);

	GE_DLLEXPIMPORT AcGe::ClipError clipPolygon(const AcGePoint2dArray& rawVertices,
												AcGePoint2dArray& clippedVertices,
												AcGe::ClipCondition& clipCondition,
												AcGeIntArray* pClippedSegmentSourceLabel = 0) const;
	GE_DLLEXPIMPORT AcGe::ClipError clipPolyline(
			const AcGePoint2dArray& rawVertices, AcGePoint2dArray& clippedVertices,
			AcGe::ClipCondition& clipCondition, AcGeIntArray* pClippedSegmentSourceLabel = 0) const;
	GE_DLLEXPIMPORT AcGe::ClipError set(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB);
	GE_DLLEXPIMPORT AcGe::ClipError set(const AcGePoint2dArray& clipBoundary);
};

#include "icarx/IcArxPackPop.h"
