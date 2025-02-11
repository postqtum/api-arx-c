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
***     Description: Declaration of AcDbEnumCode
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::DwgDataType
{
	kDwgNull = 0,
	kDwgReal = 1,
	kDwgInt32 = 2,
	kDwgInt16 = 3,
	kDwgInt8 = 4,
	kDwgText = 5,
	kDwgBChunk = 6,
	kDwgHandle = 7,
	kDwgHardOwnershipId = 8,
	kDwgSoftOwnershipId = 9,
	kDwgHardPointerId = 10,
	kDwgSoftPointerId = 11,
	kDwg3Real = 12,
	kDwgInt64 = 13,
	kDwgNotRecognized = 19
};

namespace AcDb
{

enum
{
	kDxfInvalid = -9999,
	kDxfXDictionary = -6,
	kDxfPReactors = -5,
	kDxfOperator = -4,
	kDxfXDataStart = -3,
	kDxfHeaderId = -2,
	kDxfFirstEntId = -2,
	kDxfEnd = -1,
	kDxfStart = 0,
	kDxfText = 1,
	kDxfXRefPath = 1,
	kDxfShapeName = 2,
	kDxfBlockName = 2,
	kDxfAttributeTag = 2,
	kDxfSymbolTableName = 2,
	kDxfMstyleName = 2,
	kDxfSymTableRecName = 2,
	kDxfAttributePrompt = 3,
	kDxfDimStyleName = 3,
	kDxfLinetypeProse = 3,
	kDxfTextFontFile = 3,
	kDxfDescription = 3,
	kDxfDimPostStr = 3,
	kDxfTextBigFontFile = 4,
	kDxfDimAPostStr = 4,
	kDxfCLShapeName = 4,
	kDxfSymTableRecComments = 4,
	kDxfHandle = 5,
	kDxfDimBlk = 5,
	kDxfDimBlk1 = 6,
	kDxfLinetypeName = 6,
	kDxfDimBlk2 = 7,
	kDxfTextStyleName = 7,
	kDxfLayerName = 8,
	kDxfCLShapeText = 9,

	kDxfXCoord = 10,

	kDxfYCoord = 20,

	kDxfZCoord = 30,

	kDxfElevation = 38,
	kDxfThickness = 39,

	kDxfReal = 40,
	kDxfViewportHeight = 40,
	kDxfTxtSize = 40,
	kDxfTxtStyleXScale = 41,
	kDxfViewWidth = 41,
	kDxfViewportAspect = 41,
	kDxfTxtStylePSize = 42,
	kDxfViewLensLength = 42,
	kDxfViewFrontClip = 43,
	kDxfViewBackClip = 44,
	kDxfShapeXOffset = 44,
	kDxfShapeYOffset = 45,
	kDxfViewHeight = 45,
	kDxfShapeScale = 46,
	kDxfPixelScale = 47,

	kDxfLinetypeScale = 48,

	kDxfDashLength = 49,
	kDxfMlineOffset = 49,
	kDxfLinetypeElement = 49,

	kDxfAngle = 50,
	kDxfViewportSnapAngle = 50,
	kDxfViewportTwist = 51,

	kDxfVisibility = 60,
	kDxfViewportGridDisplay = 60,
	kDxfLayerLinetype = 61,
	kDxfViewportGridMajor = 61,
	kDxfColor = 62,

	kDxfHasSubentities = 66,
	kDxfViewportVisibility = 67,
	kDxfViewportActive = 68,
	kDxfViewportNumber = 69,

	kDxfInt16 = 70,
	kDxfViewMode = 71,
	kDxfCircleSides = 72,
	kDxfViewportZoom = 73,
	kDxfViewportIcon = 74,
	kDxfViewportSnap = 75,
	kDxfViewportGrid = 76,
	kDxfViewportSnapStyle = 77,
	kDxfViewportSnapPair = 78,

	kDxfRegAppFlags = 71,

	kDxfTxtStyleFlags = 71,
	kDxfLinetypeAlign = 72,
	kDxfLinetypePDC = 73,

	kDxfInt32 = 90,
	kDxfVertexIdentifier = 91,

	kDxfSubclass = 100,
	kDxfEmbeddedObjectStart = 101,
	kDxfControlString = 102,

	kDxfDimVarHandle = 105,

	kDxfUCSOrg = 110,
	kDxfUCSOriX = 111,
	kDxfUCSOriY = 112,

	kDxfXReal = 140,
	kDxfViewBrightness = 141,
	kDxfViewContrast = 142,

	kDxfInt64 = 160,

	kDxfXInt16 = 170,

	kDxfNormalX = 210,
	kDxfNormalY = 220,
	kDxfNormalZ = 230,

	kDxfXXInt16 = 270,

	kDxfInt8 = 280,
	kDxfRenderMode = 281,
	kDxfDefaultLightingType = 282,
	kDxfShadowFlags = 284,

	kDxfBool = 290,
	kDxfDefaultLightingOn = 292,

	kDxfXTextString = 300,

	kDxfBinaryChunk = 310,

	kDxfArbHandle = 320,

	kDxfSoftPointerId = 330,
	kDxfViewBackgroundId = 332,
	kDxfShadePlotId = 333,
	kDxfLiveSectionId = 334,
	kDxfLiveSectionName = 309,

	kDxfHardPointerId = 340,
	kDxfObjVisualStyleId = 345,
	kDxfVpVisualStyleId = 346,
	kDxfMaterialId = 347,
	kDxfVisualStyleId = 348,
	kDxfDragVisualStyleId = 349,

	kDxfSoftOwnershipId = 350,

	kDxfHardOwnershipId = 360,
	kDxfSunId = 361,

	kDxfLineWeight = 370,
	kDxfPlotStyleNameType = 380,
	kDxfPlotStyleNameId = 390,
	kDxfXXXInt16 = 400,

	kDxfLayoutName = 410,

	kDxfColorRGB = 420,
	kDxfColorName = 430,

	kDxfAlpha = 440,

	kDxfGradientObjType = 450,
	kDxfGradientPatType = 451,
	kDxfGradientTintType = 452,
	kDxfGradientColCount = 453,
	kDxfGradientAngle = 460,
	kDxfGradientShift = 461,
	kDxfGradientTintVal = 462,
	kDxfGradientColVal = 463,
	kDxfGradientName = 470,

	kDxfFaceStyleId = 480,
	kDxfEdgeStyleId = 481,

	kDxfComment = 999,

	kDxfXdAsciiString = 1000,
	kDxfRegAppName = 1001,
	kDxfXdControlString = 1002,
	kDxfXdLayerName = 1003,
	kDxfXdBinaryChunk = 1004,
	kDxfXdHandle = 1005,

	kDxfXdXCoord = 1010,
	kDxfXdYCoord = 1020,
	kDxfXdZCoord = 1030,

	kDxfXdWorldXCoord = 1011,
	kDxfXdWorldYCoord = 1021,
	kDxfXdWorldZCoord = 1031,

	kDxfXdWorldXDisp = 1012,
	kDxfXdWorldYDisp = 1022,
	kDxfXdWorldZDisp = 1032,

	kDxfXdWorldXDir = 1013,
	kDxfXdWorldYDir = 1023,
	kDxfXdWorldZDir = 1033,

	kDxfXdReal = 1040,
	kDxfXdDist = 1041,
	kDxfXdScale = 1042,

	kDxfXdInteger16 = 1070,
	kDxfXdInteger32 = 1071,

	kDxfXdMax = kDxfXdInteger32
};

}
