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
***     Description: Declaration of OPMPropertyExtension class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acdbport.h"

interface IPropertyManager;

#include "IcArxPackPush.h"

class OPMPropertyExtension : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(OPMPropertyExtension, ACDB_PORT);
	~OPMPropertyExtension() = default;

	virtual IPropertyManager* GetPropertyManager() = 0;
	virtual void SetPropertyManager(IPropertyManager* pPropManager) = 0;
};

#include "IcArxPackPop.h"
