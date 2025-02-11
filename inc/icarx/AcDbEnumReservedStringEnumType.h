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
***     Description: Declaration of AcDbEnumReservedStringEnumType
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::reservedStringEnumType
{
	kByLayer = 0,
	kByBlock = 1,
	kNone = 2,
	kContinuous = 3,
	kStandard = 4,
	kNormal = 5,
	kDefPoints = 6,
	kDefault = 7,
	kMissing = 8,
	kByColor = 9,
	kModel = 10,
	kGlobal = 11,
	kVS2DWireframe = 12,
	kVS3DWireframe = 13,
	kVS3DHidden = 14,
	kVSRealistic = 15,
	kVSConceptual = 16,
	kTitle = 17,
	kHeader = 18,
	kData = 19,
	kVSShadesOfGray = 20,
	kVSSketchy = 21,
	kVSXRay = 22,
	kVSShadedWithEdges = 23,
	kVSShaded = 24,
	kReservedStringCount
};
