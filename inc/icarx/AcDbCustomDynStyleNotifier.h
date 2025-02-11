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
***     Description: Declaration of AcDbCustomDynStyleNotifier class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../acadstrc.h"

class AcDbObjectId;
class AcDbDatabase;
class AcDbCustomDynStyleReactor;

#include "IcArxPackPush.h"

class AcDbCustomDynStyleNotifier
{
public:
	ACDBCORE2D_PORT AcDbCustomDynStyleNotifier();
	ACDBCORE2D_PORT ~AcDbCustomDynStyleNotifier() = default;

	ACDBCORE2D_PORT static AcDbCustomDynStyleNotifier* instance();

	ACDBCORE2D_PORT Acad::ErrorStatus addReactor(AcDbCustomDynStyleReactor* reactor);
	ACDBCORE2D_PORT Acad::ErrorStatus removeReactor(AcDbCustomDynStyleReactor* reactor);

	ACDBCORE2D_PORT AcDbObjectId getCustomDynDimStyleId(AcDbDatabase* pDb = nullptr);
	ACDBCORE2D_PORT AcDbObjectId getCustomDynDimTextStyleId(AcDbDatabase* pDb = nullptr);
	ACDBCORE2D_PORT AcDbObjectId getCustomDynLineTypeId(AcDbDatabase* pDb = nullptr);
	ACDBCORE2D_PORT AcDbObjectId getCustomDynArrowTypeId(AcDbDatabase* pDb = nullptr);

private:
	AcDbCustomDynStyleReactor* m_pReactor = nullptr;
};

#include "IcArxPackPop.h"
