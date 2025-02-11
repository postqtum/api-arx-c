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
***     Description: Declaration of AcDbViewSymbol class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "AcString.h"

#ifndef ACSYNERGY_PORT
#	define ACSYNERGY_PORT
#endif

class AcDbImpViewSymbol;
class AcRxSymbolSketch;
class AcDbAssocViewSymbolConstrGrpPE;
class AcGeCurve3d;

#include "icarx/IcArxPackPush.h"

class ACSYNERGY_PORT AcDbViewSymbol : public AcDbEntity
{
	friend class AcDbViewSymbolSystemInternals;
	friend class AcDbAssocViewSymbolConstrGrpPE;

protected:
	AcDbViewSymbol();
	AcDbViewSymbol(AcDbSystemInternals*);

public:
	ACRX_DECLARE_MEMBERS(AcDbViewSymbol);

	~AcDbViewSymbol();

	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	Acad::ErrorStatus createDefinition(AcRxSymbolSketch* pSketchObject);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	Acad::ErrorStatus exportSymbolGeometry(AcArray<AcGeCurve3d*>& geomArr,
										   const AcDbObjectId& viewRepId);
	Acad::ErrorStatus getIdentifier(ACHAR*& pszName) const;
	Acad::ErrorStatus getIdentifier(AcString& sName) const;
	void objectClosed(const AcDbObjectId dbObjId) override;
	AcDbObjectId owningViewRep() const;
	void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	double scale() const;
	Acad::ErrorStatus setIdentifier(const AcString& sName);
	void setOwningViewRep(const AcDbObjectId& owner);
	void setScale(double val);
	Acad::ErrorStatus setSymbolGeometry(const AcDbObjectIdArray& entIds);
	Acad::ErrorStatus setSymbolGeometry(const AcArray<AcDbObject*>& entities);
	void setSymbolStyleId(const AcDbObjectId& styleId);
	Acad::ErrorStatus subClose() override;
	Acad::ErrorStatus subErase(bool erasing) override;
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize,
									   const int gripSize, const AcGeVector3d& curViewDir,
									   const int bitflags) const override;
	Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
										IcArx::Integers::GsMarker gsSelMark,
										const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
										AcDbIntArray& geomIds) const override;
	void subGripStatus(const AcDb::GripStat status) override;
	void subList() const override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags) override;
	void subSetDatabaseDefaults(AcDbDatabase* pDb) override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	bool subWorldDraw(AcGiWorldDraw* pWd) override;
	AcDbObjectId symbolStyleId() const;
	Acad::ErrorStatus updateDefinition();
};

#include "icarx/IcArxPackPop.h"
