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
***     Description: Declaration of AcGiVariant class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "../AcString.h"
#include "acut_str_util.h"

class AcCmColor;
class AcGiImpVariant;

#include "IcArxPackPush.h"

class AcGiVariant : public AcRxObject
{
private:
	AcGiImpVariant* mpAcGiImpVariant;

public:
	class EnumType
	{
	protected:
		int m_value;

	public:
		explicit EnumType(int value) : m_value(value) {}

		template<typename T>
		operator T()
		{
			return static_cast<T>(m_value);
		}
		template<typename T>
		bool operator==(T right) const
		{
			return static_cast<int>(right) == m_value;
		}
		template<typename T>
		bool operator!=(T right) const
		{
			return !(*this == right);
		}
	};

	enum VariantType
	{
		kUndefined = 0,
		kBoolean,
		kInt,
		kDouble,
		kColor,
		kString,
		kTable,
	};

	ACRX_DECLARE_MEMBERS(AcGiVariant);

	ACDBCORE2D_PORT AcGiVariant();
	AcGiVariant(bool);
	AcGiVariant(const ACHAR*);
	AcGiVariant(const AcCmColor&);
	AcGiVariant(const AcGiVariant& value);
	AcGiVariant(double);
	ACDBCORE2D_PORT AcGiVariant(int32_t);
	ACDBCORE2D_PORT ~AcGiVariant();
	AcGiVariant& operator=(const AcGiVariant& value);
	virtual bool operator==(const AcGiVariant& value) const;

	bool asBoolean() const;
	ACDBCORE2D_PORT char asChar() const;
	AcCmColor asColor() const;
	double asDouble() const;
	ACDBCORE2D_PORT EnumType asEnum() const;
	ACDBCORE2D_PORT float asFloat() const;
	int asInt() const;
	ACDBCORE2D_PORT int32_t asLong() const;
	ACDBCORE2D_PORT short asShort() const;
	AcString asString() const;
	ACDBCORE2D_PORT unsigned char asUchar() const;
	ACDBCORE2D_PORT unsigned int asUint() const;
	ACDBCORE2D_PORT uint32_t asUlong() const;
	ACDBCORE2D_PORT unsigned short asUshort() const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	void deleteElem(const ACHAR* pKey);
	const AcGiVariant* getElem(const ACHAR* pKey) const;
	Acad::ErrorStatus getElem(const ACHAR* pKey, AcGiVariant& value) const;
	AcGiVariant* getElemAt(int nIndex, ACHAR*&) const;
	Acad::ErrorStatus getElemAt(int nIndex, ACHAR*&, AcGiVariant&) const;
	ACDBCORE2D_PORT AcGiVariant* getElemAt(int nIndex, AcString&) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getElemAt(int nIndex, AcString&, AcGiVariant&) const;
	int getElemCount() const;
	static bool isEquivalent(const AcGiVariant*, const AcGiVariant*);
	void set(bool);
	void set(const ACHAR*);
	void set(const AcCmColor&);
	void set(double);
	void set(int32_t);
	void setElem(const ACHAR* pKey, const AcGiVariant&);
	VariantType type() const;
};

#include "IcArxPackPop.h"

template<typename T>
inline bool operator==(T left, const AcGiVariant::EnumType right)
{
	return (right == left);
}

template<typename T>
inline bool operator!=(T left, const AcGiVariant::EnumType right)
{
	return (right != left);
}

inline AcGiVariant* AcGiVariant::getElemAt(int nIndex, ACHAR*& pStr) const
{
	AcString sElem;
	AcGiVariant* pVar = this->getElemAt(nIndex, sElem);
	::acutNewString(sElem.constPtr(), pStr);
	return pVar;
}

inline Acad::ErrorStatus AcGiVariant::getElemAt(int nIndex, ACHAR*& pStr, AcGiVariant& var) const
{
	AcString sElem;
	const Acad::ErrorStatus es = this->getElemAt(nIndex, sElem, var);
	if (es != Acad::eOk)
		pStr = nullptr;
	else
		::acutNewString(sElem.constPtr(), pStr);
	return es;
}
