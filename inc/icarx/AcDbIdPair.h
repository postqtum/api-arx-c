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
***     Description: Declaration of AcDbIdPair class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectId.h"

#include "IcArxPackPush.h"

class AcDbIdPair
{
private:
	AcDbObjectId mKey;
	AcDbObjectId mValue;
	bool mIsCloned : 1;
	bool mIsPrimary : 1;
	bool mIsOwnerXlated : 1;

public:
	AcDbIdPair();
	AcDbIdPair(const AcDbIdPair& other);
	AcDbIdPair(AcDbObjectId key, AcDbObjectId value, bool isCloned, bool isPrimary = false,
			   bool isOwnerXlated = true);
	bool isCloned() const { return mIsCloned; }
	bool isOwnerXlated() const { return mIsOwnerXlated; }
	bool isPrimary() const { return mIsPrimary; }
	AcDbObjectId key() const { return mKey; }
	void setIsCloned(bool isCloned) { mIsCloned = isCloned; }
	void setIsOwnerXlated(bool isOwnerXlated) { mIsOwnerXlated = isOwnerXlated; }
	void setIsPrimary(bool isPrimary) { mIsPrimary = isPrimary; }
	void setKey(AcDbObjectId value) { mKey = value; }
	void setValue(AcDbObjectId value) { mValue = value; }
	AcDbObjectId value() const { return mValue; }
};

#include "IcArxPackPop.h"
