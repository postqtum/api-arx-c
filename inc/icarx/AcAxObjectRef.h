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
***     Description: Declaration of AcAxObjectRef class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectPointer.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4786)

class AcAxObjectRef
{
private:
	AcDbObjectId m_objId = nullptr;
	AcDbObject* m_pObj = nullptr;

private:
	void internalRelease();

public:
	AcAxObjectRef() = default;
	AcAxObjectRef(AcDbObjectId objId) { acquire(objId); }
	AcAxObjectRef(AcDbObject*& pObj) { acquire(pObj); }
	~AcAxObjectRef() { internalRelease(); }
	AcAxObjectRef(AcAxObjectRef& ref) = delete;
	AcAxObjectRef& operator=(AcAxObjectRef& ref) = delete;

	Acad::ErrorStatus acquire(AcDbObject*& pObj);
	Acad::ErrorStatus acquire(AcDbObjectId objId);
	bool isNull();
	AcDbObjectId objectId();
	Acad::ErrorStatus release(AcDbObjectId& objId, AcDbObject*& pObj);
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcAxObjectRef::acquire(AcDbObject*& pObj)
{
	if (!pObj)
		return Acad::eNullObjectPointer;

	if (!pObj->objectId().isNull())
		return acquire(pObj->objectId());

	internalRelease();

	m_pObj = pObj;
	pObj = nullptr;

	return Acad::eOk;
}

inline Acad::ErrorStatus AcAxObjectRef::acquire(AcDbObjectId objId)
{
	if (objId.isNull())
		return Acad::eNullObjectId;

	internalRelease();

	m_objId = objId;
	return Acad::eOk;
}

inline bool AcAxObjectRef::isNull()
{
	return (!m_pObj && m_objId.isNull());
}

inline void AcAxObjectRef::internalRelease()
{
	if (m_pObj)
	{
		if (m_pObj->objectId().isNull())
			delete m_pObj;

		else
		{
		}
		m_pObj = nullptr;
	}
	m_objId.setNull();
}

inline AcDbObjectId AcAxObjectRef::objectId()
{
	return m_objId;
}

inline Acad::ErrorStatus AcAxObjectRef::release(AcDbObjectId& objId, AcDbObject*& pObj)
{
	if (isNull())
		return Acad::eNullObjectPointer;

	pObj = m_pObj;
	objId = m_objId;

	m_pObj = nullptr;
	m_objId.setNull();

	return Acad::eOk;
}
