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
***     Description: Declaration of AcPlPlotProgress class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../AdAChar.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcPlPlotProgress
{
public:
	enum SheetCancelStatus
	{
		kSheetContinue,
		kSheetCanceledByCancelButton,
		kSheetCanceledByCancelAllButton,
		kSheetCanceledByCaller,
		kSheetCancelStatusCount
	};

	enum PlotCancelStatus
	{
		kPlotContinue,
		kPlotCanceledByCaller,
		kPlotCanceledByCancelAllButton,
		kPlotCancelStatusCount
	};

public:
	virtual void getPlotProgressRange(int& nLower, int& nUpper) const = 0;
	virtual void getSheetProgressRange(int& nLower, int& nUpper) const = 0;
	virtual bool getStatusMsgString(ACHAR*& pMsg) const = 0;
	virtual void heartbeat() = 0;
	virtual bool isPlotCancelled() const = 0;
	virtual bool isSheetCancelled() const = 0;
	virtual bool isVisible() const = 0;
	virtual PlotCancelStatus plotCancelStatus() const = 0;
	virtual int plotProgressPos() const = 0;
	virtual bool setIsVisible(bool bVisible) = 0;
	virtual void setPlotCancelStatus(PlotCancelStatus Cancel) = 0;
	virtual void setPlotProgressPos(int nPos) = 0;
	virtual void setPlotProgressRange(int nLower, int nUpper) = 0;
	virtual void setSheetCancelStatus(SheetCancelStatus Cancel) = 0;
	virtual void setSheetProgressPos(int nPos) = 0;
	virtual void setSheetProgressRange(int nLower, int nUpper) = 0;
	virtual bool setStatusMsgString(const ACHAR* pMsg) = 0;
	virtual SheetCancelStatus sheetCancelStatus() const = 0;
	virtual int sheetProgressPos() const = 0;
};

#include "IcArxPackPop.h"
