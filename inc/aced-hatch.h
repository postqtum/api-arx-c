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

enum AcHatchNotifier
{
	kNobody = 0x00,
	kImpHatch = 0x01,
	kBoundary = 0x02,
	kHatchAndBoundary = (kImpHatch | kBoundary),
	kAddScale = 0x04
};

enum AcHatchEdReact
{
	kStartHatchWatcher = 1,
	kSwapHatchId,
	kUpRootHatchWatcher,
	kDestroyHatchWatcher,
	kDisableNextStart,
	kRecomputeBoundary
};
