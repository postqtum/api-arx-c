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

#include "icarx/AcRxValueType.h"
#include "icarx/IAcRxObjectValue.h"
#include "icarx/IAcRxReferenceType.h"
#include "icarx/IAcRxEnumeration.h"
#include "icarx/IAcRxNonBlittableType.h"

#include "acbasedefs.h"
#include <memory.h>
#include <type_traits>
#include "acutasrt.h"
#include "rxclass.h"

class Storage;

#pragma push_macro("new")
#undef new
inline void* operator new(size_t size, Storage* loc)
{
	(void)(size);
	return loc;
}
#pragma pop_macro("new")

#pragma push_macro("delete")
#undef delete
inline void operator delete(void* p, Storage* loc)
{
	(void)(p);
	(void)(loc);
}
#pragma pop_macro("delete")
