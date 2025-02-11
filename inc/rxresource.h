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
***     Description: Declaration of AcRxResourceInstance class
***
*****************************************************************************/
#pragma once

#include "acbasedefs.h"
#include "PAL/api/def.h"
#include "adesk.h"
#include "pimplapi.h"
#include "AcHeapOpers.h"

class AcString;
class AcLocale;

#define ACBASE_NON_CROSSPLATFORM

#undef PAL

namespace Autodesk
{
namespace AutoCAD
{
namespace PAL
{
class AcRxResourceInstanceImp;
}
}  // namespace AutoCAD
}  // namespace Autodesk

#include "icarx/IcArxPackPush.h"

class AcRxResourceInstance
		: public Pimpl::ApiPart<AcHeapOperators, Autodesk::AutoCAD::PAL::AcRxResourceInstanceImp>
{
public:
	ACBASE_PORT AcRxResourceInstance(const AcLocale& locale, const wchar_t* resDllName);
	ACBASE_PORT explicit AcRxResourceInstance(const wchar_t* path);
	ACBASE_PORT ACBASE_NON_CROSSPLATFORM AcRxResourceInstance(void* hInst);
	ACBASE_PORT AcRxResourceInstance(AcRxResourceInstance&&) = delete;
	ACBASE_PORT AcRxResourceInstance(const AcRxResourceInstance& other);
	ACBASE_PORT ~AcRxResourceInstance();
	AcRxResourceInstance& operator=(AcRxResourceInstance&&) = delete;
	AcRxResourceInstance& operator=(const AcRxResourceInstance& other) = delete;

	ACBASE_PORT bool isLoaded() const noexcept;
	ACBASE_PORT bool loadDataResource(int32_t id, unsigned long& resourceSize,
						  const void*& data) const noexcept;
	ACBASE_PORT bool tryLoadString(int32_t id, AcString& out) const noexcept;
	ACBASE_PORT static const AcRxResourceInstance& empty();
	ACBASE_PORT void freeDataResource(const void*& data) const noexcept;
};

#include "icarx/IcArxPackPop.h"
