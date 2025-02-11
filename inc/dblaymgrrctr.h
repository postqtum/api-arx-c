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
***     Description: Declaration of AcDbLayoutManagerReactor class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "dbid.h"
#include "AdAChar.h"
#include "AcDbCore2dDefs.h"

#include "icarx/IcArxPackPush.h"

class AcDbLayoutManagerReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbLayoutManagerReactor);

	ACDBCORE2D_PORT virtual ~AcDbLayoutManagerReactor();

	virtual void abortLayoutCopied(const ACHAR* /*layoutName*/, const AcDbObjectId& /*layoutId*/) {}
	virtual void abortLayoutRemoved(const ACHAR* /*layoutName*/, const AcDbObjectId& /*layoutId*/)
	{
	}
	virtual void abortLayoutRename(const ACHAR* /*oldName*/, const ACHAR* /*newName*/,
								   const AcDbObjectId& /*layoutId*/)
	{
	}
	virtual void layoutCopied(const ACHAR* /*oldLayoutName*/, const AcDbObjectId& /*oldLayoutId*/,
							  const ACHAR* /*newLayoutname*/, const AcDbObjectId& /*newLayoutId*/)
	{
	}
	virtual void layoutCreated(const ACHAR* /*newLayoutName*/, const AcDbObjectId& /*layoutId*/) {}
	virtual void layoutRemoved(const ACHAR* /*layoutName*/, const AcDbObjectId& /*layoutId*/) {}
	virtual void layoutRenamed(const ACHAR* /*oldName*/, const ACHAR* /*newName*/,
							   const AcDbObjectId& /*layoutId*/)
	{
	}
	virtual void layoutSwitched(const ACHAR* /*newLayoutname*/, const AcDbObjectId& /*newLayoutId*/)
	{
	}
	virtual void layoutToBeCopied(const ACHAR* /*layoutName*/, const AcDbObjectId& /*oldLayoutId*/)
	{
	}
	virtual void layoutToBeRemoved(const ACHAR* /*layoutName*/, const AcDbObjectId& /*layoutId*/) {}
	virtual void layoutToBeRenamed(const ACHAR* /*oldName*/, const ACHAR* /*newName*/,
								   const AcDbObjectId& /*layoutId*/)
	{
	}
	virtual void layoutsReordered() {}
	virtual void plotStyleTableChanged(const ACHAR* /*newTableName*/,
									   const AcDbObjectId& /*layoutId*/)
	{
	}
	virtual void refreshLayoutTabs() {}
};

#include "icarx/IcArxPackPop.h"
