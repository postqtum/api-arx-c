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
***     Description:
***
*****************************************************************************/
#pragma once

#include "adesk.h"

enum AcGiArcType
{
	kAcGiArcSimple = 0,
	kAcGiArcSector,
	kAcGiArcChord
};

enum AcGiDeviationType
{
	kAcGiMaxDevForCircle = 0,
	kAcGiMaxDevForCurve,
	kAcGiMaxDevForBoundary,
	kAcGiMaxDevForIsoline,
	kAcGiMaxDevForFacet
};

enum AcGiEdgeStyleMaskValues
{
	kAcGiNoEdgeStyleMask = 0,
	kAcGiJitterMask = 1,
	kAcGiOverhangMask = 2,
	kAcGiEdgeColorMask = 4
};

enum AcGiFillType
{
	kAcGiFillAlways = 1,
	kAcGiFillNever
};

enum AcGiHighlightStyle
{
	kAcGiHighlightNone,
	kAcGiHighlightCustom,
	kAcGiHighlightDashedAndThicken,
	kAcGiHighlightDim,
	kAcGiHighlightThickDim,
	kAcGiHighlightGlow
};

enum AcGiImageOrient
{
	kAcGiXLeftToRightTopFirst,
	kAcGiXLeftToRightBottomFirst,
	kAcGiXRightToLeftTopFirst,
	kAcGiXRightToLeftBottomFirst,
	kAcGiYTopToBottomLeftFirst,
	kAcGiYTopToBottomRightFirst,
	kAcGiYBottomToTopLeftFirst,
	kAcGiYBottomToTopRightFirst
};

enum AcGiImageOrg
{
	kAcGiBitonal,
	kAcGiPalette,
	kAcGiGray,
	kAcGiRGBA,
	kAcGiBGRA,
	kAcGiARGB,
	kAcGiABGR,
	kAcGiBGR,
	kAcGiRGB
};

enum AcGiOrientationType
{
	kAcGiCounterClockwise = -1,
	kAcGiNoOrientation = 0,
	kAcGiClockwise = 1
};

enum AcGiRegenType
{
	eAcGiRegenTypeInvalid = 0,
	kAcGiStandardDisplay = 2,
	kAcGiHideOrShadeCommand,
	kAcGiRenderCommand,
	kAcGiShadedDisplay = kAcGiRenderCommand,
	kAcGiForExplode,
	kAcGiSaveWorldDrawForProxy
};

enum AcGiScaleFilterType
{
	kDefaultScaleFilter,
	kNearestScaleFilter,
	kBellScaleFilter,
	kMitchellScaleFilter,
	kTriangleScaleFilter,
	kCubicScaleFilter,
	kBsplineScaleFilter,
	kLanczos3ScaleFilter
};

enum AcGiScaleType
{
	kDefaultScale,
	kRelativeScale,
	kUnTransformedScale
};

enum AcGiRotationFilterType
{
	kDefaultRotationFilter,
	kInterpolatedRotationFilter,
	kNearestRotationFilter,
};

enum AcGiVisibility
{
	kAcGiInvisible = 0,
	kAcGiVisible,
	kAcGiSilhouette
};

using AcGiEdgeStyleMask = unsigned int;

#define kAcGiSaveWorldDrawForR12 kAcGiForExplode
