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
***     Description: Declaration of AcDbProxyObject class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbProxyObject : public AcDbObject
{
public:
	enum
	{
		kNoOperation = 0,
		kEraseAllowed = 0x01,
		kCloningAllowed = 0x80,
		kAllButCloningAllowed = 0x01,
		kAllAllowedBits = 0x81,
		kMergeIgnore = 0,
		kMergeReplace = 0x100,
		kMergeMangleName = 0x200,
		kDisableProxyWarning = 0x400
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbProxyObject);

	~AcDbProxyObject() = default;

	virtual const ACHAR* applicationDescription() const = 0;
	virtual Acad::ErrorStatus getReferences(AcDbObjectIdArray&, AcDbIntArray&) const = 0;
	AcDb::DuplicateRecordCloning mergeStyle() const override = 0;
	virtual const ACHAR* originalClassName() const = 0;
	virtual const ACHAR* originalDxfName() const = 0;
	virtual int proxyFlags() const = 0;
};

#include "IcArxPackPop.h"
