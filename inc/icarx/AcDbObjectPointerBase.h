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
***     Description: Declaration of AcDbObjectPointerBase class
***
*****************************************************************************/
#pragma once

#include "../dbsymtb.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

template<class T_OBJECT>
class AcDbObjectPointerBase
{
protected:
	T_OBJECT* m_ptr;
	Acad::ErrorStatus m_status;

public:
	AcDbObjectPointerBase();
	~AcDbObjectPointerBase();
	AcDbObjectPointerBase(AcDbObjectPointerBase&&);
	AcDbObjectPointerBase& operator=(AcDbObjectPointerBase&&);
	const T_OBJECT* operator->() const;
	T_OBJECT* operator->();
	operator const T_OBJECT*() const;
#if DBOBJPTR_EXPOSE_PTR_REF
	operator T_OBJECT*&();
#else
	operator T_OBJECT*();
#endif

	Acad::ErrorStatus acquire(T_OBJECT*& pObjToAcquire);
	Acad::ErrorStatus close();
	Acad::ErrorStatus create();
	const T_OBJECT* object() const;
	T_OBJECT* object();
	Acad::ErrorStatus open(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
						   bool openErased = false);
	Acad::ErrorStatus openStatus() const;
	Acad::ErrorStatus release(T_OBJECT*& pReleasedObj);

protected:
	AcDbObjectPointerBase(AcDbObjectId objId, AcDb::OpenMode mode, bool openErased);

#if DBOBJPTR_EXPOSE_PTR_REF
	AcDbObjectPointerBase(T_OBJECT* pObject);
	void operator=(T_OBJECT* pObject);
#endif

private:
	AcDbObjectPointerBase(const AcDbObjectPointerBase&) = delete;
	AcDbObjectPointerBase& operator=(const AcDbObjectPointerBase&) = delete;

	Acad::ErrorStatus closeInternal();
};

#include "IcArxPackPop.h"

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::AcDbObjectPointerBase()
		: m_ptr(nullptr), m_status(Acad::eNullObjectPointer)
{
}

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::AcDbObjectPointerBase(AcDbObjectId objId,
															  AcDb::OpenMode mode, bool openErased)
		: m_ptr(nullptr), m_status(acdbOpenObject(m_ptr, objId, mode, openErased))
{
}

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::AcDbObjectPointerBase(AcDbObjectPointerBase&& other)
		: m_ptr(other.m_ptr), m_status(other.m_status)
{
	other.m_ptr = nullptr;
	other.m_status = Acad::eNullObjectPointer;
}

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::~AcDbObjectPointerBase()
{
	if (m_ptr)
	{
		ICARX_ASSERT(m_status == Acad::eOk);
		Acad::ErrorStatus closeStatus = closeInternal();
		(void)closeStatus;
		ICARX_ASSERT(closeStatus == Acad::eOk);
	}
}

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>& AcDbObjectPointerBase<T_OBJECT>::operator=(
		AcDbObjectPointerBase&& other)
{
	close();

	m_ptr = other.m_ptr;
	m_status = other.m_status;

	other.m_ptr = nullptr;
	other.m_status = Acad::eNullObjectPointer;

	return *this;
}

template<class T_OBJECT>
inline const T_OBJECT* AcDbObjectPointerBase<T_OBJECT>::operator->() const
{
	return object();
}

template<class T_OBJECT>
inline T_OBJECT* AcDbObjectPointerBase<T_OBJECT>::operator->()
{
	return object();
}

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::operator const T_OBJECT*() const
{
	return object();
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::AcDbObjectPointerBase(T_OBJECT* pObject)
		: m_ptr(nullptr), m_status(Acad::eNullObjectPointer)
{
	if (pObject)
	{
		this->acquire(pObject);
	}
}

template<class T_OBJECT>
inline void AcDbObjectPointerBase<T_OBJECT>::operator=(T_OBJECT* pObject)
{
	if (!pObject)
	{
		ICARX_ASSERT(!this->m_ptrL);
	}
	else
	{
		this->acquire(pObject);
	}
}

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::operator T_OBJECT*&()
{
	return this->m_ptr;
}

#else

template<class T_OBJECT>
inline AcDbObjectPointerBase<T_OBJECT>::operator T_OBJECT*()
{
	return object();
}

#endif

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::acquire(T_OBJECT*& pObjToAcquire)
{
	if (!pObjToAcquire)
		return Acad::eNullObjectPointer;
	if (m_ptr)
	{
		ICARX_ASSERT(m_status == Acad::eOk);
		Acad::ErrorStatus closeStatus = closeInternal();
		if (closeStatus != Acad::eOk)
			return closeStatus;
	}
	m_ptr = pObjToAcquire;
	m_status = Acad::eOk;
	pObjToAcquire = nullptr;
	return Acad::eOk;
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::close()
{
	if (!m_ptr)
		return Acad::eNullObjectPointer;
	ICARX_ASSERT(m_status == Acad::eOk);
	Acad::ErrorStatus closeStatus = closeInternal();
	(void)(closeStatus);
	ICARX_ASSERT(closeStatus == Acad::eOk);
	return Acad::eOk;
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::closeInternal()
{
	if (!m_ptr)
		return Acad::eOk;
	Acad::ErrorStatus es = Acad::eOk;
	if (m_ptr->objectId().isNull())
	{
		delete m_ptr;
		es = Acad::eOk;
	}
	else
	{
		es = m_ptr->close();
	}
	m_ptr = nullptr;
	m_status = Acad::eNullObjectPointer;
	return es;
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::create()
{
	T_OBJECT* pObject = new T_OBJECT;
	if (!pObject)
		return Acad::eNullObjectPointer;
	if (m_ptr)
	{
		ICARX_ASSERT(m_status == Acad::eOk);
		Acad::ErrorStatus closeStatus = closeInternal();
		if (closeStatus != Acad::eOk)
		{
			delete pObject;
			return closeStatus;
		}
	}
	m_ptr = pObject;
	m_status = Acad::eOk;
	return Acad::eOk;
}

template<class T_OBJECT>
inline const T_OBJECT* AcDbObjectPointerBase<T_OBJECT>::object() const
{
	ICARX_ASSERT(m_status == Acad::eOk);
	ICARX_ASSERT(m_ptr);
	ICARX_ASSERT(!m_ptr || m_ptr->isReadEnabled());
	return m_ptr;
}

template<class T_OBJECT>
inline T_OBJECT* AcDbObjectPointerBase<T_OBJECT>::object()
{
	ICARX_ASSERT(m_status == Acad::eOk);
	ICARX_ASSERT(m_ptr);
	ICARX_ASSERT(!m_ptr || m_ptr->isReadEnabled());
	return m_ptr;
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::open(AcDbObjectId objId,
															   AcDb::OpenMode mode, bool openErased)
{
	if (m_ptr)
	{
		ICARX_ASSERT(m_status == Acad::eOk);
		Acad::ErrorStatus closeStatus = closeInternal();
		if (closeStatus != Acad::eOk)
			return closeStatus;
	}
	m_status = acdbOpenObject(m_ptr, objId, mode, openErased);
	return m_status;
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::openStatus() const
{
	return m_status;
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointerBase<T_OBJECT>::release(T_OBJECT*& pReleasedObj)
{
	if (!m_ptr)
		return Acad::eNullObjectPointer;
	ICARX_ASSERT(m_status == Acad::eOk);
	pReleasedObj = m_ptr;
	m_ptr = nullptr;
	m_status = Acad::eNullObjectPointer;
	return Acad::eOk;
}
