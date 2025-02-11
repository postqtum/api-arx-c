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
***     Description: Declaration of AcDbSoftOwnershipId class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectId.h"

#include "IcArxPackPush.h"

class AcDbSoftOwnershipId : public AcDbObjectId
{
public:
	AcDbSoftOwnershipId();
	AcDbSoftOwnershipId(const AcDbObjectId&);
	AcDbSoftOwnershipId(const AcDbStub*);
	AcDbSoftOwnershipId& operator=(const AcDbSoftOwnershipId&);
	AcDbSoftOwnershipId& operator=(const AcDbObjectId&);
	AcDbSoftOwnershipId& operator=(const AcDbStub*);
	bool operator==(const AcDbObjectId&) const;
	bool operator==(const AcDbStub*) const;
	bool operator!=(const AcDbObjectId&) const;
	bool operator!=(const AcDbStub*) const;
	operator AcDbStub*() const;
};

#include "IcArxPackPop.h"

inline AcDbSoftOwnershipId::AcDbSoftOwnershipId()
{
}

inline AcDbSoftOwnershipId::AcDbSoftOwnershipId(const AcDbObjectId& id) : AcDbObjectId(id)
{
}

inline AcDbSoftOwnershipId::AcDbSoftOwnershipId(const AcDbStub* pStub) : AcDbObjectId(pStub)
{
}

inline AcDbSoftOwnershipId& AcDbSoftOwnershipId::operator=(const AcDbSoftOwnershipId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbSoftOwnershipId& AcDbSoftOwnershipId::operator=(const AcDbObjectId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbSoftOwnershipId& AcDbSoftOwnershipId::operator=(const AcDbStub* pStub)
{
	mId = const_cast<AcDbStub*>(pStub);
	return *this;
}

inline bool AcDbSoftOwnershipId::operator==(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator==(id);
}

inline bool AcDbSoftOwnershipId::operator==(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator==(pStub);
}

inline bool AcDbSoftOwnershipId::operator!=(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator!=(id);
}

inline bool AcDbSoftOwnershipId::operator!=(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator!=(pStub);
}

inline AcDbSoftOwnershipId::operator AcDbStub*() const
{
	return mId;
}
