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
***     Description: Entity manipulation routines
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"

int acdbEntDel(const ads_name ent);
struct resbuf* acdbEntGetX(const ads_name ent, const struct resbuf* args);
struct resbuf* acdbEntGet(const ads_name ent);
int acdbEntLast(ads_name result);
int acdbEntNext(const ads_name ent, ads_name result);
int acdbEntUpd(const ads_name ent);
int acdbEntMod(const struct resbuf* ent);
int acdbEntMake(const struct resbuf* ent);
int acdbEntMakeX(const struct resbuf* entm, ads_name result);
