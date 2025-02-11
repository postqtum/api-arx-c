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
***     Description: Declaration of AcDbOsnapPointRef class
***
*****************************************************************************/
#pragma once

#include "../gept3dar.h"
#include "AcDbPointRef.h"

#include "IcArxPackPush.h"

class AcDbOsnapPointRef : public AcDbPointRef
{
protected:
	Acad::ErrorStatus evalPointGuts(AcDbPointRef::OsnapType ospType, const AcGePoint3d& pickPt,
									const AcGePoint3d& lastPt, AcGePoint3d& pt);
	double findNearPointParam(const AcGePoint3d& pt) const;
	bool getEllipseParams(double& sP, double& eP) const;
	Acad::ErrorStatus getIntPoints(const AcDbEntity* pEnt, const AcDbEntity* pIntEnt,
								   AcDb::Intersect intType, AcGePoint3dArray& intPts,
								   int gsMarker1 = 0, int gsMarker2 = 0) const;
	bool isTransSpatial(bool isMainObj = true) const;
	AcGePoint3d nearPoint();
	Acad::ErrorStatus updateSubentPathGuts(AcDbFullSubentPath& path, AcDbIdMapping& idMap);

public:
	ACRX_DECLARE_MEMBERS(AcDbOsnapPointRef);

	AcDbOsnapPointRef();
	AcDbOsnapPointRef(const AcGePoint3d& refPt);
	AcDbOsnapPointRef(AcDbPointRef::OsnapType osnapType, const AcDbFullSubentPath* objPath,
					  const AcDbFullSubentPath* intObjPath = nullptr, const AcGePoint3d* refPt = nullptr,
					  AcDbPointRef* lastPtRef = nullptr);
	AcDbOsnapPointRef(const AcDbOsnapPointRef& src);
	~AcDbOsnapPointRef();
	AcDbPointRef& operator=(const AcDbPointRef& src) override;
	AcDbOsnapPointRef& operator=(const AcDbOsnapPointRef& src);

	Acad::ErrorStatus copyFrom(const AcRxObject* pSrc) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer, AcDbDatabase* pDb) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer, AcDbDatabase* pDb) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer, AcDbDatabase* pDb) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer, AcDbDatabase* pDb) const override;
	Acad::ErrorStatus evalPoint(AcGePoint3d& pt) override;
	ACDBCORE2D_PORT Acad::ErrorStatus evalPoint(AcDbPointRef::OsnapType ospType,
												const AcGePoint3d& lastPt, AcGePoint3d& pt);
	Acad::ErrorStatus getEntities(AcDbFullSubentPathArray& ents,
								  bool getLastPtRef = true) const override;
	Acad::ErrorStatus getIdPath(AcDbFullSubentPath& idPath) const;
	Acad::ErrorStatus getIntIdPath(AcDbFullSubentPath& intIdPath) const;
	Acad::ErrorStatus getXrefHandles(AcDbHandleArrayPtRef& xrefHandles) const;
	Acad::ErrorStatus getXrefIntHandles(AcDbHandleArrayPtRef& xrefHandles) const;
	bool isGeomErased() const override;
	bool isXrefObj(AcDbObjectIdArray& ids1, AcDbObjectIdArray& ids2,
				   bool isMainObj = true) const override;
	AcDbPointRef* lastPointRef() const;
	double nearPointParam() const;
	AcDbPointRef::OsnapType osnapType() const;
	AcGePoint3d point() const;
	Acad::ErrorStatus setIdPath(const AcDbFullSubentPath& idPath);
	Acad::ErrorStatus setIntIdPath(const AcDbFullSubentPath& intIdPath);
	Acad::ErrorStatus setLastPointRef(AcDbPointRef* ptRef);
	Acad::ErrorStatus setNearPointParam(double newVal);
	Acad::ErrorStatus setOsnapType(AcDbPointRef::OsnapType osnType);
	Acad::ErrorStatus setPoint(const AcGePoint3d& pt);
	Acad::ErrorStatus setXrefHandles(const AcDbHandleArrayPtRef& xrefHandles);
	Acad::ErrorStatus setXrefIntHandles(const AcDbHandleArrayPtRef& xrefHandles);
	void updateDueToMirror(bool inMirror = false) override;
	Acad::ErrorStatus updateSubentPath(AcDbIdMapping& idMap) override;
	Acad::ErrorStatus updateXrefSubentPath() override;
};

#include "IcArxPackPop.h"
