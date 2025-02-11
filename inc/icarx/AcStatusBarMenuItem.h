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
***     Description: Declaration of AcStatusBarMenuItem class
***
*****************************************************************************/
#pragma once

class CMenu;

#include "IcArxPackPush.h"

class AcStatusBarMenuItem
{
public:
	enum AcStatusBarType
	{
		kApplicationStatusBar = 0,
		kDrawingStatusBar = 1
	};

public:
	AcStatusBarMenuItem();
	virtual ~AcStatusBarMenuItem();

	virtual BOOL CustomizeMenu(AcStatusBarType nType, CMenu* pMenu, UINT nStartCmdId,
											 UINT nEndCmdId);
	virtual BOOL InvokeMenuCommand(AcStatusBarType nType, UINT nCmdId);
};

#include "IcArxPackPop.h"
