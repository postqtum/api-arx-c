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
***     Description: Declaration of AcPlPlotEngine class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../acadstrc.h"

class AcPlPlotProgress;
class AcPlPlotInfo;
class AcPlPlotPageInfo;
class AcViewport;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcPlPlotEngine
{
public:
	virtual Acad::ErrorStatus beginDocument(AcPlPlotInfo& plotInfo, const ACHAR* pDocname,
											void* pParams = nullptr, int32_t nCopies = 1,
											bool bPlotToFile = false,
											const ACHAR* pFileName = nullptr);
	virtual Acad::ErrorStatus beginGenerateGraphics(void* pParams = nullptr);
	virtual Acad::ErrorStatus beginGenerateGraphics(AcViewport*& pViewport, void* pParams = nullptr);
	virtual Acad::ErrorStatus beginPage(AcPlPlotPageInfo& pageInfo, AcPlPlotInfo& plotInfo,
										bool bLastPage, void* pParams = nullptr);
	virtual Acad::ErrorStatus beginPlot(AcPlPlotProgress* pPlotProgress, void* pParams = nullptr);
	virtual void destroy();
	virtual Acad::ErrorStatus endDocument(void* pParams = nullptr);
	virtual Acad::ErrorStatus endGenerateGraphics(void* pParams = nullptr);
	virtual Acad::ErrorStatus endPage(void* pParams = nullptr);
	virtual Acad::ErrorStatus endPlot(void* pParams = nullptr);
	virtual bool isBackgroundPackaging() const;
};

#include "IcArxPackPop.h"
