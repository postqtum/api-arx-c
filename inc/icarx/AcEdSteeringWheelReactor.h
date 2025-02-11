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
***     Description: Declaration of AcEdSteeringWheelReactor class
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

class AcEdSteeringWheelReactor
{
public:
	virtual void modifyContextMenu(HMENU hMenu) = 0;
	virtual void onBeginOperation() = 0;
	virtual void onBeginShot() = 0;
	virtual void onClose() = 0;
	virtual void onEndOperation() = 0;
	virtual void onEndShot() = 0;
	virtual void onSetCursor(HCURSOR hCursor) = 0;
};

#include "IcArxPackPop.h"
