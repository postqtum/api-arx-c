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
***     Description: Declaration of AcGsDCRect class
***
*****************************************************************************/
#pragma once

#include "AcGsDCPoint.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class AcGsDCRect
{
public:
	enum NullFlag
	{
		Null
	};

public:
	AcGsDCPoint m_min;
	AcGsDCPoint m_max;

public:
	AcGsDCRect() = default;
	AcGsDCRect(AcGsDCPoint const& min, AcGsDCPoint const& max) : m_min(min), m_max(max) {}
	AcGsDCRect(long l, long r, long b, long t) : m_min(l, b), m_max(r, t) {}
	AcGsDCRect(NullFlag) { set_null(); }
	AcGsDCRect& operator=(AcGsDCRect const& other)
	{
		m_min = other.m_min;
		m_max = other.m_max;
		return *this;
	}
	bool operator==(AcGsDCRect const& rightside) const
	{
		return m_min == rightside.m_min && m_max == rightside.m_max;
	}
	bool operator!=(AcGsDCRect const& rightside) const { return !(*this == rightside); }
	void operator&=(AcGsDCRect const& rightside)
	{
		if (m_min.x < rightside.m_min.x)
			m_min.x = rightside.m_min.x;
		if (m_max.x > rightside.m_max.x)
			m_max.x = rightside.m_max.x;

		if (m_min.y < rightside.m_min.y)
			m_min.y = rightside.m_min.y;
		if (m_max.y > rightside.m_max.y)
			m_max.y = rightside.m_max.y;

		if (m_min.x > m_max.x || m_min.y > m_max.y)
			*this = Null;
	}
	void operator|=(AcGsDCRect const& rightside)
	{
		if (m_min.x > rightside.m_min.x)
			m_min.x = rightside.m_min.x;
		if (m_max.x < rightside.m_max.x)
			m_max.x = rightside.m_max.x;

		if (m_min.y > rightside.m_min.y)
			m_min.y = rightside.m_min.y;
		if (m_max.y < rightside.m_max.y)
			m_max.y = rightside.m_max.y;
	}

	bool is_null() const
	{
		ICARX_ASSERT((m_min.x <= m_max.x && m_min.y <= m_max.y) ||
					 (m_min == AcGsDCPoint::Maximum && m_max == AcGsDCPoint::Minimum));
		return m_min.x > m_max.x;
	}
	void set_null()
	{
		m_min = AcGsDCPoint::Maximum;
		m_max = AcGsDCPoint::Minimum;
	}
	bool within(AcGsDCRect const& rightside) const
	{
		ICARX_ASSERT(!is_null());
		return m_min.x >= rightside.m_min.x && m_min.y >= rightside.m_min.y &&
			   m_max.x <= rightside.m_max.x && m_max.y <= rightside.m_max.y;
	}
};

#include "IcArxPackPop.h"
