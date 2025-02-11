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
***     Description: point manipulation routines
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"

int acedTrans(const ads_point pt, const struct resbuf* from, const struct resbuf* to, int disp,
			  ads_point result);

int acdbInters(const ads_point from1, const ads_point to1, const ads_point from2,
			   const ads_point to2, int teston, ads_point result);
