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
***     Description: Declaration of AcGeDwgIO class
***
*****************************************************************************/
#pragma once

#include "gefileio.h"
#include "gelibver.h"

class AcDbDwgFiler;

#include "icarx/IcArxPackPush.h"

class AcGeDwgIO
{
public:
	GE_DLLDATAEXIMP static const AcGeLibVersion AcGeDwgIOVersion;

public:
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePoint2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeVector2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeMatrix2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeScale2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePoint2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeVector2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePoint3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeVector3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeMatrix3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeScale3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePoint3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeVector3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeTol&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeInterval&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeKnotVector&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeDoubleArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeIntArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCurveBoundary&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePosition2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePointOnCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeLine2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeLineSeg2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeRay2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCircArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeEllipArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeExternalCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCubicSplineCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeNurbCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCompositeCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeOffsetCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePolyline2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePosition3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePointOnCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePointOnSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeLine3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeRay3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeLineSeg3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeBoundedPlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCircArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeEllipArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCubicSplineCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCompositeCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeOffsetCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeNurbCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGePolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeAugPolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeExternalCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCone&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCylinder&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeTorus&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeExternalSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeOffsetSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeNurbSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeExternalBoundedSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeSphere&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeBoundBlock2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeBoundBlock3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCurveCurveInt2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeCurveCurveInt3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDwgFiler*, AcGeEllipCone&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePoint2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeVector2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeMatrix2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeScale2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePoint2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeVector2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePoint3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeVector3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeMatrix3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeScale3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePoint3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeVector3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeTol&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeInterval&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeKnotVector&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeDoubleArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeIntArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCurveBoundary&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePosition2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePointOnCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeLine2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeLineSeg2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeRay2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCircArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeEllipArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeExternalCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*,
													   const AcGeCubicSplineCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeNurbCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCompositeCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeOffsetCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePolyline2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePosition3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePointOnCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePointOnSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeLine3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeRay3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeLineSeg3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeBoundedPlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCircArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeEllipArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*,
													   const AcGeCubicSplineCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeNurbCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCompositeCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeOffsetCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGePolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeAugPolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeExternalCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCone&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCylinder&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeTorus&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeExternalSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeOffsetSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeNurbSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*,
													   const AcGeExternalBoundedSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeSphere&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeBoundBlock2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeBoundBlock3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCurveCurveInt2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeCurveCurveInt3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDwgFiler*, const AcGeEllipCone&);
};

#include "icarx/IcArxPackPop.h"
