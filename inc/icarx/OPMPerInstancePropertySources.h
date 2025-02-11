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
***     Description: Declaration of OPMPerInstancePropertySources class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acdbport.h"

interface IPropertySource;

#include "IcArxPackPush.h"

class OPMPerInstancePropertySources : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(OPMPerInstancePropertySources, ACDB_PORT);
	~OPMPerInstancePropertySources() = default;

	virtual IPropertySource* GetPropertySourceAt(const BSTR* pName) = 0;
	virtual bool GetPropertySourceNames(VARIANT* pNames) = 0;
	virtual bool RemovePropertySourceAt(const BSTR* pName) = 0;
	virtual bool SetPropertySourceAt(const BSTR* pName, IPropertySource* pSource) = 0;
};

#include "IcArxPackPop.h"
