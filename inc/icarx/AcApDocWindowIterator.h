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
***     Description: Declaration of AcApDocWindowIterator class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"

class AcApDocWindow;
class AcApDocWindowIteratorImp;

#include "IcArxPackPush.h"

class AcApDocWindowIterator
{
	friend class AcApDocWindowManagerImp;

private:
	AcApDocWindowIteratorImp* m_pImp;

private:
	AcApDocWindowIterator();

public:
	ACAD_PORT ~AcApDocWindowIterator();

	ACAD_PORT AcApDocWindow* current();
	ACAD_PORT bool done() const;
	ACAD_PORT void step();
};

#include "IcArxPackPop.h"
