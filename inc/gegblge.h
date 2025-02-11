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
***     Description: Declaration of AcGe struct
***
*****************************************************************************/
#pragma once

#include "gelibver.h"

#include "icarx/IcArxPackPush.h"

struct AcGe
{
	enum
	{
		eGood,
		eBad
	};

	enum AcGeIntersectError
	{
		kXXOk,
		kXXIndexOutOfRange,
		kXXWrongDimensionAtIndex,
		kXXUnknown
	};

	enum AcGeXConfig
	{
		kNotDefined = 1 << 0,
		kUnknown = 1 << 1,
		kLeftRight = 1 << 2,
		kRightLeft = 1 << 3,
		kLeftLeft = 1 << 4,
		kRightRight = 1 << 5,
		kPointLeft = 1 << 6,
		kPointRight = 1 << 7,
		kLeftOverlap = 1 << 8,
		kOverlapLeft = 1 << 9,
		kRightOverlap = 1 << 10,
		kOverlapRight = 1 << 11,
		kOverlapStart = 1 << 12,
		kOverlapEnd = 1 << 13,
		kOverlapOverlap = 1 << 14
	};

	enum BooleanType
	{
		kUnion,
		kSubtract,
		kCommon
	};

	enum ClipCondition
	{
		kInvalid,
		kAllSegmentsInside,
		kSegmentsIntersect,
		kAllSegmentsOutsideZeroWinds,
		kAllSegmentsOutsideOddWinds,
		kAllSegmentsOutsideEvenWinds
	};

	enum ClipError
	{
		eOk,
		eInvalidClipBoundary,
		eNotInitialized
	};

	enum EntityId
	{
		kEntity2d,
		kEntity3d,
		kPointEnt2d,
		kPointEnt3d,
		kPosition2d,
		kPosition3d,
		kPointOnCurve2d,
		kPointOnCurve3d,
		kPointOnSurface,
		kBoundedPlane,
		kCircArc2d,
		kCircArc3d,
		kConic2d,
		kConic3d,
		kCurve2d,
		kCurve3d,
		kEllipArc2d,
		kEllipArc3d,
		kLine2d,
		kLine3d,
		kLinearEnt2d,
		kLinearEnt3d,
		kLineSeg2d,
		kLineSeg3d,
		kPlanarEnt,
		kPlane,
		kRay2d,
		kRay3d,
		kSurface,
		kSphere,
		kCylinder,
		kTorus,
		kCone,
		kSplineEnt2d,
		kPolyline2d,
		kAugPolyline2d,
		kNurbCurve2d,
		kDSpline2d,
		kCubicSplineCurve2d,
		kSplineEnt3d,
		kPolyline3d,
		kAugPolyline3d,
		kNurbCurve3d,
		kDSpline3d,
		kCubicSplineCurve3d,
		kTrimmedCrv2d,
		kCompositeCrv2d,
		kCompositeCrv3d,
		kExternalSurface,
		kNurbSurface,
		kTrimmedSurface,
		kOffsetSurface,
		kEnvelope2d,
		kCurveBoundedSurface,
		kExternalCurve3d,
		kExternalCurve2d,
		kSurfaceCurve2dTo3d,
		kSurfaceCurve3dTo2d,
		kExternalBoundedSurface,
		kCurveCurveInt2d,
		kCurveCurveInt3d,
		kBoundBlock2d,
		kBoundBlock3d,
		kOffsetCurve2d,
		kOffsetCurve3d,
		kPolynomCurve3d,
		kBezierCurve3d,
		kObject,
		kFitData3d,
		kHatch,
		kTrimmedCurve2d,
		kTrimmedCurve3d,
		kCurveSampleData,
		kEllipCone,
		kEllipCylinder,
		kIntervalBoundBlock,
		kClipBoundary2d,
		kExternalObject,
		kCurveSurfaceInt,
		kSurfaceSurfaceInt,
		kHelix
	};

	enum ErrorCondition
	{
		kOk,
		k0This,
		k0Arg1,
		k0Arg2,
		kPerpendicularArg1Arg2,
		kEqualArg1Arg2,
		kEqualArg1Arg3,
		kEqualArg2Arg3,
		kLinearlyDependentArg1Arg2Arg3,
		kArg1TooBig,
		kArg1OnThis,
		kArg1InsideThis
	};

	enum ExternalEntityKind
	{
		kAcisEntity = 0,
		kExternalEntityUndefined
	};

	enum KnotParameterization
	{
		kChord = 0,
		kSqrtChord,
		kUniform,
		kCustomParameterization = 15,
		kNotDefinedKnotParam = 16
	};

	enum NurbSurfaceProperties
	{
		kOpen = 0x01,
		kClosed = 0x02,
		kPeriodic = 0x04,
		kRational = 0x08,
		kNoPoles = 0x10,
		kPoleAtMin = 0x20,
		kPoleAtMax = 0x40,
		kPoleAtBoth = 0x80
	};

	enum OffsetCrvExtType
	{
		kFillet,
		kChamfer,
		kExtend
	};

	enum PointContainment
	{
		kInside,
		kOutside,
		kOnBoundary
	};

	enum csiConfig
	{
		kXUnknown,
		kXOut,
		kXIn,
		kXTanOut,
		kXTanIn,
		kXCoincident,
		kXCoincidentUnbounded
	};

	enum ssiConfig
	{
		kSSIUnknown,
		kSSIOut,
		kSSIIn,
		kSSICoincident
	};

	enum ssiType
	{
		kSSITransverse,
		kSSITangent,
		kSSIAntiTangent
	};

	GE_DLLDATAEXIMP static const AcGeLibVersion gLibVersion;
};

#include "icarx/IcArxPackPop.h"
