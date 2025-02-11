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
***     Description: Declaration of AcDbObjectPointer class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectPointerBase.h"

#include "IcArxPackPush.h"

template<class T_OBJECT>
class AcDbObjectPointer : public AcDbObjectPointerBase<T_OBJECT>
{
public:
	AcDbObjectPointer();
	AcDbObjectPointer(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
					  bool openErased = false);
	AcDbObjectPointer(AcDbObjectPointer&&) = default;
	AcDbObjectPointer& operator=(AcDbObjectPointer&&) = default;

#if DBOBJPTR_EXPOSE_PTR_REF
	AcDbObjectPointer(T_OBJECT* pObject);
	void operator=(T_OBJECT* pObject);
#endif

	Acad::ErrorStatus open(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
						   bool openErased = false);

private:
	AcDbObjectPointer(const AcDbObjectPointer&) = delete;
	AcDbObjectPointer& operator=(const AcDbObjectPointer&) = delete;
};

#include "IcArxPackPop.h"

template<class T_OBJECT>
inline AcDbObjectPointer<T_OBJECT>::AcDbObjectPointer() : AcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT>
inline AcDbObjectPointer<T_OBJECT>::AcDbObjectPointer(AcDbObjectId objId, AcDb::OpenMode mode,
													  bool openErased)
		: AcDbObjectPointerBase<T_OBJECT>(objId, mode, openErased)
{
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class T_OBJECT>
inline AcDbObjectPointer<T_OBJECT>::AcDbObjectPointer(T_OBJECT* pObject)
		: AcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT>
inline void AcDbObjectPointer<T_OBJECT>::operator=(T_OBJECT* pObject)
{
	AcDbObjectPointerBase<T_OBJECT>::operator=(pObject);
}

#endif

template<class T_OBJECT>
inline Acad::ErrorStatus AcDbObjectPointer<T_OBJECT>::open(AcDbObjectId objId, AcDb::OpenMode mode,
														   bool openErased)
{
	return AcDbObjectPointerBase<T_OBJECT>::open(objId, mode, openErased);
}
