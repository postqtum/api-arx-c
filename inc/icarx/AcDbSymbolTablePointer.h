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
***     Description: Declaration of AcDbSymbolTablePointer class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectPointerBase.h"

#include "IcArxPackPush.h"

template<class T_OBJECT>
class AcDbSymbolTablePointer : public AcDbObjectPointerBase<T_OBJECT>
{
public:
	AcDbSymbolTablePointer();
	AcDbSymbolTablePointer(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead);
	AcDbSymbolTablePointer(AcDbDatabase* pDb, AcDb::OpenMode mode = AcDb::kForRead);
	AcDbSymbolTablePointer(AcDbSymbolTablePointer&&) = default;
	AcDbSymbolTablePointer& operator=(AcDbSymbolTablePointer&&) = default;

#if DBOBJPTR_EXPOSE_PTR_REF
	AcDbSymbolTablePointer(T_OBJECT* pObject);
	void operator=(T_OBJECT* pObject);
#endif

	Acad::ErrorStatus open(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus open(AcDbDatabase* pDb, AcDb::OpenMode mode = AcDb::kForRead);

private:
	AcDbSymbolTablePointer(const AcDbSymbolTablePointer&) = delete;
	AcDbSymbolTablePointer& operator=(const AcDbSymbolTablePointer&) = delete;
};

#include "IcArxPackPop.h"

template<class T_OBJECT>
inline AcDbSymbolTablePointer<T_OBJECT>::AcDbSymbolTablePointer()
		: AcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT>
inline AcDbSymbolTablePointer<T_OBJECT>::AcDbSymbolTablePointer(AcDbObjectId objId,
																AcDb::OpenMode mode)
		: AcDbObjectPointerBase<T_OBJECT>(objId, mode, false)
{
}

template<class T_OBJECT>
inline AcDbSymbolTablePointer<T_OBJECT>::AcDbSymbolTablePointer(AcDbDatabase* pDb,
																AcDb::OpenMode mode)
		: AcDbObjectPointerBase<T_OBJECT>()
{
	this->m_status =
			(!pDb) ? Acad::eNullObjectPointer : pDb->getSymbolTable(this->m_ptr, mode);
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class T_OBJECT>
inline AcDbSymbolTablePointer<T_OBJECT>::AcDbSymbolTablePointer(T_OBJECT* pObject)
		: AcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT>
inline void AcDbSymbolTablePointer<T_OBJECT>::operator=(T_OBJECT* pObject)
{
	AcDbObjectPointerBase<T_OBJECT>::operator=(pObject);
}

#endif

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbSymbolTablePointer<T_OBJECT>::open(AcDbObjectId objId,
																AcDb::OpenMode mode)
{
	return AcDbObjectPointerBase<T_OBJECT>::open(objId, mode, false);
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbSymbolTablePointer<T_OBJECT>::open(AcDbDatabase* pDb,
																AcDb::OpenMode mode)
{
	if (!pDb)
		return Acad::eInvalidInput;
	Acad::ErrorStatus es = Acad::eOk;
	if (this->m_ptr)
		es = this->close();
	if (es == Acad::eOk)
	{
		es = pDb->getSymbolTable(this->m_ptr, mode);
		this->m_status = es;
	}
	return es;
}
