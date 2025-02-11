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

#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbClassIterator
{
public:
	enum
	{
		kAllClasses = 1,
		kCustomClasses = 2,
		kProxyClasses = 4
	};

protected:
	AcDbClassIterator();
	virtual ~AcDbClassIterator();

public:
	virtual const ACHAR* appName() const = 0;
	virtual void detach() = 0;
	virtual bool done() const = 0;
	virtual const ACHAR* dxfName() const = 0;
	virtual bool isEntity() const = 0;
	virtual bool isProxy() const = 0;
	virtual const ACHAR* name() const = 0;
	virtual bool next() = 0;
	virtual uint32_t numInstances() const = 0;
	virtual Acad::ErrorStatus start(AcDbDatabase* pDb, int nFlags) = 0;
	ACDBCORE2D_PORT static void deleteIterator(AcDbClassIterator* pIter);
	ACDBCORE2D_PORT static AcDbClassIterator* newIterator();
};

#include "icarx/IcArxPackPop.h"
