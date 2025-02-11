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
***     Description: Declaration of AcApDocWindowManagerReactor class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"

class AcApDocWindow;

#include "IcArxPackPush.h"

class ACAD_PORT AcApDocWindowManagerReactor
{
public:
	virtual void documentWindowActivated(AcApDocWindow* window);
	virtual void documentWindowCreated(AcApDocWindow* window);
	virtual void documentWindowDestroyed(AcApDocWindow* window);
	virtual void documentWindowDocked(AcApDocWindow* window);
	virtual void documentWindowFloated(AcApDocWindow* window);
	virtual void documentWindowMoved(AcApDocWindow* window, int newIndex, int oldIndex);
	virtual void documentWindowReplaced(AcApDocWindow* newWindow, AcApDocWindow* oldWindow);
};

#include "IcArxPackPop.h"
