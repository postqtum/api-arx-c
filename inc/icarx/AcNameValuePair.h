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
***     Description: Declaration of AcNameValuePair class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "../acarray.h"

#include "IcArxPackPush.h"

class AcNameValuePair
{
public:
	AcNameValuePair() = default;

	~AcNameValuePair() = default;

	AcNameValuePair(const ACHAR* name, const ACHAR* value) : m_name(name), m_value(value) {}

	AcNameValuePair(const AcNameValuePair& src) = default;

	AcNameValuePair& operator=(const AcNameValuePair& src) = default;

	const ACHAR* name() const { return m_name.isEmpty() ? nullptr : m_name.constPtr(); };

	void setName(const ACHAR* name) { m_name = name; }

	const ACHAR* value() const { return m_value.isEmpty() ? nullptr : m_value.constPtr(); };

	void setValue(const ACHAR* value) { m_value = value; }


private:
	AcString m_name;
	AcString m_value;
};

#include "IcArxPackPop.h"

using AcNameValuePairVec = AcArray<AcNameValuePair>;
