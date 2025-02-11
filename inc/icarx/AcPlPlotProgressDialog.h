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
***     Description: Declaration of AcPlPlotProgressDialog class
***
*****************************************************************************/
#pragma once

#include "AcPlPlotProgress.h"
#include "../AcPl.h"

#include "IcArxPackPush.h"

class AcPlPlotProgressDialog;

using ACPLPLTPRGHELPPROC = void (*)(AcPlPlotProgressDialog* pAcPlPlotProgressDialog);

class AcPlPlotProgressDialog : public AcPlPlotProgress
{
public:
	enum PlotMSGIndex
	{
		kDialogTitle,
		kSheetName,
		kSheetNameToolTip,
		kStatus,
		kSheetProgressCaption,
		kSheetSetProgressCaption,
		kMsgCancelling,
		kMsgCancellingCurrent,
		kCancelSheetBtnMsg,
		kCancelJobBtnMsg,
		kMsgCount
	};

public:
	virtual void destroy() = 0;
	virtual bool getPlotMsgString(PlotMSGIndex index, ACHAR*& pMsg) const = 0;
	virtual bool isSingleSheetPlot() const = 0;
	virtual bool onBeginPlot() = 0;
	virtual bool onBeginSheet() = 0;
	virtual bool onEndPlot() = 0;
	virtual bool onEndSheet() = 0;
	virtual bool setPlotMsgString(PlotMSGIndex index, const ACHAR* pMsg) = 0;
};

#include "IcArxPackPop.h"

ACPL_PORT AcPlPlotProgressDialog* ADESK_STDCALL
acplCreatePlotProgressDialog(HWND hParent, bool bPreview = false, int nSheets = 1,
							 ACPLPLTPRGHELPPROC hlpProc = nullptr, bool bShowCancelSheetButton = true);
