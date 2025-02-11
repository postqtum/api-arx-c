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
***     Description: Routines to access sub-entities of selection sets
***
*****************************************************************************/
#pragma once

#include "acarray.h"
#include "acdb.h"
#include "adsdef.h"

class AcDbFullSubentPath;

int acedSSSetSubentTypes(const AcArray<AcDb::SubentType>& types);
int acedSSSubentAdd(const AcDbFullSubentPath& subentity, const ads_name sname, ads_name result);
int acedSSSubentDel(const AcDbFullSubentPath& subentity, const ads_name ss);
int acedSSSubentLength(const ads_name sname, int32_t index, int32_t* len);
int acedSSSubentMemb(const AcDbFullSubentPath& subentity, const ads_name ss);
int acedSSSubentName(const ads_name ss, int32_t entIndex, int32_t subentIndex,
					 AcDbFullSubentPath& subentity);
int acedSSSubentNameX(struct resbuf** rbpp, const ads_name ss, const int32_t entIndex,
					  const int32_t subentIndex, unsigned int flags);
