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

#include <stddef.h>
#include "../../adesk.h"
#include "def.h"

ACPAL_PORT void* acAllocAligned(size_t alignment, size_t size);
ACPAL_PORT void acFreeAligned(void* p);
ACPAL_PORT size_t acMsizeAligned(void* p, size_t alignment);


typedef void* AcHeapHandle;
ACPAL_PORT AcHeapHandle acHeapCreate(uint32_t flags);
ACPAL_PORT void acHeapDestroy(AcHeapHandle heap);
ACPAL_PORT void* acHeapAlloc(AcHeapHandle heap, size_t size);
ACPAL_PORT void* acTryHeapAlloc(AcHeapHandle heap, size_t size);
ACPAL_PORT void* acHeapReAlloc(AcHeapHandle heap, void* p, size_t size);
ACPAL_PORT size_t acHeapSize(AcHeapHandle heap, const void* p);
ACPAL_PORT bool acHeapValidate(AcHeapHandle heap, const void* p);
ACPAL_PORT void acHeapFree(AcHeapHandle heap, void* p);
