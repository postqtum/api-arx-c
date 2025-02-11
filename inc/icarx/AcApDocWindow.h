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
***     Description: Declaration of AcApDocWindow class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"
#include "../AcApWindow.h"

class AcRxObject;
class AcApDocWindowReactor;

#include "IcArxPackPush.h"

class AcApDocWindow : public AcApWindow
{
	friend class AcApDocWindowImp;

private:
	AcApDocWindow& operator=(const AcApDocWindow&) = delete;
	AcApDocWindow(const AcApDocWindow&) = delete;

protected:
	ACAD_PORT virtual void onActivate();
	ACAD_PORT virtual void onCreate(HWND hWnd);
	ACAD_PORT virtual void onDestroy();
	ACAD_PORT virtual void onLoad();
	ACAD_PORT virtual void onUpdate();
	ACAD_PORT virtual void setDocument(AcRxObject* document);

public:
	ACAD_PORT AcApDocWindow();
	ACAD_PORT virtual ~AcApDocWindow() noexcept;

	ACAD_PORT AcRxObject* document();
	ACAD_PORT bool canClose() const;
	ACAD_PORT bool isFloating() const;
	ACAD_PORT const ACHAR* title() const;
	ACAD_PORT virtual HWND windowHandle();
	ACAD_PORT void activate();
	ACAD_PORT void addReactor(AcApDocWindowReactor* reactor);
	ACAD_PORT void close();
	ACAD_PORT void enable(bool bEnable);
	ACAD_PORT void removeReactor(AcApDocWindowReactor* reactor);
	ACAD_PORT void setCanClose(bool bCanClose);
	ACAD_PORT void setTitle(const ACHAR* title);
};

#include "IcArxPackPop.h"
