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
***     Description: Declaration of AcDbEntityParallelDrawPE and AcGiContextParallelDrawPE classes
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

class AcDbEntity;
class AcDbDwgFiler;
class AcGiContext;

#include "IcArxPackPush.h"

class AcDbEntityParallelDrawPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbEntityParallelDrawPE, ACDBCORE2D_PORT);

	virtual bool prepareForParallelDraw(AcDbEntity* pEnt, AcDbDwgFiler* pFiler) const = 0;
};

class AcGiContextParallelDrawPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiContextParallelDrawPE, ACDBCORE2D_PORT);

	virtual AcDbDwgFiler* entityDataFiler(AcGiContext* pCtx) const = 0;
};

#include "IcArxPackPop.h"
