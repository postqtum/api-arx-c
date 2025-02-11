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
***     Description: Declaration of AcRxCopyOnWriteObject class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "rxboiler.h"
#include "acbasedefs.h"

#include "icarx/IcArxPackPush.h"

class AcRxCopyOnWriteObject : public AcRxObject
{
private:
	void* m_pData;

protected:
	ACBASE_PORT const AcRxObject* read() const;
	ACBASE_PORT void unshare();
	ACBASE_PORT AcRxObject* write();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxCopyOnWriteObject, ACBASE_PORT);

	ACBASE_PORT AcRxCopyOnWriteObject(AcRxObject* pData);
	ACBASE_PORT AcRxCopyOnWriteObject(const AcRxCopyOnWriteObject& other);
	ACBASE_PORT ~AcRxCopyOnWriteObject();
	ACBASE_PORT const AcRxCopyOnWriteObject& operator=(const AcRxCopyOnWriteObject& other);
};

#include "icarx/IcArxPackPop.h"

#define ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(CLASS_NAME, DATA_NAME, EXPIMP)  \
	ACRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, EXPIMP);                          \
	DATA_NAME* write() { return (DATA_NAME*)AcRxCopyOnWriteObject::write(); } \
	const DATA_NAME* read() const { return (const DATA_NAME*)AcRxCopyOnWriteObject::read(); }

#define ACRX_EMPTY

#define ACRX_DECLARE_MEMBERS_READWRITE(CLASS_NAME, DATA_NAME) \
	ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(CLASS_NAME, DATA_NAME, ACRX_EMPTY)
