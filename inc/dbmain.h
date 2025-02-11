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
***     Description: Common includes for database support
***
*****************************************************************************/
#pragma once

#include "icarx/acut_str_util.h"
#include "icarx/AcDbDatabase.h"
#include "icarx/AcDbObjectIterator.h"
#include "icarx/AcDbObject.h"
#include "icarx/AcDbXObject.h"
#include "icarx/AcCmComplexColor.h"
#include "icarx/AcCmColor.h"
#include "icarx/AcCmHSB.h"
#include "icarx/AcCmColorStr.h"
#include "icarx/AcDbColor.h"
#include "icarx/AcDbEntity.h"
#include "icarx/AcDbObjectReactor.h"
#include "icarx/AcDbEntityReactor.h"
#include "icarx/AcDbDatabaseReactor.h"
#include "icarx/AcDbExtents2d.h"
#include "icarx/AcDbExtents.h"
#include "icarx/AcDbInit.h"
#include "icarx/AcTextFind.h"

#include <stddef.h>
#include "adesk.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "AcHeapOpers.h"
#include "rxobject.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxditer.h"
#include "rxsrvice.h"
#include "dbboiler.h"
#include "dbptrar.h"
#include "dbcolor.h"
#include "dbidar.h"
#include "drawable.h"
#include "dbsecurity.h"
#include "AcString.h"
#include "acdb.h"
#include "dbhandle.h"
#include "dbfiler.h"
#include "ads_db.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"
#include "acgidefs.h"
#include "acarray.h"

ACDBCORE2D_PORT const AcArray<AcDbDatabase*>& acdbActiveDatabaseArray();
void* acdbAlloc(size_t);
ACDB_PORT bool acdbDisplayPreviewFromDwg(const ACHAR* pszDwgfilename, void* pPreviewWnd,
										 const uint32_t* pBgColor = nullptr);
void acdbFree(void*);
void acdbFreeResBufContents(resbuf* pField);
Acad::ErrorStatus acdbGetAdsName(ads_name& objName, AcDbObjectId objId);
Acad::ErrorStatus acdbGetObjectId(AcDbObjectId& objId, const ads_name objName);
Acad::ErrorStatus acdbGetThumbnailBitmapFromDxfFile(const ACHAR* filename, void*& pBitmap);
AcDb::DwgDataType acdbGroupCodeToType(AcDb::DxfCode pCode);
bool acdbIsCustomObject(const AcDbObjectId& id);
ACDBCORE2D_PORT bool acdbIsGsWorkerThread();
Acad::ErrorStatus acdbLoadLineTypeFile(const ACHAR* ltname, const ACHAR* fname, AcDbDatabase* pDb);
Acad::ErrorStatus acdbLoadMlineStyleFile(const ACHAR* sname, const ACHAR* fname);
ACDBCORE2D_PORT Acad::ErrorStatus acdbOpenObject(AcDbEntity*& pEnt, AcDbObjectId id,
												 AcDb::OpenMode mode = AcDb::kForRead,
												 bool openErased = false);
ACDBCORE2D_PORT Acad::ErrorStatus acdbOpenObject(AcDbObject*& pObj, AcDbObjectId id,
												 AcDb::OpenMode mode, bool openErased,
												 const AcRxClass* pClass);
ACDBCORE2D_PORT Acad::ErrorStatus acdbOpenObject(AcDbObject*& pObj, AcDbObjectId id,
												 AcRxClass* (*pfDesc)(), AcDb::OpenMode mode,
												 bool openErased);
ACDBCORE2D_PORT AcDbObjectId acdbPersistentReactorObjectId(const void* pSomething);
void* acdbRealloc(void*, size_t);
Acad::ErrorStatus acdbResurrectMeNow(const AcDbObjectId& id);
Acad::ErrorStatus acdbSetReferenced(AcDbObjectId objId);
Acad::ErrorStatus acdbValKey(const ads_name lname);

inline bool acdbIsPersistentReactor(const void* pSomething)
{
	return !::acdbPersistentReactorObjectId(pSomething).isNull();
}

inline Acad::ErrorStatus acdbOpenAcDbObject(AcDbObject*& pObj, AcDbObjectId id, AcDb::OpenMode mode,
											bool openErasedObject = false)
{
	return ::acdbOpenObject(pObj, id, mode, openErasedObject, /*pClass*/ nullptr);
}

template<class T_OBJECT>
inline Acad::ErrorStatus acdbOpenObject(T_OBJECT*& pObj, AcDbObjectId id,
										AcDb::OpenMode mode = AcDb::kForRead,
										bool openErased = false)
{
	return ::acdbOpenObject((AcDbObject*&)pObj, id, &T_OBJECT::desc, mode, openErased);
}

inline Acad::ErrorStatus acdbOpenObject(AcDbObject*& pObj, AcDbObjectId id,
										AcDb::OpenMode mode = AcDb::kForRead,
										bool openErased = false)
{
	return ::acdbOpenObject(pObj, id, mode, openErased, /*pClass*/ nullptr);
}

inline Acad::ErrorStatus acdbOpenAcDbEntity(AcDbEntity*& pEnt, AcDbObjectId id, AcDb::OpenMode mode,
											bool openErasedEntity = false)
{
	return ::acdbOpenObject(pEnt, id, mode, openErasedEntity);
}
