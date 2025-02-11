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
***     Description: Declaration of AcGiVisualStyleProperties namespace
***
*****************************************************************************/
#pragma once

namespace AcGiVisualStyleProperties
{

enum DisplayShadowType
{
	kShadowsNone,
	kShadowsGroundPlane,
	kShadowsFull,
	kShadowsFullAndGround,
};

enum DisplayStyles
{
	kNoDisplayStyle = 0,
	kBackgroundsFlag = 1,
	kLightingFlag = 2,
	kMaterialsFlag = 4,
	kTexturesFlag = 8,
};

enum FaceColorMode
{
	kNoColorMode,
	kObjectColor,
	kBackgroundColor,
	kMono,
	kTint,
	kDesaturate
};

enum FaceLightingModel
{
	kInvisible,
	kConstant,
	kPhong,
	kGooch,
	kZebra
};

enum FaceLightingQuality
{
	kNoLighting,
	kPerFaceLighting,
	kPerVertexLighting,
	kPerPixelLighting
};

enum EdgeModel
{
	kNoEdges,
	kIsolines,
	kFacetEdges,
};

enum FaceModifiers
{
	kNoFaceModifiers = 0,
	kFaceOpacityFlag = 1,
	kSpecularFlag = 2
};

enum EdgeJitterAmount
{
	kJitterLow = 1,
	kJitterMedium,
	kJitterHigh,
};

enum EdgeLinePattern
{
	kSolid = 1,
	kDashedLine,
	kDotted,
	kShortDash,
	kMediumDash,
	kLongDash,
	kDoubleShortDash,
	kDoubleMediumDash,
	kDoubleLongDash,
	kMediumLongDash,
	kSparseDot
};

enum EdgeModifiers
{
	kNoEdgeModifiers = 0,
	kEdgeOverhangFlag = 1,
	kEdgeJitterFlag = 2,
	kEdgeWidthFlag = 4,
	kEdgeColorFlag = 8,
	kEdgeHaloGapFlag = 16,
	kAlwaysOnTopFlag = 64,
	kEdgeOpacityFlag = 128,
	kEdgeWiggleFlag = 256,
	kEdgeTextureFlag = 512,
};

enum EdgeStyles
{
	kNoEdgeStyle = 0,
	kVisibleFlag = 1,
	kSilhouetteFlag = 2,
	kObscuredFlag = 4,
	kIntersectionFlag = 8
};

enum EdgeWiggleAmount
{
	kWiggleLow = 1,
	kWiggleMedium,
	kWiggleHigh,
};

enum Property
{
	kInvalidProperty = -1,
	kFaceLightingModel,
	kFaceLightingQuality,
	kFaceColorMode,
	kFaceModifiers,
	kFaceOpacity,
	kFaceSpecular,
	kFaceMonoColor,
	kEdgeModel,
	kEdgeStyles,
	kEdgeIntersectionColor,
	kEdgeObscuredColor,
	kEdgeObscuredLinePattern,
	kEdgeIntersectionLinePattern,
	kEdgeCreaseAngle,
	kEdgeModifiers,
	kEdgeColor,
	kEdgeOpacity,
	kEdgeWidth,
	kEdgeOverhang,
	kEdgeJitterAmount,
	kEdgeSilhouetteColor,
	kEdgeSilhouetteWidth,
	kEdgeHaloGap,
	kEdgeIsolines,
	kEdgeHidePrecision,
	kDisplayStyles,
	kDisplayBrightness,
	kDisplayShadowType,
	kUseDrawOrder,
	kViewportTransparency,
	kLightingEnabled,
	kPosterizeEffect,
	kMonoEffect,
	kBlurEffect,
	kPencilEffect,
	kBloomEffect,
	kPastelEffect,
	kBlurAmount,
	kPencilAngle,
	kPencilScale,
	kPencilPattern,
	kPencilColor,
	kBloomThreshold,
	kBloomRadius,
	kTintColor,
	kFaceAdjustment,
	kPostContrast,
	kPostBrightness,
	kPostPower,
	kTintEffect,
	kBloomIntensity,
	kColor,
	kTransparency,
	kEdgeWiggleAmount,
	kEdgeTexturePath,
	kDepthOfField,
	kFocusDistance,
	kFocusWidth,
	kPropertyCount,
	kPropertyCountPre2013 = kUseDrawOrder,
};

}  // namespace AcGiVisualStyleProperties
