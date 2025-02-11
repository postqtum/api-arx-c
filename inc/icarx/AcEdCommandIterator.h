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
***     Description: Declaration of AcEdCommandIterator class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

class AcEdCommand;

#include "IcArxPackPush.h"

class AcEdCommandIterator : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcEdCommandIterator);

	virtual const AcEdCommand* command() const = 0;
	virtual const ACHAR* commandGroup() const = 0;
	virtual bool done() const = 0;
	virtual bool next() = 0;
};

#include "IcArxPackPop.h"
