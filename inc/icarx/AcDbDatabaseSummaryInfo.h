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
***     Description: Declaration of AcDbDatabaseSummaryInfo class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../AcString.h"
#include "acut_str_util.h"

class AcDbDatabase;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDatabaseSummaryInfo : public AcRxObject
{
private:
	using GetPropAcString = Acad::ErrorStatus (AcDbDatabaseSummaryInfo::*)(AcString&) const;

private:
	Acad::ErrorStatus getACharString(GetPropAcString pMeth, ACHAR*& rpBuf) const;

protected:
	AcDbDatabaseSummaryInfo();

public:
	ACRX_DECLARE_MEMBERS(AcDbDatabaseSummaryInfo);

	~AcDbDatabaseSummaryInfo() = default;

	virtual Acad::ErrorStatus addCustomSummaryInfo(const ACHAR* key, const ACHAR* value) = 0;
	virtual Acad::ErrorStatus deleteCustomSummaryInfo(const ACHAR* key) = 0;
	virtual Acad::ErrorStatus deleteCustomSummaryInfo(int index) = 0;
	virtual Acad::ErrorStatus getAuthor(ACHAR*& author) const;
	virtual Acad::ErrorStatus getAuthor(AcString& author) const = 0;
	virtual Acad::ErrorStatus getComments(ACHAR*& comments) const;
	virtual Acad::ErrorStatus getComments(AcString& comments) const = 0;
	virtual Acad::ErrorStatus getCustomSummaryInfo(const ACHAR* customInfoKey, ACHAR*& value) const;
	virtual Acad::ErrorStatus getCustomSummaryInfo(const ACHAR* customInfoKey,
												   AcString& value) const = 0;
	virtual Acad::ErrorStatus getCustomSummaryInfo(int index, ACHAR*& key, ACHAR*& value) const;
	virtual Acad::ErrorStatus getCustomSummaryInfo(int index, AcString& key,
												   AcString& value) const = 0;
	virtual Acad::ErrorStatus getHyperlinkBase(ACHAR*& HyperlinkBase) const;
	virtual Acad::ErrorStatus getHyperlinkBase(AcString& HyperlinkBase) const = 0;
	virtual Acad::ErrorStatus getKeywords(ACHAR*& keywordlist) const;
	virtual Acad::ErrorStatus getKeywords(AcString& keywordlist) const = 0;
	virtual Acad::ErrorStatus getLastSavedBy(ACHAR*& lastSavedBy) const;
	virtual Acad::ErrorStatus getLastSavedBy(AcString& lastSavedBy) const = 0;
	virtual Acad::ErrorStatus getRevisionNumber(ACHAR*& revisionNumber) const;
	virtual Acad::ErrorStatus getRevisionNumber(AcString& revisionNumber) const = 0;
	virtual Acad::ErrorStatus getSubject(ACHAR*& subject) const;
	virtual Acad::ErrorStatus getSubject(AcString& subject) const = 0;
	virtual Acad::ErrorStatus getTitle(ACHAR*& title) const;
	virtual Acad::ErrorStatus getTitle(AcString& title) const = 0;
	virtual Acad::ErrorStatus setAuthor(const ACHAR* author) = 0;
	virtual Acad::ErrorStatus setComments(const ACHAR* comments) = 0;
	virtual Acad::ErrorStatus setCustomSummaryInfo(const ACHAR* customInfoKey,
												   const ACHAR* value) = 0;
	virtual Acad::ErrorStatus setCustomSummaryInfo(int index, const ACHAR* key,
												   const ACHAR* value) = 0;
	virtual Acad::ErrorStatus setHyperlinkBase(const ACHAR* HyperlinkBase) = 0;
	virtual Acad::ErrorStatus setKeywords(const ACHAR* keywordlist) = 0;
	virtual Acad::ErrorStatus setLastSavedBy(const ACHAR* lastSavedBy) = 0;
	virtual Acad::ErrorStatus setRevisionNumber(const ACHAR* revisionNumber) = 0;
	virtual Acad::ErrorStatus setSubject(const ACHAR* subject) = 0;
	virtual Acad::ErrorStatus setTitle(const ACHAR* title) = 0;
	virtual AcDbDatabase* database() const = 0;
	virtual int numCustomInfo() const = 0;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getACharString(GetPropAcString pMeth,
																 ACHAR*& rpBuf) const
{
	rpBuf = nullptr;
	AcString sTemp;
	const Acad::ErrorStatus es = (this->*pMeth)(sTemp);
	if (es == Acad::eOk)
		::acutNewString(sTemp.constPtr(), rpBuf);
	return es;
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getAuthor(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getAuthor, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getComments(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getComments, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getCustomSummaryInfo(const ACHAR* customInfoKey,
																	   ACHAR*& value) const
{
	AcString sValue;
	const Acad::ErrorStatus es = getCustomSummaryInfo(customInfoKey, sValue);
	if (es == Acad::eOk)
		::acutNewString(sValue.constPtr(), value);
	else
		value = nullptr;
	return es;
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getCustomSummaryInfo(int index, ACHAR*& key,
																	   ACHAR*& value) const
{
	AcString sKey, sValue;
	const Acad::ErrorStatus es = getCustomSummaryInfo(index, sKey, sValue);
	if (es == Acad::eOk)
	{
		::acutNewString(sKey.constPtr(), key);
		::acutNewString(sValue.constPtr(), value);
	}
	else
		key = value = nullptr;
	return es;
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getHyperlinkBase(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getHyperlinkBase, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getKeywords(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getKeywords, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getLastSavedBy(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getLastSavedBy, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getSubject(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getSubject, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getRevisionNumber(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getRevisionNumber, title);
}

inline Acad::ErrorStatus AcDbDatabaseSummaryInfo::getTitle(ACHAR*& title) const
{
	return getACharString(&AcDbDatabaseSummaryInfo::getTitle, title);
}

ACDBCORE2D_PORT Acad::ErrorStatus acdbGetSummaryInfo(AcDbDatabase* pDb,
													 AcDbDatabaseSummaryInfo*& pInfo);
ACDBCORE2D_PORT Acad::ErrorStatus acdbPutSummaryInfo(const AcDbDatabaseSummaryInfo* pInfo,
													 AcDbDatabase* pDb);
inline Acad::ErrorStatus acdbPutSummaryInfo(const AcDbDatabaseSummaryInfo* pInfo)
{
	return ::acdbPutSummaryInfo(pInfo, pInfo->database());
}
ACDBCORE2D_PORT Acad::ErrorStatus acdbValidateCustomSummaryInfoKey(
		const wchar_t* key, const AcDbDatabaseSummaryInfo* pInfo = nullptr);
