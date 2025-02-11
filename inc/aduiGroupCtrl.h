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
***     Description: Common defines for CAdUiGroupCtrl class
***
*****************************************************************************/
#pragma once

#include "icarx/CAdUiGroupCtrl.h"

#define ADUI_NCHT_BASE (HTHELP + 200)
#define ADUI_NCHT_TITLE ADUI_NCHT_BASE
#define ADUI_NCHT_CHEVRON (ADUI_NCHT_BASE + 1)
#define ADUI_NCHT_BUTTON (ADUI_NCHT_BASE + 2)

#define ADUI_GROUP_BORDER_SIZE 1
#define ADUI_GROUP_TITLE_HEIGHT 22
#define ADUI_GROUP_TITLE_BEVELSIZE 5
#define ADUI_GROUP_TITLE_TEXTLEFT 8
#define ADUI_GROUP_TITLE_TEXTTOP 1
#define ADUI_GROUP_TITLE_TEXTBOTTOM 5
#define ADUI_GROUP_BUTTON_SIZE 14
#define ADUI_GROUP_BUTTONS_RIGHT 25
#define ADUI_GROUP_CHEVRON_TOPPADDING 5
#define ADUI_GROUP_CHEVRON_BOTTOMPADDING 4
#define ADUI_GROUP_BUTTON_TOPPADDING 2
#define ADUI_GROUP_BUTTON_BOTTOMPADDING 2
#define ADUI_GROUP_BUTTON_SPACE 3
#define ADUI_GROUP_CHEVRON_RIGHT 4
#define ADUI_GROUP_EXPANDER_RIGHT_OFFSET 7
#define ADUI_GROUP_CHILD_VERT_SPACE 8

#define ADUI_GROUP_BUTTON_DISABLE_FLAG 0x80000000
#define ADUI_GROUP_BUTTON_SELECTED_FLAG 0x40000000
#define ADUI_GROUP_BUTTON_ID_MASK 0x0000FFFF
#define ADUI_GROUP_STYLE_CHEVRON 0x00000001
#define ADUI_GROUP_STYLE_SHOWBTNFORCE 0x00000002
#define ADUI_GROUP_STYLE_NONACTIVE 0x00000004
#define ADUI_GROUP_STYLE_NOBORDER 0x00000008
#define ADUI_GROUP_STYLE_TRANSBTN 0x00000010
#define ADUI_GROUP_STYLE_BTNBORDER 0x00000020
#define ADUI_GROUP_STYLE_ACTIVEHEADER 0x00000040
#define ADUI_GROUP_STYLE_OPAQUEIMAGE 0x00000080
#define ADUI_GROUP_STYLE_STRETCHIMAGE 0x00000100

const DWORD WM_ADUI_VISIBILITY_CHANGING = WM_USER + 1936;
