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
***     Description: Declaration of AcDMMReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

class AcDMMSheetReactorInfo;
class AcDMMEntityReactorInfo;

#include "IcArxPackPush.h"

class AcDMMReactor : public AcRxObject
{
protected:
	AcDMMReactor() = default;

public:
	virtual ~AcDMMReactor() = default;

	virtual void OnBeginEntity(AcDMMEntityReactorInfo* pInfo) {}
	virtual void OnBeginSheet(AcDMMSheetReactorInfo* pInfo) {}
	virtual void OnEndEntity(AcDMMEntityReactorInfo* pInfo) {}
	virtual void OnEndSheet(AcDMMSheetReactorInfo* pInfo) {}
};

#include "IcArxPackPop.h"

void AcGlobAddDMMReactor(AcDMMReactor* pReactor);
void AcGlobRemoveDMMReactor(AcDMMReactor* pReactor);

typedef void(__cdecl* ACGLOBADDDMMREACTOR)(AcDMMReactor* pReactor);
typedef void(__cdecl* ACGLOBREMOVEDMMREACTOR)(AcDMMReactor* pReactor);
