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
***     Description: Declaration of AcRxEnumType class
***
*****************************************************************************/
#pragma once

#include "IAcRxEnumeration.h"
#include "AcRxValueTypePOD.h"
#include "AcRxMember.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4355)

template<typename ValueType>
class AcRxEnumType
		: public AcRxValueTypePOD<ValueType>
		, public IAcRxEnumeration
{
private:
	AcArray<const AcRxEnumTag*> m_tags;

public:
	AcRxEnumType(const ACHAR* name, AcRxMemberCollectionConstructorPtr memberConstruct,
				 void* userData = nullptr)
			: AcRxValueTypePOD<ValueType>(name, *this, memberConstruct, userData)
	{
	}
	~AcRxEnumType()
	{
		for (int i = m_tags.length() - 1; i >= 0; i--)
		{
			AcRxMember::deleteMember(m_tags[i]);
		}
	}

	void append(AcRxEnumTag& tag)
	{
		m_tags.append(&tag);
		void acdbImpSetOwnerForEnumTag(const AcRxClass*, AcRxEnumTag*);
		acdbImpSetOwnerForEnumTag(this, &tag);
	}
	int count() const override { return m_tags.length(); }
	const AcRxEnumTag& getAt(int i) const override { return *m_tags[i]; }

#ifdef __clang__
	bool subEqualTo(const void* a, const void* b) const override;
	int subToString(const void* instance, ACHAR* buffer, size_t sizeInACHARs,
					AcRxValueType::StringFormat format) const override;
#endif
};

#include "IcArxPackPop.h"
