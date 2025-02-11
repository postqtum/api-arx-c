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
***     Description: Declaration of AcDMMEPlotProperties class
***
*****************************************************************************/
#pragma once

#include "AcDMMEPlotProperty.h"
#include "AcDMMWideString.h"

#include "IcArxPackPush.h"

class AcDMMEPlotProperties
{
private:
	AcDMMEPlotPropertyVec m_properties;
	AcString m_id;
	AcDMMStringVec m_refs;

public:
	AcDMMEPlotProperties() = default;
	AcDMMEPlotProperties(const AcDMMEPlotProperties& src) = default;
	~AcDMMEPlotProperties() = default;
	AcDMMEPlotProperties& operator=(const AcDMMEPlotProperties& src) = default;

	void AddProperty(const AcDMMEPlotProperty* property)
	{
		if (!property)
			return;
		m_properties.append(*property);
	}
	void AddProperty(wchar_t* name, wchar_t* value)
	{
		AcDMMEPlotProperty newProp(name, value);
		m_properties.append(newProp);
	}
	const wchar_t* GetId() const { return m_id.isEmpty() ? nullptr : m_id.constPtr(); }
	const AcDMMEPlotPropertyVec& GetProperties() const { return m_properties; }
	const AcDMMEPlotProperty* GetProperty(unsigned long index) const
	{
		if (m_properties.length() <= (int)index)
			return nullptr;
		return &m_properties[index];
	}
	const AcDMMStringVec* GetRefs() const { return &m_refs; }
	void SetId(const wchar_t* id)
	{
		m_id = id;
	}
	void SetRefs(const AcDMMStringVec& refs) { m_refs = refs; }
};

#include "IcArxPackPop.h"
