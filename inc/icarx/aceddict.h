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
***     Description: Dictionary objects manipulation routines
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"

struct resbuf* acdbTblNext(const ACHAR* tblname, int rewind);
struct resbuf* acdbTblSearch(const ACHAR* tblname, const ACHAR* sym, int setnext);
int acdbNamedObjDict(ads_name result);
struct resbuf* acdbDictSearch(const ads_name dict, const ACHAR* sym, int setnext);
struct resbuf* acdbDictNext(const ads_name dict, int rewind);
int acdbDictRename(const ads_name dictname, const ACHAR* oldsym, const ACHAR* newsym);
int acdbDictRemove(const ads_name dictname, const ACHAR* symname);
int acdbDictAdd(const ads_name dictname, const ACHAR* symname, const ads_name newobj);

int acdbTblObjName(const ACHAR* tblname, const ACHAR* sym, ads_name result);

int acdbSNValid(const ACHAR* tbstr, int pipetest);
