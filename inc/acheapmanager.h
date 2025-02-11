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

#include "PAL/api/heap.h"
#include "acbasedefs.h"

ACBASE_PORT void* acStackHeapAlloc(size_t size, const void* pParent);
ACBASE_PORT void acStackHeapFree(void* p);
ACBASE_PORT void* acStackHeapRealloc(void* p, size_t size);

#pragma push_macro("new")
#undef new
#pragma push_macro("delete")
#undef delete

#include "icarx/IcArxPackPush.h"

class AcStackAllocator
{
protected:
	static void operator delete(void* p) { return acStackHeapFree(p); }

public:
	virtual ~AcStackAllocator() = 0
	{
	}
	static void* operator new(size_t size, void* pParent)
	{
		return acStackHeapAlloc(size, pParent);
	}
	static void operator delete(void* p, void* pParent)
	{
		(void)(pParent);
		return acStackHeapFree(p);
	}

	static void deallocate(AcStackAllocator* p, void* pParent)
	{
		p->~AcStackAllocator();
		AcStackAllocator::operator delete(p, pParent);
	}
};

#include "icarx/IcArxPackPop.h"

#pragma pop_macro("delete")
#pragma pop_macro("new")
