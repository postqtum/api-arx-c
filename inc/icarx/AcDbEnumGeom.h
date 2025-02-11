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
***     Description: Declaration of AcDbEnumGeom
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

namespace AcDb
{
enum Poly2dType
{
	k2dSimplePoly = 0,
	k2dFitCurvePoly = 1,
	k2dQuadSplinePoly = 2,
	k2dCubicSplinePoly = 3
};

enum Poly3dType
{
	k3dSimplePoly = 0,
	k3dQuadSplinePoly = 1,
	k3dCubicSplinePoly = 2
};

enum PolyMeshType
{
	kSimpleMesh = 0,
	kQuadSurfaceMesh = 5,
	kCubicSurfaceMesh = 6,
	kBezierSurfaceMesh = 8
};

enum Vertex2dType
{
	k2dVertex = 0,
	k2dSplineCtlVertex = 1,
	k2dSplineFitVertex = 2,
	k2dCurveFitVertex = 3
};

enum Vertex3dType
{
	k3dSimpleVertex = 0,
	k3dControlVertex = 1,
	k3dFitVertex = 2
};

enum SpaceValueType
{
	kUndefined,
	kStubPtr,
	kEndOfFile,
	kBackwardBranch,
	kForwardBranch,
	kDetour
};

enum BoolOperType
{
	kBoolUnite = 0,
	kBoolIntersect = 1,
	kBoolSubtract = 2
};

enum GeomType
{
	kInvalidGeom = 0,
	kPointGeom,
	kLineGeom,
	kCircleGeom,
	kPlaneGeom
};

enum Planarity
{
	kNonPlanar = 0,
	kPlanar = 1,
	kLinear = 2
};

enum
{
	kNoGeom = 0
};

}  // namespace AcDb

