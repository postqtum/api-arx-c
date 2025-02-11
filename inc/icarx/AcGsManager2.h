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
***     Description: Declaration of AcGsManager2 class
***
*****************************************************************************/
#pragma once

#include "AcGsManager.h"

#include "IcArxPackPush.h"

class AcGsManager2 : public AcGsManager
{
public:
	virtual bool activeGraphicsKernels(AcArray<AcGsGraphicsKernel*>& result) const = 0;
	virtual bool activeModels(AcArray<AcGsModel*>& result) const = 0;
	virtual bool activeModels(const AcDbDatabase* pDb, AcArray<AcGsModel*>& result) const = 0;
	virtual AcGsModel* gsModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb) const = 0;
	virtual void setGsHighlightModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb,
									 AcGsModel* pModel) = 0;
	virtual bool hasGsModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb) const = 0;
	virtual void setGsModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb,
							AcGsModel* pModel) = 0;
	virtual AcGsModel* gsHighlightModel(AcGsGraphicsKernel* pKernel,
										const AcDbDatabase* pDb) const = 0;
};

#include "IcArxPackPop.h"
