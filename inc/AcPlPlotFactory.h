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

#include "AcPl.h"
#include "adesk.h"
#include "acadstrc.h"

class AcPlPlotEngine;

#include "icarx/IcArxPackPush.h"

class AcPlPlotFactory
{
public:
	enum PreviewEngineFlags
	{
		kShowPlot = 0x0001,
		kShowNextSheet = 0x0002,
		kShowPreviousSheet = 0x0004
	};

	static ACPL_PORT Acad::ErrorStatus createPreviewEngine(AcPlPlotEngine*& pPreview,
														   long nPreviewFlags = kShowPlot);
	static ACPL_PORT Acad::ErrorStatus createPublishEngine(AcPlPlotEngine*& pEngine);
};

#include "icarx/IcArxPackPop.h"

enum ProcessPlotState
{
	kNotPlotting = 0,
	kForegroundPlotting,
	kBackgroundPlotting
};

ACPL_PORT ProcessPlotState ADESK_STDCALL acplProcessPlotState();
