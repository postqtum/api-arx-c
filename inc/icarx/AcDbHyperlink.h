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
***     Description: Declaration of AcDbHyperlink class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

#include "IcArxPackPush.h"

class AcDbHyperlink
{
public:
	enum HLinkFlags
	{
		kUndefined = 0,
		kConvertDwgToDwf = 0x1
	};

	AcDbHyperlink() = default;
	virtual ~AcDbHyperlink() = default;

	virtual const ACHAR* description() const = 0;
	virtual const int32_t flags() const { return AcDbHyperlink::kUndefined; }
	virtual const ACHAR* getDisplayString() const = 0;
	virtual const int getNestedLevel() const = 0;
	virtual bool isOutermostContainer() const = 0;
	virtual const ACHAR* name() const = 0;
	virtual void setDescription(const ACHAR* cDescription) = 0;
	virtual void setFlags(const int32_t /*lFlags*/) {}
	virtual void setName(const ACHAR* cName) = 0;
	virtual void setSubLocation(const ACHAR* cSubLocation) = 0;
	virtual const ACHAR* subLocation() const = 0;
};

#include "IcArxPackPop.h"
