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

#include "adesk.h"
#include "acheapmanager.h"
#include  <new>

#undef new
#undef delete

class AcHeapOperators
{
private:
	static void* allocate(size_t size)
	{
		void* p = ::acHeapAlloc(nullptr, size);
		if (p)
		{
			return p;
		}
		throw std::bad_alloc();
	}

	static void deallocate(void* p)
	{
		if (p)
		{
			::acHeapFree(nullptr, p);
		}
	}

public:
	static void* operator new(size_t size) { return allocate(size); }
	static void* operator new(size_t size, const char*, int) { return allocate(size); }
	static void* operator new[](size_t size) { return allocate(size); }
	static void* operator new[](size_t size, const char*, int) { return allocate(size); }
	static void operator delete(void* p) { deallocate(p); }
	static void operator delete(void* p, const char*, int) { deallocate(p); }
	static void operator delete[](void* p) { deallocate(p); }
	static void operator delete[](void* p, const char*, int) { deallocate(p); }
};
