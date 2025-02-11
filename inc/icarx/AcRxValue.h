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
***     Description: Declaration of AcRxValue class
***
*****************************************************************************/
#pragma once

#include "../rxvaluetype.h"

class AcRxValue;

template<typename ValueType>
ValueType* rxenum_cast(AcRxValue* value) noexcept;
template<typename ValueType>
ValueType* rxvalue_cast(AcRxValue* value) noexcept;

#include "IcArxPackPush.h"

class AcRxValue
{
private:
	template<typename T, bool inlined>
	class InitNonBlittable
	{
	public:
		static void init(AcRxValue& rxValue, const T& value);
	};

	template<typename T>
	class InitNonBlittable<T, false>
	{
	public:
		static void init(AcRxValue& rxValue, const T& value);
	};

	template<typename T>
	class InitNonBlittable<T, true>
	{
	public:
		static void init(AcRxValue& rxValue, const T& value);
	};

private:
	const AcRxValueType& m_type;
	union InlineStorage
	{
		double m_point[3];
		void* m_ptr;
		char m_int8;
		short m_int16;
		int m_int32;
		int64_t m_int64;
		float m_real32;
		double m_real64;
	} m_value = {};

private:
	AcRxValue(const AcRxValue& rhs, bool realloc) : m_type(rhs.m_type) { init(rhs, realloc); }

	ACBASE_PORT void* allocate(size_t size) const;
	ACBASE_PORT void deallocate(void* p) const;
	void init(const AcRxValue& rhs, bool realloc)
	{
		bool blittable = type().isBlittable();
		bool inlined = isInlined();
		if (blittable && inlined)
		{
			memcpy_s(&m_value, sizeof(m_value), &rhs.m_value, sizeof(m_value));
			return;
		}
		if (inlined)
			type().nonBlittable()->construct(inlineValuePtr(), rhs.inlineValuePtr());
		else
			setNonInlineValue(rhs.nonInlineValuePtr(), blittable, false, realloc);
	}
	template<bool Inlined>
	void initBlittable(const void* value, size_t size);
	template<typename T>
	void initNonBlittable(const T& value)
	{
		InitNonBlittable<T, sizeof(value) <= sizeof(m_value)>::init(*this, value);
	}
	const void* inlineValuePtr() const { return &m_value; }
	void* inlineValuePtr() { return &m_value; }
	bool isInlined() const { return type().size() <= sizeof(m_value); }
	const void* nonInlineValuePtr() const { return m_value.m_ptr; }
	void* nonInlineValuePtr() { return m_value.m_ptr; }
	ACBASE_PORT void* reallocate(size_t size, void* p) const;
	void setNonInlineValue(const void* value, bool blittable, bool assignment, bool realloc)
	{
		ACRXVALUE_ASSERT(blittable == type().isBlittable());
		ACRXVALUE_ASSERT(!isInlined());
		unsigned int newSize = type().size();
		realloc = realloc || assignment;
		if (realloc)
			m_value.m_ptr = reallocate(newSize, m_value.m_ptr);
		else
			m_value.m_ptr = allocate(newSize);

		if (blittable)
			memcpy_s(nonInlineValuePtr(), newSize, value, newSize);
		else if (assignment)
			type().nonBlittable()->assign(nonInlineValuePtr(), value);
		else
			type().nonBlittable()->construct(nonInlineValuePtr(), value);
	}
	const void* valuePtr() const
	{
		if (isInlined())
			return inlineValuePtr();
		else
			return nonInlineValuePtr();
	}
	template<bool Inlined>
	void* valuePtr__();

public:
	AcRxValue() noexcept : m_type(AcRxValueType::Desc<void>::value())
	{
		memset(&m_value, 0, sizeof(m_value));
	}
	AcRxValue(const AcRxValueType& type, const AcRxValue& value) noexcept : m_type(type)
	{
		init(value, false);
	}
	template<typename ValueType>
	AcRxValue(const ValueType& value) noexcept : m_type(AcRxValueType::Desc<ValueType>::value())
	{
		ACRXVALUE_ASSERT(m_type.isBlittable());
		initBlittable<sizeof(ValueType) <= 24>(&value, sizeof(ValueType));
	}
	AcRxValue(const AcRxValue& rhs) noexcept : m_type(rhs.m_type) { init(rhs, false); }
	~AcRxValue() noexcept
	{
		if (!type().isBlittable())
			type().nonBlittable()->destruct(valuePtr());
		if (!isInlined())
			deallocate(m_value.m_ptr);
	}
	template<typename ValueType>
	AcRxValue& operator=(const ValueType& rhs) noexcept
	{
		*this = AcRxValue(rhs);
		return *this;
	}
	const AcRxValue& operator=(const AcRxValue& rhs) noexcept
	{
		if (this == &rhs)
			return *this;
		if (type() != rhs.type())
		{
			if (!type().isBlittable())
				type().nonBlittable()->destruct(valuePtr());
			if (!isInlined() && rhs.isInlined())
				deallocate(m_value.m_ptr);
#pragma push_macro("new")
#undef new
			::new ((Storage*)this) AcRxValue(rhs, !isInlined() && !rhs.isInlined());
#pragma pop_macro("new")
			return *this;
		}
		bool blittable = rhs.type().isBlittable();
		bool inlined = rhs.isInlined();
		if (blittable && inlined)
		{
			memcpy_s(this, sizeof(AcRxValue), &rhs, sizeof(AcRxValue));
			return *this;
		}
		if (inlined)
			type().nonBlittable()->assign(inlineValuePtr(), rhs.inlineValuePtr());
		else
			setNonInlineValue(rhs.nonInlineValuePtr(), blittable, true, true);
		return *this;
	}
	ACBASE_PORT bool operator==(const AcRxValue& value) const noexcept
	{
		if (type() != value.type())
			return false;
		return type().equalTo(valuePtr(), value.valuePtr());
	}

