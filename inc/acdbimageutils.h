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
***     Description: Declaration of image utility function(s)
***
*****************************************************************************/
#pragma once

#include "acdbport.h"
#include "AdAChar.h"

#ifndef _WINDEF_
struct HBITMAP__
{
	int unused;
};
typedef struct HBITMAP__* HBITMAP;

struct HPALETTE__
{
	int unused;
};
typedef struct HPALETTE__* HPALETTE;
#endif

ACDB_PORT bool acdbGetPreviewBitmapFromDwg(const ACHAR* pszDwgfilename, HBITMAP* pPreviewBmp,
										   HPALETTE* pRetPal);
