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

#include "icarx/HtmlWindowOptions.h"

#include "AdAChar.h"

class CAdUiPaletteSet;
class AcApDocWindow;

AcApDocWindow* acedAddHTMLDocWindow(const ACHAR* title, const ACHAR* uriOfHtmlPage);
int acedAddHTMLPalette(CAdUiPaletteSet* ps, const ACHAR* name, const ACHAR* uriOfHtmlPage);
bool acedShowHTMLModalWindow(HWND owner, const ACHAR* uriOfHtmlPage,
							 bool persistSizeAndPosition = true);
bool acedShowHTMLModalWindow(HWND owner, const ACHAR* uriOfHtmlPage, HtmlWindowOptions opts);
HWND acedShowHTMLModelessWindow(HWND owner, const ACHAR* uriOfHtmlPage,
								bool persistSizeAndPosition = true);
