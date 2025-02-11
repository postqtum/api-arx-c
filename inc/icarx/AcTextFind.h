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
***     Description: Text find API
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../AdAChar.h"
#include "../dbidar.h"

class AcDbDatabase;

#define AC_SRCH_BLOCK 0x01
#define AC_SRCH_DIM_TEXT 0x02
#define AC_SRCH_TEXT 0x04
#define AC_SRCH_LINK_DESC 0x08
#define AC_SRCH_LINK_URL 0x10
#define AC_SRCH_MATCH_CASE 0x20
#define AC_SRCH_WHOLE_WORD 0x40

#define AC_SRCH_DEFAULT 0x1F

bool acdbTextFind(AcDbDatabase* pDatabase, AcDbObjectIdArray& resultSet, const ACHAR* findString,
				  const ACHAR* replaceString = nullptr,
				  uint8_t searchOptions = AC_SRCH_DEFAULT,
				  const AcDbObjectIdArray& selSet = 0);
