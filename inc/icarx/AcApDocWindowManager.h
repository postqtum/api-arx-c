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
***     Description: Declaration of AcApDocWindowManager class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"

class AcApDocWindow;
class AcApDocWindowIterator;
class AcApDocWindowManagerImp;
class AcApDocWindowManagerReactor;

#include "IcArxPackPush.h"

class AcApDocWindowManager
{
	friend class AcApDocWindowManagerImp;

private:
	AcApDocWindowManagerImp* m_pImp;

private:
	AcApDocWindowManager();
	~AcApDocWindowManager();

public:
	ACAD_PORT AcApDocWindow* activeDocumentWindow();
	ACAD_PORT bool addDocumentWindow(AcApDocWindow* docWindow);
	ACAD_PORT void addReactor(AcApDocWindowManagerReactor* pReactor);
	ACAD_PORT int documentWindowCount() const;
	ACAD_PORT bool moveDocumentWindow(AcApDocWindow* docWindow, int newIndex);
	ACAD_PORT AcApDocWindowIterator* newIterator() const;
	ACAD_PORT void removeReactor(AcApDocWindowManagerReactor* pReactor);
};

#include "IcArxPackPop.h"

ACAD_PORT AcApDocWindowManager* acDocWindowManagerPtr();
#define acDocWindowManager acDocWindowManagerPtr()
