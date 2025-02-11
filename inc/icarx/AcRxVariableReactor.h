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
***     Description: Declaration of AcRxVariableReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

#include "AcRxVariable.h"
#include "AcRxVariableChangingEventArgs.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxVariableReactor : public AcRxObject
{
public:
	virtual void changed(const AcRxVariable* sender, const AcRxVariableChangedEventArgs& args) {}
	virtual void changing(const AcRxVariable* sender, AcRxVariableChangingEventArgs& args) {}
};

#include "IcArxPackPop.h"
