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

#include "acdb.h"
#include "acadstrc.h"
#include "acarray.h"
#include "acdbport.h"

class AcDbDatabase;
class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbObject;
class ENTITY;
class VERTEX;
class COEDGE;
class EDGE;
class LOOP;
class FACE;
class SHELL;
class LUMP;
class BODY;

using AcDbAsmBodyArray = AcArray<BODY*>;
using AcDbAsmEntityArray = AcArray<ENTITY*>;
using AcDbAsmVertexArray = AcArray<VERTEX*>;
using AcDbAsmEdgeArray = AcArray<EDGE*>;
using AcDbAsmFaceArray = AcArray<FACE*>;
using AcDbAsmEdgeArray2d = AcArray<AcDbAsmEdgeArray>;

enum ModelerRestoreOptions
{
	kReadForeignEntities = 0x01,
	kReadUnknownEntities = 0x02,
	kLoseUnknownCustomAttributes = 0x04,
	kReadStrangerEntityDefault =
			(kReadForeignEntities | kReadUnknownEntities | kLoseUnknownCustomAttributes),
	kModelerRestoreOptionsFuture1 = 0x08,
	kModelerRestoreOptionsFuture2 = 0x10,
	kModelerRestoreOptionsFuture3 = 0x20,
	kModelerRestoreOptionsFuture4 = 0x40,
};

extern "C"
{
	bool acdbIsModelerStarted();
	void acdbModelerEnd();
	void acdbModelerStart();
}

ACDB_PORT int acdbGetModelerDwgVer(AcDb::AcDbDwgVersion dwgVer, AcDbObject* pObj = nullptr);
ACDB_PORT Acad::ErrorStatus acdbModelerRestoreEntitiesFromDwgFiler(
		AcDbDwgFiler* filer, AcArray<ENTITY*>& entities, int* pModelerVersion = nullptr,
		unsigned restoreOptions = kReadStrangerEntityDefault);
ACDB_PORT Acad::ErrorStatus acdbModelerRestoreEntityFromDwgFiler(
		AcDbDwgFiler* filer, ENTITY*& pEntity, int* pModelerVersion = nullptr,
		unsigned restoreOptions = kReadStrangerEntityDefault);
ACDB_PORT Acad::ErrorStatus acdbModelerRestoreEntityFromDxfFiler(
		AcDbDxfFiler* filer, ENTITY*& pEntity, int* pModelerVersion = nullptr,
		unsigned restoreOptions = kReadStrangerEntityDefault);
ACDB_PORT Acad::ErrorStatus acdbModelerSaveEntitiesToDwgFiler(AcDbDwgFiler* filer,
															  const AcArray<ENTITY*>& entities,
															  AcDbDatabase* pDb,
															  int modelerVersion = -1);
ACDB_PORT Acad::ErrorStatus acdbModelerSaveEntitiesToDxfFiler(AcDbDxfFiler* filer,
															  const AcArray<ENTITY*>& entities,
															  AcDbDatabase* pDb,
															  int modelerVersion = -1);
ACDB_PORT Acad::ErrorStatus acdbModelerSaveEntityToDwgFiler(AcDbDwgFiler* filer, ENTITY* entity,
															AcDbDatabase* pDb,
															int modelerVersion = -1);
ACDB_PORT Acad::ErrorStatus acdbModelerSaveEntityToDxfFiler(AcDbDxfFiler* filer, ENTITY* entity,
															AcDbDatabase* pDb,
															int modelerVersion = -1);
