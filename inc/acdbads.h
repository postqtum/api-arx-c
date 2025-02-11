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

#include "adsdef.h"
#include "acmem.h"
#include "AdAChar.h"

#ifdef __cplusplus
#	include "adesk.h"
#	include "AcDbCore2dDefs.h"
#endif

void acdbFail(const ACHAR* str);
int acdbHandEnt(const ACHAR* handle, ads_name entres);

#ifdef __cplusplus

ACDBCORE2D_PORT int acdbXdRoom(const ads_name ent, int32_t* result);
ACDBCORE2D_PORT int acdbXdSize(const resbuf* rb, int32_t* result);

#endif

#ifdef __STDC__
#	define acdbNameSet(from, to) (memcpy(to, from, sizeof(ads_name)))
#	define acdbPointSet(from, to) (memcpy(to, from, sizeof(ads_point)))
#else
#	define acdbNameSet(from, to) (*(to) = *(from), (to)[1] = (from)[1])
#	define acdbPointSet(from, to) (*(to) = *(from), (to)[1] = (from)[1], (to)[2] = (from)[2])
#endif /* !__STDC__ */

#define acdbNameClear(name) name[0] = name[1] = 0
#define acdbNameNil(name) (name[0] == 0 && name[1] == 0)
#define acdbNameEqual(name1, name2) (name1[0] == name2[0] && name1[1] == name2[1])
