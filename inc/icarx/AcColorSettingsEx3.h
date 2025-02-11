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
***     Description: Declaration of AcColorSettingsEx3 struct
***
*****************************************************************************/
#pragma once

#include "AcColorSettingsEx2.h"

#include "IcArxPackPush.h"

struct AcColorSettingsEx3
{
	DWORD dwModel3dASnapMarkerColor;
	DWORD dwLayout3dASnapMarkerColor;
	DWORD dwParallel3dASnapMarkerColor;
	DWORD dwPerspective3dASnapMarkerColor;
	DWORD dwBEdit3dASnapMarkerColor;
	DWORD dw2DModelVportControl;
	DWORD dwParallelVportControl;
	DWORD dwPerspectiveVportControl;
};

#include "IcArxPackPop.h"

ACCORE_PORT
bool acedGetCurrentColorsEx3(AcColorSettings* pColorSettings, AcColorSettingsEx* pColorSettingsEx,
							 AcColorSettingsEx2* pColorSettingsEx2,
							 AcColorSettingsEx3* pColorSettingsEx3);

ACCORE_PORT
bool acedSetCurrentColorsEx3(AcColorSettings* pColorSettings, AcColorSettingsEx* pColorSettingsEx,
							 AcColorSettingsEx2* pColorSettingsEx2,
							 AcColorSettingsEx3* pColorSettingsEx3);

ACCORE_PORT
bool acedGetSystemColorsEx3(AcColorSettings* pColorSettings, AcColorSettingsEx* pColorSettingsEx,
							AcColorSettingsEx2* pColorSettingsEx2,
							AcColorSettingsEx3* pColorSettingsEx3);
