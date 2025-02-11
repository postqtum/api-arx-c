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
***     Description: Declaration of AcDMMEPlotProperty class
***
*****************************************************************************/
#pragma once

#include "AcDMMXMLAttribute.h"

#include "IcArxPackPush.h"

class AcDMMEPlotProperty
{
private:
	AcString m_name;
	AcString m_value;
	AcString m_type;
	AcString m_units;
	AcString m_category;
	AcDMMXMLAttributeVec m_XMLAttributes;

public:
	AcDMMEPlotProperty() = default;
	AcDMMEPlotProperty(const wchar_t* name, const wchar_t* value)
			: m_name(name), m_value(value), m_type(), m_units(), m_category(), m_XMLAttributes()
	{
	}
	AcDMMEPlotProperty(const AcDMMEPlotProperty& src) = default;
	~AcDMMEPlotProperty() = default;
	AcDMMEPlotProperty& operator=(const AcDMMEPlotProperty& src) = default;

	void AddXMLAttribute(const AcDMMXMLAttribute* attrib)
	{
		if (attrib)
			AddXMLAttribute(attrib->GetNamespace(), attrib->GetNamespaceUrl(),
							attrib->GetAttributeName(), attrib->GetAttributeValue());
	}
	void AddXMLAttribute(const wchar_t* ns, const wchar_t* nsUrl, const wchar_t* attName,
						 const wchar_t* attValue)
	{
		if (nullptr != ns && nullptr != nsUrl && nullptr != attName && nullptr != attValue)
			m_XMLAttributes.append(AcDMMXMLAttribute(ns, nsUrl, attName, attValue));
	}
	const wchar_t* GetCategory() const { return m_category.isEmpty() ? nullptr : m_category.constPtr(); }
	const wchar_t* GetName() const { return m_name.isEmpty() ? nullptr : m_name.constPtr(); }
	const wchar_t* GetType() const { return m_type.isEmpty() ? nullptr : m_type.constPtr(); }
	const wchar_t* GetUnits() const { return m_units.isEmpty() ? nullptr : m_units.constPtr(); }
	const wchar_t* GetValue() const { return m_value.isEmpty() ? nullptr : m_value.constPtr(); }
	const AcDMMXMLAttributeVec& GetXMLAttributes() const { return m_XMLAttributes; }
	void SetCategory(const wchar_t* category) { m_category = category; }
	void SetName(const wchar_t* name) { m_name = name; }
	void SetType(const wchar_t* type) { m_type = type; }
	void SetUnits(const wchar_t* units) { m_units = units; }
	void SetValue(const wchar_t* value) { m_value = value; }
};

#include "IcArxPackPop.h"

typedef AcArray<AcDMMEPlotProperty> AcDMMEPlotPropertyVec;
