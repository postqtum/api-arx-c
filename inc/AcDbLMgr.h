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

#include "adesk.h"
#include "dbid.h"
#include "dblayout.h"
#include "dblaymgrrctr.h"

#define MAX_PSPACE_LAYOUTS 256

class AcDbObjectId;

#include "icarx/IcArxPackPush.h"

class AcDbLayoutManager : public AcRxObject
{
public:
	virtual void addReactor(AcDbLayoutManagerReactor* newObj) = 0;
	virtual Acad::ErrorStatus cloneLayout(AcDbLayout* pLBTR, const ACHAR* newname,
										  int newTabOrder = 0, AcDbDatabase* pDb = nullptr) = 0;
	virtual Acad::ErrorStatus copyLayout(const ACHAR* copyname, const ACHAR* newname,
										 AcDbDatabase* pDb = nullptr) = 0;
	virtual int countLayouts(AcDbDatabase* pDb = nullptr) = 0;
	virtual Acad::ErrorStatus createLayout(const ACHAR* newname, AcDbObjectId& layoutId,
										   AcDbObjectId& blockTableRecId,
										   AcDbDatabase* pDb = nullptr) = 0;
	virtual Acad::ErrorStatus deleteLayout(const ACHAR* delname, AcDbDatabase* pDb = nullptr) = 0;
	virtual const ACHAR* findActiveLayout(bool allowModel, const AcDbDatabase* pDb = nullptr) final
	{
		static AcString sCachedName;
		this->getActiveLayoutName(sCachedName, allowModel, pDb);
		return sCachedName.constPtr();
	}
	virtual AcDbObjectId findLayoutNamed(const ACHAR* name, const AcDbDatabase* pDb = nullptr) = 0;
	virtual AcDbObjectId getActiveLayoutBTRId(const AcDbDatabase* pDb = nullptr) = 0;
	virtual Acad::ErrorStatus getActiveLayoutName(AcString& sName, bool allowModel,
												  const AcDbDatabase* pDb = nullptr) = 0;
	Acad::ErrorStatus getLayoutNamed(const ACHAR* name, AcDbLayout*& pLayout,
									 AcDb::OpenMode mode = AcDb::kForRead,
									 const AcDbDatabase* pDb = nullptr)
	{
		AcDbObjectId id = findLayoutNamed(name, pDb);
		if (id.isNull())
			return Acad::eKeyNotFound;

		return acdbOpenObject(pLayout, id, mode);
	}
	virtual AcDbObjectId getNonRectVPIdFromClipId(AcDbObjectId clipId) = 0;
	virtual bool isVpnumClipped(int index, const AcDbDatabase* pDb = nullptr) = 0;
	bool layoutExists(const ACHAR* name, const AcDbDatabase* pDb = nullptr)
	{
		return !(findLayoutNamed(name, pDb)).isNull();
	}
	virtual void removeReactor(AcDbLayoutManagerReactor* delObj) = 0;
	virtual Acad::ErrorStatus renameLayout(const ACHAR* oldname, const ACHAR* newname,
										   AcDbDatabase* pDb = nullptr) = 0;
	virtual Acad::ErrorStatus setCurrentLayout(const ACHAR* newname,
											   AcDbDatabase* pDb = nullptr) = 0;
	virtual Acad::ErrorStatus setCurrentLayoutId(AcDbObjectId layoutId) = 0;
};

#include "icarx/IcArxPackPop.h"

Acad::ErrorStatus acdbClearSetupForLayouts(IcArx::Integers::ULongPtr contextHandle);
Acad::ErrorStatus acdbDoSetupForLayouts(AcDbDatabase* pDatabase, IcArx::Integers::ULongPtr& contextHandle);
