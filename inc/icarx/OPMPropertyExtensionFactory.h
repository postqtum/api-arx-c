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
***     Description: Declaration of OPMPropertyExtensionFactory class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acdbport.h"

interface IPropertyManager;
interface IDynamicProperty;
class OPMPropertyExtension;

#include "IcArxPackPush.h"

class OPMPropertyExtensionFactory : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(OPMPropertyExtensionFactory, ACDB_PORT);
	~OPMPropertyExtensionFactory() = default;

	virtual OPMPropertyExtension* CreateOPMCommandProtocol(const ACHAR* pGlobalCommand,
														   LONG lReserved = 0) = 0;
	virtual OPMPropertyExtension* CreateOPMObjectProtocol(AcRxClass* pClass,
														  LONG lReserved = 0) = 0;
	virtual BOOL GetOPMManager(const ACHAR* pGlobalCommand, IPropertyManager** pManager) = 0;
	virtual LONG GetPropertyClassArray(AcRxClass* pClass, IDynamicProperty** pPropertyArray) = 0;
	virtual LONG GetPropertyClassArray(AcRxClass* pClass, IUnknown** pPropertyArray) = 0;
	virtual BOOL GetPropertyCount(AcRxClass* pClass, LONG* pPropCount) = 0;
	virtual BOOL GetPropertyCountEx(AcRxClass* pClass, LONG* pPropCount) = 0;
};

#include "IcArxPackPop.h"
