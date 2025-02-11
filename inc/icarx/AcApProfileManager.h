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
***     Description: Declaration of AcApProfileManager class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"
#include "../AdAChar.h"
#include "../acadstrc.h"

class AcApProfileStorage;
class AcApProfileManagerReactor;

using AcApProfileNameArray = AcArray<ACHAR*>;

#include "IcArxPackPush.h"

class AcApProfileManager
{
public:
	virtual ~AcApProfileManager() = default;

	virtual Acad::ErrorStatus FixedProfileStorage(AcApProfileStorage*& pStore,
												  BOOL bCreateIfNotExists = TRUE) = 0;
	virtual Acad::ErrorStatus ProfileCopy(const ACHAR* newProfileName, const ACHAR* oldProfileName,
										  const ACHAR* newProfileDesc) = 0;
	virtual Acad::ErrorStatus ProfileDelete(const ACHAR* strProfileName) = 0;
	virtual Acad::ErrorStatus ProfileExport(const ACHAR* strProfileName,
											const ACHAR* exportFileName) = 0;
	virtual Acad::ErrorStatus ProfileImport(const ACHAR* strProfileName,
											const ACHAR* importFileName,
											const ACHAR* profileDescription,
											bool bImportPathInfo) = 0;
	virtual int ProfileListNames(AcApProfileNameArray& nameList) = 0;
	virtual void ProfileRegistryKey(ACHAR*& strRegProfileKey, const ACHAR* strProfileName) = 0;
	virtual Acad::ErrorStatus ProfileRename(const ACHAR* newProfileName,
											const ACHAR* oldProfileName,
											const ACHAR* newProfileDesc) = 0;
	virtual Acad::ErrorStatus ProfileReset(const ACHAR* strProfileName) = 0;
	virtual Acad::ErrorStatus ProfileSetCurrent(const ACHAR* strProfileName) = 0;
	virtual Acad::ErrorStatus ProfileStorage(AcApProfileStorage*& pStore,
											 const ACHAR* strProfileName,
											 BOOL bCreateIfNotExists = TRUE) = 0;
	virtual void addReactor(AcApProfileManagerReactor*) = 0;
	virtual void removeReactor(AcApProfileManagerReactor*) = 0;
};

#include "IcArxPackPop.h"

AcApProfileManager* acProfileManagerPtr();
