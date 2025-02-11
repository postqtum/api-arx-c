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
***     Description: Declaration of OPMPerInstancePropertyExtensionFactory class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acdbport.h"

class OPMPerInstancePropertyExtension;

#include "IcArxPackPush.h"

class OPMPerInstancePropertyExtensionFactory : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(OPMPerInstancePropertyExtensionFactory, ACDB_PORT);
	~OPMPerInstancePropertyExtensionFactory() = default;

	virtual OPMPerInstancePropertyExtension* CreateOPMPerInstancePropertyExtension(
			AcRxClass* pClass) = 0;
};

#include "IcArxPackPop.h"
