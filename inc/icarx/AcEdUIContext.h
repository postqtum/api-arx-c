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
***     Description: Declaration of AcEdUIContext class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../dbidar.h"

#include "AcDbFullSubentPathArray.h"

#include "IcArxPackPush.h"

class AcEdUIContext : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcEdUIContext);

	virtual void OnUpdateMenu();
	virtual void* getMenuContext(const AcRxClass*, const AcDbObjectIdArray&) = 0;
	virtual void* getMenuContext(
			const AcRxClass*, const AcDbObjectIdArray&,
			const AcArray<AcDbFullSubentPathArray,
						  AcArrayObjectCopyReallocator<AcDbFullSubentPathArray>>& subentIds);
	virtual void onCommand(uint32_t) = 0;
};

#include "IcArxPackPop.h"

bool acedAddDefaultContextMenu(AcEdUIContext* pContext, const void* appId,
							   const ACHAR* appName = nullptr);
bool acedAddObjectContextMenu(AcRxClass* pClass, AcEdUIContext* pContext, const void* appId);
bool acedRemoveDefaultContextMenu(AcEdUIContext* pContext);
bool acedRemoveObjectContextMenu(AcRxClass* pClass, AcEdUIContext* pContext);
