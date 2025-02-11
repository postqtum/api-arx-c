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
***     Description: std::fstream support functions
***
*****************************************************************************/
#pragma once

#include <locale>
#include <fstream>

inline const std::locale& AcFStream_curLocale()
{
	static const std::locale loc(std::locale(), std::locale::classic(), LC_NUMERIC);
	return loc;
}
