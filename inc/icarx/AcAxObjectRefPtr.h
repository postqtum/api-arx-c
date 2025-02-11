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
***     Description: Declaration of AcAxObjectRefPtr class
***
*****************************************************************************/
#pragma once

#include "AcAxObjectRef.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4786)

template<class T_OBJECT>
class AcAxObjectRefPtr : public AcDbObjectPointer<T_OBJECT>
{
private:
	AcAxObjectRef* const m_pRef = nullptr;

public:
	AcAxObjectRefPtr() = default;
	AcAxObjectRefPtr(AcAxObjectRef* const pRef, AcDb::OpenMode mode, bool openErased = false);
	~AcAxObjectRefPtr();
	AcAxObjectRefPtr(AcAxObjectRefPtr& pObj) = delete;
	AcAxObjectRefPtr& operator=(AcAxObjectRefPtr& pObj) = delete;
};

#include "IcArxPackPop.h"

template<class T_OBJECT>
inline AcAxObjectRefPtr<T_OBJECT>::AcAxObjectRefPtr(AcAxObjectRef* const pRef, AcDb::OpenMode mode,
													bool openErased)
		: m_pRef(pRef)
{
	if (!pRef)
	{
		this->m_status = Acad::eNullObjectPointer;
		return;
	}

	AcDbObjectId objId = pRef->objectId();

	if (!objId.isNull())
		this->m_status = acdbOpenObject(this->m_ptr, objId, mode, openErased);
	else
	{
		AcDbObject* pTmp = nullptr;
		m_pRef->release(objId, pTmp);

		T_OBJECT* pTyped = T_OBJECT::cast(pTmp);
		if (!pTyped)
		{
			this->m_ptr = nullptr;
			m_pRef->acquire(pTmp);
			this->m_status = Acad::eNotThatKindOfClass;
		}
		else
			acquire(pTyped);
	}
}

template<class T_OBJECT>
inline AcAxObjectRefPtr<T_OBJECT>::~AcAxObjectRefPtr()
{
	if (this->m_ptr && this->m_ptr->objectId().isNull())
	{
		T_OBJECT* pTmp;
		release(pTmp);
		m_pRef->acquire(reinterpret_cast<AcDbObject*&>(pTmp));
	}
}

using AcDbObjectRefPtr = AcAxObjectRefPtr<AcDbObject>;
using AcDbEntityRefPtr = AcAxObjectRefPtr<AcDbEntity>;
