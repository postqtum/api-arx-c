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
***     Description: Declaration of AcDbObjectReactor class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../rxobject.h"
#include "../dbid.h"

class AcDbObject;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbObjectReactor : public AcRxObject
{
protected:
	ACDBCORE2D_PORT AcDbObjectReactor();

public:
	ACRX_DECLARE_MEMBERS(AcDbObjectReactor);

	ACDBCORE2D_PORT virtual ~AcDbObjectReactor();

	virtual void cancelled(const AcDbObject*) {}
	virtual void copied(const AcDbObject*, const AcDbObject* /*newObj*/) {}
	virtual void erased(const AcDbObject*, bool /*bErasing*/) {}
	virtual void goodbye(const AcDbObject*) {}
	virtual void modified(const AcDbObject*) {}
	virtual void modifiedXData(const AcDbObject*) {}
	virtual void modifyUndone(const AcDbObject*) {}
	virtual void objectClosed(const AcDbObjectId) {}
	virtual void openedForModify(const AcDbObject*) {}
	virtual void reappended(const AcDbObject*) {}
	virtual void subObjModified(const AcDbObject*, const AcDbObject* /*subObj*/) {}
	virtual void unappended(const AcDbObject*) {}
};

#include "IcArxPackPop.h"
