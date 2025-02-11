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
***     Description: Declaration of AcDbAttribute class
***
*****************************************************************************/
#pragma once

#include "AcDbAttribute.h"
#include "../gepnt3d.h"
#include "../gemat3d.h"
#include "../gescl3d.h"
#include "AcDbEnumGeom.h"

class AcDbSequenceEnd;

#include "IcArxPackPush.h"

class AcDbBlockReference : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_PORT AcDbBlockReference();
	AcDbBlockReference(const AcGePoint3d& position, AcDbObjectId blockTableRec);
	~AcDbBlockReference();

	ACDB_DECLARE_MEMBERS(AcDbBlockReference);

	Acad::ErrorStatus appendAttribute(AcDbAttribute*);
	Acad::ErrorStatus appendAttribute(AcDbObjectId&, AcDbAttribute*);
	AcDbObjectIterator* attributeIterator() const;
	AcDbObjectId blockTableRecord() const;
	AcGeMatrix3d blockTransform() const;
	virtual Acad::ErrorStatus explodeToOwnerSpace() const;
	Acad::ErrorStatus geomExtentsBestFit(
			AcDbExtents& extents, const AcGeMatrix3d& parentXform = AcGeMatrix3d::kIdentity) const;
	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	bool isPlanar() const override { return true; }
	AcGeMatrix3d nonAnnotationBlockTransform() const;
	AcGeScale3d nonAnnotationScaleFactors() const;
	AcGeVector3d normal() const;
	Acad::ErrorStatus openAttribute(AcDbAttribute*&, AcDbObjectId, AcDb::OpenMode,
									bool openErasedOne = false);
	Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&, AcDb::OpenMode);
	virtual AcGePoint3d position() const;
	double rotation() const;
	AcGeScale3d scaleFactors() const;
	virtual Acad::ErrorStatus setBlockTableRecord(AcDbObjectId);
	virtual Acad::ErrorStatus setBlockTransform(const AcGeMatrix3d&);
	virtual Acad::ErrorStatus setNormal(const AcGeVector3d& newVal);
	virtual Acad::ErrorStatus setPosition(const AcGePoint3d&);
	virtual Acad::ErrorStatus setRotation(double newVal);
	virtual Acad::ErrorStatus setScaleFactors(const AcGeScale3d& scale);
	virtual bool treatAsAcDbBlockRefForExplode() const;
};

#include "IcArxPackPop.h"
