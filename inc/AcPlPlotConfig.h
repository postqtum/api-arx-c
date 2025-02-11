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
#include "acarray.h"
#include "gepnt2d.h"
#include "geblok2d.h"
#include "dblayout.h"
#include "AcPlObject.h"

class HT_Plot_Config;
class HT_Media_Size;
class HT_Media_Description;
class AcPlPlotConfigImp;

#include "icarx/IcArxPackPush.h"

class AcPlPlotConfig : public AcPlObject
{
	friend class AcPlPlotConfigManagerImp;
	friend class AcPlPlotInfoImp;
	friend class AcPlPlotInfoValidatorImp;

public:
	enum PlotToFileCapability
	{
		kNoPlotToFile = 0,
		kPlotToFileAllowed = 1,
		kMustPlotToFile = 2
	};

private:
	ACPL_DECLARE_MEMBERS(AcPlPlotConfig)

private:
	AcPlPlotConfig();

protected:
	AcPlPlotConfig(const AcPlPlotConfig* pOther);

public:
	AcPlPlotConfig(const ACHAR* pDevName, const ACHAR* pFullPath, unsigned long nDevType);

	ACPL_PORT ~AcPlPlotConfig();

	ACPL_PORT virtual Acad::ErrorStatus copyFrom(const AcRxObject* pSrc);
	ACPL_PORT virtual const ACHAR* deviceName() const;
	ACPL_PORT virtual unsigned long deviceType() const;
	ACPL_PORT virtual const ACHAR* fullPath() const;
	ACPL_PORT virtual void getCanonicalMediaNameList(AcArray<ACHAR*>& mediaList) const;
	ACPL_PORT virtual Acad::ErrorStatus getDefaultFileExtension(
			const ACHAR*& pDefaultExtension) const;
	ACPL_PORT virtual void getDescriptionFields(ACHAR*& pDriverName, ACHAR*& pLocationName,
												ACHAR*& pComment, ACHAR*& pPortName,
												ACHAR*& pServerName, ACHAR*& pTagLine) const;
	ACPL_PORT virtual void getLocalMediaName(const ACHAR* pCanonicalMediaName,
											 ACHAR*& pLocalMediaName) const;
	ACPL_PORT virtual void getMediaBounds(const ACHAR* pCanonicalMediaName, AcGePoint2d& pageSize,
										  AcGeBoundBlock2d& printableArea) const;
	ACPL_PORT AcPlPlotConfigImp& impObj() const;
	ACPL_PORT virtual bool isPlotToFile() const;
	ACPL_PORT bool matchMediaSize(double page_x, double page_y, double printable_w,
								  double printable_h, AcDbLayout::PlotPaperUnits units,
								  bool bIsSheet, int dpi, const ACHAR* pTargetCanonicalName,
								  ACHAR*& pNearestSizeName, ACHAR*& pLocalizedName,
								  double& scaleFactor);
	ACPL_PORT virtual unsigned int maxDeviceDPI() const;
	ACPL_PORT virtual PlotToFileCapability plotToFileCapability() const;
	ACPL_PORT virtual void refreshMediaNameList();
	ACPL_PORT virtual bool saveToPC3(const ACHAR* pPC3Name);
	ACPL_PORT virtual Acad::ErrorStatus setPlotToFile(bool bPlotToFile);
};

#include "icarx/IcArxPackPop.h"
