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
***     Description: Declaration of AcDbViewRepBlockReference class
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbBlockReference.h"

#ifndef ACSYNERGY_PORT
#	define ACSYNERGY_PORT
#endif

class AcDbImpViewRepBlockReference;

#include "icarx/IcArxPackPush.h"

class ACSYNERGY_PORT AcDbViewRepBlockReference : public AcDbBlockReference
{
	friend class AcDbViewRepBlockReferenceInternals;

private:
	AcDbImpViewRepBlockReference* getImpObject();

protected:
	Acad::ErrorStatus subPopHighlight(const AcDbFullSubentPath& subId) override;
	Acad::ErrorStatus subPushHighlight(const AcDbFullSubentPath& subId,
									   AcGiHighlightStyle highlightStyle) override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	void subViewportDraw(AcGiViewportDraw* pVd) override;
	bool subWorldDraw(AcGiWorldDraw* mode) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbViewRepBlockReference);

	AcDbViewRepBlockReference();
	AcDbViewRepBlockReference(const AcGePoint3d& position, AcDbObjectId blockTableRecord);
	~AcDbViewRepBlockReference();

	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	Acad::ErrorStatus copyFrom(const AcRxObject* pSrc) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	AcDbObjectId ownerViewportId() const;
	AcGePoint3d position() const override;
	void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	void setOwnerViewportId(const AcDbObjectId& viewportId);
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	Acad::ErrorStatus subGetGsMarkersAtSubentPath(
			const AcDbFullSubentPath& subPath, AcArray<IcArx::Integers::GsMarker>& gsMarkers) const override;
};

#include "icarx/IcArxPackPop.h"
