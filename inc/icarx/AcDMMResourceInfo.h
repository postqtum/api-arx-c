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
***     Description: Declaration of AcDMMResourceInfo class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "../acarray.h"

#include "IcArxPackPush.h"

class AcDMMResourceInfo
{
private:
	AcString m_role;
	AcString m_mime;
	AcString m_path;

public:
	AcDMMResourceInfo() = default;
	AcDMMResourceInfo(const wchar_t* role, const wchar_t* mime, const wchar_t* path)
			: m_role(role), m_mime(mime), m_path(path)
	{
	}
	AcDMMResourceInfo(const AcDMMResourceInfo& src) = default;
	~AcDMMResourceInfo() = default;
	AcDMMResourceInfo& operator=(const AcDMMResourceInfo& src) = default;

	const wchar_t* GetMime() const { return m_mime.isEmpty() ? nullptr : m_mime.constPtr(); }
	const wchar_t* GetPath() const { return m_path.isEmpty() ? nullptr : m_path.constPtr(); }
	const wchar_t* GetRole() const { return m_role.isEmpty() ? nullptr : m_role.constPtr(); }
	void SetMime(const wchar_t* mime) { m_mime = mime; }
	void SetPath(const wchar_t* path) { m_path = path; }
	void SetRole(const wchar_t* role) { m_role = role; }
};

#include "IcArxPackPop.h"

typedef AcArray<AcDMMResourceInfo> AcDMMResourceVec;
