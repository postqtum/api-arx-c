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
***     Description: Declaration of AcDbHardOwnershipId class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectId.h"

class AcDbStub;

#include "IcArxPackPush.h"

class AcDbHardOwnershipId : public AcDbObjectId
{
public:
	AcDbHardOwnershipId();
	AcDbHardOwnershipId(const AcDbObjectId&);
	AcDbHardOwnershipId(const AcDbStub*);
	AcDbHardOwnershipId& operator=(const AcDbHardOwnershipId&);
	AcDbHardOwnershipId& operator=(const AcDbObjectId&);
	AcDbHardOwnershipId& operator=(const AcDbStub*);
	bool operator==(const AcDbObjectId&) const;
	bool operator==(const AcDbStub*) const;
	bool operator!=(const AcDbObjectId&) const;
	bool operator!=(const AcDbStub*) const;
	operator AcDbStub*() const;
};

#include "IcArxPackPop.h"

inline AcDbHardOwnershipId::AcDbHardOwnershipId()
{
}

inline AcDbHardOwnershipId::AcDbHardOwnershipId(const AcDbObjectId& id) : AcDbObjectId(id)
{
}

inline AcDbHardOwnershipId::AcDbHardOwnershipId(const AcDbStub* pStub) : AcDbObjectId(pStub)
{
}

inline AcDbHardOwnershipId& AcDbHardOwnershipId::operator=(const AcDbHardOwnershipId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbHardOwnershipId& AcDbHardOwnershipId::operator=(const AcDbObjectId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbHardOwnershipId& AcDbHardOwnershipId::operator=(const AcDbStub* pStub)
{
	mId = const_cast<AcDbStub*>(pStub);
	return *this;
}

inline bool AcDbHardOwnershipId::operator==(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator==(id);
}

inline bool AcDbHardOwnershipId::operator==(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator==(pStub);
}

inline bool AcDbHardOwnershipId::operator!=(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator!=(id);
}

inline bool AcDbHardOwnershipId::operator!=(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator!=(pStub);
}

inline AcDbHardOwnershipId::operator AcDbStub*() const
{
	return mId;
}
