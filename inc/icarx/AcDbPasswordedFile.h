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
***     Description: Declaration of AcDbPasswordedFile class
***
*****************************************************************************/
#pragma once

#include "AcDbHostApplicationServices.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbPasswordedFile
{
protected:
	virtual const ACHAR* getFullPath() = 0;
	virtual Acad::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;

public:
	Acad::ErrorStatus open(const wchar_t* wszPassword,
						   AcDbHostApplicationServices::PasswordOptions options);
};

#include "IcArxPackPop.h"
