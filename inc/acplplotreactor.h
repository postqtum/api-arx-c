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

#include "AdAChar.h"
#include "AcPl.h"
#include "AcPlObject.h"
#include "icarx/AcPlPlotProgress.h"

class AcPlPlotInfo;
class AcPlPlotPageInfo;
class AcPlPlotProgress;

#include "icarx/IcArxPackPush.h"

class AcPlPlotReactor : public AcRxObject
{
public:
	enum PlotType
	{
		kPlot,
		kPreview,
		kBackgroundPackaging,
		kBackgroundPlot
	};

protected:
	ACPL_PORT AcPlPlotReactor();

public:
	ACPL_PORT ~AcPlPlotReactor();

	virtual void beginDocument(AcPlPlotInfo& /*plotInfo*/, const ACHAR* /*pDocname*/,
							   int32_t /*nCopies*/, bool /*bPlotToFile*/,
							   const ACHAR* /*pFilename*/)
	{
	}
	virtual void beginPage(AcPlPlotPageInfo& /*pageInfo*/, AcPlPlotInfo& /*plotInfo*/,
						   bool /*bLastPage*/)
	{
	}
	virtual void beginPlot(AcPlPlotProgress* /*pPlotProgress*/, PlotType /*type*/) {}
	virtual void endDocument(AcPlPlotProgress::PlotCancelStatus /*status*/) {}
	virtual void endPage(AcPlPlotProgress::SheetCancelStatus /*status*/) {}
	virtual void endPlot(AcPlPlotProgress::PlotCancelStatus /*status*/) {}
	virtual void pageCancelled() {}
	virtual void plotCancelled() {}
};

#include "icarx/IcArxPackPop.h"
