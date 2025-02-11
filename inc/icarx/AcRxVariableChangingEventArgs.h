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
***     Description: Declaration of AcRxVariableChangingEventArgs class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AdAChar.h"

#include "AcRxVariableChangedEventArgs.h"

#include "IcArxPackPush.h"

class AcRxImpVariableChangingEventArgs;

class AcRxVariableChangingEventArgs : public AcRxVariableChangedEventArgs
{
public:
	AcRxVariableChangingEventArgs(AcRxImpVariableChangingEventArgs*);

	ACDBCORE2D_PORT Acad::ErrorStatus setNewValue(const resbuf& value, void* ownerId = nullptr);
	ACDBCORE2D_PORT bool isResetting() const;
	ACDBCORE2D_PORT void veto(const ACHAR* failReason);
};

#include "IcArxPackPop.h"
