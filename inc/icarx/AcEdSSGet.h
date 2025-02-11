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
***     Description: Declaration of AcEdSSGet namespace
***
*****************************************************************************/
#pragma once

namespace AcEdSSGet
{

enum AcEdSSGetFlags
{
	kNormal = 0,
	kPickPoints = 1,
	kDuplicates = 2,
	kNestedEntities = 4,
	kSubEntities = 8,
	kSinglePick = 16,
	kPickfirstSet = 32,
	kPreviousSet = 64,
	kSubSelection = 128,
	kUndo = 256,
	kFailedPickAuto = 512,
	kCommandPreview = 1024,
	kAllViewports = 2048,
	kForBoxPick = 4096,
	kPreSelectionHilite = 8192
};

enum AcEdSSGetModes
{
	kUnknown = 0,
	kWin,
	kCross,
	kBox,
	kLast,
	kEntity,
	kAll,
	kFence,
	kCPoly,
	kWPoly,
	kPick,
	kEvery,
	kXten,
	kGroup,
	kPrevious,
	kMultiple,
};

};	// namespace AcEdSSGet
