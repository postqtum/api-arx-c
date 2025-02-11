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
***     Description: Declaration of AcRxSharedObject class
***
*****************************************************************************/
#pragma once

#include "acbasedefs.h"
#include "PAL/api/def.h"
#include "adesk.h"
#include "pimplapi.h"
#include "AcHeapOpers.h"
#include <memory>

#undef PAL

namespace Autodesk
{
namespace AutoCAD
{
namespace PAL
{
class AcRxSharedObjImp;
}
}  // namespace AutoCAD
}  // namespace Autodesk

#include "icarx/IcArxPackPush.h"

class AcRxSharedObject
		: public Pimpl::ApiPart<AcHeapOperators, Autodesk::AutoCAD::PAL::AcRxSharedObjImp>
{
private:
	AcRxSharedObject(Autodesk::AutoCAD::PAL::AcRxSharedObjImp*);
	AcRxSharedObject(const wchar_t*) = delete;
	AcRxSharedObject(const AcRxSharedObject& from) = delete;
	AcRxSharedObject& operator=(const AcRxSharedObject& from) = delete;

public:
	ACBASE_PORT AcRxSharedObject();
	ACBASE_PORT AcRxSharedObject(void* nativeHandle);
	ACBASE_PORT AcRxSharedObject(AcRxSharedObject&& from);
	ACBASE_PORT ~AcRxSharedObject();
	ACBASE_PORT AcRxSharedObject& operator=(AcRxSharedObject&& from);

	ACBASE_PORT bool isLoaded() const noexcept;
	ACBASE_PORT static AcRxSharedObject tryLoad(const wchar_t* path, bool autoRelease = true);
	ACBASE_PORT void* getSymbol(const char* name) const noexcept;
};

#include "icarx/IcArxPackPop.h"
