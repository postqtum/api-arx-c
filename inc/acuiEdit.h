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

#include "icarx/CAcUiEdit.h"
#include "icarx/CAcUiAngleEdit.h"
#include "icarx/CAcUiNumericEdit.h"
#include "icarx/CAcUiStringEdit.h"
#include "icarx/CAcUiSymbolEdit.h"

#include "acui_port.h"
#include "aduiEdit.h"

#define AC_ES_STRING 0x01
#define AC_ES_SYMBOL 0x02
#define AC_ES_NUMERIC 0x04
#define AC_ES_ANGLE 0x08

#define AC_ES_VAL_ONKILLFOCUS 0x10
#define AC_ES_CONV_ONKILLFOCUS 0x20
#define AC_ES_SHOW_ERRMSG 0x40
#define AC_ES_ERRMSG_ALLOWIGNORE 0x80

#define AC_ES_NOZERO 0x100
#define AC_ES_NOBLANK 0x200
#define AC_ES_NONEGATIVE 0x400
#define AC_ES_INRANGE 0x800
