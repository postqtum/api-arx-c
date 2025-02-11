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
***     Description: Memory manipulation routines
***
*****************************************************************************/
#pragma once

#include <stddef.h>
#include "AdAChar.h"
#include "AcDbCore2dDefs.h"

ACDBCORE2D_PORT size_t acad__msize(void* p);
ACDBCORE2D_PORT ACHAR* acad__strdup(const ACHAR* p);
ACDBCORE2D_PORT void* acad_malloc(size_t size);
ACDBCORE2D_PORT void* acad_calloc(size_t num, size_t size);
ACDBCORE2D_PORT void acad_free(void* p);
ACDBCORE2D_PORT void* acad_realloc(void* p, size_t size);
