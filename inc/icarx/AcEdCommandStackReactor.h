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
***     Description: Declaration of AcEdCommandStackReactor class
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"
#include "../rxobject.h"

class AcEdCommand;
class AcEdCommandEventArgs;

#include "IcArxPackPush.h"

class AcEdCommandStackReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcEdCommandStackReactor);

	ACCORE_PORT virtual ~AcEdCommandStackReactor();

	virtual void commandAdded(AcEdCommand*, AcEdCommandEventArgs*) {}
	virtual void commandEnded(AcEdCommand*, AcEdCommandEventArgs*) {}
	virtual void commandRemoved(AcEdCommand*, AcEdCommandEventArgs*) {}
	virtual void commandWillStart(AcEdCommand*, AcEdCommandEventArgs*) {}
};

#include "IcArxPackPop.h"
