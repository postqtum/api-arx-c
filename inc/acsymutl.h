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

#include <cassert>
#include "acadstrc.h"
#include "dbsymutl.h"

#include "icarx/IcArxAssert.h"

#define ACEDSYMUTIL_SERVICES_CURRENT_VERSION 100
#define ACEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n, v) n##v
#define ACEDSYMUTIL_SERVICESNAME_WITH_VERSION(n, v) ACEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n, v)
#define ACEDSYMUTIL_SERVICES_NAME \
	ACEDSYMUTIL_SERVICESNAME_WITH_VERSION(servicesPtr, ACEDSYMUTIL_SERVICES_CURRENT_VERSION)

class AcDbDatabase;

namespace AcEdSymbolUtilities
{

enum CrSpMode
{
	kCrEndsInput = true,
	kCrSpEndsInput = false
};

enum NameCaseMode
{
	kPreserveCase = true,
	kForceToUpper = false
};

#include "icarx/IcArxPackPush.h"

class Services
{
public:
	enum
	{
		kCurrentVersion = ACEDSYMUTIL_SERVICES_CURRENT_VERSION
	};

public:
	virtual Acad::PromptStatus getCompatibleSymbolString(ACHAR*& pResponse, const ACHAR* prompt,
														 AcDbDatabase* pDb) const = 0;
	virtual Acad::PromptStatus getSymbolString(ACHAR*& pResponse, const ACHAR* prompt,
											   bool onlyCrEndsInput, bool preserveCase) const = 0;
	virtual unsigned version() const = 0;
};

#include "icarx/IcArxPackPop.h"

extern const Services* ACEDSYMUTIL_SERVICES_NAME();

inline const Services* servicesPtr()
{
	const Services* pSymUtil = ACEDSYMUTIL_SERVICES_NAME();
	ICARX_ASSERT(pSymUtil != 0);
	ICARX_ASSERT(pSymUtil->version() == Services::kCurrentVersion);
	return pSymUtil;
}

}  // namespace AcEdSymbolUtilities

namespace AcEdSymUtil = AcEdSymbolUtilities;

using AcEdSymUtilServices = AcEdSymbolUtilities::Services;

inline const AcEdSymUtilServices* acedSymUtil()
{
	return AcEdSymbolUtilities::servicesPtr();
}
