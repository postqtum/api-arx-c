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
***     Description: Declaration of AcRxVariableChangedEventArgs class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

class AcRxImpVariableChangingEventArgs;
struct resbuf;

#include "IcArxPackPush.h"

class AcRxVariableChangedEventArgs
{
	friend class AcRxImpVariableChangingEventArgs;

protected:
	AcRxImpVariableChangingEventArgs* m_pImp;

public:
	AcRxVariableChangedEventArgs(AcRxImpVariableChangingEventArgs*);

	ACDBCORE2D_PORT const resbuf& newValue() const;
	ACDBCORE2D_PORT const resbuf& oldValue() const;
};

#include "IcArxPackPop.h"
