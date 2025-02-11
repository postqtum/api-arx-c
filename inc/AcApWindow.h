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
***     Description:
***
*****************************************************************************/
#pragma once

#include "accoredefs.h"
#include "IAdHostWindow.h"

class AcApWindowImp;

#include "icarx/IcArxPackPush.h"

class ACCORE_PORT AcApWindow : public IAdHostWindow
{
	friend class AcApWindowImp;

protected:
	AcApWindowImp* m_pImp = nullptr;

protected:
	AcApWindow();
	virtual ~AcApWindow();

	virtual bool subPostRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,
									 IcArx::Integers::LongPtr& lResult);
	virtual bool subPreRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,
									IcArx::Integers::LongPtr& lResult);
	virtual bool subRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,
								 IcArx::Integers::LongPtr& lResult);

public:
	bool postRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,
						  IcArx::Integers::LongPtr& lResult);
	bool preRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,
						 IcArx::Integers::LongPtr& lResult);
	bool routeMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,
					  IcArx::Integers::LongPtr& lResult);
};

#include "icarx/IcArxPackPop.h"
