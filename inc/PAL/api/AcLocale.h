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

#include "def.h"
#include <string>

class AcLocaleImp;

#include "../../icarx/IcArxPackPush.h"

class AcLocale
{
private:
	friend class AcLocaleService;
	AcLocaleImp* m_pImpAcLocale;

public:
	using LocaleId = int;

	ACPAL_PORT AcLocale(const wchar_t* iso2LangName, const wchar_t* iso2CountryName);
	ACPAL_PORT AcLocale(LocaleId lcid);
	ACPAL_PORT AcLocale(AcLocale&& locale);
	ACPAL_PORT AcLocale(const AcLocale& locale);
	ACPAL_PORT ~AcLocale();
	ACPAL_PORT AcLocale& operator=(const AcLocale& locale);
	ACPAL_PORT AcLocale& operator=(AcLocale&& locale);
	ACPAL_PORT bool operator==(const AcLocale& loc) const;
	ACPAL_PORT bool operator!=(const AcLocale& loc) const;
	ACPAL_PORT operator LocaleId();
	ACPAL_PORT bool isValid() const;
	ACPAL_PORT const wchar_t* iso2CountryName() const;
	ACPAL_PORT const wchar_t* iso2LangName() const;
};

#include "../../icarx/IcArxPackPop.h"
