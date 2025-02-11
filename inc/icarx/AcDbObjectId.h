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
***     Description: Declaration of AcDbObjectId class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../AcDbCore2dDefs.h"
#include "../dbhandle.h"

class AcDbStub;
class AcDbDatabase;
class AcRxClass;

#include "IcArxPackPush.h"

class AcDbObjectId
{
public:
	static const AcDbObjectId kNull;

protected:
	AcDbStub* mId;

private:
	AcDbObjectId& setFromOldId(long);

public:
	AcDbObjectId();
	AcDbObjectId(const AcDbStub*);
	AcDbObjectId& operator=(const AcDbObjectId&);
	AcDbObjectId& operator=(const AcDbStub*);
	bool operator==(const AcDbObjectId&) const;
	bool operator!=(const AcDbObjectId&) const;
	bool operator==(const AcDbStub*) const;
	bool operator!=(const AcDbStub*) const;
	bool operator<(const AcDbObjectId&) const;
	bool operator>(const AcDbObjectId&) const;
	bool operator<=(const AcDbObjectId&) const;
	bool operator>=(const AcDbObjectId&) const;
	bool operator<(const AcDbStub*) const;
	bool operator>(const AcDbStub*) const;
	bool operator<=(const AcDbStub*) const;
	bool operator>=(const AcDbStub*) const;
	operator AcDbStub*() const;

	IcArx::Integers::IntDbId asOldId() const;
	ACDBCORE2D_PORT bool convertToRedirectedId();
	ACDBCORE2D_PORT AcDbDatabase* database() const;
	AcDbHandle handle() const;
	bool isEffectivelyErased() const;
	bool isErased() const;
	bool isNull() const;
	bool isResident() const;
	ACDBCORE2D_PORT bool isValid() const;
	ACDBCORE2D_PORT bool isWellBehaved() const;
	ACDBCORE2D_PORT AcDbHandle nonForwardedHandle() const;
	AcRxClass* objectClass() const;
	bool objectLeftOnDisk() const;
	ACDBCORE2D_PORT AcDbDatabase* originalDatabase() const;
	AcDbObjectId& setFromOldId(IcArx::Integers::IntDbId oldId);
	inline AcDbObjectId& setFromOldId(IcArx::Integers::UIntPtr nUnsignedId)
	{
		const IcArx::Integers::IntDbId nSignedId =
				static_cast<IcArx::Integers::IntDbId>(nUnsignedId);
		return this->setFromOldId(nSignedId);
	}
	void setNull();
};

#include "IcArxPackPop.h"

inline AcDbObjectId::AcDbObjectId()
{
	mId = nullptr;
}

inline AcDbObjectId::AcDbObjectId(const AcDbStub* pStub)
{
	mId = const_cast<AcDbStub*>(pStub);
}

inline AcDbObjectId& AcDbObjectId::operator=(const AcDbObjectId& id)
{
	mId = id.mId;
	return *this;
}

inline AcDbObjectId& AcDbObjectId::operator=(const AcDbStub* pStub)
{
	mId = const_cast<AcDbStub*>(pStub);
	return *this;
}

inline bool AcDbObjectId::operator==(const AcDbObjectId& id) const
{
	return mId == id.mId;
}

inline bool AcDbObjectId::operator!=(const AcDbObjectId& id) const
{
	return mId != id.mId;
}

inline bool AcDbObjectId::operator==(const AcDbStub* pStub) const
{
	return mId == pStub;
}

inline bool AcDbObjectId::operator!=(const AcDbStub* pStub) const
{
	return mId != pStub;
}

inline bool AcDbObjectId::operator<(const AcDbObjectId& id) const
{
	return mId < id.mId;
}

inline bool AcDbObjectId::operator>(const AcDbObjectId& id) const
{
	return mId > id.mId;
}

inline bool AcDbObjectId::operator<=(const AcDbObjectId& id) const
{
	return mId <= id.mId;
}

inline bool AcDbObjectId::operator>=(const AcDbObjectId& id) const
{
	return mId >= id.mId;
}

inline bool AcDbObjectId::operator<(const AcDbStub* pStub) const
{
	return mId < pStub;
}

inline bool AcDbObjectId::operator>(const AcDbStub* pStub) const
{
	return mId > pStub;
}

inline bool AcDbObjectId::operator<=(const AcDbStub* pStub) const
{
	return mId <= pStub;
}

inline bool AcDbObjectId::operator>=(const AcDbStub* pStub) const
{
	return mId >= pStub;
}

inline AcDbObjectId::operator AcDbStub*() const
{
	return mId;
}

inline IcArx::Integers::IntDbId AcDbObjectId::asOldId() const
{
	return reinterpret_cast<IcArx::Integers::IntDbId>(this->mId);
}

inline bool AcDbObjectId::isNull() const
{
	return mId == nullptr;
}

inline AcDbObjectId& AcDbObjectId::setFromOldId(IcArx::Integers::IntDbId oldId)
{
	this->mId = reinterpret_cast<AcDbStub*>(oldId);
	return *this;
}

inline void AcDbObjectId::setNull()
{
	mId = nullptr;
}
