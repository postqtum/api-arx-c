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

#include <cstddef>
#include "dbdict.h"
#include "AcString.h"

namespace AcDbDictUtil
{

inline Acad::ErrorStatus dictionaryGetAt(AcDbObjectId& id, const ACHAR* name,
										 AcDbObjectId ownerDictId)
{
	id.setNull();
	AcDbDictionary* pDict;
	Acad::ErrorStatus es = ::acdbOpenObject(pDict, ownerDictId, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		es = pDict->getAt(name, id);
		pDict->close();
	}
	return es;
}

inline Acad::ErrorStatus dictionaryNameAt(AcString& name, AcDbObjectId itemId,
										  AcDbObjectId ownerDictId)
{
	name.setEmpty();
	AcDbDictionary* pDict;
	Acad::ErrorStatus es = ::acdbOpenObject(pDict, ownerDictId, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		es = pDict->nameAt(itemId, name);
		pDict->close();
	}
	return es;
}

inline Acad::ErrorStatus dictionaryNameAt(AcString& name, AcDbObjectId itemId)
{
	name.setEmpty();
	AcDbObject* pObject;
	Acad::ErrorStatus es = ::acdbOpenObject(pObject, itemId, AcDb::kForRead);
	if (es != Acad::eOk)
		return es;
	const AcDbObjectId dictId = pObject->ownerId();
	es = pObject->close();
	return AcDbDictUtil::dictionaryNameAt(name, itemId, dictId);
}

inline Acad::ErrorStatus dictionaryNameAt(ACHAR*& pName, AcDbObjectId itemId,
										  AcDbObjectId ownerDictId)
{
	AcString sName;
	return ::acutAcStringToAChar(sName, pName,
								 AcDbDictUtil::dictionaryNameAt(sName, itemId, ownerDictId));
}

inline Acad::ErrorStatus dictionaryNameAt(ACHAR*& pName, AcDbObjectId itemId)
{
	AcString sName;
	return ::acutAcStringToAChar(sName, pName, AcDbDictUtil::dictionaryNameAt(sName, itemId));
}

#define DBDICTUTIL_MAKE_DICTIONARY_UTILS(LOWERNAME, UPPERNAME)                               \
	inline Acad::ErrorStatus get##UPPERNAME##Id(AcDbObjectId& id, const ACHAR* name,         \
												AcDbDatabase* pDb)                           \
	{                                                                                        \
		id.setNull();                                                                        \
		if (pDb == nullptr)                                                                  \
			return Acad::eNoDatabase;                                                        \
		return AcDbDictUtil::dictionaryGetAt(id, name, pDb->LOWERNAME##DictionaryId());      \
	}                                                                                        \
	inline Acad::ErrorStatus get##UPPERNAME##Name(AcString& name, AcDbObjectId itemId)       \
	{                                                                                        \
		name.setEmpty();                                                                     \
		AcDbDatabase* pDb = itemId.database();                                               \
		if (pDb == nullptr)                                                                  \
			return Acad::eNoDatabase;                                                        \
		return AcDbDictUtil::dictionaryNameAt(name, itemId, pDb->LOWERNAME##DictionaryId()); \
	}                                                                                        \
	inline Acad::ErrorStatus get##UPPERNAME##Name(ACHAR*& name, AcDbObjectId itemId)         \
	{                                                                                        \
		AcString sName;                                                                      \
		return ::acutAcStringToAChar(sName, name,                                            \
									 AcDbDictUtil::get##UPPERNAME##Name(sName, itemId));     \
	}                                                                                        \
	inline bool has##UPPERNAME(const ACHAR* name, AcDbDatabase* pDb)                         \
	{                                                                                        \
		AcDbObjectId id;                                                                     \
		return AcDbDictUtil::get##UPPERNAME##Id(id, name, pDb) == Acad::eOk;                 \
	}

DBDICTUTIL_MAKE_DICTIONARY_UTILS(color, Color)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(group, Group)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(layout, Layout)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(mLStyle, MLStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(material, Material)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(namedObjects, NamedObjects)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(plotSettings, PlotSettings)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(plotStyleName, PlotStyleName)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(scaleList, ScaleList)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(tableStyle, TableStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS(visualStyle, VisualStyle)

#undef DBDICTUTIL_MAKE_DICTIONARY_UTILS

}  // namespace AcDbDictUtil
