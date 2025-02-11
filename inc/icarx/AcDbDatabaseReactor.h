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
***     Description: Declaration of AcDbEntityReactor class
***
*****************************************************************************/
#pragma once

#include "../dbidar.h"
#include "../AcDbCore2dDefs.h"
#include "../rxobject.h"

class AcDbDatabase;
class AcDbObject;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDatabaseReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbDatabaseReactor);

	ACDBCORE2D_PORT virtual ~AcDbDatabaseReactor();

	virtual void goodbye(const AcDbDatabase*) {}
	virtual void headerSysVarChanged(const AcDbDatabase*, const ACHAR* /*name*/, bool /*bSuccess*/)	{}
	virtual void headerSysVarWillChange(const AcDbDatabase*, const ACHAR* /*name*/) {}
	virtual void objectAppended(const AcDbDatabase*, const AcDbObject*) {}
	virtual void objectErased(const AcDbDatabase*, const AcDbObject*, bool /*bErased*/) {}
	virtual void objectModified(const AcDbDatabase*, const AcDbObject*) {}
	virtual void objectOpenedForModify(const AcDbDatabase*, const AcDbObject*) {}
	virtual void objectReAppended(const AcDbDatabase*, const AcDbObject*) {}
	virtual void objectUnAppended(const AcDbDatabase*, const AcDbObject*) {}
	virtual void proxyResurrectionCompleted(const AcDbDatabase*, const ACHAR* /*appname*/,
											AcDbObjectIdArray& /*objects*/){}
};

#include "IcArxPackPop.h"
