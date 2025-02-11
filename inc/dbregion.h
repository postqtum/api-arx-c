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
***     Description: Declaration of AcDbRegion class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#include "icarx/IcArxPackPush.h"

class AcDbRegion : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	GEOMENT_DECLARE_MEMBERS(AcDbRegion);

public:
	ACDB_PORT AcDbRegion();
	ACDB_PORT ~AcDbRegion();

	virtual void* ASMBodyCopy(bool bDeepCopy = false) const;
	virtual Acad::ErrorStatus booleanOper(AcDb::BoolOperType operation, AcDbRegion* otherRegion);
	virtual void commitWritableASMBody();
	static Acad::ErrorStatus createFromCurves(const AcDbVoidPtrArray& curveSegments,
											  AcDbVoidPtrArray& regions);
	ACDB_PORT void dragStatus(const AcDb::DragStat) override;
	virtual Acad::ErrorStatus getArea(double& regionArea) const;
	virtual Acad::ErrorStatus getAreaProp(const AcGePoint3d& origin, const AcGeVector3d& xAxis,
										  const AcGeVector3d& yAxis, double& perimeter,
										  double& area, AcGePoint2d& centroid, double momInertia[2],
										  double& prodInertia, double prinMoments[2],
										  AcGeVector2d prinAxes[2], double radiiGyration[2],
										  AcGePoint2d& extentsLow, AcGePoint2d& extentsHigh) const;
	virtual void const* getLockedASMBody();
	virtual void* getLockedWritableASMBody();
	virtual Acad::ErrorStatus getNormal(AcGeVector3d&) const;
	virtual Acad::ErrorStatus getPerimeter(double&) const;
	virtual Acad::ErrorStatus getPlane(AcGePlane& regionPlane) const;
	ACDB_PORT Acad::ErrorStatus getPlane(AcGePlane& plane, AcDb::Planarity& type) const override;
	virtual AcDbSubentId internalSubentId(void* ent) const;
	virtual void* internalSubentPtr(const AcDbSubentId& id) const;
	virtual bool isNull() const;
	virtual uint32_t numChanges() const;
	ACDB_PORT virtual Acad::ErrorStatus setASMBody(const void* modelerBody);
	virtual void unlockASMBody();
	ACDB_PORT virtual bool usesGraphicsCache();
};

#include "icarx/IcArxPackPop.h"
