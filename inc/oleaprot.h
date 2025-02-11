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
***     Description: Declaration of AcAxOleLinkManager class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "acdbport.h"
#include "dbmain.h"

struct IUnknown;
struct IDispatch;

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcAxOleLinkManager
{
public:
	virtual IDispatch* GetDocIDispatch(AcDbDatabase* pDatabase) = 0;
	virtual IUnknown* GetIUnknown(AcDbObject* pObject) = 0;
	virtual IUnknown* GetIUnknown(AcDbDatabase* pDatabase) = 0;
	virtual IUnknown* GetIUnknown(AcDbObject* pObject, const AcDbSubentId& id) = 0;
	virtual bool SetDocIDispatch(AcDbDatabase* pDatabase, IDispatch* pDispatch) = 0;
	virtual bool SetIUnknown(AcDbObject* pObject, IUnknown* pUnknown) = 0;
	virtual bool SetIUnknown(AcDbDatabase* pDatabase, IUnknown* pUnknown) = 0;
	virtual bool SetIUnknown(AcDbObject* pObject, const AcDbSubentId& id, IUnknown* pUnknown) = 0;
};

#include "icarx/IcArxPackPop.h"

ACDB_PORT AcAxOleLinkManager* AcAxGetOleLinkManager();
