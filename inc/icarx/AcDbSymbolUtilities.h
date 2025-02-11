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
***     Description: Declaration of AcDbSymbolUtilities namespace
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../AcString.h"
#include "../dbmain.h"
#include "AcDbObjectId.h"
#include "AcDbSymbolTableRecord.h"
#include "AcDbDatabase.h"
#include "AcDbBlockTable.h"
#include "AcDbViewTable.h"
#include "AcDbViewportTable.h"
#include "AcDbUCSTable.h"
#include "AcDbTextStyleTable.h"
#include "AcDbLinetypeTable.h"
#include "AcDbLayerTable.h"
#include "AcDbDimStyleTable.h"
#include "AcDbReg.h"

#define ACDBSYMUTIL_SERVICES_CURRENT_VERSION 106

namespace AcDbSymbolUtilities
{

enum CompatibilityMode
{
	kPreExtendedNames = false,
	kExtendedNames = true,
};

enum NameCaseMode
{
	kForceToUpper = false,
	kPreserveCase = true,
};

enum NewNameMode
{
	kAsExistingName = false,
	kAsNewName = true,
};

enum VerticalBarMode
{
	kNoVerticalBar = false,
	kAllowVerticalBar = true,
};

#include "IcArxPackPush.h"

class Services
{
public:
	enum
	{
		kCurrentVersion = ACDBSYMUTIL_SERVICES_CURRENT_VERSION
	};

	virtual AcDbObjectId blockModelSpaceId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* blockModelSpaceName() const = 0;
	virtual AcDbObjectId blockPaperSpaceId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* blockPaperSpaceName() const = 0;
	virtual int compareSymbolName(const ACHAR* thisName, const ACHAR* otherName) const = 0;
	virtual bool compatibilityMode(AcDbDatabase* pDb) const = 0;
	virtual Acad::ErrorStatus getBlockNameFromInsertPathName(ACHAR*& pBlockName,
															 const ACHAR* pathName) const = 0;
	virtual Acad::ErrorStatus getInsertPathNameFromBlockName(ACHAR*& pPathName,
															 const ACHAR* blockName) const = 0;
	virtual bool getMaxSymbolNameLength(size_t& maxLength, size_t& maxSize, bool isNewName,
										bool compatibilityMode) const = 0;
	virtual Acad::ErrorStatus getPathNameFromSymbolName(ACHAR*& pPathName, const ACHAR* symbolName,
														const ACHAR* extensions) const = 0;
	virtual Acad::ErrorStatus getSymbolNameFromPathName(ACHAR*& pSymbolName, const ACHAR* pathName,
														const ACHAR* extensions) const = 0;
	virtual bool hasVerticalBar(const ACHAR* name) const = 0;
	virtual bool isBlockLayoutName(const ACHAR* name) const = 0;
	virtual bool isBlockModelSpaceName(const ACHAR* name) const = 0;
	virtual bool isBlockPaperSpaceName(const ACHAR* name) const = 0;
	virtual bool isLayerDefpointsName(const ACHAR* name) const = 0;
	virtual bool isLayerZeroName(const ACHAR* name) const = 0;
	virtual bool isLinetypeByBlockName(const ACHAR* name) const = 0;
	virtual bool isLinetypeByLayerName(const ACHAR* name) const = 0;
	virtual bool isLinetypeContinuousName(const ACHAR* name) const = 0;
	virtual bool isRegAppAcadName(const ACHAR* name) const = 0;
	virtual bool isTextStyleStandardName(const ACHAR* name) const = 0;
	virtual bool isViewportActiveName(const ACHAR* name) const = 0;
	virtual AcDbObjectId layerDefpointsId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* layerDefpointsName() const = 0;
	virtual AcDbObjectId layerZeroId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* layerZeroName() const = 0;
	virtual AcDbObjectId linetypeByBlockId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* linetypeByBlockName() const = 0;
	virtual AcDbObjectId linetypeByLayerId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* linetypeByLayerName() const = 0;
	virtual AcDbObjectId linetypeContinuousId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* linetypeContinuousName() const = 0;
	virtual Acad::ErrorStatus makeDependentName(ACHAR*& pNewName, const ACHAR* dwgName,
												const ACHAR* symbolName) const = 0;
	virtual Acad::ErrorStatus preValidateSymbolName(ACHAR*& pSymbolName,
													bool preserveCase) const = 0;
	virtual AcDbObjectId regAppAcadId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* regAppAcadName() const = 0;
	virtual Acad::ErrorStatus repairPreExtendedSymbolName(ACHAR*& pNewName, const ACHAR* oldName,
														  bool allowVerticalBar) const = 0;
	virtual Acad::ErrorStatus repairSymbolName(ACHAR*& pNewName, const ACHAR* oldName,
											   bool allowVerticalBar) const = 0;
	virtual bool splitDependentName(size_t& numLeftBytes, const ACHAR*& pRight,
									const ACHAR* symbolName) const = 0;
	virtual AcDbObjectId textStyleStandardId(AcDbDatabase* pDb) const = 0;
	virtual const ACHAR* textStyleStandardName() const = 0;
	virtual Acad::ErrorStatus validateCompatibleSymbolName(const ACHAR* name, bool isNewName,
														   bool allowVerticalBar,
														   bool compatibilityMode) const = 0;
	virtual Acad::ErrorStatus validatePreExtendedSymbolName(const ACHAR* name,
															bool allowVerticalBar) const = 0;
	virtual Acad::ErrorStatus validateSymbolName(const ACHAR* name,
												 bool allowVerticalBar) const = 0;
	virtual int version() const = 0;
	virtual const ACHAR* viewportActiveName() const = 0;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus getSymbolName(AcString& sName, AcDbObjectId objId)
{
	sName.setEmpty();
	AcDbSymbolTableRecord* pRec = nullptr;
	Acad::ErrorStatus es = ::acdbOpenObject(pRec, objId, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		es = pRec->getName(sName);
		pRec->close();
	}
	return es;
}

inline Acad::ErrorStatus getSymbolName(ACHAR*& pName, AcDbObjectId objId)
{
	AcString sName;
	return ::acutAcStringToAChar(sName, pName, AcDbSymbolUtilities::getSymbolName(sName, objId));
}

#define ACDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n, v) n##v
#define ACDBSYMUTIL_SERVICESNAME_WITH_VERSION(n, v) ACDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n, v)
#define ACDBSYMUTIL_SERVICES_NAME \
	ACDBSYMUTIL_SERVICESNAME_WITH_VERSION(servicesPtr, ACDBSYMUTIL_SERVICES_CURRENT_VERSION)

ACDBCORE2D_PORT const Services* ACDBSYMUTIL_SERVICES_NAME();

inline const Services* servicesPtr()
{
	const Services* pSymUtil = ACDBSYMUTIL_SERVICES_NAME();
	return pSymUtil;
}

#define DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(T_TABLE)                                   \
	inline Acad::ErrorStatus get##T_TABLE##Id(AcDbObjectId& objId, const ACHAR* name, \
											  AcDbDatabase* pDb)                      \
	{                                                                                 \
		if (!pDb)                                                                     \
			return Acad::eNullObjectPointer;                                          \
		AcDb##T_TABLE##Table* pTable = nullptr;                                       \
		Acad::ErrorStatus es = pDb->getSymbolTable(pTable, AcDb::kForRead);           \
		if (es == Acad::eOk)                                                          \
		{                                                                             \
			es = pTable->getAt(name, objId);                                          \
			pTable->close();                                                          \
		}                                                                             \
		return es;                                                                    \
	}
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Block)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(DimStyle)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Layer)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Linetype)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(RegApp)

