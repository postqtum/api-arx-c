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
***     Description: Declaration of AcPlPlotConfigManager class
***
*****************************************************************************/
#pragma once

#include "AcPlPlotConfigInfo.h"
#include "../acarray.h"

class AcPlPlotConfigManagerImp;
class AcPlPlotConfig;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcPlPlotConfigManager
{
public:
	enum RefreshCode
	{
		kAll,
		kRefreshDevicesList,
		kRefreshStyleList,
		kRefreshSystemDevicesList,
		kRefreshPC3DevicesList
	};

	enum StdConfigs
	{
		kNoneDevice,
		kDefaultWindowsSysPrinter,
		kDWF6ePlot,
		kDWFePlotOptForPlotting,
		kDWFePlotOptForViewing,
		kPublishToWebDWF,
		kPublishToWebJPG,
		kPublishToWebPNG,
		kDWFxePlot,
		kPublishToWebDWFx,
		kPDFePlot,
		kPDFePlotGeneralDocs,
		kPDFePlotHighQuality,
		kPDFePlotSmallerFile,
		kPDFePlotWebMobile,
		kSVFePlot
	};

	enum StyTypes
	{
		kUndefined = 0,
		kRegular = 0x01,
		kTranslation = 0x02,
		kColorDep = 0x04,
		kAllTypes = 0x07
	};

	virtual Acad::ErrorStatus getCurrentConfig(AcPlPlotConfig*& pConfig);
	virtual bool getDevicesList(
			AcArray<AcPlPlotConfigInfo, AcArrayObjectCopyReallocator<AcPlPlotConfigInfo> >&
					deviceList);
	virtual const ACHAR* getStdConfigName(StdConfigs stdConfig);
	virtual bool getStyleList(AcArray<ACHAR*>& list, long styType = kAllTypes);
	virtual AcPlPlotConfigManagerImp* impObj();
	virtual void refreshList(RefreshCode refreshCode = kAll);
	virtual Acad::ErrorStatus setCurrentConfig(AcPlPlotConfig*& pConfig, const ACHAR* pDeviceName);
};

#include "IcArxPackPop.h"

ACPL_PORT AcPlPlotConfigManager* ADESK_STDCALL acplPlotConfigManagerPtr();
