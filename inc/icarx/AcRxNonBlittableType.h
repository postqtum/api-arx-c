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
***     Description: Declaration of AcRxNonBlittableType class
***
*****************************************************************************/
#pragma once

#include "AcRxValueType.h"

#include "IcArxPackPush.h"

template<typename T>
class AcRxNonBlittableType : public AcRxValueType
{
private:
	class NonBlittable : public IAcRxNonBlittableType
	{
		void assign(void* dest, const void* source) const override
		{
			static_cast<T*>(dest)->operator=(*static_cast<const T*>(source));
		}
		void construct(void* dest, const void* source) const override
		{
			::new (dest) T(*static_cast<const T*>(source));
		}
		void destruct(const void* instance) const override
		{
			(static_cast<const T*>(instance))->~T();
		}
	} m_nonBlittable;

private:
	bool subEqualTo(const void* a, const void* b) const override;
	int subToString(const void* instance, ACHAR* buffer, size_t sizeInACHARs,
					AcRxValueType::StringFormat format) const override;

public:
	AcRxNonBlittableType(const ACHAR* name, const ACHAR* parent,
						 AcRxMemberCollectionConstructorPtr memberConstruct, void* userData = nullptr)
			: AcRxValueType(name, parent, m_nonBlittable, sizeof(T), memberConstruct, userData)
	{
	}
	AcRxNonBlittableType(const ACHAR* name, AcRxMemberCollectionConstructorPtr memberConstruct,
						 void* userData = nullptr)
			: AcRxValueType(name, m_nonBlittable, sizeof(T), memberConstruct, userData)
	{
	}
	AcRxNonBlittableType(const ACHAR* name, const IAcRxEnumeration& enumeration,
						 AcRxMemberCollectionConstructorPtr memberConstruct, void* userData = nullptr)
			: AcRxValueType(name, enumeration, m_nonBlittable, sizeof(T), memberConstruct, userData)
	{
	}
	AcRxNonBlittableType(const ACHAR* name, const IAcRxObjectValue& rxObjValue,
						 AcRxMemberCollectionConstructorPtr memberConstruct, void* userData = nullptr)
			: AcRxValueType(name, rxObjValue, m_nonBlittable, sizeof(T), memberConstruct, userData)
	{
	}
};

#include "IcArxPackPop.h"