inline Acad::ErrorStatus getTextStyleId(AcDbObjectId& objId, const ACHAR* name, AcDbDatabase* pDb)
{
	if (!pDb)
		return Acad::eNullObjectPointer;
	AcDbTextStyleTable* pTable = nullptr;
	Acad::ErrorStatus es = pDb->getSymbolTable(pTable, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		AcDbTextStyleTableRecord* pRec = nullptr;
		es = pTable->getAt(name, pRec, AcDb::kForRead);
		if (es == Acad::eOk)
		{
			if (pRec->isShapeFile())
				es = Acad::eKeyNotFound;
			else
				objId = pRec->objectId();
			pRec->close();
		}
		pTable->close();
	}
	return es;
}

DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(UCS)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(View)
#undef DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION

#define DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(T_TABLE)                         \
	inline bool has##T_TABLE(AcDbObjectId objId, AcDbDatabase* pDb)         \
	{                                                                       \
		if (!pDb)                                                           \
			return false;                                                   \
		bool hasSymbol = false;                                             \
		AcDb##T_TABLE##Table* pTable = nullptr;                             \
		Acad::ErrorStatus es = pDb->getSymbolTable(pTable, AcDb::kForRead); \
		if (es == Acad::eOk)                                                \
		{                                                                   \
			hasSymbol = !!pTable->has(objId);                               \
			pTable->close();                                                \
		}                                                                   \
		return hasSymbol;                                                   \
	}
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Block)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(DimStyle)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Layer)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Linetype)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(RegApp)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(TextStyle)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(UCS)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(View)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Viewport)
#undef DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION

#define DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(T_TABLE)                       \
	inline bool has##T_TABLE(const ACHAR* name, AcDbDatabase* pDb)          \
	{                                                                       \
		if (!pDb)                                                           \
			return false;                                                   \
		bool hasSymbol = false;                                             \
		AcDb##T_TABLE##Table* pTable = nullptr;                             \
		Acad::ErrorStatus es = pDb->getSymbolTable(pTable, AcDb::kForRead); \
		if (es == Acad::eOk)                                                \
		{                                                                   \
			hasSymbol = !!pTable->has(name);                                \
			pTable->close();                                                \
		}                                                                   \
		return hasSymbol;                                                   \
	}
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Block)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(DimStyle)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Layer)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Linetype)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(RegApp)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(TextStyle)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(UCS)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(View)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Viewport)
#undef DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION

}  // namespace AcDbSymbolUtilities
