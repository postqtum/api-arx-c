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
***     Description: Declaration of AcDMMXMLAttribute class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"
#include "../acarray.h"

#include "IcArxPackPush.h"

class AcDMMXMLAttribute
{
private:
	AcString m_namespace;
	AcString m_namespaceUrl;
	AcString m_attributeName;
	AcString m_attributeValue;

public:
	AcDMMXMLAttribute() = default;
	AcDMMXMLAttribute(const wchar_t* ns, const wchar_t* nsUrl, const wchar_t* attName,
					  const wchar_t* attValue)
			: m_namespace(ns)
			, m_namespaceUrl(nsUrl)
			, m_attributeName(attName)
			, m_attributeValue(attValue)
	{
	}
	AcDMMXMLAttribute(const AcDMMXMLAttribute& src) = default;
	~AcDMMXMLAttribute() = default;
	AcDMMXMLAttribute& operator=(const AcDMMXMLAttribute& src) = default;
	const wchar_t* GetAttributeName() const
	{
		return m_attributeName.isEmpty() ? nullptr : m_attributeName.constPtr();
	}
	const wchar_t* GetAttributeValue() const
	{
		return m_attributeValue.isEmpty() ? nullptr : m_attributeValue.constPtr();
	}
	const wchar_t* GetNamespace() const
	{
		return m_namespace.isEmpty() ? nullptr : m_namespace.constPtr();
	}
	const wchar_t* GetNamespaceUrl() const
	{
		return m_namespaceUrl.isEmpty() ? nullptr : m_namespaceUrl.constPtr();
	}
	void SetAttributeName(const wchar_t* attName) { m_attributeName = attName; }
	void SetAttributeValue(const wchar_t* attValue) { m_attributeValue = attValue; }
	void SetNamespace(const wchar_t* ns) { m_namespace = ns; }
	void SetNamespaceUrl(const wchar_t* nsUrl) { m_namespaceUrl = nsUrl; }
};

#include "IcArxPackPop.h"

typedef AcArray<AcDMMXMLAttribute> AcDMMXMLAttributeVec;