	ACBASE_PORT static const AcRxValue& empty() noexcept;
	ACBASE_PORT const AcRxEnumTag* getEnumTag() const noexcept;
	bool isEmpty() const noexcept { return *this == empty(); }
	bool isVaries() const noexcept { return *this == varies(); }
	ACBASE_PORT size_t serializeIn(const void* pBytes, size_t maxBytesToRead) noexcept;
	ACBASE_PORT size_t serializeOut(void* pBytes, size_t& maxBytesToWrite) const noexcept;
	ACBASE_PORT int toString(
			ACHAR* buffer, size_t sizeInACHARs,
			AcRxValueType::StringFormat format = AcRxValueType::kStringFormatGlobal) const noexcept;
	const AcRxValueType& type() const noexcept { return m_type; }
	ACBASE_PORT static const AcRxValue* unbox(const AcRxObject* pO) noexcept;
	ACBASE_PORT static AcRxValue* unbox(AcRxObject* pO) noexcept;
	ACBASE_PORT static const AcRxValue& varies() noexcept;

	template<typename ValueType>
	friend const ValueType* rxenum_cast(const AcRxValue* value) noexcept
	{
		return rxenum_cast<ValueType>(const_cast<AcRxValue*>(value));
	}
	template<typename ValueType>
	friend ValueType* rxenum_cast(AcRxValue* value) noexcept
	{
		ACRXVALUE_ASSERT(!value || value->isVaries() || value->type().isEnum());
		return value && value->type().isEnum() &&
		                       AcRxValueType::Desc<ValueType>::value() ==
		                               value->type().enumeration()->getAt(0).type()
		             ? static_cast<ValueType*>(value->valuePtr__<sizeof(ValueType) <= 24>())
		             : nullptr;
	}
	template<typename ValueType>
	friend const ValueType* rxvalue_cast(const AcRxValue* value) noexcept
	{
		return rxvalue_cast<ValueType>(const_cast<AcRxValue*>(value));
	}
	template<typename ValueType>
	friend ValueType* rxvalue_cast(AcRxValue* value) noexcept
	{
		return value && AcRxValueType::Desc<ValueType>::value() == value->type()
		             ? static_cast<ValueType*>(value->valuePtr__<sizeof(ValueType) <= 24>())
		             : nullptr;
	}
};

#include "IcArxPackPop.h"

