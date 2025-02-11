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
***     Description: Declaration of CAcUiLTypeRecord class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectId.h"

#include "IcArxPackPush.h"


class CAcUiLTypeRecord : public CObject
{
public:
	CString& ltypeName();
	void setLTypeName(CString sName);
	AcDbObjectId objectId();
	void setObjectId(AcDbObjectId id);
	BOOL isDependent();
	void setIsDependent(BOOL bValue);

private:
	CString m_strLTypeName;
	AcDbObjectId m_idObjectId;
	BOOL m_bIsDependent;
};

#include "IcArxPackPop.h"

inline CString& CAcUiLTypeRecord::ltypeName()
{
	return m_strLTypeName;
}

inline void CAcUiLTypeRecord::setLTypeName(CString sName)
{
	m_strLTypeName = sName;
}

inline AcDbObjectId CAcUiLTypeRecord::objectId()
{
	return m_idObjectId;
}

inline void CAcUiLTypeRecord::setObjectId(AcDbObjectId id)
{
	m_idObjectId = id;
}

inline BOOL CAcUiLTypeRecord::isDependent()
{
	return m_bIsDependent;
}

inline void CAcUiLTypeRecord::setIsDependent(BOOL bValue)
{
	m_bIsDependent = bValue;
}
