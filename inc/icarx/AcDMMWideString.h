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
***     Description: Declaration of AcDMMWideString class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"
#include "../acarray.h"

typedef const wchar_t* PCWIDESTR;
typedef wchar_t* PWIDESTR;

#include "IcArxPackPush.h"

class AcDMMWideString
{
private:
	AcString m_string;

public:
	AcDMMWideString() = default;
	AcDMMWideString(const AcDMMWideString& ws) = default;
	AcDMMWideString(PCWIDESTR pwsz) : m_string(pwsz) {}
	virtual ~AcDMMWideString() = default;
	AcDMMWideString& operator=(const AcDMMWideString& ws) = default;
	AcDMMWideString& operator=(PCWIDESTR pwsz)
	{
		m_string = pwsz;
		return *this;
	}
	AcDMMWideString& operator+=(const AcDMMWideString& ws)
	{
		m_string += ws.m_string;
		return *this;
	}
	operator PCWIDESTR() const { return m_string.constPtr(); }

	friend AcDMMWideString operator+(const AcDMMWideString& wsLeft, wchar_t wch)
	{
		auto result = wsLeft;
		result.m_string += wch;
		return result;
	}
	friend AcDMMWideString operator+(wchar_t wch, const AcDMMWideString& wsRight)
	{
		AcDMMWideString result;
		result.m_string = wch;
		result.m_string += wsRight.m_string;
		return result;
	}
	friend AcDMMWideString operator+(const AcDMMWideString& wsLeft, const AcDMMWideString& wsRight)
	{
		auto result = wsLeft;
		result.m_string += wsRight.m_string;
		return result;
	}

	void Empty() { m_string.setEmpty(); }
	unsigned GetLength() const { return static_cast<unsigned>(m_string.length()); }
	bool IsEmpty() const { return m_string.isEmpty(); }
};

#include "IcArxPackPop.h"

typedef AcArray<AcDMMWideString> AcDMMStringVec;
