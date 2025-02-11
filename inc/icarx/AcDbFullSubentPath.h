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
***     Description: Declaration of AcDbFullSubentPath class
***
*****************************************************************************/
#pragma once

#include "AcDbSubentId.h"

#include "IcArxPackPush.h"

class AcDbFullSubentPath
{
public:
	static const AcDbFullSubentPath kNull;

private:
	AcDbObjectIdArray mObjectIds;
	AcDbSubentId mSubentId;
	void* mpUserAppData{nullptr};

public:
	AcDbFullSubentPath();
	AcDbFullSubentPath(AcDb::SubentType type, IcArx::Integers::GsMarker index);
	AcDbFullSubentPath(AcDbObjectId entId, AcDb::SubentType type, IcArx::Integers::GsMarker index);
	AcDbFullSubentPath(AcDbObjectId entId, AcDbSubentId subId);
	AcDbFullSubentPath(AcDbObjectIdArray objectIds, AcDbSubentId subId);
	AcDbFullSubentPath(const AcDbFullSubentPath&);
	~AcDbFullSubentPath();
	AcDbFullSubentPath& operator=(const AcDbFullSubentPath&);
	bool operator==(const AcDbFullSubentPath& id) const;
	bool operator!=(const AcDbFullSubentPath& id) const;

	void objectIds(AcDbObjectIdArray& objectIds) const { objectIds = mObjectIds; }
	AcDbObjectIdArray& objectIds() { return mObjectIds; }
	const AcDbObjectIdArray& objectIds() const { return mObjectIds; }
	void setObjectIds(const AcDbObjectIdArray& objectIds) { mObjectIds = objectIds; }
	void setSubentId(const AcDbSubentId& subentId) { mSubentId = subentId; }
	void setUserAppData(void* pData) { mpUserAppData = pData; }
	const AcDbSubentId subentId() const { return mSubentId; }
	AcDbSubentId& subentId() { return mSubentId; }
	void* userAppData() const { return mpUserAppData; }
};

#include "IcArxPackPop.h"

inline AcDbFullSubentPath::AcDbFullSubentPath() : mpUserAppData(nullptr)
{
}

inline AcDbFullSubentPath::AcDbFullSubentPath(AcDb::SubentType type, IcArx::Integers::GsMarker index)
		: mSubentId(type, index), mpUserAppData(nullptr)
{
}

extern const AcDbFullSubentPath kNullSubent;
