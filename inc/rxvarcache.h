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
***     Description:
***
*****************************************************************************/
#pragma once

#include "rxvar.h"
#include "adscodes.h"
#include "adsdef.h"
#include "eoktest.h"
#include "icarx/IcArxAssert.h"

extern void acutDelString(wchar_t*& pString);
extern Acad::ErrorStatus acutUpdString(const ACHAR* pString, ACHAR*& newString);

#include "icarx/IcArxPackPush.h"

class AcRxVariableCache : public AcRxVariableReactor
{
private:
	resbuf m_cache;
	AcString m_name;

private:
	void changed(const AcRxVariable* sender, const AcRxVariableChangedEventArgs& args) override
	{
		if (m_cache.restype == RTSTR)
			acutDelString(m_cache.resval.rstring);
		const auto& rb = args.newValue();
		memcpy_s(&m_cache, sizeof(m_cache), &rb, sizeof(rb));
		if (rb.restype == RTSTR)
		{
			m_cache.resval.rstring = nullptr;
			Acad::ErrorStatus es = acutUpdString(rb.resval.rstring, m_cache.resval.rstring);
			ICARX_ASSERT(Acad::eOk == es);
		}
	}
	bool reload(const AcRxVariable* source)
	{
		if (m_cache.restype == RTSTR)
			acutDelString(m_cache.resval.rstring);
		return eOkVerify(source->getValue(m_cache));
	}

public:
	AcRxVariableCache(const ACHAR* name) : m_name(name), m_cache({0})
	{
		m_cache.restype = RTNONE;
		auto var = AcRxVariablesDictionary::get()->getVariable(name);
		if (var == nullptr)
			return;
		var->addReactor(this);
		reload(var);
	}
	~AcRxVariableCache()
	{
		if (m_cache.restype == RTSTR)
			acutDelString(m_cache.resval.rstring);

		auto var = AcRxVariablesDictionary::get()->getVariable(m_name.kwszPtr());
		if (var == nullptr)
			return;
		var->removeReactor(this);
	}

	bool getBool(bool def) { return !!getInt16(def ? 1 : 0); }
	double getDouble(double def)
	{
		ICARX_ASSERT(m_cache.restype == RTREAL || m_cache.restype == RTNONE);
		if (m_cache.restype != RTREAL)
			return def;
		return m_cache.resval.rreal;
	}
	short getInt16(short def)
	{
		ICARX_ASSERT(m_cache.restype == RTSHORT || m_cache.restype == RTNONE);
		if (m_cache.restype != RTSHORT)
			return def;
		return m_cache.resval.rint;
	}
	AcString getString()
	{
		AcString ret;
		ICARX_ASSERT(m_cache.restype == RTSTR || m_cache.restype == RTNONE);
		if (m_cache.restype != RTSTR)
			return ret;
		return m_cache.resval.rstring;
	}
	bool reload()
	{
		auto var = AcRxVariablesDictionary::get()->getVariable(m_name.kwszPtr());
		if (var == nullptr)
			return false;
		return reload(var);
	}
};

#include "icarx/IcArxPackPop.h"
