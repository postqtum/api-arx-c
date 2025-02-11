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

#include "acadstrc.h"
#include "AcDbCore2dDefs.h"

class AcDbDatabase;
class AcDbObjectId;

#include "icarx/IcArxPackPush.h"

class AcAxDocLock
{
public:
	enum DocLockType
	{
		kNormal = 0,
		kCurDocSwitch = 1
	};

private:
	Acad::ErrorStatus m_lockStatus;
	void* m_pDocToUnlock;
	void* m_pCurDocToRestore;
	bool m_restoreActivation;

private:
	void lockDocument(AcDbDatabase* pDatabase, DocLockType lockType = kNormal);
	void initialize();

public:
	AcAxDocLock();
	AcAxDocLock(const AcDbObjectId& objectId, DocLockType = kNormal);
	AcAxDocLock(AcDbDatabase* pDatabase, DocLockType = kNormal);
	~AcAxDocLock();

	ACDBCORE2D_PORT void* document() const;
	ACDBCORE2D_PORT Acad::ErrorStatus lockStatus() const;
};

#include "icarx/IcArxPackPop.h"
