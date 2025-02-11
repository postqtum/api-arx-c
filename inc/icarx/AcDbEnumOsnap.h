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
***     Description: Declaration of AcDbEnumOsnap
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::OsnapMask
{
	kOsMaskEnd = 1,
	kOsMaskMid = 2,
	kOsMaskCen = 4,
	kOsMaskNode = 8,
	kOsMaskQuad = 0x10,
	kOsMaskInt = 0x20,
	kOsMaskIns = 0x40,
	kOsMaskPerp = 0x80,
	kOsMaskTan = 0x100,
	kOsMaskNear = 0x200,
	kOsMaskQuick = 0x400,
	kOsMaskCentroid = AcDb::OsnapMask::kOsMaskQuick,
	kOsMaskApint = 0x800,
	kOsMaskImmediate = 0x10000,
	kOsMaskAllowTan = 0x20000,
	kOsMaskDisablePerp = 0x40000,
	kOsMaskRelCartesian = 0x80000,
	kOsMaskRelPolar = 0x100000,
	kOsMaskNoneOverride = 0x200000
};

enum AcDb::OsnapMode
{
	kOsModeEnd = 1,
	kOsModeMid = 2,
	kOsModeCen = 3,
	kOsModeNode = 4,
	kOsModeQuad = 5,
	kOsModeIns = 7,
	kOsModePerp = 8,
	kOsModeTan = 9,
	kOsModeNear = 10,
	kOsModeCentroid = 11,
};
