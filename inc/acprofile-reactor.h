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

#include "AdAChar.h"
#include "AcCoreDefs.h"

#include "icarx/IcArxPackPush.h"

class AcApProfileManagerReactor
{
public:
	ACCORE_PORT virtual ~AcApProfileManagerReactor();

	virtual void currentProfileChanged(const ACHAR* /*newProfile*/) {}
	virtual void currentProfileWillBeReset(const ACHAR* /*currentProfile*/) {}
	virtual void currentProfileWillBeSaved(const ACHAR* /*currentProfile*/) {}
	virtual void currentProfileWillChange(const ACHAR* /*newProfile*/) {}
	virtual void currentProfileReset(const ACHAR* /*currentProfile*/) {}
	virtual void currentProfileSaved(const ACHAR* /*currentProfile*/) {}
	virtual void profileReset(const ACHAR* /*profileName*/) {}
	virtual void profileSaved(const ACHAR* /*profileName*/) {}
	virtual void profileWillBeSaved(const ACHAR* /*profileName*/) {}
	virtual void profileWillReset(const ACHAR* /*profileName*/) {}
};

#include "icarx/IcArxPackPop.h"
