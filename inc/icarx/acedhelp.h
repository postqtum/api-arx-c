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
***     Description: Online help support routines
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

int acedHelp(const ACHAR* szFilename, const ACHAR* szTopic, int iCmd);
int acedHelpForExternal(const ACHAR* pszFunctionName);

#define HELP_CONTENTS 0x0003L
#define HELP_HELPONHELP 0x0004L
#define HELP_PARTIALKEY 0x0105L
