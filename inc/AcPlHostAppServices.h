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
#include "AcPl.h"

class AcPlPlotLogger;
class AcadPlotInternalServices;

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcPlHostAppServices
{
public:
	enum PlotStatus
	{
		kSheetIdxAndName = -5,
		kDisableCancelSheet = -4,
		kDwfFilePlotted = -3,
		kPlottingMsg = -2,
		kNoPlotYet = -1,
		kPlotStart = 0,
		kViewPlotLog = 1,
		kPlotSuccessful = 2,
		kPlotHadErrors = 3,
		kPlotHadSystemError = 4,
		kViewPlottedFile = 5,
		kViewFileWhenSuccessful = 6
	};

	virtual const AcadPlotInternalServices* acadInternalServices() = 0;
	virtual AcPlPlotLogger* getPlotLogger() = 0;
	virtual void updatePlotJobStatus(PlotStatus nStatus, const ACHAR* szPlotMsg) = 0;
};

#include "icarx/IcArxPackPop.h"

ACPL_PORT Acad::ErrorStatus AcPlSetHostAppServices(AcPlHostAppServices* pHostServices);
ACPL_PORT AcPlHostAppServices* AcPlGetHostAppServices();
