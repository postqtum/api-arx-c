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
***     Description: Declaration of AcGeDxfIO class
***
*****************************************************************************/
#pragma once

#include "gefileio.h"
#include "gelibver.h"

class AcDbDxfFiler;

#include "icarx/IcArxPackPush.h"

class AcGeDxfIO
{
public:
	GE_DLLDATAEXIMP static const AcGeLibVersion AcGeDxfIOVersion;

public:
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePoint2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeVector2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeMatrix2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeScale2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePoint2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeVector2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePoint3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeVector3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeMatrix3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeScale3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePoint3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeVector3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeTol&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeInterval&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeKnotVector&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeDoubleArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeIntArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCurveBoundary&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePosition2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePointOnCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeLine2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeLineSeg2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeRay2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCircArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeEllipArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeExternalCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCubicSplineCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeNurbCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCompositeCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeOffsetCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePolyline2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePosition3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePointOnCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePointOnSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeLine3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeRay3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeLineSeg3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeBoundedPlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCircArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeEllipArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCubicSplineCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeNurbCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCompositeCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeOffsetCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGePolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeAugPolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeExternalCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCone&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCylinder&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeTorus&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeExternalSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeOffsetSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeNurbSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeExternalBoundedSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeSphere&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeBoundBlock2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeBoundBlock3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCurveCurveInt2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeCurveCurveInt3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus inFields(AcDbDxfFiler*, AcGeEllipCone&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePoint2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeVector2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeMatrix2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeScale2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePoint2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeVector2dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePoint3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeVector3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeMatrix3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeScale3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePoint3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeVector3dArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeTol&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeInterval&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeKnotVector&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeDoubleArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeIntArray&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCurveBoundary&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePosition2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePointOnCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeLine2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeLineSeg2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeRay2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCircArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeEllipArc2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeExternalCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*,
													   const AcGeCubicSplineCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeNurbCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCompositeCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeOffsetCurve2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePolyline2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePosition3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePointOnCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePointOnSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeLine3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeRay3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeLineSeg3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeBoundedPlane&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCircArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeEllipArc3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*,
													   const AcGeCubicSplineCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeNurbCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCompositeCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeOffsetCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGePolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeAugPolyline3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeExternalCurve3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCone&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCylinder&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeTorus&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeExternalSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeOffsetSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeNurbSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*,
													   const AcGeExternalBoundedSurface&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeSphere&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeBoundBlock2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeBoundBlock3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCurveCurveInt2d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeCurveCurveInt3d&);
	GE_DLLEXPIMPORT static Acad::ErrorStatus outFields(AcDbDxfFiler*, const AcGeEllipCone&);
};

#include "icarx/IcArxPackPop.h"
