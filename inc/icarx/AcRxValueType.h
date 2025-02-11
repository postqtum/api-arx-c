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
***     Description: Declaration of AcRxValueType class
***
*****************************************************************************/
#pragma once

#include "../rxclass.h"
#include "../acutasrt.h"
#include "../acarray.h"
#include "../dbintar.h"

#include "IAcRxNonBlittableType.h"
#include "IAcRxEnumeration.h"
#include "IAcRxReferenceType.h"
#include "IAcRxObjectValue.h"

#ifdef NDEBUG
#	define ACRXVALUE_ASSERT(x)
#else
#	define ACRXVALUE_ASSERT(x)                                           \
		if (!(x))                                                         \
			acutAssertMessage(ACRX_T(#x), ACRX_T(__FILE__), __LINE__, 0); \
		else
#endif

#include "IcArxPackPush.h"

class AcRxValueType : public AcRxClass
{
public:
	template<typename ValueType>
	struct Desc
	{
		static ACBASE_PORT const AcRxValueType& value() noexcept;
		static void del();
	};

	enum StringFormat
	{
		kStringFormatGlobal = 0,
		kStringFormatCurrent = 1,
	};

private:
	IAcRxNonBlittableType* m_pNonBlittable = nullptr;
	IAcRxEnumeration* m_pEnum = nullptr;
	IAcRxReferenceType* m_pRef = nullptr;
	IAcRxObjectValue* m_pRxObjValue = nullptr;
	void* m_unused1 = nullptr;
	unsigned int m_size = 0;

private:
	AcRxValueType& operator=(const AcRxValueType& rhs);
	AcRxValueType(const AcRxValueType& rhs);
	virtual bool subEqualTo(const void* a, const void* b) const = 0;
	virtual int subToString(const void* instance, ACHAR* buffer, size_t sizeInACHARs,
							AcRxValueType::StringFormat format) const = 0;

protected:
	ACBASE_PORT AcRxValueType(const ACHAR* name, const ACHAR* parent,
							  const IAcRxNonBlittableType& nonBlittable, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);
	ACBASE_PORT AcRxValueType(const ACHAR* name, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);

	ACBASE_PORT AcRxValueType(const ACHAR* name, const IAcRxNonBlittableType& pNonBlittable,
							  unsigned int size, AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);

	ACBASE_PORT AcRxValueType(const ACHAR* name, const IAcRxEnumeration& pEnum, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);
	ACBASE_PORT AcRxValueType(const ACHAR* name, const IAcRxEnumeration* pEnum,
							  const IAcRxNonBlittableType* pNonBlittable, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);
	ACBASE_PORT AcRxValueType(const ACHAR* name, const IAcRxEnumeration& pEnum,
							  const IAcRxNonBlittableType& pNonBlittable, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);
	ACBASE_PORT AcRxValueType(const ACHAR* name, const IAcRxObjectValue& rxObjValue,
							  const IAcRxNonBlittableType& pNonBlittable, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);
	ACBASE_PORT AcRxValueType(const ACHAR* name, const IAcRxReferenceType& pRef, unsigned int size,
							  AcRxMemberCollectionConstructorPtr memberConstruct,
							  void* userData = nullptr);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxValueType, ACBASE_PORT);

	ACBASE_PORT ~AcRxValueType();
	bool operator==(const AcRxValueType& rhs) const { return this == &rhs; }
	bool operator!=(const AcRxValueType& rhs) const { return this != &rhs; }

	ACBASE_PORT static __declspec(noreturn) void badCast();
	const IAcRxEnumeration* enumeration() const { return m_pEnum; }
	bool equalTo(const void* a, const void* b) const
	{
		ACRXVALUE_ASSERT(a);
		if (!a)
			return false;
		ACRXVALUE_ASSERT(b);
		if (!b)
			return false;
		return subEqualTo(a, b);
	}
	bool isBlittable() const { return m_pNonBlittable == 0; }
	bool isEnum() const { return m_pEnum != 0; }
	bool isReference() const { return m_pRef != 0; }
	const IAcRxNonBlittableType* nonBlittable() const { return m_pNonBlittable; }
	const IAcRxReferenceType* reference() const { return m_pRef; }
	const IAcRxObjectValue* rxObjectValue() const { return m_pRxObjValue; }
	unsigned int size() const { return m_size; }
	int toString(const void* instance, ACHAR* buffer, size_t sizeInACHARs,
				 StringFormat format) const
	{
		ACRXVALUE_ASSERT(instance);
		if (!instance)
			return -1;
		ACRXVALUE_ASSERT((sizeInACHARs == 0) == (buffer == nullptr));
		if ((sizeInACHARs == 0) != (buffer == nullptr))
			return -1;
		return subToString(instance, buffer, sizeInACHARs, format);
	}
};

class AcCmColor;
class AcDbBlockParamValueSet;
class AcDbDate;
class AcDbLoftOptions;
class AcDbMText;
class AcDbSweepOptions;
class AcDbTableCellBlockReference;
class AcGeMatrix3d;
class AcGiLightAttenuation;
class AcGiMaterialColor;
class AcGiMaterialMap;
class AcGiPhotographicExposureParameters;
class AcGiShadowParameters;
class AcGiSkyParameters;
class AcGiToneOperatorParameters;
class AcString;
class AcUnderlayLayer;
struct DimFillColor;

using AcDbBlkParamValueSetValuesArray = AcArray<double>;
using AcStringArray = AcArray<AcString, AcArrayObjectCopyReallocator<AcString>>;

template<>
struct AcRxValueType::Desc<void>
{
	ACBASE_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<const ACHAR*>
{
	ACBASE_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<const char*>
{
	ACBASE_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcCmColor>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbBlkParamValueSetValuesArray>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbBlockParamValueSet>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbDate>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbIntArray>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbLoftOptions>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbMText*>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbSweepOptions>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcDbTableCellBlockReference>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGeMatrix3d>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiLightAttenuation>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiMaterialColor>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiMaterialMap>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiPhotographicExposureParameters>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiShadowParameters>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiSkyParameters>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcGiToneOperatorParameters>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcStringArray>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<AcUnderlayLayer>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

template<>
struct AcRxValueType::Desc<DimFillColor>
{
	ACDBCORE2D_PORT static const AcRxValueType& value() noexcept;
	static void del();
};

#include "IcArxPackPop.h"
