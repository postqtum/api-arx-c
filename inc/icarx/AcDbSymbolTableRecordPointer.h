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
***     Description: Declaration of AcDbSymbolTableRecordPointer class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectPointerBase.h"
#include "AcDbSymbolTablePointer.h"

#include "IcArxPackPush.h"

template<class T_OBJECT>
class AcDbSymbolTableRecordPointer : public AcDbObjectPointerBase<T_OBJECT>
{
public:
	AcDbSymbolTableRecordPointer();
	AcDbSymbolTableRecordPointer(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
								 bool openErased = false);
	AcDbSymbolTableRecordPointer(const ACHAR* name, AcDbDatabase* pDb,
								 AcDb::OpenMode mode = AcDb::kForRead, bool openErased = false);
	AcDbSymbolTableRecordPointer(AcDbSymbolTableRecordPointer&&) = default;
	AcDbSymbolTableRecordPointer& operator=(AcDbSymbolTableRecordPointer&&) = default;

#if DBOBJPTR_EXPOSE_PTR_REF
	AcDbSymbolTableRecordPointer(T_OBJECT* pObject);
	void operator=(T_OBJECT* pObject);
#endif

	Acad::ErrorStatus open(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
						   bool openErased = false);
	Acad::ErrorStatus open(const ACHAR* name, AcDbDatabase* pDb,
						   AcDb::OpenMode mode = AcDb::kForRead, bool openErased = false);

private:
	AcDbSymbolTableRecordPointer(const AcDbSymbolTableRecordPointer&) = delete;
	AcDbSymbolTableRecordPointer& operator=(const AcDbSymbolTableRecordPointer&) = delete;
};

#include "IcArxPackPop.h"

template<class T_OBJECT>
inline AcDbSymbolTableRecordPointer<T_OBJECT>::AcDbSymbolTableRecordPointer()
		: AcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT>
inline AcDbSymbolTableRecordPointer<T_OBJECT>::AcDbSymbolTableRecordPointer(AcDbObjectId objId,
																			AcDb::OpenMode mode,
																			bool openErased)
		: AcDbObjectPointerBase<T_OBJECT>(objId, mode, openErased)
{
}

template<class T_OBJECT>
inline AcDbSymbolTableRecordPointer<T_OBJECT>::AcDbSymbolTableRecordPointer(const ACHAR* name,
																			AcDbDatabase* pDb,
																			AcDb::OpenMode mode,
																			bool openErased)
		: AcDbObjectPointerBase<T_OBJECT>()
{
	if (!name)
		this->m_status = Acad::eInvalidInput;
	else
	{
		AcDbSymbolTablePointer<typename T_OBJECT::TableType> pTable(pDb, AcDb::kForRead);
		this->m_status = pTable.openStatus();
		if (this->m_status == Acad::eOk)
			this->m_status = pTable->getAt(name, this->m_ptr, mode, openErased);
	}
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class T_OBJECT>
inline AcDbSymbolTableRecordPointer<T_OBJECT>::AcDbSymbolTableRecordPointer(T_OBJECT* pObject)
		: AcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT>
inline void AcDbSymbolTableRecordPointer<T_OBJECT>::operator=(T_OBJECT* pObject)
{
	AcDbObjectPointerBase<T_OBJECT>::operator=(pObject);
}

#endif

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbSymbolTableRecordPointer<T_OBJECT>::open(AcDbObjectId objId,
																	  AcDb::OpenMode mode,
																	  bool openErased)
{
	return AcDbObjectPointerBase<T_OBJECT>::open(objId, mode, openErased);
}

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbSymbolTableRecordPointer<T_OBJECT>::open(const ACHAR* name,
																	  AcDbDatabase* pDb,
																	  AcDb::OpenMode mode,
																	  bool openErased)
{
	if (!name)
		return Acad::eInvalidInput;
	else
	{
		AcDbSymbolTablePointer<typename T_OBJECT::TableType> pTable(pDb, AcDb::kForRead);
		Acad::ErrorStatus es = pTable.openStatus();
		if (es == Acad::eOk)
		{
			if (this->m_ptr)
				es = this->close();
			if (es == Acad::eOk)
			{
				es = pTable->getAt(name, this->m_ptr, mode, openErased);
				this->m_status = es;
			}
		}
		return es;
	}
}
