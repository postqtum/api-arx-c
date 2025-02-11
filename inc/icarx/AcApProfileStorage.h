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
***     Description: Declaration of AcApProfileStorage class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"
#include "../acadstrc.h"

struct IUnknown;

#include "IcArxPackPush.h"

class AcApProfileStorage
{
public:
	virtual ~AcApProfileStorage() = default;

	virtual Acad::ErrorStatus CreateNode(const ACHAR* pszNodePath, IUnknown*& pUnknown) = 0;
	virtual Acad::ErrorStatus DeleteNode(const ACHAR* pszNodePath) = 0;
	virtual Acad::ErrorStatus GetNode(const ACHAR* pszNodePath, IUnknown*& pUnknown) = 0;
	virtual Acad::ErrorStatus GetStorageFile(AcString& pszFile) = 0;
	virtual Acad::ErrorStatus ReplaceNode(const ACHAR* pszNodePath, IUnknown* pUnknown) = 0;
	virtual Acad::ErrorStatus Save() = 0;
};

#include "IcArxPackPop.h"
