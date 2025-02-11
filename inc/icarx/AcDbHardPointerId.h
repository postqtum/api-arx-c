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
***     Description: Declaration of AcDbHardPointerId class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectId.h"

#include "IcArxPackPush.h"

class AcDbHardPointerId : public AcDbObjectId
{
public:
	AcDbHardPointerId();
	AcDbHardPointerId(const AcDbObjectId&);
	AcDbHardPointerId(const AcDbStub*);
	AcDbHardPointerId& operator=(const AcDbHardPointerId&);
	AcDbHardPointerId& operator=(const AcDbObjectId&);
	AcDbHardPointerId& operator=(const AcDbStub*);
	bool operator==(const AcDbObjectId&) const;
	bool operator==(const AcDbStub*) const;
	bool operator!=(const AcDbObjectId&) const;
	bool operator!=(const AcDbStub*) const;
	operator AcDbStub*() const;
};

#include "IcArxPackPop.h"

inline AcDbHardPointerId::AcDbHardPointerId()
{
}

inline AcDbHardPointerId::AcDbHardPointerId(const AcDbObjectId& id) : AcDbObjectId(id)
{
}

inline AcDbHardPointerId::AcDbHardPointerId(const AcDbStub* pStub) : AcDbObjectId(pStub)
{
}

inline AcDbHardPointerId& AcDbHardPointerId::operator=(const AcDbHardPointerId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbHardPointerId& AcDbHardPointerId::operator=(const AcDbObjectId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbHardPointerId& AcDbHardPointerId::operator=(const AcDbStub* pStub)
{
	mId = const_cast<AcDbStub*>(pStub);
	return *this;
}

inline bool AcDbHardPointerId::operator==(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator==(id);
}

inline bool AcDbHardPointerId::operator==(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator==(pStub);
}

inline bool AcDbHardPointerId::operator!=(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator!=(id);
}

inline bool AcDbHardPointerId::operator!=(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator!=(pStub);
}

inline AcDbHardPointerId::operator AcDbStub*() const
{
	return mId;
}
