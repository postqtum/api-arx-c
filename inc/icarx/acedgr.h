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
***     Description: AcEd graphics related routines
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"


int acedRedraw(const ads_name ent, int mode);
int acedOsnap(const ads_point pt, const ACHAR* mode, ads_point result);
int acedGrRead(int track, int* type, struct resbuf* result);
int acedGrText(int box, const ACHAR* text, int hl);
int acedGrDraw(const ads_point from, const ads_point to, int color, int hl);
int acedGrVecs(const struct resbuf* vlist, ads_matrix mat);
int acedXformSS(const ads_name ssname, ads_matrix genmat);
int acedDragGen(const ads_name ss, const ACHAR* pmt, int cursor,
				int (*scnf)(ads_point pt, ads_matrix mt), ads_point p);
int acedSetView(const struct resbuf* view, int vport);
