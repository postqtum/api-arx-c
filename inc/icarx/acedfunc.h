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
***     Description: ADS function support routines
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../adsdef.h"

int acedRegFunc(int (*fhdl)(void), int fcode);

int acedUsrBrk(void);

int acedDefun(const ACHAR* pszName, int nFuncNum);
int acedDefunEx(const ACHAR* pszGlobalName, const ACHAR* pszLocalName, int nFuncNum);

int acedSetFunHelp(const ACHAR* pszFunctionName, const ACHAR* pszHelpfile, const ACHAR* pszTopic,
				   int iCmd);

int acedUndef(const ACHAR* sname, int nFuncNum);

int acedGetFunCode(void);
struct resbuf* acedGetArgs(void);

int acedRetList(const struct resbuf* rbuf);
int acedRetVal(const struct resbuf* rbuf);
int acedRetPoint(const ads_point pt);
int acedRetStr(const ACHAR* s);
int acedRetName(const ads_name aname, int type);
int acedRetInt(int ival);
int acedRetReal(ads_real rval);
int acedRetT(void);
int acedRetNil(void);
int acedRetVoid(void);

int acedInvoke(const struct resbuf* args, struct resbuf** result);
