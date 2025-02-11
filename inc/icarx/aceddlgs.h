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
***     Description: AcEd support for various dialogs
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../adsdef.h"

int acedGetFileD(const ACHAR* title, const ACHAR* defawlt, const ACHAR* ext, int flags,
				 struct resbuf* result);
int acedGetFileNavDialog(const ACHAR* title, const ACHAR* defawlt, const ACHAR* ext,
						 const ACHAR* dlgname, int flags, struct resbuf** result);

int acedTextBox(const struct resbuf* args, ads_point pt1, ads_point pt2);

int acedTablet(const struct resbuf* args, struct resbuf** result);
