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
***     Description: Declaration of AcDbPlotSettingsValidator class
***
*****************************************************************************/
#pragma once

#include "AdAChar.h"
#include "dbPlotsettings.h"

template<class T, class R>
class AcArray;

#ifndef OBJARX_EXCLUDE_CONFLICTS

using PlotPaperUnits = AcDbPlotSettings::PlotPaperUnits;
using PlotRotation = AcDbPlotSettings::PlotRotation;
using PlotType = AcDbPlotSettings::PlotType;
using StdScaleType = AcDbPlotSettings::StdScaleType;

#endif

#include "icarx/IcArxPackPush.h"

class AcDbPlotSettingsValidator
{
public:
	virtual Acad::ErrorStatus canonicalMediaNameList(AcDbPlotSettings* pPlotSet,
													 AcArray<const ACHAR*>& mediaList) = 0;
	virtual Acad::ErrorStatus getLocaleMediaName(AcDbPlotSettings* pPlotSet,
												 const ACHAR* canonicalName,
												 const ACHAR*& localeName) = 0;
	virtual Acad::ErrorStatus getLocaleMediaName(AcDbPlotSettings* pPlotSet, int index,
												 const ACHAR*& localeName) = 0;
	virtual Acad::ErrorStatus plotDeviceList(AcArray<const ACHAR*>& deviceList) = 0;
	virtual Acad::ErrorStatus plotStyleSheetList(AcArray<const ACHAR*>& styleList) = 0;
	virtual void refreshLists(AcDbPlotSettings* pPlotSet) = 0;
	virtual Acad::ErrorStatus setCanonicalMediaName(AcDbPlotSettings* pPlotSet,
													const ACHAR* mediaName) = 0;
	virtual Acad::ErrorStatus setClosestMediaName(AcDbPlotSettings* pPlotSet,
												  const double paperWidth, const double paperHeight,
												  const AcDbPlotSettings::PlotPaperUnits units,
												  bool matchPrintableArea) = 0;
	virtual Acad::ErrorStatus setCurrentStyleSheet(AcDbPlotSettings* pPlotSet,
												   const ACHAR* styleSheetName) = 0;
	virtual Acad::ErrorStatus setCustomPrintScale(AcDbPlotSettings* pPlotSet,
												  const double numerator,
												  const double denominator) = 0;
	virtual Acad::ErrorStatus setDefaultPlotConfig(AcDbPlotSettings* pPlotSet) = 0;
	virtual Acad::ErrorStatus setPlotCentered(AcDbPlotSettings* pPlotSet, bool isCentered) = 0;
	virtual Acad::ErrorStatus setPlotCfgName(AcDbPlotSettings* pPlotSet,
											 const ACHAR* plotDeviceName,
											 const ACHAR* mediaName = nullptr) = 0;
	virtual Acad::ErrorStatus setPlotOrigin(AcDbPlotSettings* pPlotSet, const double xCoordinate,
											const double yCoordinate) = 0;
	virtual Acad::ErrorStatus setPlotPaperUnits(AcDbPlotSettings* pPlotSet,
												const AcDbPlotSettings::PlotPaperUnits units) = 0;
	virtual Acad::ErrorStatus setPlotRotation(AcDbPlotSettings* pPlotSet, const AcDbPlotSettings::PlotRotation rotationType) = 0;
	virtual Acad::ErrorStatus setPlotType(AcDbPlotSettings* pPlotSet,
										  const AcDbPlotSettings::PlotType plotAreaType) = 0;
	virtual Acad::ErrorStatus setPlotViewName(AcDbPlotSettings* pPlotSet,
											  const ACHAR* viewName) = 0;
	virtual Acad::ErrorStatus setPlotWindowArea(AcDbPlotSettings* pPlotSet, const double xmin,
												const double ymin, const double xmax,
												const double ymax) = 0;
	virtual Acad::ErrorStatus setStdScale(AcDbPlotSettings* pPlotSet,
										  const double standardScale) = 0;
	virtual Acad::ErrorStatus setStdScaleType(AcDbPlotSettings* pPlotSet,
											  const AcDbPlotSettings::StdScaleType scaleType) = 0;
	virtual Acad::ErrorStatus setUseStandardScale(AcDbPlotSettings* pPlotSet, bool useStandard) = 0;
	virtual void setZoomToPaperOnUpdate(AcDbPlotSettings* pPlotSet, bool doZoom) = 0;
};

#include "icarx/IcArxPackPop.h"
