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
***     Description: Declaration of AcDbHyperlinkCollection class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../AcDbCore2dDefs.h"

class AcDbHyperlink;

#include "IcArxPackPush.h"

class AcDbHyperlinkCollection
{
public:
	AcDbHyperlinkCollection() = default;
	virtual ~AcDbHyperlinkCollection() = default;

	virtual void addAt(const int nIndex, const ACHAR* sName, const ACHAR* sDescription,
					   const ACHAR* sSubLocation = nullptr) = 0;
	ACDBCORE2D_PORT void addAt(int index, const AcDbHyperlink* pHLink);
	virtual void addHead(const ACHAR* sName, const ACHAR* sDescription,
						 const ACHAR* sSubLocation = nullptr) = 0;
	virtual void addTail(const ACHAR* sName, const ACHAR* sDescription,
						 const ACHAR* sSubLocation = nullptr) = 0;
	virtual int count() const = 0;
	virtual AcDbHyperlink* item(const int nIndex) const = 0;
	virtual void removeAt(const int nIndex) = 0;
	virtual void removeHead() = 0;
	virtual void removeTail() = 0;
};

#include "IcArxPackPop.h"
