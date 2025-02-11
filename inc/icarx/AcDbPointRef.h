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
***     Description: Declaration of AcDbPointRef class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "../rxobject.h"

#include "AcDbIdMapping.h"
#include "AcDbFullSubentPath.h"

class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbObject;
class AcDbEntity;
class AcDbViewport;

using AcDbFullSubentPathArray =
		AcArray<AcDbFullSubentPath, AcArrayObjectCopyReallocator<AcDbFullSubentPath>>;
using AcDbHandleArrayPtRef = AcArray<AcDbHandle, AcArrayObjectCopyReallocator<AcDbHandle>>;

#include "IcArxPackPush.h"

class AcDbPointRef : public AcRxObject
{
public:
	enum OsnapType
	{
		kOsnapNone = 0,
		kOsnapEnd = 1,
		kOsnapMid = 2,
		kOsnapCen = 3,
		kOsnapNode = 4,
		kOsnapQuad = 5,
		kOsnapInt = 6,
		kOsnapIns = 7,
		kOsnapPerp = 8,
		kOsnapTan = 9,
		kOsnapNear = 10,
		kOsnapApint = 11,
		kOsnapStart = 13,
		kOsnapCentroid = 14
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbPointRef);

	static bool calcTransform(const AcDbObjectIdArray& ids, AcGeMatrix3d& A_Ecs2Wcs);
	virtual Acad::ErrorStatus deepClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
										AcDbIdMapping& /*idMap*/, bool isPrimary = true) const
	{
		(void)(pOwnerObject);
		(void)(pClonedObject);
		(void)(isPrimary);

		return Acad::eOk;
	}
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer, AcDbDatabase* pDb) = 0;
	static Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer, AcDbDatabase* pDb,
										 AcDbPointRef*& pPointRef);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer, AcDbDatabase* pDb) const = 0;
	static Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer, AcDbDatabase* pDb,
										  const AcDbPointRef* pPointRef);
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer, AcDbDatabase* pDb) = 0;
	static Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer, AcDbDatabase* pDb,
										 AcDbPointRef*& pPointRef);
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer, AcDbDatabase* pDb) const = 0;
	static Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer, AcDbDatabase* pDb,
										  const AcDbPointRef* pPointRef);
	virtual Acad::ErrorStatus evalPoint(AcGePoint3d& pnt_wcs) = 0;
	virtual Acad::ErrorStatus getEntities(AcDbFullSubentPathArray& ents,
										  bool getLastPtRef = true) const = 0;
	virtual bool isGeomErased() const = 0;
	virtual bool isXrefObj(AcDbObjectIdArray& ids1, AcDbObjectIdArray& ids2,
						   bool isMainObj = true) const = 0;
	static AcGeMatrix3d mswcsToPswcs(const AcDbViewport* pVPort);
	virtual AcDbPointRef& operator=(const AcDbPointRef& src);
	virtual Acad::ErrorStatus subErase(bool erasing)
	{
		(void)(erasing);
		return Acad::eOk;
	}
	static AcDbEntity* subentPtr(const AcDbFullSubentPath& objPath, bool& isCloned,
								 bool& reverseArc, bool& isStandAloneArc);
	virtual void updateDueToMirror(bool inMirror = false) = 0;
	virtual Acad::ErrorStatus updateSubentPath(AcDbIdMapping& idMap) = 0;
	virtual Acad::ErrorStatus updateXrefSubentPath() = 0;
	virtual Acad::ErrorStatus wblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
										  AcDbIdMapping& /*idMap*/, bool isPrimary = true) const
	{
		(void)(pOwnerObject);
		(void)(pClonedObject);
		(void)(isPrimary);

		return Acad::eOk;
	}
	static AcGeMatrix3d wcsToDcsMatrix(const AcDbViewport* pVPort);
};

#include "IcArxPackPop.h"