template<>
inline void* AcRxValue::valuePtr__<false>()
{
	ACRXVALUE_ASSERT(!isInlined());
	return nonInlineValuePtr();
}

template<>
inline void* AcRxValue::valuePtr__<true>()
{
	ACRXVALUE_ASSERT(isInlined());
	return inlineValuePtr();
}

template<>
inline void AcRxValue::initBlittable<false>(const void* value, size_t size)
{
	ACRXVALUE_ASSERT(type().isBlittable());
	ACRXVALUE_ASSERT(!isInlined());
	m_value.m_ptr = allocate(size);
	memcpy_s(nonInlineValuePtr(), size, value, size);
}

template<>
inline void AcRxValue::initBlittable<true>(const void* value, size_t size)
{
	ACRXVALUE_ASSERT(type().isBlittable());
	ACRXVALUE_ASSERT(isInlined());
	memcpy_s(inlineValuePtr(), size, value, size);
}

template<typename T>
inline void AcRxValue::InitNonBlittable<T, false>::init(AcRxValue& rxValue, const T& value)
{
	rxValue.setNonInlineValue(&value, false, false, false);
}

template<typename T>
inline void AcRxValue::InitNonBlittable<T, true>::init(AcRxValue& rxValue, const T& value)
{
	::new (rxValue.inlineValuePtr()) T(value);
}

template<>
inline AcRxValue::AcRxValue(const ACHAR* const& value) noexcept
		: m_type(AcRxValueType::Desc<const ACHAR*>::value())
{
	memcpy_s(&m_value, sizeof(const ACHAR*), &value, sizeof(const ACHAR*));
}

template<>
inline AcRxValue& AcRxValue::operator=(const ACHAR* const& rhs) noexcept
{
	*this = AcRxValue(rhs);
	return *this;
}

class AcDbHyperlink;

template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcCmColor& clr) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(
		const AcDbBlkParamValueSetValuesArray& blockParamValueSetArr) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcDbBlockParamValueSet& blcParamValueSet) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcDbDate& str) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcDbIntArray& intArr) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcDbLoftOptions& loftOptions) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcDbSweepOptions& sweepOptions) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(AcDbMText* const& pMText) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcDbTableCellBlockReference& tableCellBlkRef) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGeMatrix3d& m) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiLightAttenuation& v) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiMaterialColor& clr) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiMaterialMap& clr) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiPhotographicExposureParameters& v) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiShadowParameters& v) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiSkyParameters& v) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcGiToneOperatorParameters& v) noexcept;
template<>
ACBASE_PORT AcRxValue::AcRxValue(const AcString& str) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcStringArray& stringArray) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const AcUnderlayLayer& str) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(const DimFillColor& dimFillColor) noexcept;
template<>
ACDBCORE2D_PORT AcRxValue::AcRxValue(AcDbHyperlink* const & hyperlink) noexcept;

template<typename ValueType>
ValueType* rxenum_cast(AcRxValue* value) noexcept;
template<typename ValueType>
ValueType* rxvalue_cast(AcRxValue* value) noexcept;
template<>
inline const ACHAR* const* rxvalue_cast<const ACHAR*>(const AcRxValue* value) noexcept
{
	return value && AcRxValueType::Desc<const ACHAR*>::value() == value->type()
				   ? (const ACHAR* const*)&(value->m_value)
				   : 0;
}
template<>
inline const void* rxvalue_cast<void>(const AcRxValue* value) noexcept
{
	return value ? value->valuePtr() : 0;
}
template<>
ACDBCORE2D_PORT AcGeMatrix3d* rxvalue_cast<AcGeMatrix3d>(AcRxValue* value) noexcept;
template<>
ACDBCORE2D_PORT AcDbMText* const* rxvalue_cast<AcDbMText*>(const AcRxValue* value) noexcept;
template<>
ACDBCORE2D_PORT AcDbMText** rxvalue_cast<AcDbMText*>(AcRxValue* value) noexcept;
template<>
ACDBCORE2D_PORT AcDbHyperlink** rxvalue_cast<AcDbHyperlink*>(AcRxValue* value) noexcept;
