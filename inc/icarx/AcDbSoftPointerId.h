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
***     Description: Declaration of AcDbSoftPointerId class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectId.h"

#include "IcArxPackPush.h"

class AcDbSoftPointerId : public AcDbObjectId
{
public:
	AcDbSoftPointerId();
	AcDbSoftPointerId(const AcDbObjectId&);
	AcDbSoftPointerId(const AcDbStub*);
	AcDbSoftPointerId& operator=(const AcDbSoftPointerId&);
	AcDbSoftPointerId& operator=(const AcDbObjectId&);
	AcDbSoftPointerId& operator=(const AcDbStub*);
	bool operator==(const AcDbObjectId&) const;
	bool operator==(const AcDbStub*) const;
	bool operator!=(const AcDbObjectId&) const;
	bool operator!=(const AcDbStub*) const;
	operator AcDbStub*() const;
};

#include "IcArxPackPop.h"

inline AcDbSoftPointerId::AcDbSoftPointerId()
{
}

inline AcDbSoftPointerId::AcDbSoftPointerId(const AcDbObjectId& id) : AcDbObjectId(id)
{
}

inline AcDbSoftPointerId::AcDbSoftPointerId(const AcDbStub* pStub) : AcDbObjectId(pStub)
{
}

inline AcDbSoftPointerId& AcDbSoftPointerId::operator=(const AcDbSoftPointerId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbSoftPointerId& AcDbSoftPointerId::operator=(const AcDbObjectId& id)
{
	AcDbObjectId::operator=(id);
	return *this;
}

inline AcDbSoftPointerId& AcDbSoftPointerId::operator=(const AcDbStub* pStub)
{
	mId = const_cast<AcDbStub*>(pStub);
	return *this;
}

inline bool AcDbSoftPointerId::operator==(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator==(id);
}

inline bool AcDbSoftPointerId::operator==(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator==(pStub);
}

inline bool AcDbSoftPointerId::operator!=(const AcDbObjectId& id) const
{
	return AcDbObjectId::operator!=(id);
}

inline bool AcDbSoftPointerId::operator!=(const AcDbStub* pStub) const
{
	return AcDbObjectId::operator!=(pStub);
}

inline AcDbSoftPointerId::operator AcDbStub*() const
{
	return mId;
}
