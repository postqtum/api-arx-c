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
***     Description: Declaration of AcDbRecover and AcDbRecoverCallBack classes
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

class AcDbDatabase;
class AcDbImpRecoverCallBack;

#include "IcArxPackPush.h"

class AcDbRecover
{
public:
	virtual int callBack(AcDbDatabase*) = 0;
};

class AcDbRecoverCallBack
{
private:
	AcDbImpRecoverCallBack* mpImpRecoverCallBack;

public:
	AcDbRecoverCallBack();
	virtual ~AcDbRecoverCallBack();

	virtual Acad::ErrorStatus registerCallBack(AcDbRecover*);
	virtual Acad::ErrorStatus removeCallBack();
};

#include "IcArxPackPop.h"
