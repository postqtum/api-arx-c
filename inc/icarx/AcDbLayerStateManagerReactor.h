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
***     Description: Declaration of AcDbLayerStateManagerReactor class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcDbLayerStateManagerReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbLayerStateManagerReactor);

	ACDBCORE2D_PORT ~AcDbLayerStateManagerReactor();

	virtual void abortLayerStateDelete(const ACHAR* /*layerStateName*/,
									   const AcDbObjectId& /*layerStateId*/)
	{
	}
	virtual void abortLayerStateRename(const ACHAR* /*oldLayerStateName*/,
									   const ACHAR* /*newLayerStateName*/)
	{
	}
	virtual void abortLayerStateRestore(const ACHAR* /*layerStateName*/,
										const AcDbObjectId& /*layerStateId*/)
	{
	}
	virtual void layerStateCompareFailed(const ACHAR* /*layerStateName*/,
										 const AcDbObjectId& /*layerStateId*/)
	{
	}
	virtual void layerStateCreated(const ACHAR* /*layerStateName*/,
								   const AcDbObjectId& /*layerStateId*/)
	{
	}
	virtual void layerStateDeleted(const ACHAR* /*layerStateName*/) {}
	virtual void layerStateRenamed(const ACHAR* /*oldLayerStateName*/,
								   const ACHAR* /*newLayerStateName*/)
	{
	}
	virtual void layerStateRestored(const ACHAR* /*layerStateName*/,
									const AcDbObjectId& /*layerStateId*/)
	{
	}
	virtual void layerStateToBeDeleted(const ACHAR* /*layerStateName*/,
									   const AcDbObjectId& /*layerStateId*/)
	{
	}
	virtual void layerStateToBeRenamed(const ACHAR* /*oldLayerStateName*/,
									   const ACHAR* /*newLayerStateName*/)
	{
	}
	virtual void layerStateToBeRestored(const ACHAR* /*layerStateName*/,
										const AcDbObjectId& /*layerStateId*/)
	{
	}
};

#include "IcArxPackPop.h"
