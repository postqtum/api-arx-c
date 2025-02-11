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
***     Description: Declaration of AcRxValueTypePOD class
***
*****************************************************************************/
#pragma once

#include "AcRxValueType.h"

#include "IcArxPackPush.h"

template<typename ValueType>
class AcRxValueTypePOD : public AcRxValueType
{
public:
	AcRxValueTypePOD(const ACHAR* name, AcRxMemberCollectionConstructorPtr memberConstruct,
					 void* userData = nullptr)
			: AcRxValueType(name, sizeof(ValueType), memberConstruct, userData)
	{
	}
	AcRxValueTypePOD(const ACHAR* name, const IAcRxEnumeration& pEnum,
					 AcRxMemberCollectionConstructorPtr memberConstruct, void* userData = nullptr)
			: AcRxValueType(name, pEnum, sizeof(ValueType), memberConstruct, userData)
	{
	}
	AcRxValueTypePOD(const ACHAR* name, const IAcRxReferenceType& pRef,
					 AcRxMemberCollectionConstructorPtr memberConstruct, void* userData = nullptr)
			: AcRxValueType(name, pRef, sizeof(ValueType), memberConstruct, userData)
	{
	}

	bool subEqualTo(const void* a, const void* b) const override;
	int subToString(const void* instance, ACHAR* buffer, size_t sizeInACHARs,
					AcRxValueType::StringFormat format) const override;
};

#include "IcArxPackPop.h"

template<typename ValueType>
int AcRxValueTypePOD<ValueType>::subToString(const void*, ACHAR*, size_t,
											 AcRxValueType::StringFormat) const
{
	return -1;
}

template<typename ValueType>
bool AcRxValueTypePOD<ValueType>::subEqualTo(const void*, const void*) const
{
	return false;
}

class AcDbObjectId;

template<>
int AcRxValueTypePOD<AcDbObjectId>::subToString(const void*, ACHAR*, size_t,
												AcRxValueType::StringFormat) const;

template<>
bool AcRxValueTypePOD<AcDbObjectId>::subEqualTo(const void*, const void*) const;
