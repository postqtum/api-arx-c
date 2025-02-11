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
***     Description: Declaration of AcDbSubentId class
***
*****************************************************************************/
#pragma once

#include "../acdb.h"
#include "../dbidar.h"

#include "IcArxPackPush.h"

class AcDbSubentId
{
public:
	static const AcDbSubentId kNull;

private:
	AcDb::SubentType mType;
	IcArx::Integers::GsMarker mIndex;
	AcRxClass* mpTypeClass;

public:
	AcDbSubentId();
	AcDbSubentId(AcDb::SubentType type, IcArx::Integers::GsMarker index);
	AcDbSubentId(AcRxClass* pTypeClass, IcArx::Integers::GsMarker index);
	~AcDbSubentId() = default;
	bool operator==(const AcDbSubentId& id) const
	{
		return ((mIndex == id.mIndex) && (mType == id.mType) && (mpTypeClass == id.mpTypeClass));
	}
	bool operator!=(const AcDbSubentId& id) const { return !(*this == id); }

	IcArx::Integers::GsMarker index() const { return mIndex; }
	void setIndex(IcArx::Integers::GsMarker index) { mIndex = index; }
	void setType(AcDb::SubentType);
	void setTypeClass(AcRxClass* pClass);
	AcDb::SubentType type() const { return mType; }
	AcRxClass* typeClass() const { return mpTypeClass; }
};

#include "IcArxPackPop.h"

#ifndef OBJARX_EXCLUDE_CONFLICTS
const IcArx::Integers::GsMarker kNullSubentIndex = 0;
#endif	// OBJARX_EXCLUDE_CONFLICTS

__declspec(selectany) extern const AcDbSubentId
		kNullSubentId(AcDb::kNullSubentType, kNullSubentIndex);

inline AcDbSubentId::AcDbSubentId()
		: mType(AcDb::kNullSubentType), mIndex(kNullSubentIndex), mpTypeClass(nullptr)
{
}

inline AcDbSubentId::AcDbSubentId(AcDb::SubentType t, IcArx::Integers::GsMarker i)
		: mType(t), mIndex(i), mpTypeClass(nullptr)
{
}

inline AcDbSubentId::AcDbSubentId(AcRxClass* pTypeClass, IcArx::Integers::GsMarker i)
		: mType(AcDb::kClassSubentType), mIndex(i), mpTypeClass(pTypeClass)
{
}

inline void AcDbSubentId::setType(AcDb::SubentType type)
{
	mType = type;
	if (mType != AcDb::kClassSubentType)
		mpTypeClass = nullptr;
}

inline void AcDbSubentId::setTypeClass(AcRxClass* pTypeClass)
{
	mpTypeClass = pTypeClass;
	if (mpTypeClass != nullptr)
		mType = AcDb::kClassSubentType;
}
