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
***     Description: AcEd entity selection support routines
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"
#include "../AdAChar.h"
#include "../adsdef.h"

int acedEntSel(const ACHAR* str, ads_name entres, ads_point ptres);
#ifdef __cplusplus
class AcSelectionPreview;
ACCORE_PORT int acedEntSel(const ACHAR* str, ads_name entres, ads_point ptres,
						   AcSelectionPreview* pSelectionPreview);
#endif
int acedNEntSel(const ACHAR* str, ads_name entres, ads_point ptres, ads_point xformres[4],
				struct resbuf** refstkres);
int acedNEntSelP(const ACHAR* str, ads_name entres, ads_point ptres, int pickflag,
				 ads_matrix xformres, struct resbuf** refstkres);
int acedSSGet(const ACHAR* str, const void* pt1, const void* pt2, const struct resbuf* filter,
			  ads_name ss);
#ifdef __cplusplus
ACCORE_PORT int acedSSGet(const ACHAR* str, const void* pt1, const void* pt2,
						  const struct resbuf* filter, ads_name ss,
						  AcSelectionPreview* pSelectionPreview);
#endif
int acedSSGetFirst(struct resbuf** gset, struct resbuf** pset);
int acedSSSetFirst(const ads_name pset, const ads_name unused);
int acedSSFree(const ads_name sname);
#ifdef __cplusplus
int acedSSLength(const ads_name sname, int32_t* len);
#else
int acedSSLength(const ads_name sname, long* len);
#endif
int acedSSAdd(const ads_name ename, const ads_name sname, ads_name result);
int acedSSDel(const ads_name ename, const ads_name ss);
int acedSSMemb(const ads_name ename, const ads_name ss);
int acedSSName(const ads_name ss, int i, ads_name entres);
int acedSSNameX(struct resbuf** rbpp, const ads_name ss, int i);
int acedSSNameXEx(struct resbuf** rbpp, const ads_name ss, int i, unsigned int flags);

int acedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const ACHAR*));
int acedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const ACHAR*));
int acedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const ACHAR*));
int acedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const ACHAR*));
