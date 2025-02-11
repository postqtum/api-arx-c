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
***     Description: Declaration of AcColorSettingsEx struct
***
*****************************************************************************/
#pragma once

#include "AcColorSettings.h"

#include "IcArxPackPush.h"

struct AcColorSettingsEx
{
	DWORD dwModelLightWeb;
	DWORD dwLayoutLightWeb;
	DWORD dwParallelLightWeb;
	DWORD dwPerspectiveLightWeb;
	DWORD dwBEditLightWeb;
	DWORD dwModelLightWebMissingFile;
	DWORD dwLayoutLightWebMissingFile;
	DWORD dwParallelLightWebMissingFile;
	DWORD dwPerspectiveLightWebMissingFile;
	DWORD dwBEditLightWebMissingFile;
	DWORD dwModelLightWebShape;
	DWORD dwLayoutLightWebShape;
	DWORD dwParallelLightWebShape;
	DWORD dwPerspectiveLightWebShape;
	DWORD dwBEditLightWebShape;
	DWORD dwModelLightWebLuxAtDist;
	DWORD dwLayoutLightWebLuxAtDist;
	DWORD dwParallelLightWebLuxAtDist;
	DWORD dwPerspectiveLightWebLuxAtDist;
	DWORD dwBEditLightWebLuxAtDist;
	DWORD dwBEditUnconstrainedColor;
	DWORD dwBEditPartiallyConstrainedColor;
	DWORD dwBEditFullyConstrainedColor;
	DWORD dwBEditOverConstrainedColor;
};

#include "IcArxPackPop.h"

ACCORE_PORT bool acedGetCurrentColorsEx(AcColorSettings* pColorSettings,
										AcColorSettingsEx* pColorSettingsEx);

ACCORE_PORT bool acedSetCurrentColorsEx(AcColorSettings* pColorSettings,
										AcColorSettingsEx* pColorSettingsEx);

ACCORE_PORT bool acedGetSystemColorsEx(AcColorSettings* pColorSettings,
									   AcColorSettingsEx* pColorSettingsEx);
