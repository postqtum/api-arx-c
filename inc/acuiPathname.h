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

#include "aduiPathname.h"

class AFILE;

#include "icarx/IcArxPackPush.h"

class CAcUiPathname : public CAdUiPathname
{
protected:
	ACCORE_PORT virtual void AssignCopy(const CAcUiPathname&);

public:
	ACCORE_PORT CAcUiPathname();
	ACCORE_PORT CAcUiPathname(const CAcUiPathname&);
	ACCORE_PORT ~CAcUiPathname();
	const CAcUiPathname& operator=(const CAcUiPathname& pathSrc);
	const CAcUiPathname& operator=(const CAcUiPathname* pathSrc);

	ACCORE_PORT PathErr Parse(const wchar_t*, bool wildcard_ok = false) override;
	ACCORE_PORT bool Open(AFILE** fdp, const wchar_t* openmode);
	ACCORE_PORT int Status();
};

#include "icarx/IcArxPackPop.h"

inline const CAcUiPathname& CAcUiPathname::operator=(const CAcUiPathname& pathSrc)
{
	AssignCopy(pathSrc);
	return *this;
}

inline const CAcUiPathname& CAcUiPathname::operator=(const CAcUiPathname* pathSrc)
{
	AssignCopy(*pathSrc);
	return *this;
}
