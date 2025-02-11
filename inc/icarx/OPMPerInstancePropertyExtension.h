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
***     Description: Declaration of OPMPerInstancePropertyExtension class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acdbport.h"

#include "IcArxPackPush.h"

class OPMPerInstancePropertyExtension : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(OPMPerInstancePropertyExtension, ACDB_PORT);
	~OPMPerInstancePropertyExtension() = default;

	virtual bool AddObjectPropertySourceName(const BSTR* pName) = 0;
	virtual bool GetObjectPropertySourceNames(VARIANT* pNames) = 0;
	virtual bool RemoveObjectPropertySourceName(const BSTR* pName) = 0;
};

#include "IcArxPackPop.h"
